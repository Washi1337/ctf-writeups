public class GClass18
{
	public static readonly object object_0 = new object();

	public static volatile GClass18 gclass18_0;

	public readonly Register[] Registers;

	public string Register0Value;

	public string Register1Value;

	public string Register2Value;

	public string Register3Value;

	public string Register4Value;

	public string Register5Value;

	public string Register6Value;

	public string Register7Value;

	public string Register8Value;

	public string Register9Value;

	public GClass18()
	{
		Registers = MainModule.GetOrCreateRegisters();
		MainModule.object_2 = null;
		MainModule.SetRegister0Value(this, MainModule.GetValue(Registers[0]));
		MainModule.SetRegister1Value(this, MainModule.GetValue(Registers[1]));
		MainModule.SetRegister2Value(this, MainModule.GetValue(Registers[2]));
		MainModule.SetRegister3Value(this, MainModule.GetValue(Registers[3]));
		MainModule.SetRegister4Value(this, MainModule.GetValue(Registers[4]));
		Register[] array = Registers;
		MainModule.UnusedInt_8 = 828233320;
		MainModule.SetRegister5Value(this, MainModule.GetValue(array[5]));
		MainModule.SetRegister6Value(this, MainModule.GetValue(Registers[6]));
		MainModule.SetRegister7Value(this, MainModule.GetValue(Registers[7]));
		MainModule.SetRegister8Value(this, MainModule.GetValue(Registers[8]));
		MainModule.SetRegister9Value(this, MainModule.GetValue(Registers[9]));
	}
}
