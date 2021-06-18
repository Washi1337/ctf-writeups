import struct
import sys 
import pefile

def rol_uint32(value, count):
    count &= 0x1f
    return ((value << count) | (value >> (0x20 - count))) & 0xFFFFFFFF

def ror_uint32(value, count):
    count &= 0x1f
    return (((value >> count)  & 0xFFFFFFFF) | (value << (0x20 - count)))  & 0xFFFFFFFF

def decrypt(data, pos, length, key):
    x = 0
    last_word = 0
    for i in range(pos, pos + length, 4):
        roll_count = (x << 2) & 0x1f
        current_word = struct.unpack_from("I", data, i)[0]
        if current_word == 0:
            break
        result = current_word ^ last_word ^ key
        x ^= 1
        result = rol_uint32(result, roll_count)
        struct.pack_into("I", data, i, result)
        last_word = current_word

def encrypt(data, pos, length, key):
    x = 0
    last_word = 0
    for i in range(pos, pos + length, 4):
        roll_count = (x << 2) & 0x1f
        result = struct.unpack_from("I", data, i)[0]
        result = ror_uint32(result, roll_count)
        x ^= 1
        current_word = result ^ last_word ^ key
        struct.pack_into("I", data, i, current_word)
        last_word = current_word

def decrypt_section(data, key):
    try:
        for i in range(0, len(data), 0x1000):
            roll_count = (i // 8) & 0x1f
            decrypt(data, i, 0x1000, rol_uint32(key, roll_count))
    except:
        pass 

if __name__ == "__main__":
    input_file = sys.argv[1]
    pe = pefile.PE(input_file)
    
    time_date_stamp = pe.FILE_HEADER.TimeDateStamp

    section_data = None
    for section in pe.sections:
        if section.Name == b".bss\x00\x00\x00\x00": 
            start_offset = section.VirtualAddress
            size = section.SizeOfRawData
            section_data = bytearray(section.get_data())
            break
    
    if not section_data:
        print("No .bss section found.")
    else:
        h = size + start_offset ^ (time_date_stamp ^ 0xb961999e)
        decrypt_section(section_data, h)
        with open(input_file + ".bss.bin", "wb") as f:
            f.write(section_data)