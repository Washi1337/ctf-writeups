using System;

namespace ClumsyVM.Architecture
{
    [Flags]
    public enum MicroMemoryOperation
    {
        None = 0,
        WriteDword = 0b100,
        ReadDword = 0b010,
        ReadByte = 0b001
    }
}
