using System;
using System.Threading;

public class EndAutomatonState : AutomatonState
{
	public static readonly object object_0 = new object();

	public object object_1;

	public static VMState VMState;

	protected override void vmethod_0(VMCpu gclass26_0, AutomatonState gclass27_0)
	{
		MainModule.SetAutomatonState(gclass26_0, gclass27_0);
	}

	[Obsolete]
	public override void Execute()
	{
		VMState = MainModule.GetOrCreateClass13();
		object_1 = MainModule.GetOrCreateVMCpu();
		MainModule.Verify();
		if (!MainModule.GetBool2(object_1))
		{
			if (MainModule.GetMustSuspend(object_1))
			{
				Thread.CurrentThread.Suspend();
			}
			if (MainModule.GetMustReset(object_1))
			{
				vmethod_0((VMCpu)object_1, AutomatonState.GetStateByName("Reset"));
			}
			else
			{
				vmethod_0((VMCpu)object_1, AutomatonState.GetStateByName("math"));
			}
		}
	}
}
