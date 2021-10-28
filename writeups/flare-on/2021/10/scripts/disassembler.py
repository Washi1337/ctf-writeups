import pygob
import sys 

OPCODE_TABLE = {
    0x00: "nop",
    0x01: "mov",
    0x02: "???",

    0x05: "teq",
    0x06: "tgt",
    0x07: "tlt",
    0x08: "tcp",

    0x09: "add",
    0x0a: "sub",
    0x0b: "mul",
    0x0c: "div",
    0x0d: "not",

    0x10: "and",
    0x11: "or",
    0x12: "xor",
    0x13: "shl",
    0x14: "shr",
}

path = sys.argv[1]
data = open(path, "rb").read()
program = pygob.load(data)

print(program)
print("")


def instruction_str(instr):
    return f"{OPCODE_TABLE[instr.Opcode]} {instr.A0:>5} {instr.A1:>5} {instr.A2:>5}       {instr.Bm:>2} {instr.Cond:>2}"


def device_str(idx):
    if idx == 0:
        return "stdin"
    elif idx == 1:
        return "stdout"
    elif idx - 2 < len(program.Cpus):
        return f"cpu{idx - 2}"
    elif idx - 2 - len(program.Cpus) < len(program.ROMs):
        return f"rom{idx - 2 - len(program.Cpus)}"
    elif idx - 2 - len(program.Cpus) - len(program.ROMs) < len(program.RAMs):
        return f"ram{idx - 2 - len(program.Cpus) - len(program.ROMs)}"
    return f"device{idx}"


def reg_str(cpu_idx, reg_index):
    if reg_index <= 3:
        for link in program.Links:
            if link.LHDevice == cpu_idx + 2 and link.LHReg == reg_index:
                return f"{device_str(link.RHDevice)}.{reg_str(link.RHDevice - 2, link.RHReg)}"
        return f"reg{reg_index}"

    if reg_index == 4:
        return "acc"
    if reg_index == 5:
        return "dat"

    return f"unkreg{reg_index}"


def operand_str(cpu_idx, instr, op_idx):
    raw_op = instr.A0 if op_idx  == 0 else instr.A1
    if ((instr.Bm >> op_idx) & 1) != 0:
        return reg_str(cpu_idx, raw_op)
    return raw_op


def translate_instr(cpu_idx, instr):
    result = ""
    if instr.Cond != 0:
        result = f"if c == {instr.Cond} then "

    return result + translate_op(cpu_idx, instr)


def translate_op(cpu_idx, instr):
    if instr.Opcode == 1:
        return f"{reg_str(cpu_idx, instr.A1)} = {operand_str(cpu_idx, instr, 0)}"
    if instr.Opcode == 5:
        return f"c = {operand_str(cpu_idx, instr, 0)} == {operand_str(cpu_idx, instr, 1)}"
    if instr.Opcode == 6:
        return f"c = {operand_str(cpu_idx, instr, 0)} > {operand_str(cpu_idx, instr, 1)}"
    if instr.Opcode == 7:
        return f"c = {operand_str(cpu_idx, instr, 0)} < {operand_str(cpu_idx, instr, 1)}"
    if instr.Opcode == 8:
        return f"c = cmp({operand_str(cpu_idx, instr, 0)}, {operand_str(cpu_idx, instr, 1)})"
    if instr.Opcode == 9:
        return f"acc += {operand_str(cpu_idx, instr, 0)}"
    if instr.Opcode == 0xa:
        return f"acc -= {operand_str(cpu_idx, instr, 0)}"
    if instr.Opcode == 0xb:
        return f"acc *= {operand_str(cpu_idx, instr, 0)}"
    if instr.Opcode == 0xc:
        return f"acc /= {operand_str(cpu_idx, instr, 0)}"
    if instr.Opcode == 0xd:
        return f"acc = ~acc"
    if instr.Opcode == 0x10:
        return f"acc &= {operand_str(cpu_idx, instr, 0)}"
    if instr.Opcode == 0x11:
        return f"acc |= {operand_str(cpu_idx, instr, 0)}"
    if instr.Opcode == 0x12:
        return f"acc ^= {operand_str(cpu_idx, instr, 0)}"
    if instr.Opcode == 0x13:
        return f"acc <<= {operand_str(cpu_idx, instr, 0)}"
    if instr.Opcode == 0x14:
        return f"acc >>= {operand_str(cpu_idx, instr, 0)}"


print("RAMs")
for i in range(len(program.RAMs)):
    ram = program.RAMs[i]
    print(i, ram)

print("")

print("ROMS")
for i in range(len(program.ROMs)):
    rom = program.ROMs[i]
    print(i, rom)

print("")

print("LINKS")
for i in range(len(program.Links)):
    link = program.Links[i]
    print(i, link)
    
print("")


print("CPUS")
for i in range(len(program.Cpus)):
    cpu = program.Cpus[i]

    print(f"cpu{i}:")

    print("    disassembly:")
    for instr in cpu.Instructions:
        print("        " + instruction_str(instr))
    print("")

    print("    transpiled:")
    for instr in cpu.Instructions:
        print("        " + translate_instr(i, instr))

    print("")
