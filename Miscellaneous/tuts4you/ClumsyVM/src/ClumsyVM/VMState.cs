public class VMState
{
	public static readonly object object_0 = new object();

	public static volatile VMState gclass13_0;

	public readonly VMMemory Memory1;

	public readonly VMInternalState1 InternalState1;

	public readonly VMMemory2 memory2;

	public readonly GClass21 object_4;

	public VMState()
	{
		InternalState1 = MainModule.GetOrCreateInternalState1();
		Memory1 = MainModule.GetOrCreateVMMemory();
		memory2 = MainModule.GetOrCreateMemory2();
		object_4 = MainModule.smethod_164();
	}
}
