import struct 

def read_string(data, ptr):
    result = bytearray()
    while data[ptr] != 0:
        result.append(data[ptr])
        ptr += 1
    return result 


if __name__ == "__main__":
    with open("baseconfig.bin", "rb") as f:
        data = f.read()

    count = struct.unpack_from("I", data, 0)[0]
    ptr = 8
    for i in range(count):
        num = struct.unpack_from("I", data, ptr)[0] ^ 0xb961999e

        if struct.unpack_from("I", data, ptr + 4)[0] & 1 == 0:
            string1_offset = struct.unpack_from("Q", data, ptr + 0x8)[0]
            string2_offset = struct.unpack_from("Q", data, ptr + 0x10)[0]
            print("string1:", hex(string1_offset))
            print("string2:", hex(string2_offset))
        else:
            string1_offset = struct.unpack_from("I", data, ptr + 0x8)[0]
            string2_offset = struct.unpack_from("I", data, ptr + 0x10)[0]
            print(hex(num), "=", read_string(data, ptr + string1_offset))
            if string2_offset != 0:
                print("string2:", hex(ptr + string2_offset))

        ptr += 0x18
