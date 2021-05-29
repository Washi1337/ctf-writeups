using System;
using System.Linq;

namespace ClumsyVM.Architecture
{
    public readonly struct EmbeddedInstruction
    {
        public EmbeddedInstruction(int offset, EmbeddedOpCodeInfo opCode, byte[] operandBytes)
        {
            Offset = offset;
            OpCode = opCode;
            OperandBytes = operandBytes;
        }

        public int Offset
        {
            get;
        }

        public EmbeddedOpCodeInfo OpCode
        {
            get;
        }

        public byte[] OperandBytes
        {
            get;
        }

        /// <inheritdoc />
        public override string ToString()
        {
            string byteString = OpCode.Byte.ToString("X2");

            object[] operands;
            if (OperandBytes != null)
            {
                operands = OperandBytes.Select(x => (object) x.ToString("X2")).ToArray();
                byteString += " " + string.Join(" ", operands);
            }
            else
            {
                operands = Array.Empty<object>();
            }

            string mnemonic = string.Format(OpCode.Format, operands);
            return $"{Offset:X8}:   {byteString,-10}    {mnemonic}";
        }
    }
}
