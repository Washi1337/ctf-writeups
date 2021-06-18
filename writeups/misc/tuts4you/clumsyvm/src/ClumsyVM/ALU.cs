public class ALU
{
	public static readonly object object_0 = new object();

	public static volatile ALU gclass5_0;

	public ShiftRotateUnit object_1;

	public string Bits_14_19;

	public bool ParityFlag;

	public bool ZeroFlag;

	public string Arg1; // contains value of register "1", only if string_2 originates also from reg "1".

	public string Arg2; // contains value of register indicated by 32-36

	public string Result;

	public ALU()
	{
		MainModule.Set_Bits_14_19(this, "000000");
		MainModule.SetArg1(this, "00000000000000000000000000000000");
		MainModule.SetArg2(this, "00000000000000000000000000000000");
		MainModule.SetParityFlag(this, 0);
		MainModule.SetZeroFlag(this, 0);
		MainModule.SetResult(this, "00000000000000000000000000000000");
	}

	// --------------------------------------------------------
	// Extra custom properties/functions I added myself below.

	public string SelectedOperation =>
		Bits_14_19.Substring(0, 2) switch
		{
			"00" => "AND",
			"01" => "OR",
			"10" => "NOT",
			_ => "ADD"
		};

	public string A => Bits_14_19[2] == '1' ? "reg \"1\"" : "0";

	public string B => Bits_14_19[3] == '1' ? "input reg" : "0";

	public bool FlipA => Bits_14_19[4] == '1';

	public bool Increment => Bits_14_19[5] == '1';

	/// <inheritdoc />
	public override string ToString()
	{
		string prefix = FlipA ? "¬" : "";
		string suffix = Increment ? " + 1" : "";
		return $"{prefix}{A} {SelectedOperation} {B}{suffix}";
	}
}
