using AsmResolver.DotNet;
using AsmResolver.DotNet.Code.Cil;
using AsmResolver.DotNet.Signatures;
using AsmResolver.IO;
using AsmResolver.PE.DotNet.Cil;
using AsmResolver.PE.DotNet.Metadata.Tables;
using AsmResolver.PE.DotNet.Metadata.Tables.Rows;

public struct MethodPatchInfo
{
    public MethodDefinition TargetMethod;
    public byte[] TemplateBody;
    public Dictionary<uint, int> Patches;

    public void ApplyPatch()
    {
        var module = TargetMethod.Module!;

        var body = new CilMethodBody(TargetMethod);

        // Need to resort to raw method body for local variables, because AsmResolver sometimes
        // won't return the body of the target method as they are broken.
        var bodyReader = module.DotNetDirectory!.Metadata!
            .GetStream<TablesStream>()
            .GetTable<MethodDefinitionRow>()
            .GetByRid(TargetMethod.MetadataToken.Rid).Body.CreateReader();

        // Read raw method body.
        var rawBody = CilRawMethodBody.FromReader(ref bodyReader);

        // If fat, we have some extra fields to process.
        if (rawBody is CilRawFatMethodBody fatBody)
        {
            body.MaxStack = fatBody.MaxStack;

            if (fatBody.LocalVarSigToken != 0)
            {
                // Read the original signature.
                var signature = (LocalVariablesSignature)
                    ((StandAloneSignature) module.LookupMember(fatBody.LocalVarSigToken))
                    .Signature!;

                // Add the locals.
                foreach (var type in signature.VariableTypes)
                    body.LocalVariables.Add(new CilLocalVariable(type));
            }
        }

        // Decode all instructions.
        var patchedBody = CreatePatchedBody();
        var disassembler = new CilDisassembler(
            ByteArrayDataSource.CreateReader(patchedBody),
            new PhysicalCilOperandResolver(module, body));

        // Add them to the body.
        body.Instructions.AddRange(disassembler.ReadInstructions());

        // Replace original method body with new one.
        TargetMethod.CilMethodBody = body;
    }

    private byte[] CreatePatchedBody()
    {
        byte[] result = (byte[]) TemplateBody.Clone();
        if (Patches is null)
            return result;

        foreach ((uint key, int token) in Patches)
        {
            result[(int)key] = (byte)token;
            result[(int)(key + 1U)] = (byte)(token >> 8);
            result[(int)(key + 2U)] = (byte)(token >> 0x10);
            result[(int)(key + 3U)] = (byte)(token >> 0x18);
        }

        return result;
    }
}