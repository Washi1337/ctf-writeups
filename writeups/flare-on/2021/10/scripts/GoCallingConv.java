
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class GoCallingConv extends GhidraScript {

    private static final DataType UNDEF = new Undefined8DataType();
    private static final DataType PTR = new PointerDataType(new Undefined8DataType());

    public void run() throws Exception {
        var func = getFunctionContaining​(currentAddress);
        if (func == null) {
            popup("Not at a function!");
            return;
        }
        
        int parameterCount = askInt("Parameters", "Enter number of parameters.");

        // boolean hasReturnValue = askYesNo("Return value", "Does the function return a value?");
        
        var parameters = new ArrayList<Variable>();
        int offset = 1;

        for (int i = 0; i < parameterCount; i++) {
            int parameterAddress = (i+offset)*8;
            println(String.format("Adding parameter at [0x:%x]", parameterAddress));

            var parameter = new ParameterImpl(
                "param_" + i, 
                UNDEF, 
                parameterAddress, 
                currentProgram);
            parameters.add(parameter);
        }

        int returnValueCount = askInt("Return value", "Enter number of return values.");
        for (int i = 0; i < returnValueCount; i++) {
            int returnAddress = (parameterCount+i+2)*8;
            println(String.format("Adding return value at [0x:%x]", returnAddress));

            var returnValue = new ParameterImpl(
                "return_" + i, 
                PTR, 
                returnAddress, 
                currentProgram);
            parameters.add(returnValue);
        }

        func.replaceParameters(
            Function.FunctionUpdateType.CUSTOM_STORAGE, 
            true, 
            SourceType.USER_DEFINED, 
            parameters.toArray(new Variable[parameters.size()]));
        func.setReturnType(DataType.VOID, 
            SourceType.USER_DEFINED);
        // int returnAddress = (parameters.size() + 1 + offset) * 8;
        
        // if (askYesNo("Return type", String.format("Add return type at Stack[0x%x]?", returnAddress))) {
        //     println(String.format("Adding return value at [0x:%x]", returnAddress));
        //     func.setReturn(
        //         VOID_PTR, 
        //         new VariableStorage(currentProgram, returnAddress, 8),
        //         SourceType.USER_DEFINED
        //     );
        // }
    }
}