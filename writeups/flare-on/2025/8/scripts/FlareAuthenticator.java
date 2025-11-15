// Sample Java GhidraScript
// @category FlareAuthenticator
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Stack;

import ghidra.app.emulator.EmulatorHelper;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.SourceType;

public class FlareAuthenticator extends GhidraScript {

    private static final HashMap<String, String> GPR = new HashMap<>();

    static {
        GPR.put("RAX", "RAX");
        GPR.put("RBX", "RBX");
        GPR.put("RCX", "RCX");
        GPR.put("RDX", "RDX");
        GPR.put("R8", "R8");
        GPR.put("R9", "R9");
        GPR.put("R10", "R10");
        GPR.put("R11", "R11");
        GPR.put("EAX", "RAX");
        GPR.put("EBX", "RBX");
        GPR.put("ECX", "RCX");
        GPR.put("EDX", "RDX");
        GPR.put("R8D", "R8");
        GPR.put("R9D", "R9");
        GPR.put("R10D", "R10");
        GPR.put("R11D", "R11");
        GPR.put("AL", "RAX");
        GPR.put("BL", "RBX");
        GPR.put("CL", "RCX");
        GPR.put("DL", "RDX");
        GPR.put("R8B", "R8");
        GPR.put("R9B", "R9");
        GPR.put("R10B", "R10");
        GPR.put("R11B", "R11");
    }

    @Override
    protected void run() throws Exception {
        // Temp buffers to avoid re-allocing new lists every time.
        var successors = new ArrayList<Long>();
        var comments = new ArrayList<String>();

        // Write out a graphviz dot file.
        try (var fs = new FileWriter("/tmp/%s.dot".formatted(currentAddress)))
        {
            var printer = new PrintWriter(fs);
            printer.println("digraph G {");

            var agenda = new Stack<Long>();
            var visited = new HashSet<Long>();

            // Start at current address.
            agenda.push(currentAddress.getOffset()); // main = 0x140074860
            while (!agenda.isEmpty()) {
                var current = agenda.pop();
                if (!visited.add(current)) {
                    continue;
                }

                // Process current block.
                successors.clear();
                comments.clear();
                deobfuscateBlock(currentAddress.getNewAddress(current), successors, comments);

                // Create block label.
                var builder = new StringBuilder();
                builder.append(toHexString(current, true, false)).append("\\l");
                for (var comment: comments) {
                    builder.append(comment).append("\\l");
                }
                printer.println("\t%d [label=\"%s\", shape=box3d]".formatted(current, builder));

                // Draw outgoing edges and schedule successors.
                boolean first = true;
                for (var successor: successors) {
                    // Draw edge
                    printer.println("\t%d -> %d [color=%s]".formatted(current, successor, first ? "gray" : "green"));
                    first = false;

                    // Did we reach the end (return)?
                    if (successor == Long.MAX_VALUE) continue;

                    // Create a function at the target address so Ghidra knows it is code.
                    var successorAddr = currentAddress.getNewAddress(successor);
                    if (getFunctionAt(successorAddr) == null) {
                        createFunction(successorAddr, "BLOCK_%s".formatted(successorAddr));
                    }

                    // Schedule successor.
                    if (!visited.contains(successor) && !agenda.contains(successor)) {
                        agenda.push(successor);
                    }
                }
            }

            printer.println("}");
        }

    }

    private void deobfuscateBlock(Address entry, List<Long> successors, List<String> comments) throws Exception {
        println("Processing block %s".formatted(entry));

        // Move forward in the block's instructions.
        for (var instr : currentProgram.getListing().getInstructions(entry, true)) {
            var formatted = instr.toString();
            if (formatted.equals("CALL RAX")) {
                deobfuscateCallRax(instr.getAddress(), comments);
            } else if (formatted.equals("JMP RAX")) {
                deobfuscateJmpRax(instr.getAddress(), successors);
                break;
            } else if (formatted.startsWith("RET")) {
                // We reached the end of the function.
                successors.add(Long.MAX_VALUE);
                break;
            } else if (formatted.startsWith("JMP")) {
                var operand = formatted.split(" ")[1];
                if (operand.startsWith("0x")) {
                    successors.add(Long.parseLong(operand.substring(2), 16));
                }
                break;
            } else if (formatted.startsWith("JZ") || formatted.startsWith("JNZ")) {
                var operand = formatted.split(" ")[1];
                successors.add(instr.getAddress().getOffset() + instr.getLength());
                if (operand.startsWith("0x")) {
                    successors.add(Long.parseLong(operand.substring(2), 16));
                }
                break;
            }
        }
    }

    private void deobfuscateJmpRax(Address jmpRaxAddress, List<Long> successors) throws Exception {
        var footerExpression = findFooterExpression(jmpRaxAddress);
        if (footerExpression == null) {
            println("Could not recover footer expression for jmp at %s".formatted(jmpRaxAddress));
            return;
        }

        switch (footerExpression.type) {
        case UNCONDITIONAL:
        {
            handleUnconditional(footerExpression, successors);
            break;
        }
        case CONDITIONAL_SETZ:
        case CONDITIONAL_SETNZ:
        case CONDITIONAL_SETGE:
        {
            handleConditional(footerExpression, successors);
            break;
        }
        case CONDITIONAL_UNKNOWN:
        {
            handleConditionalUnknown(footerExpression, successors);
            break;
        }
        default:
            throw new Exception("Unsupported %s".formatted(footerExpression.type));
        }
    }

    private void handleUnconditional(FooterInfo footer, List<Long> successors) throws Exception {
        long target = inferTarget(footer, false);
        println("Unconditional edge: %s -> %x".formatted(footer.start, target));

        setPreComment(footer.end, "Unconditional edge: %s -> %x".formatted(footer.start, target));
        successors.add(target);
        disassemble(footer.start.getNewAddress(target));
    }

    private void handleConditional(FooterInfo footer, List<Long> successors) throws Exception {
        long falseTarget = inferTarget(footer, false);
        long trueTarget = inferTarget(footer, true);
        successors.add(falseTarget);
        successors.add(trueTarget);

        println("Conditional edge -> %x".formatted(trueTarget));
        println("Default edge -> %x".formatted(falseTarget));

        setPreComment(footer.end, "Conditional edge -> %x\nDefault edge -> %x".formatted(trueTarget, falseTarget));
        disassemble(footer.start.getNewAddress(trueTarget));
        disassemble(footer.start.getNewAddress(falseTarget));
    }

    private void handleConditionalUnknown(FooterInfo footer, List<Long> successors) throws Exception {
        var listing = currentProgram.getListing();
        var instr = listing.getInstructionAt(footer.start);
        var registers = Arrays.stream(instr.getInputObjects()).filter(x->x instanceof Register).map(x->(Register)x).toArray(Register[]::new);
        if (registers.length != 2) {
            println("WARNING: could not infer targets on %s : %s".formatted(footer.start, instr));
            println("Treating as unconditional");
            footer.type = FooterType.UNCONDITIONAL;
            handleUnconditional(footer, successors);
            return;
        }

        var reg1 = (Register) registers[0];
        var reg2 = (Register) registers[1];

        var values = new long[] {
            -1, 0, 1
        };

        var builder = new StringBuilder();
        for (var a : values) {
            for (var b : values) {
                var emulator = new EmulatorHelper(currentProgram);
                emulator.writeRegister("RIP", footer.start.getOffset());
                emulator.writeRegister(reg1, a);
                emulator.writeRegister(reg2, b);

                while (emulator.getEmulator().getPC() != footer.end.getOffset())  {
                    emulator.step(monitor);
                }

                var target = emulator.readRegister("RAX").longValue();
                if (!successors.contains(target)) {
                    successors.add(target);
                    builder.append("%x ".formatted(target));
                    disassemble(footer.start.getNewAddress(target));
                }
            }
        }

        println("Edges: %s".formatted(builder));
        setPreComment(footer.end, "edges: %s".formatted(builder));
    }

    private long inferTarget(FooterInfo footer, boolean flag) throws Exception  {
        var emulator = new EmulatorHelper(currentProgram);
        emulator.writeRegister("RIP", footer.start.getOffset());

        switch (footer.type) {
        case UNCONDITIONAL:
            break;

        case CONDITIONAL_SETZ:
        case CONDITIONAL_SETNZ:
            emulator.writeRegister("ZF", flag ? 1L : 0L);
            break;

        case CONDITIONAL_SETGE:
            emulator.writeRegister("SF", 1L);
            emulator.writeRegister("OF", flag ? 1L : 0L);
            break;

        default:
            throw new Exception("Unsupported %s".formatted(footer.type));
        }

        while (emulator.getEmulator().getPC() != footer.end.getOffset())  {
            emulator.step(monitor);
        }

        return emulator.readRegister("RAX").longValue();
    }

    class FooterInfo {
        public Address start;
        public Address end;
        public FooterType type;

        public FooterInfo(Address start, Address end, FooterType type) {
            this.start = start;
            this.end = end;
            this.type = type;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append("FooterInfo{");
            sb.append("start = ").append(start);
            sb.append(" , end = ").append(end);
            sb.append(" , type = ").append(type);
            sb.append(" , size = ").append(end.getOffset() - start.getOffset());
            sb.append('}');
            return sb.toString();
        }
    }

    enum FooterType {
        UNCONDITIONAL,
        CONDITIONAL_SETZ,
        CONDITIONAL_SETNZ,
        CONDITIONAL_SETGE,
        CONDITIONAL_UNKNOWN,
    }

    private FooterInfo findFooterExpression(Address address) throws Exception {
        Address start = null;

        // Move backwards until all registers were accounted for.
        var unboundedRegisters = new HashSet<String>();
        int max = 0;
        boolean first = true;
        for (var instr: currentProgram.getListing().getInstructions(address, false)) {
            // Sanity check: Don't move too far back.
            if (max++ > 40) {
                return null;
            }

            // Check if all registers were accounted for.
            if (!first && unboundedRegisters.isEmpty()) {
                start = instr.getAddress().add(instr.getLength());
                break;
            }

            first = false;

            // Update current liveness of all registers.
            updateLiveness(instr, unboundedRegisters);
        }

        // Determine exact variant of branch.
        FooterType type = FooterType.UNCONDITIONAL;
        max = 0;
        for (var instr: currentProgram.getListing().getInstructions(start, false)) {
            // Should be very closeby
            if (max++ > 3) {
                break;
            }

            // Determine based on opcode.
            var formatted = instr.toString();
            if (formatted.startsWith("SETZ")) {
                type = FooterType.CONDITIONAL_SETZ;
                start = instr.getAddress();
                break;
            } else if (formatted.startsWith("SETNZ")) {
                type = FooterType.CONDITIONAL_SETNZ;
                start = instr.getAddress();
                break;
            } else if (formatted.startsWith("SETGE")) {
                type = FooterType.CONDITIONAL_SETGE;
                start = instr.getAddress();
                break;
            } else if (formatted.startsWith("SUB")) {
                type = FooterType.CONDITIONAL_UNKNOWN;
                start = instr.getAddress();
                break;
            } else if (formatted.startsWith("SET")) {
                throw new Exception("Unsupported %s : %s".formatted(instr.getAddress(), formatted));
            }
        }

        return new FooterInfo(start, address, type);
    }

    private void updateLiveness(Instruction instr, HashSet<String> unboundedRegisters) {
        for (var obj:  instr.getResultObjects()) {
            if (obj instanceof Register reg && GPR.containsKey(reg.getName())) {
                unboundedRegisters.remove(GPR.get(reg.getName()));
            }
        }

        for (var obj:  instr.getInputObjects()) {
            if (obj instanceof Register reg && GPR.containsKey(reg.getName())) {
                unboundedRegisters.add(GPR.get(reg.getName()));
            }
        }
    }

    private void deobfuscateCallRax(Address address,  List<String> comments) throws Exception {
        // track back
        var start = findCallStart(address);
        if (start == null) {
            println("Could not infer start of %s : CALL RAX".formatted(address));
            return;
        }

        var listing = currentProgram.getListing();

        var emulator = new EmulatorHelper(currentProgram);
        emulator.writeRegister("RIP", start.getOffset());

        // Execute till call
        int max = 0;
        var lastWithRax = start;
        while (emulator.getEmulator().getPC() != address.getOffset())  {
            if (max++ > 100) {
                println("Could not emulate CALL RAX expression for %s".formatted(address));
                return;
            }

            var instr = listing.getInstructionAt(address.getNewAddress(emulator.getEmulator().getPC()));
            if (instr != null) {
                var formatted = instr.toString();
                if (formatted.contains("RAX") || formatted.contains("EAX")) {
                    lastWithRax = instr.getAddress().add(instr.getLength());
                }
            }

            emulator.step(monitor);
        }

        var target = emulator.readRegister("RAX").longValue();

        var targetAddr = address.getNewAddress(target);
        var symbol = getSymbolAt(targetAddr);
        if (symbol != null) {
            var comment = "%s::%s".formatted(symbol.getParentNamespace(), symbol.getName());
            println("Inferred symbol at %s : %s".formatted(address, symbol));

            boolean add = false;
            if (!symbol.getName().startsWith("FUN_") && !symbol.getName().startsWith("SUB_")) {
                add = true;
            } else {
                var func = getFunctionAt(targetAddr);
                if (func != null) {
                    var first = func.getBody().getFirstRange().getMinAddress().getOffset();
                    var last = func.getBody().getLastRange().getMaxAddress().getOffset();

                    add = (last - first) >= 100;
                }
            }

            if (add) {
                comments.add("%s : %s".formatted(address, comment));
                setPreComment(address, "BIG " + comment);
            } else {
                setPreComment(address, comment);
            }
        }
    }

    private Address findCallStart(Address address) throws Exception {
        var listing = currentProgram.getListing();

        boolean first = true;
        int max = 0;
        var iterator = listing.getInstructions(address, false);
        while (max++ < 10 && iterator.hasNext()) {
            var instr = iterator.next();
            var formatted = instr.toString();

            if (first && formatted.equals("NOP")) {
                break;
            }

            first = false;

            if (formatted.startsWith("MOV RAX,qword ptr [")
                || formatted.startsWith("MOV EAX,dword ptr [")) {
                return instr.getAddress();
            }
        }

        return null;
    }
}
