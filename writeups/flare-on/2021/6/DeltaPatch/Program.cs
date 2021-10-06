
using System;
using System.IO;
using System.ComponentModel;
using System.Runtime.InteropServices;

internal unsafe static class Program
{
    [DllImport("msdelta.dll", SetLastError=true)]
    private static extern bool ApplyDelta(ulong flags, string sourceName, string deltaName, string targetName);

    public static void Main(string[] args)
    {
        if (args.Length != 2)
        {
            // Step 2
            var template = File.ReadAllBytes("kitty.bin");
            foreach (var file in Directory.GetFiles("messages"))
            {
                Console.WriteLine(file);
                if (!ApplyDelta(0, "kitty.bin", file, "decoded\\" + Path.GetFileName(file)))
                    throw new Win32Exception();
            }
        }
        else 
        {
            // Step 1
            if (!ApplyDelta(0, args[0], args[1], Path.ChangeExtension(args[1], ".patched.bin")))
                throw new Win32Exception();
        }

        Console.WriteLine("Done");  
    }
}
