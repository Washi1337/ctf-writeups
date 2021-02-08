using System.Collections.Generic;

namespace ClumsyVM.Architecture
{
    public class VMDisassembler
    {
        private static readonly EmbeddedOpCodeInfo[] OpCodeTable = new EmbeddedOpCodeInfo[256];

        static VMDisassembler()
        {
            for (int i = 0; i < OpCodeTable.Length; i++)
                OpCodeTable[i] = new EmbeddedOpCodeInfo((byte) i, $"db 0x{i:X2}", 0);

            OpCodeTable[0x10] = new EmbeddedOpCodeInfo(0x10, "push 0x{0:X8}", 1);
            OpCodeTable[0x15] = new EmbeddedOpCodeInfo(0x15, "mov r7, [r5 + 0x{0:X8}]; push r7", 1);
            OpCodeTable[0x36] = new EmbeddedOpCodeInfo(0x36, "mov [r5 + 0x{0:X8}], r7; pop r7", 1);
            OpCodeTable[0x57] = new EmbeddedOpCodeInfo(0x57, "push r7", 0);
            OpCodeTable[0x59] = new EmbeddedOpCodeInfo(0x59, "pop r7", 0);
            OpCodeTable[0x5C] = new EmbeddedOpCodeInfo(0x5C, "sub r7", 0);
            OpCodeTable[0x5F] = new EmbeddedOpCodeInfo(0x5F, "xchg r7", 0);
            OpCodeTable[0x65] = new EmbeddedOpCodeInfo(0x65, "add r7", 0);
            OpCodeTable[0x84] = new EmbeddedOpCodeInfo(0x84, "add [r5 + 0x{0:X8}], 0x{1:X8}", 2);
            OpCodeTable[0xB6] = new EmbeddedOpCodeInfo(0xB6, "or r7", 0);
            OpCodeTable[0xA7] = new EmbeddedOpCodeInfo(0xA7, "halt", 0);
            OpCodeTable[0xAD] = new EmbeddedOpCodeInfo(0xAD, "ret", 0);
            OpCodeTable[0xB9] = new EmbeddedOpCodeInfo(0xB9, "call index [r6 + 0x{0:X8}{1:X8}]", 2);
        }

        public static IEnumerable<EmbeddedInstruction> Disassemble(byte[] code)
        {
            int ip = 0;

            while (ip < code.Length)
            {
                int instructionIp = ip;

                var opCode = OpCodeTable[code[ip++]];
                byte[] operandBytes = null;
                if (opCode.OperandSize > 0)
                {
                    operandBytes = new byte[opCode.OperandSize];
                    for (int i = 0; i < opCode.OperandSize; i++)
                        operandBytes[i] = code[ip++];
                }

                yield return new EmbeddedInstruction(instructionIp, opCode, operandBytes);
            }
        }

    }
}
