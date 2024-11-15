---
title: 9 - serpentine
layout: default
---

# 9 - serpentine

**Time spent:** 4 days

**Tools used:** Ghidra - x64dbg - C - Python - z3


## Orientation
- Shellcode allocation.
- Starts with HLT ???
- Privileged instruction == exceptions right?

## Exception handlers
- x64dbg also jumps around a lot to HLTs without actually crashing
- Program must handle it somehow anyways.
- Find exception handlers, there are a few fake ones, but the one that's actually important is RtlInstallFunctionTableCallback.
- RUNTIME_FUNCTION
    - UnwindInfo contains exception handler address
    - ->  HLT is essentially a jump to a handler

- Self modifying code ?

## Solving the SMC:
- Call -> decodes one instruction, then garbles it back as an anti dump.
- returns to next instruction, always fits!
- Write script that translates all calls to the underlying instructions.
  
- Code still doesn't decompile quite right..
- Also, it has unknown pointer [R9+0x28] showing up all the time?


## Solving R9:
- How are handlers *actually* called?
    - ReactOS to the rescue! -> R9 contains DispatcherContext
    - There are UnwindCodes too, doing extra things (reference article about unwind)


## Deobfuscation:
- Hotpatching or generating the right x86 code will be difficult.
- Code will still look terrible even if we did this.
- If only there was a thing that would allow us to write new code easily without having to write the x86 ourselves, while  also optimizing our code.
- Wait, we all know what this thing is, it's called a compiler!
- Introduce C variables for all registers.
- Transpile everything to (very basic!) C
- X86 opcodes are pretty trivial, unwind opcodes not too bad either.
- How to do stack ops? define char[1000] stack local and set RSP variable to end of this buffer!
- Recompile with GCC -O1
- Gets rid of all the clutter, near clean code.
- Thank you GCC devs for 20+ years of compiler optimization theory!

## Weird Pointers:
- Well, almost... There are still some weird pointers.
- Add function code back into serpentine.exe ghidra project
- References now get resolved to LUTs.
- We need to get rid of these, SMT is bad with lookup tables.
- Recognize XOR LUT,  arithmetic and bitwise op LUTs!
- 32-bit arithmetic and bitwise ops split up into 8 bit ops
- expressions are actually very simple!
- final result should be 0

## Getting the Flag

Repeat x32 (painful!)
All into z3 with some regular expressions

Not sure why block 5 and 6 didn't work, must've made a mistake somewhere...
Not needed though, enough overlap in the blocks.
Flag


## Final Words

Awesome, very cleverly set up
Way too long
Could've been 5 layers.
More layers != always better