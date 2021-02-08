using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;

namespace Solution
{
    class Program
    {
        static void Main(string[] args)
        {
	        (int key, string plainText) = Bruteforce()
		        .First(x => x.PlainText.All(c => c >= 0x20 && c <= 0x7F)); // get first ascii readable solution.

		    Console.WriteLine($"R7: {key:X8} -> Plaintext: {plainText}");
        }

        private static IEnumerable<(int R7, string PlainText)> Bruteforce()
        {
	        string knownSuffix = "0000000000000000000000000100001000000000000000000000000100000110";

	        for (int i = 0; i < int.MaxValue; i++)
	        {
		        // Construct candidate key.
		        string candidateR7 = Convert.ToString(i, 2).PadLeft(32, '0');
		        string candidateKey = candidateR7 + knownSuffix;

		        string cipherText = "XJeEaI72hAOSJgApwmVkaLerdwyKhADpmLuhuxonxfQ2j9zSfj/osQ==";

		        // Attempt decryption.
		        string plainText;
		        try
		        {
			        plainText = DecryptTripleDES(cipherText, candidateKey, shouldHashKey: true);
		        }
		        catch
		        {
			        plainText = null;
		        }

		        if (plainText is not null)
					yield return (i, plainText);
	        }
        }

        public static string DecryptTripleDES(string encrypted_data, string key, bool shouldHashKey)
        {
	        // Copied from the binary.

        	object obj = Convert.FromBase64String(encrypted_data);
        	object key2;
        	if (shouldHashKey)
        	{
        		MD5CryptoServiceProvider mD5CryptoServiceProvider = new MD5CryptoServiceProvider();
        		key2 = mD5CryptoServiceProvider.ComputeHash(Encoding.UTF8.GetBytes(key));
        		mD5CryptoServiceProvider.Clear();
        	}
        	else
        	{
        		key2 = Encoding.UTF8.GetBytes(key);
        	}
        	TripleDESCryptoServiceProvider obj2 = new TripleDESCryptoServiceProvider
        	{
        		Key = (byte[])key2,
        		Mode = CipherMode.ECB,
        		Padding = PaddingMode.PKCS7
        	};
        	object bytes = obj2.CreateDecryptor().TransformFinalBlock((byte[])obj, 0, ((Array)obj).Length);
        	obj2.Clear();
        	return Encoding.UTF8.GetString((byte[])bytes);
        }
    }
}
