using System.Collections.Generic;

public class VMType1
{
	public static readonly object LockObject = new object();

	public static volatile VMType1 vmType1Instance;

	public readonly VMCpuWrapper vmCpuWrapper;

	public readonly VMState object_2;

	public List<GClass3> list_0;

	public List<GClass4> list_1;

	public VMType1()
	{
		vmCpuWrapper = MainModule.GetOrCreateClass25();
		object_2 = MainModule.GetOrCreateClass13();
		list_1 = new List<GClass4>();
		list_0 = new List<GClass3>();
	}
}
