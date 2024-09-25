import struct 


class Reader:
    def __init__(self, code: bytes):
        self.code = code
        self.pc = 0

    def read_u8(self) -> int:
        b = self.code[self.pc]
        self.pc += 1
        return b

    def read_u32(self) -> int:
        v = struct.unpack_from("I", self.code, offset=self.pc)[0]
        self.pc += 4
        return v

    def read_u64(self) -> int:
        v = struct.unpack_from("Q", self.code, offset=self.pc)[0]
        self.pc += 8
        return v


class Instruction:
    def __init__(self, offset, opcode, operands):
        self.offset = offset
        self.opcode = opcode
        self.operands = operands

    def __str__(self):
        return f"L{self.offset:04x}: {self.opcode} {','.join(map(str, self.operands))}"


def pop64_reg(offset: int, opcode: int, reader: Reader) -> Instruction:
    reg = reader.read_u8() & 0xFF
    return Instruction(offset, "pop64", [f"r{reg}"])

def pop32_reg(offset: int, opcode: int, reader: Reader) -> Instruction:
    reg = reader.read_u8() & 0xFF
    return Instruction(offset, "pop32", [f"r{reg}"])

def push64_reg(offset: int, opcode: int, reader: Reader) -> Instruction:
    reg = reader.read_u8() & 0xFF
    return Instruction(offset, "push64", [f"r{reg}"])

def push32_reg(offset: int, opcode: int, reader: Reader) -> Instruction:
    reg = reader.read_u8() & 0xFF
    return Instruction(offset, "push32", [f"r{reg}"])

def push_sp(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "push", ["sp"])

def pop_sp(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "pop", ["sp"])

def push64_imm(offset: int, opcode: int, reader: Reader) -> Instruction:
    operand = reader.read_u64()
    return Instruction(offset, "push64", [hex(operand)])

def push32_imm(offset: int, opcode: int, reader: Reader) -> Instruction:
    operand = reader.read_u32()
    return Instruction(offset, "push32", [hex(operand)])

def sub64(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "sub64", [])

def sub32(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "sub32", [])

def add64(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "add64", [])

def add32(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "add32", [])

def load64(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "load64", [])

def load32(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "load32", [])

def store32(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "store32", [])

def and32(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "and32", [])

def xor32(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "xor32", [])

def or32(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "or32", [])

def jnz(offset: int, opcode: int, reader: Reader) -> Instruction:
    addr = reader.read_u32()
    return Instruction(offset, "jnz", [f"L{addr:04x}"])

def vmexit(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, "vmexit", [])

def db(offset: int, opcode: int, reader: Reader) -> Instruction:
    return Instruction(offset, f"db {opcode:04x}", [])

OPCODES = {
    0x16101: pop64_reg,
    0x16126: pop32_reg,
    0x1606a: push64_reg,
    0x16090: push32_reg,
    0x16194: push64_imm,
    0x161b1: push32_imm,
    0x1620a: push_sp,
    0x1626c: pop_sp,
    0x1631f: sub64,
    0x16337: sub32,
    0x162b1: add64,
    0x162c9: add32,
    0x163a5: xor32,
    0x16413: and32,
    0x16481: or32,
    0x16689: load64,
    0x1669f: load32,
    0x16707: store32,
    0x1676b: jnz,
    0x1604e: vmexit
}

def decode_instruction(reader: Reader) -> Instruction:
    offset = reader.pc
    raw = reader.read_u32()       
    handler = OPCODES.get(raw, db)
    return handler(offset, raw, reader)


code = open("vmcode.bin", "rb").read()
reader = Reader(code)
base_addr = 0x1678f

with open("disassembly.asm", "w") as f:
    while reader.pc < len(reader.code):
        instr = decode_instruction(reader)
        instr.offset += base_addr
        f.write(str(instr) + "\n")


# r13: PC
# r14: base address
# r15: (original) stack pointer

# 0x100 stack size


