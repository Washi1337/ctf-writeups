using System.Buffers.Binary;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Parameters;
using Org.BouncyCastle.Math;
using Org.BouncyCastle.Math.EC;
using Org.BouncyCastle.Security;

internal class Program
{
    private static readonly BigInteger XorMask = new("133713371337133713371337133713371337133713371337133713371337133713371337133713371337133713371337", 16);

    private static readonly FpCurve Curve = new(
        new BigInteger("c90102faa48f18b5eac1f76bb40a1b9fb0d841712bbe3e5576a7a56976c2baeca47809765283aa078583e1e65172a3fd", 16),
        new BigInteger("a079db08ea2470350c182487b50f7707dd46a58a1d160ff79297dcc9bfad6cfc96a81c4a97564118a40331fe0fc1327f", 16),
        new BigInteger("9f939c02a7bd7fc263a4cce416f4c575f28d0c1315c4f0c282fca6709a5f9f7f9c251c9eede9eb1baa31602167fa5380", 16)
    );

    private static readonly FpPoint G = (FpPoint) Curve.CreatePoint(
        new BigInteger("087b5fe3ae6dcfb0e074b40f6208c8f6de4f4f0679d6933796d3b9bd659704fb85452f041fff14cf0e9aa7e45544f9d8", 16),
        new BigInteger("127425c1d330ed537663e87459eaa1b1b53edfe305f6a79b184b3180033aab190eb9aa003e02e9dbf6d593c5e3b08182", 16)
    );

    private static readonly byte[][] Messages =
    [
        Convert.FromHexString("0a6c559073da49754e9ad9846a72954745e4f2921213eccda4b1422e2fdd646fc7e28389c7c2e51a591e0147e2ebe7ae"),
        Convert.FromHexString("264022daf8c7676a1b2720917b82999d42cd1878d31bc57b6db17b9705c7ff2404cbbf13cbdb8c096621634045293922"),
        Convert.FromHexString("a0d2eba817e38b03cd063227bd32e353880818893ab02378d7db3c71c5c725c6bba0934b5d5e2d3ca6fa89ffbb374c31"),
        Convert.FromHexString("96a35eaf2a5e0b430021de361aa58f8015981ffd0d9824b50af23b5ccf16fa4e323483602d0754534d2e7a8aaf8174dc"),
        Convert.FromHexString("f272d54c31860f"),
        Convert.FromHexString("3fbd43da3ee325"),
        Convert.FromHexString("86dfd7"),
        Convert.FromHexString("c50cea1c4aa064c35a7f6e3ab0258441ac1585c36256dea83cac93007a0c3a29864f8e285ffa79c8eb43976d5b587f8f35e699547116"),
        Convert.FromHexString("fcb1d2cdbba979c989998c"),
        Convert.FromHexString("61490b"),
        Convert.FromHexString("ce39da"),
        Convert.FromHexString("577011e0d76ec8eb0b8259331def13ee6d86723eac9f0428924ee7f8411d4c701b4d9e2b3793f6117dd30dacba"),
        Convert.FromHexString("2cae600b5f32cea193e0de63d709838bd6"),
        Convert.FromHexString("a7fd35"),
        Convert.FromHexString("edf0fc"),
        Convert.FromHexString("802b15186c7a1b1a475daf94ae40f6bb81afcedc4afb158a5128c28c91cd7a8857d12a661acaec"),
        Convert.FromHexString("aec8d27a7cf26a17273685"),
        Convert.FromHexString("35a44e"),
        Convert.FromHexString("2f3917"),
        Convert.FromHexString("ed09447ded797219c966ef3dd5705a3c32bdb1710ae3b87fe66669e0b4646fc416c399c3a4fe1edc0a3ec5827b84db5a79b81634e7c3afe528a4da15457b637815373d4edcac2159d056"),
        Convert.FromHexString("f5981f71c7ea1b5d8b1e5f06fc83b1def38c6f4e694e3706412eabf54e3b6f4d19e8ef46b04e399f2c8ece8417fa"),
        Convert.FromHexString("4008bc"),
        Convert.FromHexString("54e41e"),
        Convert.FromHexString("f701fee74e80e8dfb54b487f9b2e3a277fa289cf6cb8df986cdd387e342ac9f5286da11ca2784084"),
        Convert.FromHexString("5ca68d1394be2a4d3d4d7c82e5"),
        Convert.FromHexString("31b6dac62ef1ad8dc1f60b79265ed0deaa31ddd2d53aa9fd9343463810f3e2232406366b48415333d4b8ac336d4086efa0f15e6e59"),
        Convert.FromHexString("0d1ec06f36"),

    ];

    private static readonly SecureRandom Random = new SecureRandom();

    public static void Main(string[] args)
    {
        Console.WriteLine("Q = " + Curve.Q);
        Console.WriteLine("A = " + Curve.A.ToBigInteger());
        Console.WriteLine("B = " + Curve.B.ToBigInteger());
        Console.WriteLine("Order: " + Curve.Order);
        Console.WriteLine("GX = " + G.AffineXCoord.ToBigInteger());
        Console.WriteLine("GY = " + G.AffineYCoord.ToBigInteger());

        var recoveredD = new BigInteger("168606034648973740214207039875253762473", 10);

        byte[] buffer = new byte[0x30];

        Clear(buffer);
        Messages[2].CopyTo(buffer.AsSpan());
        var x = new BigInteger(1, buffer, 0, 0x30, true).Xor(XorMask);
        Console.WriteLine("X = " + x);

        Clear(buffer);
        Messages[3].CopyTo(buffer.AsSpan());
        var y = new BigInteger(1, buffer, 0, 0x30, true).Xor(XorMask);
        Console.WriteLine("Y = " + y);

        var theirPoint = Curve.ValidatePoint(x, y);

        var sharedQ = theirPoint.Multiply(recoveredD).Normalize();
        var sharedX = sharedQ.AffineXCoord.ToBigInteger();
        var sharedY = sharedQ.AffineYCoord.ToBigInteger();
        sharedX.ToUInt32ArrayBigEndianUnsigned(MemoryMarshal.Cast<byte, uint>(buffer));
        ByteSwap(buffer);

        byte[] key = SHA512.HashData(buffer);

        var chacha = SetupChaCha(key);

        for (int i = 4; i < Messages.Length; i++)
            Console.WriteLine(Encoding.ASCII.GetString(DecryptMessage(chacha, Messages[i])));


        // To emulate an actual traffic session, uncomment the following:
        // Private key and points are static for easier debugging
        //  
        // var myD = new BigInteger("4ba456ce749b8896d3527a10b44d62bf", 16);
        // var myX = new BigInteger("9786287acc8be9df81b5b4bd7ed71db152be400c99770b55732d35a50e6b00a038419b25fce83fc1add868d924cb9918", 16);
        // var myY = new BigInteger("a39748813d3b77d7e0718c67c4334ff13782342055b54280cfc793566677a9e29a3fa21f290ba1f6b088d3efe1748760", 16);
        // 
        // var myD = new BigInteger(0x80, Random);
        // var myQ = G.Multiply(myD).Normalize();
        // var myX = myQ.AffineXCoord.ToBigInteger();
        // var myY = myQ.AffineYCoord.ToBigInteger();
        // var validate = Curve.ValidatePoint(myX, myY);
        // 
        // var socket = new Socket(SocketType.Stream, ProtocolType.Tcp);
        // socket.Bind(new IPEndPoint(IPAddress.Any, 31337));
        // socket.Listen();
        //
        // XorMask.ToUInt32ArrayBigEndianUnsigned(MemoryMarshal.Cast<byte, uint>(buffer));
        // Console.WriteLine("XOR: " + BitConverter.ToString(buffer));
        //
        // while (true)
        // {
        //     try
        //     {
        //         RunSession(socket, myX, myY, myD);
        //     }
        //     catch (Exception e)
        //     {
        //         Console.WriteLine(e.ToString());
        //     }
        // }
    }

    private static void ByteSwap(Span<byte> buffer)
    {
        for (int i = 0; i < buffer.Length; i+=4)
        {
            uint value = BinaryPrimitives.ReadUInt32LittleEndian(buffer[i..]);
            BinaryPrimitives.WriteUInt32BigEndian(buffer[i..], value);
        }
    }

    private static void Clear(Span<byte> buffer)
    {
        for (int i = 0; i < buffer.Length; i++)
            buffer[i] = 0;
    }

    private static void RunSession(Socket socket, BigInteger myX, BigInteger myY, BigInteger myD)
    {
        Console.WriteLine("Waiting for connection...");
        using var client = socket.Accept();
        using var stream = new NetworkStream(client);

        Console.WriteLine("Connected");

        Console.WriteLine("Key exchanging");
        byte[] hash = KeyExchange(myX, myY, myD, stream);

        Console.WriteLine("Setting up salsa engine with key " + Convert.ToHexString(hash));
        var engine = SetupChaCha(hash);

        Console.WriteLine("Verifying");
        Verify(client, engine);

        while (true)
        {
            string? input = Console.ReadLine();
            if (string.IsNullOrEmpty(input))
                break;

            SendMessage(client, engine, input);
            Console.WriteLine(ReceiveMessage(client, engine));
        }
    }

    private static ChaChaEngine SetupChaCha(byte[] hash)
    {
        var salsa = new ChaChaEngine();
        var keyParam = new KeyParameter(hash[..0x20]);
        var keyWithIv = new ParametersWithIV(keyParam, hash[0x20..0x28]);
        salsa.Init(true, keyWithIv);
        return salsa;
    }

    private static byte[] KeyExchange(BigInteger myX, BigInteger myY, BigInteger myD, NetworkStream stream)
    {
        byte[] buffer = new byte[0x30];

        Clear(buffer);
        stream.Read(buffer);
        var x = new BigInteger(1, buffer, 0, 0x30, true).Xor(XorMask);

        Clear(buffer);
        stream.Read(buffer);
        var y = new BigInteger(1, buffer, 0, 0x30, true).Xor(XorMask);

        Clear(buffer);
        x.ToUInt32ArrayBigEndianUnsigned(MemoryMarshal.Cast<byte, uint>(buffer));

        Clear(buffer);
        y.ToUInt32ArrayBigEndianUnsigned(MemoryMarshal.Cast<byte, uint>(buffer));
        var theirPoint = Curve.ValidatePoint(x, y);

        Clear(buffer);
        x.ToUInt32ArrayBigEndianUnsigned(MemoryMarshal.Cast<byte, uint>(buffer));

        Clear(buffer);
        myX.Xor(XorMask).ToUInt32ArrayBigEndianUnsigned(MemoryMarshal.Cast<byte, uint>(buffer));
        ByteSwap(buffer);
        stream.Write(buffer);

        Clear(buffer);
        y.ToUInt32ArrayBigEndianUnsigned(MemoryMarshal.Cast<byte, uint>(buffer));

        Clear(buffer);
        myY.Xor(XorMask).ToUInt32ArrayBigEndianUnsigned(MemoryMarshal.Cast<byte, uint>(buffer));
        ByteSwap(buffer);
        stream.Write(buffer);

        var sharedQ = theirPoint.Multiply(myD).Normalize();
        var sharedX = sharedQ.AffineXCoord.ToBigInteger();
        var sharedY = sharedQ.AffineYCoord.ToBigInteger();
        Curve.ValidatePoint(sharedX, sharedY);

        sharedX.ToUInt32ArrayBigEndianUnsigned(MemoryMarshal.Cast<byte, uint>(buffer));
        ByteSwap(buffer);

        return SHA512.HashData(buffer);
    }

    private static void Verify(Socket client, ChaChaEngine engine)
    {
        SendMessage(client, engine, "verify");
        string response = ReceiveMessage(client, engine);
        if (response != "verify")
            throw new Exception("Failed to verify");
    }

    private static void SendMessage(Socket client, ChaChaEngine engine, string message)
    {
        int count = message.Length + 1;
        byte[] messageBytes = new byte[count];
        byte[] encrypted = new byte[count];

        Encoding.ASCII.GetBytes(message, messageBytes);

        for (int i = 0; i < encrypted.Length; i++)
        {
            encrypted[i] = engine.ReturnByte(messageBytes[i]);
        }

        client.Send(encrypted);
    }

    private static string ReceiveMessage(Socket client, Salsa20Engine engine)
    {
        byte[] buffer = new byte[0x400];
        byte[] receive = new byte[1];

        for (int i = 0; i < buffer.Length; i++)
        {
            client.Receive(receive);
            byte b = engine.ReturnByte(receive[0]);
            buffer[i++] = b;

            if (b == 0)
                return Encoding.Unicode.GetString(buffer, 0, i-1);
        }

        return Encoding.Unicode.GetString(buffer);
    }

    private static byte[] DecryptMessage(Salsa20Engine engine, byte[] data)
    {
        for (int i = 0; i < data.Length; i++)
        {
            data[i] = engine.ReturnByte(data[i]);
        }

        return data;
    }
}
