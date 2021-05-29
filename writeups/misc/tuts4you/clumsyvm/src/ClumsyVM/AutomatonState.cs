using System.Threading;

public abstract class AutomatonState
{
	public static volatile StartAutomatonState gclass31_0;

	public static volatile FetchAutomatonState gclass29_0;

	public static volatile ExecuteAutomatonState gclass28_0;

	public static volatile EndAutomatonState gclass30_0;

	protected abstract void vmethod_0(VMCpu gclass26_0, AutomatonState gclass27_0);

	public abstract void Execute();

	public unsafe static AutomatonState GetStateByName(string name)
	{
		object object_;
		int lockTaken;
		if (name.Equals("maths"))
		{
			if (gclass29_0 != null)
			{
				return gclass29_0;
			}
			object_ = FetchAutomatonState.object_0;
			GClass1.int_0 = -1592516334;
			lockTaken = 0;
			try
			{
				Monitor.Enter(object_, ref *(bool*)(&lockTaken));
				if (gclass29_0 == null)
				{
					gclass29_0 = new FetchAutomatonState();
				}
			}
			finally
			{
				if (lockTaken != 0)
				{
					object object_2 = default(object);
					GClass37.object_0 = object_2;
					Monitor.Exit(object_);
				}
			}
			return gclass29_0;
		}
		if (name.Equals("1234567"))
		{
			if (gclass28_0 != null)
			{
				return gclass28_0;
			}
			object_ = ExecuteAutomatonState.object_0;
			lockTaken = 0;
			try
			{
				Monitor.Enter(object_, ref *(bool*)(&lockTaken));
				if (gclass28_0 == null)
				{
					gclass28_0 = new ExecuteAutomatonState();
				}
			}
			finally
			{
				if (lockTaken != 0)
				{
					object obj = object_;
					MainModule.object_6 = object_;
					Monitor.Exit(obj);
				}
			}
			return gclass28_0;
		}
		if (name.Equals("math"))
		{
			if (gclass30_0 != null)
			{
				return gclass30_0;
			}
			object_ = EndAutomatonState.object_0;
			lockTaken = 0;
			try
			{
				Monitor.Enter(object_, ref *(bool*)(&lockTaken));
				if (gclass30_0 == null)
				{
					gclass30_0 = new EndAutomatonState();
				}
			}
			finally
			{
				if (lockTaken != 0)
				{
					Monitor.Exit(object_);
				}
			}
			return gclass28_0;
		}
		object_ = StartAutomatonState.object_0;
		lockTaken = 0;
		try
		{
			Monitor.Enter(object_, ref *(bool*)(&lockTaken));
			if (gclass31_0 != null)
			{
				return gclass31_0;
			}
			object object_3 = StartAutomatonState.object_0;
			int lockTaken2 = 0;
			try
			{
				Monitor.Enter(object_3, ref *(bool*)(&lockTaken2));
				if (gclass31_0 == null)
				{
					gclass31_0 = new StartAutomatonState();
				}
			}
			finally
			{
				if (lockTaken2 != 0)
				{
					Monitor.Exit(object_3);
				}
			}
			return gclass31_0;
		}
		finally
		{
			if (lockTaken != 0)
			{
				Monitor.Exit(object_);
			}
		}
	}

	public AutomatonState()
	{
	}
}
