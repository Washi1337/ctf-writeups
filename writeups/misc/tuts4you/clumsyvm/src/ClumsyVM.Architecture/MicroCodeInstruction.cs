using System;
using System.Text;

namespace ClumsyVM.Architecture
{
    public readonly struct MicroCodeInstruction
    {
        private readonly string _rawData;

        public MicroCodeInstruction(string rawData)
        {
            _rawData = rawData;
        }

        public bool IsEmpty => _rawData.Substring(10) == "00000000000000000000000000";

        public bool Unknown => _rawData[0] == 1;

        public int NextOffset => Convert.ToInt32(_rawData.Substring(1, 8), 2);

        public bool AddReg3ToNextOffset => _rawData[9] == '1';

        public bool Parity => _rawData[10] == '1';

        public bool Zero => _rawData[11] == '1';

        public MicroShiftOperation Shift => (MicroShiftOperation) Convert.ToInt32(_rawData.Substring(12, 2), 2);

        public MicroAluOperation Alu => (MicroAluOperation) Convert.ToInt32(_rawData.Substring(14, 2), 2);

        public int OperandCount => Alu == MicroAluOperation.Not ? 1 : 2;

        public bool Operand0IsZero => _rawData[16] == '0';

        public bool Operand1IsZero => _rawData[17] == '0';

        public bool FlipBitsOperand0 => _rawData[18] == '1';

        public bool Increment => _rawData[19] == '1';

        public MicroDestinationRegisters Destinations => (MicroDestinationRegisters)  Convert.ToInt32(_rawData.Substring(20, 9), 2);

        public int GetDestinationsCount()
        {
            int count = 0;
            for (var i = MicroDestinationRegisters.R0; i <= MicroDestinationRegisters.R9; i = (MicroDestinationRegisters) ((int) i << 1))
            {
                if ((Destinations & i) != 0)
                    count++;
            }

            return count;
        }

        public MicroMemoryOperation Memory => (MicroMemoryOperation) Convert.ToInt32(_rawData.Substring(29, 3), 2);

        public MicroInputRegister Input => (MicroInputRegister) Convert.ToInt32(_rawData.Substring(32, 4), 2);

        public string GetAluMnemonic()
        {
            var builder = new StringBuilder();

            if (Shift != MicroShiftOperation.Nothing1 && Shift != MicroShiftOperation.Nothing2)
                builder.Append('(');

            if (Alu != MicroAluOperation.Not)
            {
                if (FlipBitsOperand0)
                    builder.Append("!");

                if (Operand0IsZero)
                    builder.Append("0");
                else
                    builder.Append("r9");
            }

            switch (Alu)
            {
                case MicroAluOperation.And:
                    builder.Append(" & ");
                    break;
                case MicroAluOperation.Or:
                    builder.Append(" | ");
                    break;
                case MicroAluOperation.Not:
                    builder.Append("!");
                    break;
                case MicroAluOperation.Add:
                    builder.Append(" + ");
                    break;
                default:
                    throw new ArgumentOutOfRangeException();
            }

            if (Operand1IsZero)
                builder.Append("0");
            else
                builder.Append(Input.ToString().ToLowerInvariant());

            if (Increment)
                builder.Append(" + 1");

            builder.Append(Shift switch
            {
                MicroShiftOperation.ShiftLeft8 => ") << 8",
                MicroShiftOperation.RotateRight1 => ") ror 1",
                _ => ""
            });

            builder.Append(';');

            return builder.ToString();
        }

        public string GetMemoryMnemonic()
        {
            var builder = new StringBuilder();
            if ((Memory & MicroMemoryOperation.WriteDword) != 0)
                builder.Append("dword[r0] := r1; ");
            if ((Memory & MicroMemoryOperation.ReadDword) != 0)
                builder.Append("r1 := dword[r0]; ");
            if ((Memory & MicroMemoryOperation.ReadByte) != 0)
                builder.Append("r3 := byte[r2];");
            return builder.ToString();
        }
    }
}
