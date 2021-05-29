public class VMMemory2Copy
{
	public static readonly object object_0 = new object();

	public static volatile VMMemory2Copy gclass15_0;

	public readonly VMMemory2 object_1;

	public string[] Array;

	public VMMemory2Copy()
	{
		object_1 = MainModule.GetOrCreateMemory2();
		MainModule.SetArray(this, MainModule.GetArray(object_1));
	}
}
