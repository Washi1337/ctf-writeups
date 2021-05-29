using System;
using System.Text;
using System.Threading;
using ClumsyVM.Architecture;

public class FetchAutomatonState : AutomatonState
{
	public static readonly object object_0 = new object();

	public readonly VMState VMState;

	public VMCpu VMCpu;

	public FetchAutomatonState()
	{
		VMState = MainModule.GetOrCreateClass13();
	}

	protected override void vmethod_0(VMCpu gclass26_0, AutomatonState gclass27_0)
	{
		MainModule.SetAutomatonState(gclass26_0, gclass27_0);
		DumpState();
	}

	private int lastPc = -1;

	private void DumpState()
	{
		// Parse current instruction.
		string rawInstr = MainModule.GetCurrentInstruction(VMCpu).Trim();
		var instr = new MicroCodeInstruction(rawInstr);

		var builder = new StringBuilder();

		// Add an extra new line if we are switching to an unusual PC (indicator of a basic block header).
		int pc = Convert.ToInt32(MainModule.GetProgramCounter(VMCpu), 2);
		if (lastPc + 1 != pc)
			Console.WriteLine();

		// Print current and next PC.
		builder.Append(pc.ToString("X8"));
		builder.Append(" -> ");
		builder.Append(instr.AddReg3ToNextOffset
			? "r3      "
			: instr.NextOffset.ToString("X8"));
		builder.Append(":    ");

		// Print destination registers.
		if (instr.Destinations != 0)
		{
			builder.Append(instr.Destinations.ToString().ToLowerInvariant().PadLeft(8));
			builder.Append(" :=   ");
		}
		else
		{
			builder.Append("              ");
		}

		// Print mnemonics.
		builder.Append(instr.GetAluMnemonic().PadRight(20));
		builder.Append(instr.GetMemoryMnemonic().PadRight(35));

		// Print if it checks zero or parity flags.
		builder.Append(instr.Parity ? 'P' : ' ');
		builder.Append(instr.Zero ? 'Z' : ' ');
		builder.Append("   ");

		// Print current state of flags.
		var flags = MainModule.GetFlags(VMState);
		builder.Append("P:");
		builder.Append(flags[0]);
		builder.Append(" Z:");
		builder.Append(flags[1]);
		builder.Append("   ");

		// Print current register values.
		for (int i = 0; i < 10; i++)
		{
			int raw = Convert.ToInt32(MainModule.GetValue(VMState.InternalState1.Registers[i]), 2);
			builder.Append("r");
			builder.Append(i.ToString());
			builder.Append(": ");
			builder.Append(raw.ToString("X8"));
			if (i < 9)
				builder.Append(", ");
		}

		Console.WriteLine(builder.ToString());
		lastPc = pc;
	}

	[Obsolete]
	public override void Execute()
	{
		VMCpu = MainModule.GetOrCreateVMCpu();

		MainModule.DoNothing2(this);
		MainModule.CopyOverStuff(VMState);
		if (MainModule.GetBool2(VMCpu))
		{
			MainModule.SetBool2(VMCpu, 0);
			return;
		}
		if (MainModule.GetMustSuspend(VMCpu))
		{
			Thread.CurrentThread.Suspend();
		}
		int num = 0;
		if (MainModule.GetMustReset(VMCpu))
		{
			vmethod_0((VMCpu)VMCpu, AutomatonState.GetStateByName("Reset"));
			return;
		}
		if (MainModule.GetMust1234567(VMCpu))
		{
			MainModule.SetMust1234567(VMCpu, 0);
			vmethod_0((VMCpu)VMCpu, AutomatonState.GetStateByName("1234567"));
			return;
		}
		MainModule.ComputeNextProgramCounter(this);
		MainModule.SetCurrentInstruction(VMCpu, MainModule.FetchInstruction(VMState, MainModule.GetProgramCounter(VMCpu)));
		if (MainModule.GetProgramCounter(VMCpu) == "010100111")
		{
			num = 1;
		}
		if (num != 0)
		{
			MainModule.SetBool3(VMCpu, 1);
		}
		vmethod_0((VMCpu)VMCpu, AutomatonState.GetStateByName("1234567"));
	}
}
