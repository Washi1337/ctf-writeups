using System;

public class Register
{
	public static readonly object object_0 = new object();

	public static volatile Register[] Registers;

	public readonly ALU object_1;

	public readonly InputRegisterLoader object_2;

	public string Value;

	public string Name;

	public Register(string string_2, string string_3)
	{
		MainModule.SetName(this, string_2);
		MainModule.SetValue(this, string_3);
		object_2 = MainModule.smethod_59();
		object_1 = MainModule.GetOrCreateALU();
	}

	// --------------------------------------------------------
	// Extra custom properties/functions I added myself below.

	/// <inheritdoc />
	public override string ToString()
	{
		int val = Convert.ToInt32(Value, 2);
		return $"{Name} = {val} (0x{val:X8}) (0b{Value})";
	}
}
