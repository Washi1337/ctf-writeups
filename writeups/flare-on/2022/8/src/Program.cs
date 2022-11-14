using AsmResolver;
using AsmResolver.DotNet;
using AsmResolver.DotNet.Builder;
using AsmResolver.DotNet.Code.Cil;
using AsmResolver.DotNet.Serialized;
using AsmResolver.DotNet.Signatures.Types;
using AsmResolver.PE.DotNet.Builder;
using AsmResolver.PE.DotNet.Cil;
using AsmResolver.PE.DotNet.Metadata.Tables;
using AsmResolver.PE.File;

namespace RewriteDynamicMethod;

internal static class Program
{
    private static readonly MetadataToken Stage1DecrypterToken = 0x060000BC;
    private static readonly MetadataToken Stage2DecrypterToken = 0x060000BB;

    private static readonly Dictionary<MetadataToken, byte[]> BodyTemplates = new();
    private static readonly Dictionary<MetadataToken, Dictionary<uint, int>> BodyPatches = new();

    public static void Main()
    {
        // Read file with EmptyErrorListener to surpress parser errors.
        var peFile = PEFile.FromFile(@"/home/washi/RE/ctf/flareon/2022/08/FlareOn.Backdoor.exe");
        var module = ModuleDefinition.FromFile(peFile, new ModuleReaderParameters(EmptyErrorListener.Instance));

        // Extract our data.
        ExtractTemplatesAndPatches(module);

        // Decrypt all methods.
        DecryptAllMethods(peFile, module);

        // Create an image builder that preserves most data.
        var imageBuilder = new ManagedPEImageBuilder(new DotNetDirectoryFactory
        {
            MetadataBuilderFlags = MetadataBuilderFlags.PreserveAll,
            MethodBodySerializer = new CilMethodBodySerializer
            {
                ComputeMaxStackOnBuildOverride = false
            }
        });

        var result = imageBuilder.CreateImage(module);

        // Print out any builder errors.
        Console.WriteLine($"Writer errors {result.DiagnosticBag.Exceptions.Count}");
        foreach (var error in result.DiagnosticBag.Exceptions)
            Console.WriteLine(error.Message);

        // If we failed, don't bother writing to disk.
        if (result.HasFailed)
            return;

        Console.WriteLine("Writing...");

        // We successfully built a PE image, turn it into a PE file.
        var fileBuilder = new ManagedPEFileBuilder();
        var file = fileBuilder.CreateFile(result.ConstructedImage);

        // Copy over all original sections from the original PE file (except .text etc.)
        for (int i = 4; i < peFile.Sections.Count; i++)
        {
            var section = peFile.Sections[i];
            var clonedSection = new PESection(section.Name, section.Characteristics,
                new VirtualSegment(new DataSegment(section.ToArray()), section.GetVirtualSize()));
            file.Sections.Add(clonedSection);
        }

        // Write to disk!
        file.Write("/tmp/output.exe");
    }

    private static void ExtractTemplatesAndPatches(ModuleDefinition module)
    {
        // Terrible "emulator" code for extracting the patches and body templates.

        var initializer = (MethodDefinition) module.LookupMember(0x060000A1);

        List<byte>? currentBody = null;
        Dictionary<uint, int>? currentPatches = null;

        int? value1 = null;
        int? value2 = null;

        foreach (var instruction in initializer.CilMethodBody!.Instructions)
        {
            if (instruction.IsLdcI4())
            {
                int constant = instruction.GetLdcI4Constant();
                if (value1 is null)
                    value1 = constant;
                else
                    value2 = constant;
            }
            else switch (instruction.OpCode.Code)
            {
                case CilCode.Newobj:
                    if (instruction.Operand!.ToString()!.Contains("List"))
                        currentBody = new List<byte>();
                    else if (instruction.Operand!.ToString()!.Contains("Dictionary"))
                        currentPatches = new Dictionary<uint, int>();
                    else
                        return;
                    break;

                case CilCode.Callvirt:
                    if (instruction.Operand is IMethodDescriptor { Name: "Add" } method)
                    {
                        if (method.Signature!.ParameterTypes.Count == 1)
                            currentBody!.Add((byte) value1!);
                        else
                            currentPatches!.Add((uint) value1!, (int) value2!);

                        value1 = null;
                        value2 = null;
                    }
                    break;

                case CilCode.Stsfld:
                    var field = (IFieldDescriptor) instruction.Operand!;
                    var fieldType = field.Signature!.FieldType;
                    if (fieldType.Name!.Contains("Byte[]"))
                        BodyTemplates[field.MetadataToken] = currentBody!.ToArray();
                    else if (fieldType.Name.Contains("Dictionary"))
                        BodyPatches[field.MetadataToken] = currentPatches!;
                    break;
            }
        }
    }

    private static void DecryptAllMethods(IPEFile peFile, ModuleDefinition module)
    {
        foreach (var method in module.GetAllTypes().SelectMany(type => type.Methods))
            DecryptMethod(peFile, method);
    }

    private static void DecryptMethod(IPEFile peFile, MethodDefinition method)
    {
        // Check if this method is a decrypter for another method.
        if ((method.Name != "Main" && !method.Name!.Value.StartsWith("flare_")) || method.CilMethodBody is null)
            return;

        // Get all call instructions.
        var callInstructions = method.CilMethodBody.Instructions
            .Where(i => i.OpCode.Code == CilCode.Call)
            .ToArray();

        // Find target method that this method is decrypting.
        var targetMethod = callInstructions
            .FirstOrDefault(i => i.Operand!.ToString()!.Contains("flared"))?
            .Operand as MethodDefinition;

        if (targetMethod is null)
            return;

        // Determine whether it is a stage 1 or stage 2 decrypter, and apply the patch.
        if (callInstructions.Any(i => ((IMethodDescriptor) i.Operand!).MetadataToken == Stage1DecrypterToken))
            ApplyStage1Patch(method, targetMethod);
        else if (callInstructions.Any(i => ((IMethodDescriptor) i.Operand!).MetadataToken == Stage2DecrypterToken))
            ApplyStage2Patch(peFile, targetMethod);
    }

    private static void ApplyStage1Patch(MethodDefinition method, MethodDefinition targetMethod)
    {
        // Find fields that are used for hotpatching.
        var fields = method.CilMethodBody!.Instructions
            .Where(i => i.OpCode.Code == CilCode.Ldsfld)
            .Select(i => i.Operand)
            .OfType<FieldDefinition>()
            .ToArray();

        var patchInfo = new MethodPatchInfo();
        patchInfo.TargetMethod = targetMethod;

        // Find the field reference that contains the body.
        var bodyField = fields.FirstOrDefault(f => f.Signature?.FieldType is SzArrayTypeSignature);
        if (bodyField is null)
            return;

        patchInfo.TemplateBody = BodyTemplates[bodyField.MetadataToken];

        // Find the field reference that contains the patches.
        var patchesField = fields.FirstOrDefault(f => f.Signature?.FieldType is GenericInstanceTypeSignature);
        if (patchesField is not null)
            patchInfo.Patches = BodyPatches[patchesField.MetadataToken];

        // Apply
        patchInfo.ApplyPatch();
    }

    private static void ApplyStage2Patch(IPEFile peFile, MethodDefinition targetMethod)
    {
        try
        {
            // flare_66
            string hash = DecompiledCode.ComputeMethodHash(targetMethod);

            // flare_69
            var section = peFile.Sections.First(s => hash.StartsWith(s.Name));
            byte[] sectionData = section.ToArray()[..(int)section.GetVirtualSize()];

            // flare_46
            byte[] decryptedData = DecompiledCode.Rc4Decrypt(new byte[] { 0x12, 0x78, 0xAB, 0xDF }, sectionData);
            byte[] code = DecompiledCode.CreateStage2PatchedBody(decryptedData);

            // flare_67
            var patch = new MethodPatchInfo();
            patch.TargetMethod = targetMethod;
            patch.TemplateBody = code;
            patch.ApplyPatch();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Could not decrypt bytecode for {targetMethod.MetadataToken} ({targetMethod}). {ex}");
        }
    }
}