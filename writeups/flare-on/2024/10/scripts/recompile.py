import os
import pathlib
import struct

class Reader:
    def __init__(self, code: bytes):
        self.code = code
        self.pc = 0

    def read_u8(self) -> int:
        self.pc += 1
        return self.code[self.pc - 1]

    def read_u16(self) -> int:
        result = struct.unpack_from(">H", self.code, self.pc)[0]
        self.pc += 2
        return result
    
    def read_u32(self) -> int:
        result = struct.unpack_from(">I", self.code, self.pc)[0]
        self.pc += 4
        return result
    

class Instruction:
    def __init__(self, offset, opcode, operand, pop_count, push_count):
        self.offset = offset
        self.opcode = opcode
        self.operand = operand
        self.pop_count = pop_count
        self.push_count = push_count

    def __str__(self) -> str:
        return f"L{self.offset:04x}: {self.opcode} {self.operand or ''}"
    
    def __repr__(self):
        return str(self)

def read_instruction(reader: Reader) -> Instruction:
    offset = reader.pc
    code = reader.read_u8()
    
    if code == 0x1:
        value = hex(reader.read_u16())
        if offset == 4-1:
            value = "(input[0] | input[1] << 8)"
        if offset == 11-1:
            value = "(input[2] | input[3] << 8)"
        if offset == 18-1:
            value = "(input[4] | input[5] << 8)"
        if offset == 25-1:
            value = "(input[6] | input[7] << 8)"
        if offset == 32-1:
            value = "(input[8] | input[9] << 8)"
        if offset == 39-1:
            value = "(input[10] | input[11] << 8)"
        if offset == 46-1:
            value = "(input[12] | input[13] << 8)"
        if offset == 53-1:
            value = "(input[14] | input[15] << 8)"
        return Instruction(offset, "push", value, 0, 1)
    elif code == 0x5:
        return Instruction(offset, "load", None, 1, 1)
    elif code == 0x6:
        return Instruction(offset, "store", None, 2, 0)
    elif code == 0x9:
        return Instruction(offset, "add", None, 2, 1)
    elif code == 0xd:
        return Instruction(offset, "mul", None, 2, 1)
    elif code == 0xe:
        return Instruction(offset, "jump", f"L{reader.read_u16():04x}", 0, 0)
    elif code == 0x10:
        return Instruction(offset, "jumpfalse", f"L{reader.read_u16():04x}", 1, 0)
    elif code == 0x11:
        return Instruction(offset, "equals", None, 2, 1)
    elif code == 0x12:
        return Instruction(offset, "lessthan", None, 2, 1)
    elif code == 0x14:
        return Instruction(offset, "greaterthan", None, 2, 1)
    elif code == 0x18:
        return Instruction(offset, "exit", None, 0, 0)
    elif code == 0x19:
        return Instruction(offset, "set_output", None, 1, 0)
    elif code == 0x1a:
        return Instruction(offset, "xor", None, 2, 1)
    elif code == 0x1b:
        return Instruction(offset, "or", None, 2, 1)
    elif code == 0x1c:
        return Instruction(offset, "and", None, 2, 1)
    elif code == 0x1d:
        return Instruction(offset, "rem", None, 2, 1)
    elif code == 0x1e:
        return Instruction(offset, "shift_left", None, 2, 1)
    elif code == 0x1f:
        return Instruction(offset, "shift_right", None, 2, 1)
    elif code == 0x21:
        return Instruction(offset, "rotate_uint32_right", None, 2, 1)
    elif code == 0x24:
        return Instruction(offset, "rotate_byte_left?", None, 2, 1)
    elif code == 0x25:
        return Instruction(offset, "rotate_byte_right?", None, 2, 1)

    return Instruction(offset, "db", hex(code), 0, 0)


def disassemble(reader: Reader):
    while reader.pc < len(reader.code):
        yield read_instruction(reader)


def disassemble_file(input_file: str) -> list[Instruction]:
    data = open(input_file, "rb").read()
    
    sig, data_size, code_offset, code_size = struct.unpack_from("IIII", data, 0)
    print("// signature:", hex(sig))
    print("// data_size:", hex(data_size))
    print("// code_offset:", hex(code_offset))
    print("// code_size:", hex(code_size))

    code = data[code_offset:code_offset+code_size]
    reader = Reader(code)
    
    instructions = []
    for instr in disassemble(reader):
        instructions.append(instr)
        if instr.opcode == "db":
            raise ValueError("Unsupported instruction " + str(instr))

    return instructions


class Expression:
    def __init__(self, instr: Instruction, args: list):
        self.instr = instr
        self.args = args
    
    def get_first_offset(self) -> int:
        if len(self.args) == 0:
            return self.instr.offset
        
        return self.args[0].get_first_offset()

    def __str__(self):
        if self.instr.operand:
            return f"{self.instr.opcode}[{self.instr.operand}]({', '.join(map(str, self.args))})"
        else:
            return f"{self.instr.opcode}({', '.join(map(str, self.args))})"
        
    def __repr__(self):
        return str(self)
    

def decompile(instructions: list[Instruction]) -> list[Expression]:
    result = []
    stack = []

    for instr in instructions:
        # Pop the arguments from the stack.
        args = []
        for _ in range(instr.pop_count):
            args.append(stack.pop())
        args.reverse()

        # Build new expression
        expr = Expression(instr, args)

        # If the opcode pushes a value, push it on the stack,
        # otherwise it is a statement.
        if instr.push_count == 1:
            stack.append(expr)
        else:
            result.append(expr)

    return result


def lift_expr(expr: Expression):    
    lifted_args = []
    for arg in expr.args:
        lifted_args.append(lift_expr(arg))
    
    if expr.instr.opcode == "push":
        return f"(uint64_t) ({expr.instr.operand})"
    if expr.instr.opcode == "load":
        return f"mem[{lifted_args[0]}]"
    if expr.instr.opcode == "store":
        return f"mem[{lifted_args[0]}] = {lifted_args[1]}"
    if expr.instr.opcode == "shift_left":
        return f"({lifted_args[0]} << {lifted_args[1]})"
    if expr.instr.opcode == "shift_right":
        return f"({lifted_args[0]} >> {lifted_args[1]})"
    if expr.instr.opcode == "xor":
        return f"({lifted_args[0]} ^ {lifted_args[1]})"
    if expr.instr.opcode == "or":
        return f"({lifted_args[0]} | {lifted_args[1]})"
    if expr.instr.opcode == "and":
        return f"({lifted_args[0]} & {lifted_args[1]})"
    if expr.instr.opcode == "add":
        return f"({lifted_args[0]} + {lifted_args[1]})"
    if expr.instr.opcode == "rem":
        return f"({lifted_args[0]} % {lifted_args[1]})"
    if expr.instr.opcode == "mul":
        return f"({lifted_args[0]} * {lifted_args[1]})"
    if expr.instr.opcode == "equals":
        return f"({lifted_args[0]} == {lifted_args[1]})"
    if expr.instr.opcode == "lessthan":
        return f"({lifted_args[0]} < {lifted_args[1]})"
    if expr.instr.opcode == "greaterthan":
        return f"({lifted_args[0]} > {lifted_args[1]})"
    if expr.instr.opcode == "rotate_uint32_right":
        return f"rotate_uint32_right({lifted_args[0]}, {lifted_args[1]})"    
    if expr.instr.opcode == "rotate_byte_left?":
        return f"rotate_byte_left({lifted_args[0]}, {lifted_args[1]})"
    if expr.instr.opcode == "rotate_byte_right?":
        return f"rotate_byte_right({lifted_args[0]}, {lifted_args[1]})"
    if expr.instr.opcode == "jumpfalse":
        return f"if (!{lifted_args[0]}) goto {expr.instr.operand}"
    if expr.instr.opcode == "jump":
        return f"goto {expr.instr.operand}"
    if expr.instr.opcode == "set_output":
        return f"output = {lifted_args[0]}"
    if expr.instr.opcode == "exit":
        return f"return output"

    raise ValueError("Unsupported opcode " + expr.instr.opcode)

harness_pre = '''
#include <stdio.h>
#include <string.h>
typedef unsigned long long uint64_t;

uint64_t rotate_byte_left(uint64_t a, uint64_t b) { return (a << b | a >> (8 - b)) & 0xFF; } 
uint64_t rotate_uint32_left(uint64_t a, uint64_t b) { return (a << b | a >> (32 - b)) & 0xFFFFFFFF; } 
uint64_t rotate_byte_right(uint64_t a, uint64_t b) { return (a >> b | a << (8 - b)) & 0xFF; } 
uint64_t rotate_uint32_right(uint64_t a, uint64_t b) { return (a >> b | a << (32 - b)) & 0xFFFFFFFF; }

uint64_t get(char* input) {
\tuint64_t mem[0x100] = { 0 };
\tuint64_t output = 0;

'''

harness_post = '''
}

int main() {
	char input[16] = {0};

	printf("%s\\n", input);
	printf("%llx\\n", get(input));
}
'''

def lift(expressions: list[Expression]) -> str:
    code = harness_pre
    for expr in expressions:
        lifted = lift_expr(expr)
        code += f"L{expr.get_first_offset():04x}:\t{lifted};\n"
    code += harness_post
    return code

for file in pathlib.Path("disk").glob("*.c4tb"):
    
    disassembly = disassemble_file(file)
    with open(file.with_suffix(".asm"), "w") as f:
        f.writelines(f"{i}\n" for i in disassembly)

    expressions = decompile(disassembly)
    with open(file.with_suffix(".ir"), "w") as f:
        f.writelines(f"{i}\n" for i in expressions)

    lifted = lift(expressions)
    with open(file.with_suffix(".c"), "w") as f:
        f.write(lifted)
