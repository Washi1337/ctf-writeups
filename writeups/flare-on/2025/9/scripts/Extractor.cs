
using System.Buffers.Binary;
using System.Diagnostics;
using System.Text.Json;
using AsmResolver.PE;
using AsmResolver.PE.Exports;
using AsmResolver.PE.Imports;
using Iced.Intel;

namespace Extractor;

public record DllInfo(string Name)
{
    public Dictionary<string, Transform> DeclaredTransforms { get; set; }= new();
    public List<TransformRef> TransformSequence { get; set; }= new();
    public ulong Modulus { get; set; }
    public ulong[] InitialMatrix { get; set; }= new ulong[16];
    public ulong[] ExpectedMatrix { get; set; }= new ulong[16];
    public ulong Exponent { get; set; }
}

public record struct Transform(TransformType Type, byte[] Data);

public record struct TransformRef(string? Module, string Name);

public enum TransformType
{
    Substitution,
    Permutation,
    Exponentiation,
}

internal static class Program
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Loading DLLs....");

        foreach (string file in Directory.GetFiles(@"resources", "*.dll"))
        {
            string fileName = Path.GetFileName(file);
            Console.WriteLine(fileName);

            var info = new DllInfo(fileName);

            byte[] contents = File.ReadAllBytes(file);
            var image = PEImage.FromBytes(contents);

            foreach (var export in image.Exports.Entries)
            {
                if (export.Name.StartsWith("_Z21f"))
                {
                    info.DeclaredTransforms[export.Name!] = ParseTransformCode(contents, image, export);
                }
                else if (export.Name == "_Z5checkPh")
                {
                    ParseCheckFunction(contents, image, export, info);
                }
            }

            using var fs = File.Create($@"extracted\{fileName}.json");
            JsonSerializer.Serialize(fs, info);
        }

    }

    private static Transform ParseTransformCode(byte[] contents, PEImage image, ExportedSymbol export)
    {
        var instructions = GetInstructionsUntil(contents, image.ImageBase + export.Address.Rva, (int) export.Address.Offset);
        ulong codeSize = instructions[^1].IP - instructions[0].IP;
        return codeSize switch
        {
            > 590 and < 610 => new Transform(TransformType.Substitution, ExtractSubstitution(instructions)),
            < 300 => new Transform(TransformType.Permutation, ExtractPermutation(instructions)),
            > 640 => new Transform(TransformType.Exponentiation, ExtractExponent(instructions)),
            _ => throw new Exception($"{export}: {instructions[0].IP:X8} - {instructions[^1].IP:X8} ({codeSize} bytes)")
        };
    }

    private static byte[] ExtractExponent(List<Instruction> instructions)
    {
        int x = 0;
        byte[] buffer = new byte[31];

        foreach (var instr in instructions)
        {
            if (instr is {Mnemonic: Mnemonic.Mov, Op0Kind: OpKind.Register, Op1Kind: OpKind.Immediate64})
            {
                BinaryPrimitives.WriteUInt64LittleEndian(buffer.AsSpan(x), instr.Immediate64);
                x += sizeof(ulong);
                if (x == 16)
                    x--; // shitty hack because alignment...
            }
        }

        Debug.Assert(x == buffer.Length);
        return buffer;
    }

    private static void ParseCheckFunction(byte[] contents, PEImage image, ExportedSymbol export, DllInfo info)
    {
        var instructions = GetInstructionsUntil(contents, image.ImageBase + export.Address.Rva, (int) export.Address.Offset);

        int i = 0;
        ParseTransforms(image, info, instructions, ref i);
        ParseExponentiationParameters(info, instructions, ref i);
        ParseInitialMatrix(info, instructions, ref i);

        ParseExpectedMatrix(info, instructions, ref i);
    }

    private static void ParseExpectedMatrix(DllInfo info, List<Instruction> instructions, ref int i)
    {
        int current = 0;

        bool memcmpFound = false;

        i = instructions.Count -1;
        for (; i >= 0 && current < 16; i--)
        {
            var instruction = instructions[i];

            if (!memcmpFound)
            {
                if (instruction.Mnemonic == Mnemonic.Call)
                    memcmpFound = true;
            }
            else
            {
                if (instruction is {Mnemonic: Mnemonic.Mov, Op0Kind: OpKind.Register, Op1Kind: OpKind.Immediate64})
                {
                    info.ExpectedMatrix[info.InitialMatrix.Length - 1 - current] = instruction.Immediate64;
                    current++;
                }
            }
        }
    }

    private static void ParseTransforms(PEImage image, DllInfo info, List<Instruction> instructions, ref int index)
    {
        for (; index < instructions.Count; index++)
        {
            var instruction = instructions[index];
            if (instruction.OpCode.Mnemonic == Mnemonic.Call)
            {
                if (instruction.Op0Kind == OpKind.Register)
                {
                    ulong ptr = instructions[index - 1].IPRelativeMemoryAddress;
                    ImportedSymbol? xref = null;
                    foreach (var import in image.Imports)
                    {
                        foreach (var symbol in import.Symbols)
                        {
                            if (ptr - image.ImageBase == symbol.AddressTableEntry!.Rva)
                            {
                                xref = symbol;
                                break;
                            }
                        }
                    }

                    if (xref is null)
                        throw new ArgumentNullException();
                    info.TransformSequence.Add(new TransformRef(xref.DeclaringModule.Name, xref.Name));
                }
                else
                {
                    var xref = image.Exports.Entries.First(x => x.Address.Rva == instruction.IPRelativeMemoryAddress - image.ImageBase);
                    info.TransformSequence.Add(new TransformRef(null, xref.Name!));
                }
            }
            else if (instruction is { Mnemonic: Mnemonic.Mov, Op0Kind: OpKind.Register, Op1Kind: OpKind.Immediate64})
            {
                return;
            }
        }

        throw new ArgumentException();
    }

    private static void ParseExponentiationParameters(DllInfo info, List<Instruction> instructions, ref int i)
    {
        Debug.Assert(instructions[i] is {Mnemonic:Mnemonic.Mov, Op0Kind: OpKind.Register, Op1Kind: OpKind.Immediate64});

        for (; i < instructions.Count; i++)
        {
            var instruction = instructions[i];
            if (instruction is {Mnemonic: Mnemonic.Mov, Op0Kind: OpKind.Register, Op1Kind: OpKind.Immediate64})
            {
                if (info.Modulus == 0)
                {
                    info.Modulus = instruction.Immediate64;
                }
                else
                {
                    info.Exponent = instruction.Immediate64;
                    i++;
                    break;
                }
            }
        }
    }

    private static void ParseInitialMatrix(DllInfo info, List<Instruction> instructions, ref int i)
    {
        int current = 0;
        for (; i < instructions.Count && current < 16; i++)
        {
            var instruction = instructions[i];
            if (instruction is {Mnemonic: Mnemonic.Mov, Op0Kind: OpKind.Register, Op1Kind: OpKind.Immediate64})
                info.InitialMatrix[current++] = instruction.Immediate64;
        }
    }

    private static byte[] ExtractSubstitution(List<Instruction> instructions)
    {
        int x = 0;
        byte[] buffer = new byte[256];

        foreach (var instr in instructions)
        {
            if (instr is {Mnemonic: Mnemonic.Mov, Op0Kind: OpKind.Register, Op1Kind: OpKind.Immediate64})
            {
                BinaryPrimitives.WriteUInt64LittleEndian(buffer.AsSpan(x), instr.Immediate64);
                x += sizeof(ulong);
            }
        }

        Debug.Assert(x == buffer.Length);
        return buffer;
    }

    private static byte[] ExtractPermutation(List<Instruction> instructions)
    {
        int x = 0;
        byte[] buffer = new byte[32];

        foreach (var instr in instructions)
        {
            if (instr is {Mnemonic: Mnemonic.Mov, Op0Kind: OpKind.Register, Op1Kind: OpKind.Immediate64})
            {
                BinaryPrimitives.WriteUInt64LittleEndian(buffer.AsSpan(x), instr.Immediate64);
                x += sizeof(ulong);
            }
        }

        Debug.Assert(x == buffer.Length);
        return buffer;
    }

    private static List<Instruction> GetInstructionsUntil(byte[] code, ulong baseAddr, int index)
    {
        var result = new List<Instruction>();
        var decoder = Decoder.Create(64, new ByteArrayCodeReader(code, index, code.Length - index - 1));
        decoder.IP = baseAddr;

        while (true)
        {
            var instruction = decoder.Decode();
            result.Add(instruction);
            if (instruction.OpCode.Mnemonic == Mnemonic.Ret)
                break;
        }

        return result;
    }
}
