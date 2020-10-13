using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using ExifLib;

namespace ConsoleApp11
{
    class Program
    {
        static string GetDesc()
        {
            using var exifReader = new ExifReader(@"05.jpg");
            string desc;
            exifReader.GetTagValue(ExifTags.ImageDescription, out desc);
            return desc;
        }

        static string GetPassword()
        {
            var password = new byte[]
            {
                62,
                38,
                63,
                63,
                54,
                39,
                59,
                50,
                39
            };

            return Decode(password);
            
            static string Decode(byte[] e)
            {
                string text = "";
                foreach (byte b in e)
                {
                    text += Convert.ToChar(b ^ 83).ToString();
                }
                return text;
            }

        }

        private static string GetNote()
        {
            return "keep steaks for dinner";
            // return "hang out in tiger cage";
        }

        private static string GetSteps()
        {
            return "magic";
        }

        private static string GetKey()
        {
            string Desc = GetDesc();
            string Note = GetNote();
            string Password = GetPassword();
            string Step = GetSteps();
            
            string text = new string(new[]
            {
                Desc[2],
                Password[6],
                Password[4],
                Note[4],
                Note[0],
                Note[17],
                Note[18],
                Note[16],
                Note[11],
                Note[13],
                Note[12],
                Note[15],
                Step[4],
                Password[6],
                Desc[1],
                Password[2],
                Password[2],
                Password[4],
                Note[18],
                Step[2],
                Password[4],
                Note[5],
                Note[4],
                Desc[0],
                Desc[3],
                Note[15],
                Note[8],
                Desc[4],
                Desc[3],
                Note[4],
                Step[2],
                Note[13],
                Note[18],
                Note[18],
                Note[8],
                Note[4],
                Password[0],
                Password[7],
                Note[0],
                Password[4],
                Note[11],
                Password[6],
                Password[4],
                Desc[4],
                Desc[3]
            });

            return text;
        }

        private static void test()
        {
            HashAlgorithm hashAlgorithm = SHA256.Create();
            byte[] bytes = Encoding.ASCII.GetBytes(GetPassword() + GetNote() + GetSteps() + GetDesc());
            byte[] first = hashAlgorithm.ComputeHash(bytes);
            byte[] second = new byte[]
            {
                50,
                148,
                76,
                233,
                110,
                199,
                228,
                72,
                114,
                227,
                78,
                138,
                93,
                189,
                189,
                147,
                159,
                70,
                66,
                223,
                123,
                137,
                44,
                73,
                101,
                235,
                129,
                16,
                181,
                139,
                104,
                56
            };
            Console.WriteLine(BitConverter.ToString(first));
            Console.WriteLine(BitConverter.ToString(second));
        }
        
        public static string GetString(byte[] cipherText, byte[] Key, byte[] IV)
        {
            string result = null;
            using var rijndaelManaged = new RijndaelManaged();
            rijndaelManaged.Key = Key;
            rijndaelManaged.IV = IV;
            var cryptoTransform = rijndaelManaged.CreateDecryptor(rijndaelManaged.Key, rijndaelManaged.IV);

            using var outputStream = new MemoryStream();
            using MemoryStream memoryStream = new MemoryStream(cipherText);
            using CryptoStream cryptoStream = new CryptoStream(memoryStream, cryptoTransform, 0);
             
            var buffer = new byte[rijndaelManaged.BlockSize];
            
            try
            {
                while (memoryStream.Position < memoryStream.Length)
                {
                    int read = cryptoStream.Read(buffer, 0, buffer.Length);
                    outputStream.Write(buffer, 0, read);
                    outputStream.Flush();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("error decrypting: " + e);
            }

            outputStream.Position = 0;
            using var reader = new StreamReader(outputStream);
            return reader.ReadToEnd();

        }

        private static byte[] GetData()
        {
            return File.ReadAllBytes(@"Runtime.dll");
        }
        
        private static byte[] GetImageData()
        {
            var data = GetData();
            var key = SHA256.Create().ComputeHash(Encoding.ASCII.GetBytes(GetKey()));
            Console.WriteLine(BitConverter.ToString(key));
            var salt = Encoding.ASCII.GetBytes("NoSaltOfTheEarth");
            return Convert.FromBase64String(GetString(data, key, salt));
        }
        
        
        static void Main(string[] args)
        {
            Console.WriteLine(GetDesc());
            Console.WriteLine(GetPassword());
            Console.WriteLine(GetNote());
            Console.WriteLine(GetSteps());
            Console.WriteLine(GetKey());
            test();
            File.WriteAllBytes(@"output.png", GetImageData());
        }
    }
}