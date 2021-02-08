using System;

public class InputRegisterLoader
{
	public static readonly object object_0 = new object();

	public static volatile InputRegisterLoader gclass8_0;

	public ALU ALU;

	public Register[] Registers;

	public string Result;

	public string Bits_32_36;

	public InputRegisterLoader()
	{
		MainModule.SetResult(this, "00000000000000000000000000000000");
		MainModule.Set_Bits_32_36(this, "0000");
	}

	// --------------------------------------------------------
	// Extra custom properties/functions I added myself below.

	public string SelectedRegister => $"REG_{Convert.ToInt32(Bits_32_36, 2)}";

	/// <inheritdoc />
	public override string ToString() => SelectedRegister;
}
