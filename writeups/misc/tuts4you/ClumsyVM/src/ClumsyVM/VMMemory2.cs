public class VMMemory2
{
	public static readonly object object_0 = new object();

	public static volatile VMMemory2 gclass14_0;

	public string[] MemoryContents;

	public VMMemory2()
	{
		MainModule.SetArray(this, new string[512]);
		int i;
		for (i = 0; i < 512; i++)
		{
			MainModule.GetArray(this)[i] = "00000000000000000000000000000000";
		}
		MainModule.GetArray(this)[0] = "00000011000000000000000100000000";
		MainModule.GetArray(this)[1] = "00000001001101100000111100010000";
		GClass1.int_0 = i;
		MainModule.GetArray(this)[2] = "00000010001101100001011000010000";
		string[] array = MainModule.GetArray(this);
		MainModule.Unused_5 = i;
		array[3] = "00000010000101010000000100010101";
		MainModule.int_0 = i;
		MainModule.GetArray(this)[4] = "10100111000000110011011010110110";
		MainModule.GetArray(this)[5] = "00000000000000000000000000000000";
		GClass37.object_0 = i;
	}
}
