using System;
using System.Text;

public class ExecuteAutomatonState : AutomatonState
{
	public static readonly object object_0 = new object();

	public readonly VMState State;

	public VMCpu Cpu;

	public ExecuteAutomatonState()
	{
		State = MainModule.GetOrCreateClass13();
	}

	protected override void vmethod_0(VMCpu gclass26_0, AutomatonState gclass27_0)
	{
		MainModule.SetAutomatonState(gclass26_0, gclass27_0);
	}

	public override void Execute()
	{
		MainModule.DoNothing3();
		Cpu = MainModule.GetOrCreateVMCpu();

		if (MainModule.GetMustReset(Cpu))
		{
			vmethod_0((VMCpu)Cpu, AutomatonState.GetStateByName("Reset"));
			return;
		}
		MainModule.WrapExecuteInstruction(State, MainModule.GetCurrentInstruction(Cpu));
		if (MainModule.GetMustMath(Cpu))
		{
			vmethod_0((VMCpu)Cpu, AutomatonState.GetStateByName("math"));
		}
		else
		{
			vmethod_0((VMCpu)Cpu, AutomatonState.GetStateByName("maths"));
		}
	}
}
