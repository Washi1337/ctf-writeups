
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class DumpGoStringTable extends GhidraScript {

    public void run() throws Exception {
        var addressFactory = currentProgram.getAddressFactory();
        var space = addressFactory.getDefaultAddressSpace();
        var memory = currentProgram.getMemory();       

        var entriesAddress = memory.getLong(currentAddress);
        var entriesCount = memory.getLong(currentAddress.add(8));
                
        var rawValues = new long[(int) entriesCount * 2]; 
        memory.getLongs(space.getAddress(entriesAddress), rawValues);

        println("----");

        for (int i = 0; i < rawValues.length; i += 2) {
            var dataAddr = space.getAddress(rawValues[i]);
            var buffer = new byte[(int) rawValues[i + 1]];
            memory.getBytes(dataAddr, buffer);
            println('"' + new String(buffer, "UTF-8") + "\", ");
        }

        println("----");
    }
}
