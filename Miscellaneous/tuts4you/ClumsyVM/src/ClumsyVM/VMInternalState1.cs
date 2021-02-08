public class VMInternalState1
{
	public static readonly object object_0 = new object();

	public static volatile VMInternalState1 gclass22_0;

	public static int int_0;

	public static int int_1;

	public static int int_2;

	public readonly ALU ALU;

	public readonly InputRegisterLoader RegisterContainer;

	public readonly GClass11 object_3;

	public readonly Register[] Registers;

	public readonly ShiftRotateUnit ShiftRotateUnit;

	public readonly MMU MMU;

	public string LastReadWriteOperation;

	public string[] MemoryReadResult;

	public bool MemoryReadResultIsSet;

	public string CurrentInstruction;

	public VMInternalState1()
	{
		ShiftRotateUnit = MainModule.GetOrCreateGClass19();
		ALU = MainModule.GetOrCreateALU();
		object_3 = MainModule.GetOrCreateGClass11();
		RegisterContainer = MainModule.smethod_59();
		Registers = MainModule.GetOrCreateRegisters();
		MMU = MainModule.smethod_53();
	}
}
