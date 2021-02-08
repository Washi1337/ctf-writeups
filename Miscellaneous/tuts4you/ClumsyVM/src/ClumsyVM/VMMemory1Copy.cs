public class VMMemory1Copy
{
	public static readonly object object_0 = new object();

	public static volatile VMMemory1Copy gclass17_0;

	public readonly VMMemory Memory;

	public string[] MemoryContents;

	public VMMemory1Copy()
	{
		Memory = MainModule.GetOrCreateVMMemory();
		MainModule.SetContents(this, MainModule.GetArray(Memory));
	}
}
