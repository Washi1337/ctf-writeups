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


- 10,000 resources!! (name of challenge!)
- Program reads out `license.bin`
- License file is chunked
- Every chunk starts with 2 bytes of resource ID and 32 bytes of payload data
- Resource is actually a DLL with a `check` function. This is called with the 32 bytes payload.
- For each chunk, call check function of DLL, needs to return 1


## Dumping all DLLs

- All encrypted/compressed DLLs
- no intention of understanding the algo.
- decompress using raw x86 code.
- win


## Investigating a single DLL

- Start with bunch of transforms (3 types)
  - perms
  - subs
  - cursed exponentiation

- Moved into matrix after xor
- Check det(A) == 0 (i.e., check if invertible)
- Matrix exponentiation


## Creating the License.bin 

- All dlls very similar. 
- Build extractor for parameters.
  - Identify calls, map to code size and hacky carve out constants
  - Identify XOR key and matrix exponent similarly.
- Construct automatically the reverse of all ops based on extracted config
  - Sage to the rescue
- Works for one chunk!
- Great, now just do for entire license.bin, right?
- Wait huh didnt work ??
- After chunk 2 we see differences.
- But chunk 2 in isolation works?
- There must be something going on in between each chunk.


## Back to the Drawing Board

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
