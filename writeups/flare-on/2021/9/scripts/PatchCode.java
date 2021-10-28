
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import static ghidra.program.model.listing.CodeUnit.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.*;
import java.util.*;
import java.io.*;

public class PatchCode extends GhidraScript {

    public String resolveFunction(long value) {
        var needle = String.format("%08X", value);
        System.out.println(needle);

        try {
            var file = new FileInputStream("hashes.txt");
            var scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                var line = scanner.nextLine();
                if (line.startsWith(needle)) {
                    println(line);
                    return line.substring(10);
                }
            }
        } catch (FileNotFoundException e) {
            println(e.toString());
        }

        return null;
    }

    public void run() throws Exception {
        long hash = askLong("Hash", "Enter hash");
        String functionName = resolveFunction(hash);

        var memory = currentProgram.getMemory();
        memory.setBytes(currentAddress, new byte[]
        {
            (byte) 0x90,
            (byte) 0xff, (byte) 0xd0
        });

        var listing = currentProgram.getListing();
        listing.setComment(currentAddress, PRE_COMMENT, functionName);
    }
}
