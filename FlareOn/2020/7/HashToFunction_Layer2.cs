using System;
using System.Collections.Generic;
using System.IO;
using AsmResolver.PE;
using AsmResolver.PE.Exports;

namespace HashToFunction
{
    internal class Program
    { 
        public static void Main(string[] args)
        {
            using var writer = new StreamWriter(@"D:\Washi\RE\ctf-writeups\FlareOn\2020\7\mapping.txt");
            foreach (string path in Directory.GetFiles(@"C:\windows\system32", "*.dll"))
            {
                Console.WriteLine(path);
                writer.WriteLine(path);
                writer.WriteLine(ComputeFuncChecksum(Path.GetFileName(path).ToLower()).ToString("X8"));
                foreach (var entry in GetExportMapping(path))
                    writer.WriteLine(entry.Key.ToString("X8") + " " + entry.Value);
                
                writer.WriteLine();
            }
        }
        
        private static uint ComputeFuncChecksum(string name)
        {
            uint sum = 0;
            int i = 0;
            do
            {
                sum = (sum >> 0xe | sum << 0x12);
                if (i != name.Length)
                    sum += name[i];
                i++;
            } while (i < name.Length+1);
        
            // zero terminator:
            return sum;
        }
        
        private static Dictionary<long, ExportedSymbol> GetExportMapping(string path)
        {
            var dict = new Dictionary<long, ExportedSymbol>();

            try
            {
                var image = PEImage.FromFile(path);
                foreach (var export in image.Exports.Entries)
                {
                    if (export.IsByName)
                    {
                        uint funcNameSum = ComputeFuncChecksum(export.Name);
                        dict.Add(funcNameSum, export);
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }

            return dict;
        }
        
    }
}