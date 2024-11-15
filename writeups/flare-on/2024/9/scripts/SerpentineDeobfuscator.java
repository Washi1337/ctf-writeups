// Sample Java GhidraScript
// @category FLARE

import ghidra.app.emulator.EmulatorHelper;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

public class SerpentineDeobfuscator extends GhidraScript {
    
    private Address BASE;

    @Override
    protected void run() throws Exception {
        
        BASE = currentAddress.getNewAddress(0x13370000L);
        recursiveDeob(currentAddress);
    }

    private void recursiveDeob(Address address) throws Exception {
        var listing = currentProgram.getListing();
        var current = address;

        while (current != null) {
            monitor.checkCancelled();

            if ((getByte(current) & 0xff) == 0xF4) {
                current = traverseHltBranch(current);
            }

            while (current != null) {
                monitor.checkCancelled();

                var instruction = listing.getInstructionAt(current);
                
                if (instruction == null) {
                    // If we are at a null instruction, it's either because we 
                    // reached the end, or ghidra is annoying with its auto 
                    // recursive disassembly.

                    var previous = listing.getInstructionBefore(current);

                    // Are we at the end of one handler?
                    if (previous.toString().startsWith("JMP")) {
                        current = previous.getAddress();
                        break;
                    }

                    // Sometimes disassemble(x) lets ghidra disassemble random crap too. try clearing it and try one more time.
                    println("Null instruction at "+ current +", trying to force disassemble..");
                    listing.clearCodeUnits(current, current.add(15), true);
                    disassemble(current);
                    instruction = listing.getInstructionAt(current);
                    
                    if (instruction == null) {
                        // It failed again, user should decide how  to continue.
                        println("Ended at null instruction: " + current);
                        return;
                    }
                }
                
                String disassembly = instruction.toString();
                if (disassembly.startsWith("CALL")) {
                    // We're at an obfuscated instruction call -> deobfuscate it.
                    current = deobfuscateCall(current);
                } else {
                    // Normal instruction -> skip.
                    current = current.add(instruction.getLength());
                }
            }

            // Follow last jump-chain (ugly but works^tm).

            var instr = listing.getInstructionAt(current);
            if (instr == null || !instr.toString().startsWith("JMP"))
                return;
            
            var operand = instr.toString().split(" ")[1];
            if (!operand.startsWith("0x")) {
                // Every stage ends with a JMP <register>.
                println("Reached end at " + current);
                return;
            }

            current = current.getAddress(operand);
            instr = listing.getInstructionAt(current);
            if (instr == null || !instr.toString().startsWith("JMP")) {
                return;
            }

            current = current.getAddress(instr.toString().split(" ")[1]);
        }
    }

    private Address traverseHltBranch(Address address) throws Exception {
        int relativeOffset = (int) getByte(address.add(1)) & 0xFF;
        
        var unwindInfoAddress = address.add(2 + relativeOffset);
        if (unwindInfoAddress.getOffset() % 2 == 1)
            unwindInfoAddress = unwindInfoAddress.add(1);

        var info = readUnwindInfo(unwindInfoAddress);

        var handlerAddress = BASE.add(info.ExceptionHandler);
        disassemble(handlerAddress);
        
        println(address + " : HLT -> Exception Handler: " + handlerAddress);

        return handlerAddress;
    }

    private Address deobfuscateCall(Address address) throws Exception {
        var listing = currentProgram.getListing();

        var call = listing.getInstructionAt(address);

        var emulator = new EmulatorHelper(currentProgram);
        emulator.writeRegister("RIP", address.getOffset());

        // step into handler
        emulator.step(monitor);
        var handlerAddress = emulator.getExecutionAddress();
        if ((getByte(handlerAddress) & 0xFF) != 0x8F) {
            println("No pop found at handler for " + address);
            return null;
        }

        // emulate instructions responsible for decryption.
        for (int i = 0; i < 7; i++) {
            emulator.step(monitor);
        }

        // Decode new instruction
        var startAddress = emulator.getExecutionAddress();

        byte[] newCode = emulator.readMemory(startAddress, 50);
        listing.clearCodeUnits(startAddress, startAddress.add(newCode.length), true);
        setBytes(startAddress, newCode);
        disassemble(startAddress);

        // Read next decoded instruction.
        var instruction = listing.getInstructionAt(startAddress);
        var endAddress = instruction.getAddress().add(instruction.getLength());

        println(call.getAddress() + " : " + call + " -> " + instruction);

        // Delete decoder function and clear code (Helps preventing ghidra's auto analysis do weird stuff).
        listing.clearCodeUnits(handlerAddress, endAddress.add(10), true);
        currentProgram.getFunctionManager().removeFunction(handlerAddress);

        // Decide what to do with the instruction.
        if (!instruction.toString().startsWith("JMP")) {
            // Inline, there should be exactly enough space.
            byte[] actualCode = getBytes(startAddress, (int) endAddress.subtract(startAddress));
            listing.clearCodeUnits(address, address.add(actualCode.length + 10), true);
            setBytes(address, actualCode);
            disassemble(address);

            return address.add(actualCode.length);
        } else {
            // HACK: jmp's operands are relative to the current RIP so we cannot 
            // just inline the jmp instruction. Instead, we patch the call to a 
            // jump to the jmp to retain the current RIP.
            listing.clearCodeUnits(address, address.add(5), true);
            setByte(address, (byte) 0xE9);
            setInt(address.add(1), (int) startAddress.subtract(address.add(5)));
            disassemble(address);
        
            return address;
        }
    }

    private UnwindInfo readUnwindInfo(Address address) throws Exception {
        var result = new UnwindInfo();

        result.Flags = getByte(address);
        result.SizeOfProlog = getByte(address.add(1));
        byte codeCount = getByte(address.add(2));
        result.FrameRegisterAndOffset = getByte(address.add(3));

        if (codeCount % 2 == 1) {
            codeCount++;
        }

        result.UnwindCodes = new short[codeCount];

        var current = address.add(4);
        for (int i = 0; i < codeCount; i++) {
            result.UnwindCodes[i] = getShort(current);
            current = current.add(2);
        }

        result.ExceptionHandler = getInt(current);

        return result;
    }

    class UnwindInfo {
        public byte Flags;
        public byte SizeOfProlog;
        public byte FrameRegisterAndOffset;
        public short[] UnwindCodes;
        public int ExceptionHandler;

        public int getFrameRegister() {
            return FrameRegisterAndOffset & 0xF;
        }

        public int getFrameRegisterOffset() {
            return (FrameRegisterAndOffset >> 4) & 0xF;
        }

        @Override
        public String toString() {
            return String.format(
                "Flags: %x, SizeOfProlog: %x, FrameReg: %x, UnwindCodes: %d, Handler: %x",
                Flags,
                SizeOfProlog,
                FrameRegisterAndOffset,
                UnwindCodes.length,
                ExceptionHandler
            );
        }
    }
}
