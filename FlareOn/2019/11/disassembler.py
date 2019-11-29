import struct
import sys

if len(sys.argv) <= 1:
    print("Usage: disassembler.py input-file")
    sys.exit(1)

input_file_path = sys.argv[1]
VM_CODE =  open(input_file_path, "rb").read()
PC = 0

class Instruction:
    def __init__(self, address, opcode, operands):
        self.address = address
        self.opcode = opcode
        self.operands = operands

    def __str__(self):
        formatted = self.opcode.format(*self.operands)
        return "{0:04x}: {1}".format(self.address, formatted)

def read_next_instruction():
    global PC, VM_CODE
    opcode = VM_CODE[PC]
    PC += 1

    if 0 <= opcode < len(OPCODE_TABLE):
        read_handler = OPCODE_TABLE[opcode]
        if read_handler:
            return read_handler()
    
    return Instruction(PC - 1, "db {0:02x}", [opcode])

def read_instruction(mnemonic, operand_count):
    def read():
        global PC, VM_CODE

        address = PC - 1

        operands = []
        for i in range(operand_count):
            operands.append(VM_CODE[PC])
            PC += 1

        return Instruction(address, mnemonic, operands)
    return read

def read_opcode_11():
    global PC, VM_CODE
    instr = read_instruction("v{0} = [0x{1:08x}, 0x{2:08x}, 0x{3:08x}, 0x{4:08x}, 0x{5:08x}, 0x{6:08x}, 0x{7:08x}, 0x{8:08x}]", 1)()
    
    data = struct.unpack_from("=IIIIIIII", VM_CODE, PC)
        
    instr.operands.extend(reversed(data))
    PC += 0x20
    return instr


OPCODE_TABLE = [None] * 0x100
OPCODE_TABLE[0] = read_instruction("clearmemory", 0)
OPCODE_TABLE[0x1] = read_instruction("v{0} = vpmaddubsw(v{1}, v{2})", 3)
OPCODE_TABLE[0x2] = read_instruction("v{0} = vpmaddwd(v{1}, v{2})", 3)
OPCODE_TABLE[0x3] = read_instruction("v{0} = vpxor(v{1}, v{2})", 3)
OPCODE_TABLE[0x4] = read_instruction("v{0} = vpor(v{1}, v{2})", 3)
OPCODE_TABLE[0x5] = read_instruction("v{0} = vpand({1}, v{2})", 3)
OPCODE_TABLE[0x7] = read_instruction("v{0} = vpaddb(v{1}, v{2})", 3)
OPCODE_TABLE[0xB] = read_instruction("v{0} = vpaddd(v{1}, v{2})", 3)
OPCODE_TABLE[0x11] = read_opcode_11
OPCODE_TABLE[0x12] = read_instruction("v{0} = vpsrld(v{1}, {2})", 3)
OPCODE_TABLE[0x13] = read_instruction("v{0} = vpslld(v{1}, {2})", 3)
OPCODE_TABLE[0x14] = read_instruction("v{0} = vpshufb(v{1}, v{2})", 3)
OPCODE_TABLE[0x15] = read_instruction("v{0} = vpermd(v{1}, v{2})", 3)
OPCODE_TABLE[0x16] = read_instruction("v{0} = vpcmpeqb(v{1}, v{2})", 3)
OPCODE_TABLE[0xFF] = read_instruction("ret", 0)

instructions = []
while PC < len(VM_CODE):
    instructions.append(read_next_instruction())

print("offset   | op |   disassembly")
print("---------+----+--------------------------")
for i in instructions:
    formatted = i.opcode.format(*i.operands)
    print("{0:04x}:    | {1:02x} |   {2}".format(i.address, VM_CODE[i.address], formatted))
        