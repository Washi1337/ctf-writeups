public class GClass21
{
	public static readonly object object_0 = new object();

	public static volatile GClass21 gclass21_0;

	public bool bool_0;

	public VMMemory1Copy vmMemory1Copy;

	public VMMemory2Copy vmMemory2Copy;

	public GClass23 object_3;

	public GClass21()
	{
		MainModule.SetBool0(this, (byte) 1);
		MainModule.smethod_159(this, MainModule.GetOrCreateVMMemory1Copy());
		MainModule.smethod_161(this, MainModule.smethod_101());
		MainModule.smethod_163(this, MainModule.smethod_187());
	}
}
