using System;
using System.IO;
using AsmResolver.PE;
using AsmResolver.PE.Exports;

public static class Program
{
	public static void Main()
	{
		foreach (string file in Directory.GetFiles(@"C:\Windows\SysWOW64", "*.dll"))
		{
			try
			{
				Console.WriteLine(file);
				var image = PEImage.FromFile(file);
				if (image.Exports is null)
					continue;

				foreach (var export in image.Exports.Entries)
				{
					if (export.IsByName)
						Console.WriteLine($"{GetHash(export.Name):X8}: {export}");
				}

				Console.WriteLine();
			}
			catch (Exception ex)
			{
				Console.Error.WriteLine(file + " -> "  + ex);
			}
		}
	}

	public static uint GetHash(string name)
	{
		uint sum = 0x40;

		foreach (char c in name)
		{
			sum = (uint)c - sum * 0x45523f21;
		}

		return sum;
	}
}