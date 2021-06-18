public class GClass6
{
	public static readonly object object_0 = new object();

	public static volatile GClass6 gclass6_0;

	public readonly ALU ALU;

	public string AluOperation;

	public string AluArg1;

	public string AluArg2;

	public string AluResult;

	public bool ParityFlag;

	public bool ZeroFlag;

	public GClass6()
	{
		ALU = MainModule.GetOrCreateALU();
		MainModule.SetAluOperation(this, MainModule.Get_Bits_14_19(ALU));
		MainModule.SetAluArg1(this, MainModule.GetArg1(ALU));
		MainModule.SetAluArg2(this, MainModule.GetArg2(ALU));
		MainModule.SetAluResult(this, MainModule.GetResult(ALU));
		MainModule.SetParityFlag(this, MainModule.GetParityFlag(ALU) ? 1 : 0);
		MainModule.SetZeroFlag(this, MainModule.GetZeroFlag(ALU) ? 1 : 0);
	}
}
