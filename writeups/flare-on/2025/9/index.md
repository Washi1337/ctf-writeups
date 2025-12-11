---
title: 9 - 10000
layout: default
---

# 9 - 10000

**Time spent:** ~1.5 day

**Tools used:** Ghidra, GhidraScript, x64dbg, C# (AsmResolver), Python, Sagemath

Challenge 9 is the final end boss of this year, and boy was it an end boss :).

It starts off with the fact that the download is a whopping 1GB single executable file, and quickly brings you into a rabbit hole of pretty complex maths (at least for me!) and a lot of programming to automate the sh-t out of everything.

This challenge is very much one of my favorite challenges in the series. It is incredibly inefficient, incredibly unrealistic, very CTF-y (like DEFCON), but also a lot of fun!

Let's dive in.


## Orientation

The vast majority of the bytes in the file come from the 10,000 resources that are stored in the `.rsrc` section.

![](img/01.png)

If we look at the resources stored in the PE, we can see there are a whopping 10,000 unique resources in the file, each containing what seems to be some kind of compressed buffer:

![](img/02.png)

If you squint a little, you can actually see that these buffers seem to contain MZ headers.
This would mean the binary embeds 10,000 PE files.
For the ones that are in the know, this makes it sound a lot like a DEFCON challenge series called `n<challenge>` (e.g., `nfuncs`, `ncuts`, `nloads`), which features a similar construction :).

If we look at the binary in Ghidra, we can see that the main code is really not that complicated:

![](img/03.png)

From this code we can learn the program expects a `license.bin` in the working directory of roughly 330KB, neatly separated into 10,000 chunks equally sized chunks.
Each chunk starts with a 16 bit integer referencing one of the 10,000 resources.
The resource is then decompressed and manually mapped into memory _somehow_, and an exported function called `check` is looked up.
The remaining of the chunk's data (32 bytes) is then passed onto the this `check` function, which seems to return either `true` or `false`.
If it doesn't return `true`, the program exits early, meaning we should make all 10,000 checks complete successfully.


## Dumping all DLLs

Let's start simple and decompress all the embedded DLLs.

Looking into the loader function `load_pe_from_resource` (`FUN_140001482`), we can see a basic construction of loading the resource data, decompressing and finally manual mapping the DLL into memory:

![](img/04.png)

I have no intention of identifying or understanding the algorithm behind the functions `get_decompressed_size` and `decompress` functions themselves.
Instead, I quickly identified that whatever algorithm was used, its implementation did not have any references to external calls or global data.
This makes it very easy to just straight up copy the x86 code and treat it as a blackbox decompressor.
Wrap it up into a couple of C# code and you have a nice and short unpacker script:

```csharp
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace Decompressor;

public static class NativeCode
{
    public static readonly byte[] GetDecompressedSizeCode = [ /* ... truncated ... */ ];
    public static readonly byte[] DecompressCode = [ /* ... truncated ... */ ];
}

internal class Program
{
    [DllImport("kernel32.dll")]
    private static extern nint VirtualAlloc(nint lpAddress, nint dwSize, uint flAllocationType, uint flProtect);

    private unsafe delegate nint GetDecompressedSize(byte* data, nint dataLength);
    private unsafe delegate void Decompress(byte* compressed, byte* decompressed, nint compressedSize, nint decompressedSize, int index);

    public static unsafe void Main(string[] args)
    {
        // Copy the two x86 functions into some executable memory.
        nint ptr = VirtualAlloc(0, NativeCode.GetDecompressedSizeCode.Length, 0x3000 /* MEM_COMMIT | MEM_RESERVE */, 0x40 /* PAGE_EXECUTE_READWRITE */);
        Marshal.Copy(NativeCode.GetDecompressedSizeCode, 0, ptr, NativeCode.GetDecompressedSizeCode.Length);
        var getDecompressedSize = Marshal.GetDelegateForFunctionPointer<GetDecompressedSize>(ptr);

        ptr = VirtualAlloc(0, NativeCode.DecompressCode.Length, 0x3000 /* MEM_COMMIT | MEM_RESERVE */, 0x40 /* PAGE_EXECUTE_READWRITE */);
        Marshal.Copy(NativeCode.DecompressCode, 0, ptr, NativeCode.DecompressCode.Length);
        var decompress = Marshal.GetDelegateForFunctionPointer<Decompress>(ptr);

        // Extract all
        for (int i = 0; i < 10000; i++)
        {
            // Read out resource data.
            byte[] compressed = File.ReadAllBytes($@"compressed\resource{i:0000}.bin");
            fixed (byte* pCompressed = compressed)
            {
                // Determine decompressed size.
                nint size = getDecompressedSize(pCompressed, compressed.Length);

                // Decompress.
                byte[] decompressed = new byte[size];
                fixed (byte* pDecompressed = decompressed)
                {
                    decompress(pCompressed, pDecompressed, size, decompressed.Length, 0);
                }

                // Write back to disk.
                File.WriteAllBytes($"decompressed\{i:0000}.dll", decompressed);
            }
        }
        Console.WriteLine("Done!");
    }
}
```

This works great, we now have 10,000 decompressed DLLs.

TODO: image


## Investigating a single DLL

Similar to other challenges in this year, I worked under the assumption that the 10,000 DLLs were probably not written manually.
This means that all DLLs probably look very similar and only differ in some minor ways.
Therefore, let's just zoom in on a single DLL for now (I just grabbed the first one `0000.dll`), and investigate its `check` function.

When we open it in Ghidra, we are greeted with a very long series of function calls to `fXXXXXXX...` applied to the input chunk data:

![](img/06.png)

Some of these functions are defined in the current DLL, others are imported from other DLLs also embedded in the main binary:

![](img/07.png)

Zooming into these, we can identify that there are three "kinds" of functions. They look like the following:

|-----------------------|-----------------|
| Substitution          | ![](img/08.png) |
| Permutation           | ![](img/10.png) |
| Binary Exponentiation | ![](img/09.png) |


After the long series of hardcoded `f` transforms, the result is XOR'ed into a hardcoded 4x4 matrix:

![](img/11.png)

Once the XOR'ing is done, a series of multiplications and additions modulo some constant `N` follow, of which the result needs to equal 0:

![](img/12.png)

At first I did not recognize what the purpose was of this sanity check, but looking down a bit further, you can see actually an algorithm being implemented that is very similar to the `f` binary exponentiation, but this time applied to the 4x4 matrix instead.

![](img/13.png)

The final result is compared to yet another hardcoded matrix:

![](img/14.png)

To summarize, each `check` function consists of the following:
- Firstly, it feeds the input through a bunch of substitutions, permutations and exponentiations.
- Secondly, it XOR's the result into a hardcoded 4x4 matrix
- Finally, it raises the resulting matrix to the power of some constant, and compares it to some expected result.

This raises the natural question, if we want to make `check` return `true`, we need to come up with an inverse of all these operations.
The `f` functions and the XOR operation seem reversible, since they are all linear operations.
However, not all matrices are created equal, and certainly not all matrices are invertible.
However, if we recall from linear algebra, if a matrix is invertible, then [its determinant is non-zero](https://en.wikipedia.org/wiki/Determinant).
There is a [huge formula for the determinant of a 4x4 matrix](https://semath.info/src/determinant-four-by-four.html), but really it all boils down to just a very long sequence of additions and multiplications...

![](img/15.png)

Hmm, multiplications and additions for which the result needs to be 0, similar to that previous sanity check we found earlier!
From here I didn't check the formula to the T, I just assumed that whatever code we saw before, it is the determinant check.

Now we have accounted for everything that is happening in each `check` function.
Time to reverse everything!


## Creating the License.bin

This requires quite a bit of automation.

First, we need to extract the configuration of transforms and constants.
I will spare you the exact details for how I did this, but it involves reading out the export tables, disassembling, and a lot of ugly pattern matching on the x86 code. The full code can be found in Extractor.cs:

- Download: [Extractor.cs](scripts/Extractor.cs)

Now let's get to building the inverse of all operations.

As said before, reversing the `f` functions is relatively easy.
Once you have extracted the substitution and permutation tables, it is trivial to come up with the inverse tables for both.

```python
def invert_subs(output: bytes, substitution_table: bytes) -> bytes:
    result = bytearray()
    for b in output:
        result.append(substitution_table.index(b))
    return result

def invert_perm(output: bytes, permutation_table: bytes) -> bytes:
    perms = {i: v for i,v in enumerate(permutation_table)}
    inverse = {v: i for i, v in perms.items()}
    return perm(output, inverse)
```

The exponentiation is a little trickier: We cannot just solve the discrete log problem and compute `m^(-e)`.
However, we can use the fact that the exponentiation operates in the domain of `uint256`s, or in other words, in the group `Z_n` where `n = 2^256`.
Since the numbers are guaranteed to be made odd before the exponentiation is done, all numbers that we are processing should be invertible in this group.
This means we can do a trick similar to textbook RSA.
Instead of trying to compute `m^(-e)`, we can try to find a `d` that makes `(m^e)^d = m` in the group `Z_n`.
We are therefore looking for a `d` such that `e * d = 1 (mod n)`, or in other words, `d = e^(-1) mod order(Z_n)`:

```python
def invert_exp(output: bytes, exponent: bytes) -> bytes:
    output = int.from_bytes(output, 'little')
    exponent = int.from_bytes(exponent, 'little')

    original_low_bit = output & 1
    output |= 1

    modulus = 1 << 256
    d = pow(exponent, -1, modulus)
    m = pow(output, d, modulus) ^ original_low_bit ^ 1

    return m.to_bytes(32, 'little')
```

Finally, we need to reverse the matrix operations.
The XOR'ing part of the matrix is easy, as the reverse of any XOR is just applying the XOR again.
For the exponentiation, we can almost use the same trick as the normal binary exponentiation, except here we need to make sure we use the right group order.
Instead of operating in the integer group `Z_n`, we are now operating in the **matrix** group `GL(4, n)`, and thus also need the order of `GL(4, n)`.
Lucky for us, sagemath can compute all of this in just a couple lines of code!

```python
def matrix_inverse_exp(matrix, e, N):
    group_order = GL(4, N).order()
    d = int(pow(e, -1, group_order))
    return mat_pow4(matrix, d, N)

def get_transformed_input(initial_matrix, expected_matrix, modulus, exponent) -> bytes:
    # Invert matrix exponentiation
    inverse_exp = matrix_inverse_exp(expected_matrix, exponent, modulus)
    assert mat_pow4(inverse_exp, exponent, modulus) == expected_matrix

    # Recover original output of transform chains
    xored = xor(inverse_exp, initial_matrix)
    assert xored[0] == xored[4]

    return struct.pack("QQQQ", xored[0], xored[1], xored[2], xored[3])
```

We have now all the ingredients to construct an input that makes a single `check` function pass:

```python
def generate_chunk(files, module_id):
    current_file = f"{module_id:04}.dll"
    data = files[current_file]
    transformed = get_transformed_input(data["InitialMatrix"], data["ExpectedMatrix"], data["Modulus"], data["Exponent"])

    for transform_entry in reversed(data["TransformSequence"]):
        module = transform_entry["Module"]
        name = transform_entry["Name"]

        if module is None:
            module = current_file

        transform = files[module]["DeclaredTransforms"][name]
        transform_type = transform["Type"]
        transform_data = base64.b64decode(transform["Data"])
        transform_module_id = int(module[:-4])

        if transform_type == 0:
            transform_type = "substitution"
            new_data = invert_subs(transformed, transform_data)
        elif transform_type == 1:
            transform_type = "permutation"
            new_data = invert_perm(transformed, transform_data)
        elif transform_type == 2:
            transform_type = "exponentiaton"
            new_data = invert_exp(transformed, transform_data)
        else:
            raise KeyError("Unknown transform type " + transform_type)

        new_data = bytearray(new_data)

        transformed = new_data

    return struct.pack("H", module_id) + transformed
```

Wrap this all in a loop...

```python
print("Loading configs...")
files = dict()
for name in tqdm.tqdm(os.listdir("extracted")):
    if not name.endswith(".json"):
        continue

    with open(f"extracted/{name}", "rb") as f:
        files[name[:-5]] = json.load(f)

print("Generating license...")
serial = bytearray()
for iteration in tqdm.tqdm(range(10000)):
    module_id = iteration
    chunk = generate_chunk(files, module_id, counters)
    serial.extend(chunk)
```

... and it should work right?


TODO: image

Hmmm.... this doesn't look like a correct decryption.

Let's look into x64dbg and see at which check it fails.

TODO: image

Yikes! It only passes the first 2 checks or so..

Why??!


## Back to the Drawing Board

This stumped me for a very long time.

Eventually, I noticed that the first `f` transform were not exactly as I expected.
They all have one extra XOR operation with some number stored in a table at the very beginning:

![](img/17.png)

I initially thought this was a stack cookie computation, because sometimes Ghidra fails to recognize them and it looked very much like one. But no, this XOR is very important!

If we track down where this global table is coming from, it is actually exactly the final buffer that is used in the main function of our main executable file.
More specifically, this buffer is updated after every `check` call.

![](img/18.png)

Looking at this code, we see that every slot in the table contains the sum of all indices each module was used.
This tells us the order in which each DLL is invoked is actually important.

How do we determine the order of execution?

The way I went about it, was to treat the expected buffer as a huge system of equations.






- What **really** happens after each DLL check ?
- global buffer updated after every invocation.
- Buffer is array of sums based on index of each DLL invocation, and used in check functions (oops! missed that!)
- We need to find the right order such that the buffer checks out with expected sums.
- Treat sum as system of 10000 equations -> Coeff matrix ->  Sagemath go brrr
- Get order


## Creating the License.bin for Real

- Get flag


## Final Words

- DEFCON nfuns much? :p
