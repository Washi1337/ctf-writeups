//Annotates all System.String literals in a NativeAOT compiled .NET binary based on the provided System.String MethodTable address.
//@author Washi (@washi_dev)
//@category FLARE
//@keybinding 
//@menupath 
//@toolbar 

import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.*;
import ghidra.program.model.lang.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.util.*;
import ghidra.program.model.reloc.*;
import ghidra.program.model.data.*;
import ghidra.program.model.block.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.scalar.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.nio.charset.StandardCharsets;
import ghidra.app.emulator.EmulatorHelper;
import ghidra.app.cmd.disassemble.*;
import ghidra.program.database.symbol.*;
import ghidra.features.base.values.GhidraValuesMap;
import java.util.*;

public class NativeAotStringsFinder extends GhidraScript {

    private static final CategoryPath CATEGORY_DOTNET   = new CategoryPath("/dotnet");
    private static final String       TYPENAME_STRING   = "System.String";
    private static final int          MAX_STRING_LENGTH = 1000;

    public void run() throws Exception {
        var listing = currentProgram.getListing();
        var stringType = getSystemStringType();

		var map = new GhidraValuesMap();
		var dataStartField = map.defineAddress("Hydrated Data Start", currentProgram);
		var dataLengthField = map.defineLong("Hydrated Data Length");
		var methodTableField = map.defineAddress("String MethodTable Address", currentProgram);

		var result = askValues("Hydrated Data Parameters", "Enter Hydrated data params", map);
		var dataStart = result.getAddress(dataStartField.getName());
		var dataLength = result.getLong(dataLengthField.getName());
		var methodTable = result.getAddress(methodTableField.getName());

        // Find all string MT references and create pointers.
        for (int i = 0; i < dataLength; i+=8) {
            var current = dataStart.add(i);
            
            if (getDataAt(current) == null) {
                if (getLong(current) == methodTable.getOffset()) {
                    createData(current, Pointer64DataType.dataType);
                }
            }
        }

        // Iterate over all xrefs to the System.String MT.
        var it = listing
            .getCodeUnitAt(methodTable)
            .getReferenceIteratorTo();

        while (it.hasNext()) {
            var reference = it.next();            
            if (reference.getReferenceType() != RefType.DATA)
                continue;

            var referrerAddress = reference.getFromAddress();

            // Is the referrer a symbol?
            var symbol = getSymbolAt(referrerAddress);
            if (symbol == null)
                continue;
            
            // Check if the length makes any sense.
            var length = getInt(referrerAddress.add(8));
            if (length <= 0 || length >= MAX_STRING_LENGTH)
                continue;

            // Verify there is a zero-terminator.
            var stringStart = referrerAddress.add(stringType.getLength());
            var stringEnd = stringStart.add(length * 2);
            if (getByte(stringEnd) != 0)
                continue;

            // Define string header and unicode data.
            clearListing​(referrerAddress, stringEnd);
            createData(referrerAddress, stringType);
            var s = createUnicodeString(stringStart);
            
            // Rename it.
            symbol = getSymbolAt(referrerAddress);
            symbol.setName("dn_" + s.getPathName(), SourceType.ANALYSIS);
        }
    }

    private DataType getSystemStringType() {
        var manager = currentProgram.getDataTypeManager();
        var result = manager.getDataType(CATEGORY_DOTNET, TYPENAME_STRING);

        if (result == null) {
            var newType = new StructureDataType​(CATEGORY_DOTNET, TYPENAME_STRING, 0);
            newType.add(Pointer64DataType.dataType, 0, "MethodTable", null);
            newType.add(IntegerDataType.dataType, 0, "Length", null);
            // we don't include the first char because it messes up the unicode view in the Listing.
            // newType.add(WideCharDataType.dataType, 0, "FirstChar", null);

            result = newType;
            manager.addDataType(result, DataTypeConflictHandler.DEFAULT_HANDLER);
        }

        return result;
    }

}
