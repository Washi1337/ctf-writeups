using System;

namespace ClumsyVM.Architecture
{
    [Flags]
    public enum MicroDestinationRegisters
    {
        R0 = 0b000000001,
        R1 = 0b000000010,
        R2 = 0b000000100,
        R4 = 0b000001000,
        R5 = 0b000010000,
        R6 = 0b000100000,
        R7 = 0b001000000,
        R8 = 0b010000000,
        R9 = 0b100000000,
    }
}
