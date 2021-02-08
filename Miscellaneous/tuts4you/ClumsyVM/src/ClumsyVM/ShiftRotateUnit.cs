public class ShiftRotateUnit
{
	public static readonly object object_0 = new object();

	public static volatile ShiftRotateUnit gclass19_0;

	public GClass11 ResultLine;

	public string string_0;

	public string string_1;

	public ShiftRotateUnit()
	{
		ResultLine = MainModule.GetOrCreateGClass11();
		MainModule.SetString1(this, "00000000000000000000000000000000");
		MainModule.SetString0(this, "00");
	}

	// --------------------------------------------------------
	// Extra custom properties/functions I added myself below.

	public string SelectedOperation => string_0 switch
	{
		"10" => "shift left 8",
		"01" => "rotate right 1",
		_ => "Nothing"
	};

	/// <inheritdoc />
	public override string ToString() => SelectedOperation;
}
