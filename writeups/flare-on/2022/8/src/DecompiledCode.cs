using System.Reflection;
using System.Security.Cryptography;
using System.Text;
using AsmResolver.DotNet;
using AsmResolver.DotNet.Signatures;
using AsmResolver.DotNet.Signatures.Types;
using AsmResolver.PE.DotNet.Cil;
using AsmResolver.PE.DotNet.Metadata.Tables;
using AsmResolver.PE.DotNet.Metadata.Tables.Rows;

namespace RewriteDynamicMethod;

public partial class DecompiledCode
{
    private static CallingConventions ReflectionCallingConvention(MethodDefinition method) => !method.Signature!.HasThis
        ? CallingConventions.Standard
        : (CallingConventions) method.Signature.Attributes;

    public static string TypeReflectionToString(TypeSignature type) => type is GenericInstanceTypeSignature genericType
        ? $"{genericType.GenericType.FullName}[{string.Join(", ", genericType.TypeArguments.Select(TypeReflectionToString))}]"
        : type.FullName;

    public static string ComputeMethodHash(MethodDefinition targetMethod)
    {
        var module = targetMethod.Module;
        string text = "";
        string text2 = "";
        byte[] bytes = Encoding.ASCII.GetBytes(((System.Reflection.MethodAttributes) targetMethod.Attributes).ToString());
        byte[] bytes2 = Encoding.ASCII.GetBytes(TypeReflectionToString(targetMethod.Signature.ReturnType));
        byte[] bytes3 = Encoding.ASCII.GetBytes(ReflectionCallingConvention(targetMethod).ToString());
        foreach (var parameter in targetMethod.Parameters)
        {
            string text3 = text2;
            var parameterType = parameter.ParameterType;
            text2 = text3 + ((parameterType != null) ? TypeReflectionToString(parameterType) : null);
        }

        var reader = module.DotNetDirectory.Metadata
            .GetStream<TablesStream>()
            .GetTable<MethodDefinitionRow>()
            .GetByRid(targetMethod.MetadataToken.Rid).Body.CreateReader();
        var methodBody = CilRawMethodBody.FromReader(ref reader);

        int maxStack = 8;
        var localVariables = new List<TypeSignature>();

        if (methodBody is CilRawFatMethodBody fatBody)
        {
            maxStack = fatBody.MaxStack;
            if (fatBody.LocalVarSigToken != 0)
            {
                var signature = (LocalVariablesSignature)
                    ((StandAloneSignature) module.LookupMember(fatBody.LocalVarSigToken))
                    .Signature!;
                foreach (var type in signature.VariableTypes)
                    localVariables.Add(type);
            }
        }

        byte[] bytes4 = Encoding.ASCII.GetBytes(maxStack.ToString());
        byte[] bytes5 = BitConverter.GetBytes(methodBody.Code.GetPhysicalSize());
        foreach (var localType in localVariables)
        {
            string text4 = text;
            text = text4 + ((localType != null) ? TypeReflectionToString(localType) : null);
        }
        byte[] bytes6 = Encoding.ASCII.GetBytes(text);
        byte[] bytes7 = Encoding.ASCII.GetBytes(text2);
        IncrementalHash incrementalHash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
        incrementalHash.AppendData(bytes5);
        incrementalHash.AppendData(bytes);
        incrementalHash.AppendData(bytes2);
        incrementalHash.AppendData(bytes4);
        incrementalHash.AppendData(bytes6);
        incrementalHash.AppendData(bytes7);
        incrementalHash.AppendData(bytes3);
        byte[] hashAndReset = incrementalHash.GetHashAndReset();
        StringBuilder stringBuilder = new StringBuilder(hashAndReset.Length * 2);
        for (int j = 0; j < hashAndReset.Length; j++)
        {
            stringBuilder.Append(hashAndReset[j].ToString("x2"));
        }
        return stringBuilder.ToString();
    }

    public static byte[] Rc4Decrypt(byte[] p, byte[] d)
    {
        int[] array = new int[0x100];
        int[] array2 = new int[0x100];
        byte[] array3 = new byte[d.Length];
        int i;
        for (i = 0; i < 0x100; i++)
        {
            array[i] = (int)p[i % p.Length];
            array2[i] = i;
        }
        int num;
        for (i = (num = 0); i < 0x100; i++)
        {
            num = (num + array2[i] + array[i]) % 0x100;
            int num2 = array2[i];
            array2[i] = array2[num];
            array2[num] = num2;
        }
        int num3;
        num = (num3 = (i = 0));
        while (i < d.Length)
        {
            num3++;
            num3 %= 0x100;
            num += array2[num3];
            num %= 0x100;
            int num2 = array2[num3];
            array2[num3] = array2[num];
            array2[num] = num2;
            int num4 = array2[(array2[num3] + array2[num]) % 0x100];
            array3[i] = (byte)((int)d[i] ^ num4);
            i++;
        }
        return array3;
    }
    
    public static byte[] CreateStage2PatchedBody(byte[] encoded)
    {
        byte[] b = (byte[]) encoded.Clone();

        int j = 0;
        while (j < b.Length)
        {
            bool flag = b[j] == 0xFE;
            uint num;
            if (flag)
            {
                num = 0xFE00U + b[j + 1];
                j++;
            }
            else
            {
                num = b[j];
            }

            if (!dictionary.ContainsKey(num))
                break;

            DecompiledCode.OT ot = dictionary[num];
            j++;

            switch (ot)
            {
                case OT.B :
                    uint num2 = (uint)flared_68(b, j);
                    num2 ^= 0xA298A6BDU;
                    b[j] = (byte)num2;
                    b[j + 1] = (byte)(num2 >> 8);
                    b[j + 2] = (byte)(num2 >> 0x10);
                    b[j + 3] = (byte)(num2 >> 0x18);
                    j += 4;
                    break;

                case DecompiledCode.OT.C:
                case DecompiledCode.OT.E:
                    j++;
                    break;
                case DecompiledCode.OT.D:
                case DecompiledCode.OT.G:
                    j += 4;
                    break;
                case DecompiledCode.OT.F:
                    j += 2;
                    break;
                case DecompiledCode.OT.H:
                    j += 8;
                    break;
                case DecompiledCode.OT.I:
                    j += 4 + flared_68(b, j) * 4;
                    break;
            }
        }

        return b;
    }

    public static int flared_68(byte[] b, int o)
    {
        int num = (int)b[o + 3] * 0x1000000;
        num += (int)b[o + 2] * 0x10000;
        num += (int)b[o + 1] * 0x100;
        return num + (int)b[o];
    }

}