// Sample Java GhidraScript
// @category FLARE

import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.*;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;

public class SerpentineTranspile extends GhidraScript {

    private Address BASE;
    private final StringBuilder _builder = new StringBuilder();

    private Address _currentAddress;
    private Instruction _currentInstruction;
    private String _currentBasePointer;

    private int _stackCounter;


    @Override
    protected void run() throws Exception {
        var listing = currentProgram.getListing();
        BASE = currentAddress.getNewAddress(0x13370000L);
        _currentAddress = currentAddress;

        // Emit header.
        _builder.append("#include <stdio.h>\n");
        _builder.append("typedef unsigned char uint8_t;\n");
        _builder.append("typedef unsigned short uint16_t;\n");
        _builder.append("typedef unsigned long uint32_t;\n");
        _builder.append("typedef unsigned long long uint64_t;\n");
        _builder.append("\n\n");
        _builder.append("int get(); \n");
        
        _builder.append("int main() {\n");
        _builder.append("printf(\"%d\", get());\n");
        _builder.append("};\n\n");

        // Start transpiled function
        _builder.append("int get() {\n");

        // Set all registers and old registers to 0.
        for (var reg : Registers) {
            _builder.append("uint64_t " + reg + "_old = 0;\n");
        }
        _builder.append("uint64_t MXCSR_old = 0;\n");
        for (var reg : Registers) {
            _builder.append("uint64_t " + reg + " = 0;\n");
        }
        _builder.append("uint64_t MXCSR = 0;\n");
        _builder.append("uint64_t ZF = 0;\n");
        _builder.append("\n\n");

        // Traverse implied CFG and transpile on the go.
        try {
            while (true) {
                monitor.checkCancelled();
                
                _currentInstruction = listing.getInstructionAt(_currentAddress);

                // Check if we're still at a valid instruction.
                if (_currentInstruction == null) {
                    // Try force decoding... 
                    listing.clearCodeUnits(_currentAddress, _currentAddress.add(10), true);
                    disassemble(_currentAddress);
                    _currentInstruction = listing.getInstructionAt(_currentAddress);
                    if (_currentInstruction == null) {
                        // Still failed, something must be up!
                        throw new Exception("Stopped at null instr " + _currentAddress);
                    }
                }

                println(_currentAddress + " : " + _currentInstruction);
                if (_currentInstruction.toString().startsWith("JMP R")) {
                    // Stages end with "JMP <register>"
                    break;
                }
                
                // Emit original instruction as comment (debug purposes).
                _builder.append("\n// " + _currentAddress + ": " + _currentInstruction + "\n");

                var disassembly = _currentInstruction.toString();

                // Excuse my horrid opcode/operand parsing. I don't know ghidra's API well enough :')

                int delimiterIndex = disassembly.indexOf(' ');
                if (delimiterIndex == -1) {
                    // We have no operand.
                    switch (disassembly) {
                        case "HLT": processHlt(); break;
                        case "NOP": _currentAddress = _currentAddress.add(1); break;
                        default: throw new Exception("Unsupported " + _currentInstruction);
                    }
                } else {
                    // We have at least one operand.
                    var opcode = disassembly.substring(0, delimiterIndex);
                    var operands = disassembly.substring(delimiterIndex+1);

                    switch (opcode) {
                        case "ADD": processAdd(operands); break;
                        case "SUB": processSub(operands); break;
                        case "MOV": processMov(operands); break;
                        case "MOVZX": processMovzx(operands); break;
                        case "PUSH": processPush(operands); break;
                        case "JMP": processJmp(operands); break;
                        case "MUL": processMul(operands); break;
                        case "LDMXCSR": processLdmxcsr(operands); break;
                        case "SHL": processShl(operands); break;
                        case "NOT": processNot(operands); break;
                        case "AND": processAnd(operands); break;
                        case "OR": processOr(operands); break;
                        case "XOR": processXor(operands); break;
                        case "TEST": processTest(operands); break;
                        case "CMOVNZ": processCmovnz(operands); break;
                        case "LEA": processLea(operands); break;
                        default: throw new Exception("Unsupported " + _currentInstruction);
                    }
                }           
            }
        } finally {
            // Close get() function and write to file.
            _builder.append("}\n");
            Files.write(Paths.get("/tmp/transpiled.c"), _builder.toString().getBytes(), StandardOpenOption.CREATE);
        }
    }

    private int readByte() throws Exception { 
        byte b = getByte(_currentAddress);
        _currentAddress = _currentAddress.add(1);
        return b & 0xFF;
    }

    private void processHlt() throws Exception {
        _builder.append("// ----------------\n");

        readByte();
        int relativeOffset = readByte();
        
        var unwindInfoAddress = _currentAddress.add(relativeOffset);
        if (unwindInfoAddress.getOffset() % 2 == 1)
            unwindInfoAddress = unwindInfoAddress.add(1);

        var info = readUnwindInfo(unwindInfoAddress);
        println(info.toString());

        // Transpile unwind codes.
        for (var code : info.UnwindCodes) {
            println(code.toString());
            _builder.append("\n// " + code + "\n");
            switch (code.Code) {
            case PushMachframe:
                if ((byte) code.Operand == 0) {
                    _builder.append("RSP = *(uint64_t*) (RSP + 0x18);\n");
                } else {
                    _builder.append("RSP = *(uint64_t*) (RSP + 0x20);\n");
                }
                break;

            case AllocSmall:
            case AllocLarge:
                _builder.append("RSP += " + code.Operand + ";\n");
                break;

            case PushNonVol:
                appendPop(Registers.get((byte) code.Operand));
                break;

            case SetFpreg:
                var register = Registers.get((byte) info.getFrameRegister());
                int offset = info.getFrameRegisterOffset() * 16;
                _builder.append("RSP = " + register + " - " + offset + ";\n");
                break;
                
            default:
                throw new Exception("Not supported!" + code.toString());
            }
        }

        _builder.append("// save current state\n");
        for (var reg : Registers) {
            _builder.append(reg + "_old = " + reg + ";\n");
        }

        _builder.append("MXCSR_old = MXCSR;\n");
        _builder.append("char stack" + _stackCounter + "[0x10000];\n");
        _builder.append("RSP = (uint64_t) &stack" + _stackCounter + "[0x10000 - 8];\n");
        _stackCounter++;
        _builder.append("\n");

        var handlerAddress = BASE.add(info.ExceptionHandler);
        _currentAddress = handlerAddress;
    }

    private String getBinarySource(String operands) throws Exception {
        int x = operands.indexOf(",");
        var source = operands.substring(x + 1);

        var parsed = tryParseSingleOperand(source);
        if (parsed == null) {
            throw new Exception("Unsupported source operand " + _currentInstruction);
        }

        return parsed;
    }

    private String getBinaryDest(String operands) throws Exception {
        int x = operands.indexOf(",");
        var dest = operands.substring(0, x);

        var parsed = tryParseSingleOperand(dest);
        if (parsed == null) {
            throw new Exception("Unsupported dest operand " + _currentInstruction);
        }

        return parsed;
    }

    private String tryParseSingleOperand(String operand) {
        if (Registers.contains(operand)) {
            // plain register
            return operand;
        }

        int index = LowByteRegisters.indexOf(operand);
        if (index != -1) {
            // rax -> al
            return "*((uint8_t*) &" + Registers.get(index) + ")";
        }

        index = DwordRegisters.indexOf(operand);
        if (index != -1) {
            // rax -> eax
            return "*((uint32_t*) &" + Registers.get(index) + ")";
        }

        if (operand.startsWith("0x") || operand.startsWith("-0x") ) {
            // plain number
            return operand;
        }

        operand = tryParseReference(operand);
        if (operand != null) {
            return operand;
        }

        return null;
    }

    private String tryParseReference(String operand) {
        String type;

        if (operand.startsWith("[")) {
            // We're dealing with a "[address]" reference (e.g., in a LEA instruction).
            return operand.substring(1, operand.length() - 1);
        } else {
            // Format:  "<type> ptr [<address>]"
            // example: "qword ptr [0x1337]"

            int space = operand.indexOf(' ');
            if (space == -1)
                return null;

            // Map x86 keyword to C type.
            type = operand.substring(0, space);
            switch (type) {
                case "byte": type = "uint8_t"; break;
                case "word": type = "uint16_t"; break;
                case "dword": type = "uint32_t"; break;
                case "qword": type = "uint64_t"; break;
                default:
                    return null;
            }
        }
        
        int openBrace = operand.indexOf('[');
        int closeBrace = operand.indexOf(']');
        if (openBrace == -1) 
            return null;

        String reference = operand.substring(openBrace+1, closeBrace);

        // If the reference is an offset relative to the CONTEXT base pointer, 
        // map the raw field offsets to the (old) registers.
        if (_currentBasePointer != null && reference.startsWith(_currentBasePointer)) {
            int fieldOffset = Integer.parseInt(reference.split(" \\+ ")[1].substring(2), 16);
            
            if (fieldOffset == 0x34) {
                reference = "&MXCSR_old";
            } else if (fieldOffset >= 0x78 && fieldOffset <= 0xf0) {
                int register = (fieldOffset - 0x78) / 8;                
                reference = "&" + Registers.get(register) + "_old";
            }
        }

        // Format appropriately, taking C type into account.
        return "*((" + type + "*) (" + reference + "))";
    }

    private void processMov(String operands) throws Exception {
        if (operands.endsWith("[R9 + 0x28]")) {
            // This is a reference to the CONTEXT pointer. Update our currently 
            // assumed register that contains the context pointer.
            _currentBasePointer = operands.split(",")[0];
            _builder.append("// switch to context pointer " + _currentBasePointer + "\n");
            
            // We don't need to assign anything here.
        } else {
            // Normal assignment.
            _builder.append(getBinaryDest(operands) + " = " + getBinarySource(operands) + ";\n");
        }
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }

    private void processMovzx(String operands) throws Exception {
        _builder.append(getBinaryDest(operands) + " = (" + getBinarySource(operands) + ") & 0xFF;\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }

    private void processAdd(String operands) throws Exception {
        _builder.append(getBinaryDest(operands) + " += " + getBinarySource(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }

    private void processSub(String operands) throws Exception {
        _builder.append(getBinaryDest(operands) + " -= " + getBinarySource(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }

    private void processPush(String operands) throws Exception {
        appendPush(operands);
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }

    private void appendPush(String operands) {
        _builder.append("RSP -= 8;\n");
        _builder.append("*(uint64_t*) (RSP) = " + tryParseSingleOperand(operands) + ";\n");
    }

    private void processPop(String operands) throws Exception {
        appendPop(operands);
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }

    private void appendPop(String operands) {
        _builder.append(tryParseSingleOperand(operands) + " = *(uint64_t*) (RSP);\n");
        _builder.append("RSP += 8;\n");
    }
    
    private void processJmp(String operand) throws Exception {
        _currentAddress = _currentAddress.getAddress(operand.substring(2));
    }
    
    private void processMul(String operands) throws Exception {
        _builder.append("RAX *= " + tryParseSingleOperand(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }
    
    private void processLdmxcsr(String operands) throws Exception {
        _builder.append("MXCSR = " + tryParseSingleOperand(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }
    
    private void processShl(String operands) throws Exception {
        _builder.append(getBinaryDest(operands) + " <<= " + getBinarySource(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }
    
    private void processNot(String operands) throws Exception {
        _builder.append(tryParseSingleOperand(operands) + " = ~" + tryParseSingleOperand(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }
    
    private void processAnd(String operands) throws Exception {
        _builder.append(getBinaryDest(operands) + " &= " + getBinarySource(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }
    
    private void processOr(String operands) throws Exception {
        _builder.append(getBinaryDest(operands) + " |= " + getBinarySource(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }
    
    private void processXor(String operands) throws Exception {
        _builder.append(getBinaryDest(operands) + " ^= " + getBinarySource(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }
    
    private void processTest(String operands) throws Exception {
        _builder.append("ZF = (" + getBinaryDest(operands) + " & " + getBinarySource(operands) + ") == 0;\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }
    
    private void processLea(String operands) throws Exception {
        _builder.append(getBinaryDest(operands) + " = " + getBinarySource(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());
    }
    
    private void processCmovnz(String operands) throws Exception {
        _builder.append("if (ZF) " + getBinaryDest(operands) + " = " + getBinarySource(operands) + ";\n");
        _currentAddress = _currentAddress.add(_currentInstruction.getLength());

        // Technically not accurate, but for this challenge every block ends with a CMOVNZ followed by a jmp
        _builder.append("return " + getBinaryDest(operands) + ";\n\n");
    }

    private UnwindInfo readUnwindInfo(Address address) throws Exception {
        var result = new UnwindInfo();

        result.Flags = getByte(address);
        result.SizeOfProlog = getByte(address.add(1));
        byte codeCount = getByte(address.add(2));
        result.FrameRegisterAndOffset = getByte(address.add(3));
        result.UnwindCodes = new ArrayList<>();

        var current = address.add(4);
        int i = 0;
        while (i < codeCount) {
            monitor.checkCancelled();

            var code = new UnwindCode(getByte(current), getByte(current.add(1)));
            current = current.add(2);
            i++;

            switch (code.getOpCode()) {
            case AllocLarge:
                if (code.getOpInfo() == 0) {
                    result.UnwindCodes.add(new UnwindInstruction(code.getCodeOffset(), code.getOpCode(), getShort(current) * 8));
                    current = current.add(2);
                    i++;
                } else if (code.getOpInfo() == 1) {
                    result.UnwindCodes.add(new UnwindInstruction(code.getCodeOffset(), code.getOpCode(), getInt(current)));
                    current = current.add(4);
                    i+=2;
                } else {
                    result.UnwindCodes.add(new UnwindInstruction(code.getCodeOffset(), code.getOpCode(), code.getOpInfo()));
                }
                break;
            case AllocSmall:
                result.UnwindCodes.add(new UnwindInstruction(code.getCodeOffset(), code.getOpCode(), code.getOpInfo() * 8 + 8));
                break;
            default:
                result.UnwindCodes.add(new UnwindInstruction(code.getCodeOffset(), code.getOpCode(), code.getOpInfo()));
                break;
            }
        }

        if (codeCount % 2 == 1) {
            codeCount++;
            current = current.add(2);
        }

        result.ExceptionHandler = getInt(current);

        return result;
    }

    class UnwindInfo {
        public byte Flags;
        public byte SizeOfProlog;
        public byte FrameRegisterAndOffset;
        public List<UnwindInstruction> UnwindCodes;
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
                UnwindCodes.size(),
                ExceptionHandler
            );
        }
    }

    class UnwindInstruction {
        public byte Offset;
        public UnwindOpCode Code;
        public Object Operand;
        public UnwindInstruction(byte offset, UnwindOpCode code, Object operand) {
            Offset = offset;
            Code = code;
            Operand = operand;
        }

        @Override
        public String toString() {
            return toHexString(Offset, true, true) + ": " + Code.toString() + " " +  Operand.toString();
        }
    }

    class UnwindCode {
        public byte Byte1;
        public byte Byte2;

        public UnwindCode(byte byte1, byte byte2) {
            Byte1 = byte1;
            Byte2 = byte2;
        }

        public byte getCodeOffset() {
            return Byte1;
        }

        public UnwindOpCode getOpCode() {
            switch (Byte2 & 0xF) {
                case 0: return UnwindOpCode.PushNonVol;
                case 1: return UnwindOpCode.AllocLarge;
                case 2: return UnwindOpCode.AllocSmall;
                case 3: return UnwindOpCode.SetFpreg;
                case 4: return UnwindOpCode.SaveNonvol;
                case 5: return UnwindOpCode.SaveNonvolFar;
                case 8: return UnwindOpCode.SaveXmm128;
                case 9: return UnwindOpCode.SaveXmm128Far;
                case 10: return UnwindOpCode.PushMachframe;
                default: return UnwindOpCode.Unknown;
            }
        }

        public byte getOpInfo() {
            return (byte) ((Byte2 & 0xF0) >> 4);
        }

        public int getFrameOffset() {
            return Byte1 | Byte2 << 8;
        }

        @Override
        public String toString() {
            return "UnwindCode [Byte1=" + Byte1 + ", Byte2=" + Byte2 + ", getOpCode()=" + getOpCode() + ", getOpInfo()="
                    + getOpInfo() + "]";
        }
    }
    enum UnwindOpCode {
        Unknown,
        PushNonVol,
        AllocLarge,
        AllocSmall,
        SetFpreg,
        SaveNonvol,
        SaveNonvolFar,
        SaveXmm128,
        SaveXmm128Far,
        PushMachframe,
    }
    
    private static List<String> Registers = Arrays.asList(new String[] {
        "RAX",
        "RCX",
        "RDX",
        "RBX",
        "RSP",
        "RBP",
        "RSI",
        "RDI",
        "R8",
        "R9",
        "R10",
        "R11",
        "R12",
        "R13",
        "R14",
        "R15",
    });

    private static List<String> LowByteRegisters = Arrays.asList(new String[] {
        "AL",
        "CL",
        "DL",
        "BL",
        "SL",
        "BPL",
        "SIL",
        "DIL",
        "R8B",
        "R9B",
        "R10B",
        "R11B",
        "R12B",
        "R13B",
        "R14B",
        "R15B",
    });

    private static List<String> DwordRegisters = Arrays.asList(new String[] {
        "EAX",
        "ECX",
        "EDX",
        "EBX",
        "ESP",
        "EBP",
        "ESI",
        "EDI",
        "R8D",
        "R9D",
        "R10D",
        "R11D",
        "R12D",
        "R13D",
        "R14D",
        "R15D",
    });
}
