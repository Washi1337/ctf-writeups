namespace ClumsyVM.Architecture
{
    public readonly struct EmbeddedOpCodeInfo
    {
        public EmbeddedOpCodeInfo(byte b, string format, int operandSize)
        {
            Byte = b;
            Format = format;
            OperandSize = operandSize;
        }

        public byte Byte
        {
            get;
        }

        public string Format
        {
            get;
        }

        public int OperandSize
        {
            get;
        }
    }
}
