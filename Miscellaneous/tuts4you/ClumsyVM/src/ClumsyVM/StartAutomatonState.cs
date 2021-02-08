public class StartAutomatonState : AutomatonState
{
	public static readonly object object_0 = new object();

	public readonly VMState object_1;

	public VMCpu object_2;

	public StartAutomatonState()
	{
		object_1 = MainModule.GetOrCreateClass13();
	}

	protected override void vmethod_0(VMCpu gclass26_0, AutomatonState gclass27_0)
	{
		MainModule.SetAutomatonState(gclass26_0, gclass27_0);
	}

	public override void Execute()
	{
		MainModule.DoNothing();
		object_2 = MainModule.GetOrCreateVMCpu();
		MainModule.SetCurrentInstruction(object_2, "000000001000000000000000000000001001");
		MainModule.SetInt0(object_2, 0);
		MainModule.SetInt1(object_2, 0);
		MainModule.SetMust1234567(object_2, 1);
		MainModule.SetMustReset(object_2, 0);
		MainModule.SetBool3(object_2, 0);
		MainModule.SetBool2(object_2, 0);
		MainModule.smethod_82(object_1);
		vmethod_0((VMCpu)object_2, AutomatonState.GetStateByName("maths"));
	}
}
