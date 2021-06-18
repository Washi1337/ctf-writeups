public class VMCpuWrapper
{
	public static readonly object LockObject = new object();

	public static volatile VMCpuWrapper Instance;

	public VMCpu cpu;
}
