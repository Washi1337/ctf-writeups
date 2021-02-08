using System;

public class GClass1
{
	public static int int_0;

	public static void Main(string[] string_0)
	{
		MainVMType object_ = new MainVMType();
		Console.WriteLine("ClumsyVM - Erjey");
		MainModule.WrapImportMemory(object_, 0);
		MainModule.WrapStartMainLoop(object_, 0);
		Console.ReadLine();
	}
}
