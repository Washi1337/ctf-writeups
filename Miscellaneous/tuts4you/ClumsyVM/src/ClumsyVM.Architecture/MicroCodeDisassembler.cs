using System;
using System.Linq;

namespace ClumsyVM.Architecture
{
    public static class MicroCodeDisassembler
    {
        public static void Disassemble(string[] codeLines)
        {
            var instructions = codeLines
                .Select(line => new MicroCodeInstruction(line))
                .ToArray();

            const string indent = "          ";

            for (int i = 0; i < instructions.Length; i++)
            {
                var instruction = instructions[i];
                if (instruction.IsEmpty)
                    continue;

                Console.Write($"{i:X8}: ");

                if (instruction.GetDestinationsCount() > 0)
                    Console.Write(instruction.Destinations.ToString().ToLowerInvariant() + " := ");

                Console.Write(instruction.GetAluMnemonic());

                if (instruction.Memory != 0)
                {
                    Console.WriteLine();
                    Console.Write(indent);
                    Console.Write(instruction.GetMemoryMnemonic());
                }

                if (instruction.AddReg3ToNextOffset || instruction.NextOffset != i + 1)
                {
                    Console.WriteLine();
                    Console.Write(indent);
                    Console.Write("goto ");
                    Console.Write(instruction.AddReg3ToNextOffset
                        ? "r3"
                        : instruction.NextOffset.ToString("X8"));
                    Console.Write(";");
                    Console.WriteLine();
                }

                Console.WriteLine();
            }
        }
    }
}
