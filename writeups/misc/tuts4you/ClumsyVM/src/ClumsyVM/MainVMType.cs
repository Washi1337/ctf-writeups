using System.Collections.Generic;

public class MainVMType
{
	public readonly VMType1 State1;

	public readonly GClass42 State2;

	public List<GClass36> List0;

	public List<GClass37> List1;

	public MainVMType()
	{
		State1 = MainModule.GetOrCreateGClass2();
		List1 = new List<GClass37>();
		List0 = new List<GClass36>();
		State2 = MainModule.GetOrCrateGClass42();
	}
}
