public class MMU
{
	public static readonly object object_0 = new object();

	public static volatile MMU gclass7_0;

	public readonly VMMemory2 memory;

	public string operation;

	public MMU()
	{
		memory = MainModule.GetOrCreateMemory2();
	}

	// --------------------------------------------------------
	// Extra custom properties/functions I added myself below.

	public string SelectedOperation
	{
		get
		{
			string op = "";
			if (operation[0] == '1')
				op += "Write Dword ";
			if (operation[1] == '1')
				op += "Read Dword ";
			if (operation[2] == '1')
				op += "Read Byte ";
			return op;
		}
	}

	/// <inheritdoc />
	public override string ToString()
	{
		return SelectedOperation;
	}
}
