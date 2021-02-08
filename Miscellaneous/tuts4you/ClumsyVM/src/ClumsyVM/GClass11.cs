public class GClass11
{
	public static readonly object object_0 = new object();

	public static volatile GClass11 gclass11_0;

	public readonly Register[] Registers;

	public string string_0;

	public string string_1;

	public GClass11()
	{
		Registers = MainModule.GetOrCreateRegisters();
		MainModule.SetString1(this, "00000000000000000000000000000000");
		MainModule.SetString0(this, "000000000");
	}
}
