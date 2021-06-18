using System;
using System.IO;
using System.Linq;
using System.Text;
using ClumsyVM.Architecture;

namespace ClumsyVM
{
    class Program
    {
        public static void Main(string[] args)
        {
            var memory = RewriteMemory();
            DisassembleMicroCode();
            DisassembleEmbeddedCode(memory);
        }

        private static byte[] RewriteMemory()
        {
            var memoryCells = File.ReadAllLines("initialmemory.txt")
                .Select(line => Convert.ToInt32(line, 2))
                .ToArray();

            var builder = new StringBuilder();
            var stream = new MemoryStream();
            for (int i = 0; i < memoryCells.Length; i++)
            {
                int cell = memoryCells[i];
                byte[] bytes = BitConverter.GetBytes(cell);
                string hexBytes = string.Join(" ", bytes.Select(x => x.ToString("X2")));

                stream.Write(bytes, 0, bytes.Length);
                builder.AppendLine($"{i * 4:X8} ({i:X8}):    {hexBytes}        0x{cell:X8}   ({cell})");
            }

            File.WriteAllBytes("initialmemory_2.bin", stream.ToArray());
            File.WriteAllText("initialmemory_2.txt", builder.ToString());
            return stream.ToArray();
        }

        private static void DisassembleMicroCode()
        {
            MicroCodeDisassembler.Disassemble(File.ReadAllLines("microcode.txt"));
        }

        private static void DisassembleEmbeddedCode(byte[] memory)
        {
            var builder = new StringBuilder();

            foreach (var instruction in VMDisassembler.Disassemble(memory))
                builder.AppendLine(instruction.ToString());

            File.WriteAllText("embedded_code.txt", builder.ToString());
        }
    }
}
