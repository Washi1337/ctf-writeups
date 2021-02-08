public class VMCpu
{
	public static volatile VMCpu gclass26_0;

	public static readonly object object_0 = new object();

	public AutomatonState CurrentAutomatonState;

	public string ProgramCounter;

	public string CurrentInstruction;

	public int int_0;

	public int int_1;

	public bool Must1234567;

	public bool MustReset;

	public bool bool_2;

	public bool MustMath;

	public bool MustSuspend;

	public VMCpu()
	{
		MainModule.SetProgramCounter(this, "000000000");
		MainModule.SetCurrentInstruction(this, "000000000000000000000000000000000000");
		MainModule.SetInt0(this, 0);
		MainModule.SetInt1(this, 0);
		MainModule.SetBool2(this, 0);
		MainModule.SetBool3(this, 0);
		MainModule.SetMustReset(this, 0);
		CurrentAutomatonState = AutomatonState.GetStateByName("Reset");
	}
}
