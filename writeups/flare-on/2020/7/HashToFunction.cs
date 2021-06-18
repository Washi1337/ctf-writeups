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
            foreach (var entry in GetExportMapping())
                writer.WriteLine($"{entry.Key:X8}: {entry.Value}");
        }
        
        private static uint ComputeDllChecksum(string name)
        {
            uint sum = 0;
            foreach (char c in name)
            {
                char c1 = c;
                if ('`' < c1)
                {
                    c1 = (char) (c1 - 0x20);
                }
        
                sum = (sum >> 0xd | sum << 0x13) + c1;
                sum = (sum >> 0xd | sum << 0x13) + 0;
            }
        
            sum = (sum >> 0xd | sum << 0x13) + 0;
            sum = (sum >> 0xd | sum << 0x13) + 0;
            return sum;
        }
        private static uint ComputeFuncChecksum(string name)
        {
            uint sum = 0;
            foreach (char c in name)
            {
                sum = (sum >> 0xd | sum << 0x13) + c;
            }
        
            // zero terminator:
            sum = (sum >> 0xd | sum << 0x13) +0;
            return sum;
        }
        
        
        private static Dictionary<long, ExportedSymbol> GetExportMapping()
        {
            var dict = new Dictionary<long, ExportedSymbol>();
        
            foreach (var path in Directory.GetFiles(@"C:\windows\system32", "*.dll"))
            {
                try
                {
                    var image = PEImage.FromFile(path);
                    uint dllNameSum = ComputeDllChecksum(Path.GetFileName(path));
                    if (image.Exports is null)
                        continue;
                    foreach (var export in image.Exports.Entries)
                    {
                        if (export.IsByName)
                        {
                            uint funcNameSum = ComputeFuncChecksum(export.Name);
                            dict.Add(funcNameSum + dllNameSum, export);
                        }
                    }
                }
                catch
                {
                    //ignore
                }
            }
        
            return dict;
        }
        
    }
}