import struct

v5 = [0x00000000, 0x00000000, 0xb9b9bfbf, 0x04131000, 0x00000000, 0x00000000, 0xb9b9bfbf, 0x04131000]
v6 = [0x2f2f2f2f, 0x2f2f2f2f, 0x2f2f2f2f, 0x2f2f2f2f, 0x2f2f2f2f, 0x2f2f2f2f, 0x2f2f2f2f, 0x2f2f2f2f]
v10 = [0x01400140, 0x01400140, 0x01400140, 0x01400140, 0x01400140, 0x01400140, 0x01400140, 0x01400140]
v11 = [0x00011000, 0x00011000, 0x00011000, 0x00011000, 0x00011000, 0x00011000, 0x00011000, 0x00011000]
v12 = [0xffffffff, 0x0c0d0e08, 0x090a0405, 0x06000102, 0xffffffff, 0x0c0d0e08, 0x090a0405, 0x06000102]
v13 = [0xffffffff, 0xffffffff, 0x00000006, 0x00000005, 0x00000004, 0x00000002, 0x00000001, 0x00000000]

#
# Helper functions
#

def vector_to_bytes(vector):
    result = struct.pack("=IIIIIIII", *reversed(vector))
    return result

def bytes_to_vector(vector):
    result = list(reversed(struct.unpack("=IIIIIIII", vector)))
    return result

def print_vector(vector):
    print(" ".join([format(x, "08x") for x in vector]))

#
# AVX/2 emulating functions
#

def vpermd(input, permutation):
    result = [0] * len(input)

    for i in range(len(permutation)):
        if permutation[i] == 0xFFFFFFFF:
            result[i] = 0
        else:
            result[i] = input[len(input) - permutation[i] - 1]

    return result

def vpshufb(left, right):
    left = vector_to_bytes(left)
    right = vector_to_bytes(right)
    result = bytearray([0] * 32)

    for i in range(16):
        if ((right[i] & 0x80) == 0x80):
            result[i] = 0
        else:
            result[i] = left[right[i] & 0xF]
        if ((right[i+16] & 0x80) == 0x80):
            result[i+16] = 0
        else:
            result[i+16] = left[(right[i+16] & 0xF) +16]

    return bytes_to_vector(result)


def vpsrld(input, count):
    return [i >> count for i in input]

def vpslld(input, count):
    return [(i << count) & 0xFFFFFFFF for i in input]

def vpand(left, right):
    return [i & j for i,j in zip(left, right)]

def vpcmpeqb(left, right):
    result = [0] * len(left)
    for i in range(len(left)):
        b1 = struct.pack("=I", left[i])
        b2 = struct.pack("=I", right[i])
        b3 = [0] * 4
        for j in range(4):
            b3[j] = 0xFF if b1[j] == b2[j] else 0x00
        result[i] = struct.unpack("=I", bytes(b3))[0]
    return result

def vpaddb(left, right):
    result = [0] * len(left)
    for i in range(len(left)):
        b1 = struct.pack("=I", left[i])
        b2 = struct.pack("=I", right[i])
        b3 = [0] * 4
        for j in range(4):
            b3[j] = (b1[j] + b2[j]) & 0xFF
        result[i] = struct.unpack("=I", bytes(b3))[0]
    return result

def vpmaddubsw(left, right):
    result = [0] * len(left)
    for i in range(len(left)):
        b1 = struct.pack("=I", left[i])
        b2 = struct.pack("=I", right[i])

        r1 = (b1[0] * b2[0] + b1[1] * b2[1]) & 0xFFFF
        r2 = (b1[2] * b2[2] + b1[3] * b2[3]) & 0xFFFF

        result[i] = r1 | (r2 << 16)
    return result
        
    
def vpmaddwd(left, right):
    result = [0] * len(left)

    for i in range(len(left)):
        x0 = left[i] & 0xFFFF
        x1 = (left[i] >> 16) & 0xFFFF
        y0 = right[i] & 0xFFFF
        y1 = (right[i] >> 16) & 0xFFFF

        result[i] = (x0*y0 + x1*y1) & 0xFFFFFFFF
    
    return result

#
# Devirtualized hash function
#

def encode(v1):
    global v5, v6, v10, v11, v12, v13

    v7 = vpsrld(v1, 4)
    v7 = vpand(v7, v6)

    v8 = vpcmpeqb(v1, v6)
    v8 = vpcmpeqb(v1, v6)
    v7 = vpaddb(v8, v7)

    v7 = vpshufb(v5, v7)     
    v2 = vpaddb(v1, v7)     

    v7 = vpmaddubsw(v2, v10)
    v2 = vpmaddwd(v7, v11)

    v2 = vpshufb(v2, v12)
    v2 = vpermd(v2, v13)

    return v2

#
# Decode helper functions
#

def compute_shuffle_inverse(shuffle_vector):
    shuffle_vector = vector_to_bytes(shuffle_vector)

    result = bytearray([0xFF] * 32)
    for i in range(16):
        if shuffle_vector[i] != 0xFF:
            result[shuffle_vector[i]] = i
        if shuffle_vector[i+16] != 0xFF:
            result[shuffle_vector[i+16]+16] = i

    return bytes_to_vector(result)

def inverse_vpmaddwd_v11(vector):
    result = [0]*len(vector)
    for i in range(len(vector)):
        a = vector[i] & 0xFFF
        b = (vector[i] >> 12) & 0xFFF
        result[i] = b | (a << 16)
    return result

def inverse_vpmaddubsw_v10(vector):
    def extract(s):
        x = (s >> 6)
        y = s - (x << 6)
        return x, y
    
    result = [0]*len(vector)
    for i in range(len(vector)):
        a = vector[i] & 0xFFFF
        b = (vector[i] >> 16) & 0xFFFF
        x0, y0 = extract(a)
        x1, y1 = extract(b)
        result[i] = x0 | (y0 << 8) | (x1 << 16) | (y1 << 24)
        
    return result

#
# Decode function
#

def decode(v2):
    global v12
    v13_inverse = [0xFFFFFFFF, 0x00000005, 0x00000004, 0x00000003, 0xFFFFFFFF, 0x00000002, 0x00000001, 0x00000000]

    v2 = vpermd(v2, v13_inverse)
    v2 = vpshufb(v2, compute_shuffle_inverse(v12))
    v7 = inverse_vpmaddwd_v11(v2)
    v2 = inverse_vpmaddubsw_v10(v7)

    encoded = vector_to_bytes(v2)
    decoded = bytearray([0]*len(encoded))

    for i in range(len(encoded)):
        c = encoded[i]
        if 0x00 <= c < 0x1A:
            decoded[i] = (c - 0xBF) & 0xFF
        if 0x1A <= c < 0x34:
            decoded[i] = (c - 0xB9) & 0xFF
        if 0x34 <= c < 0x44:
            decoded[i] = (c - 0x04) & 0xFF

    return bytes_to_vector(decoded)


if __name__ == "__main__":
    print("--[Correctness test]--")
    v1 = bytes_to_vector(b"1234567890ABCDEFGHIJKLMNOPQRSTUV")
    print("Testing: ", end='')
    print_vector(v1)
    print("Encoded: ", end='')
    print_vector(encode(v1))
    print("Decoded: ", end='')
    print_vector(decode(encode(v1)))

    print()

    print("--[Actual solution]--")
    v2 = bytes_to_vector(b"\x70\x70\xB2\xAC\x01\xD2\x5E\x61\x0A\xA7\x2A\xA8\x08\x1C\x86\x1A\xE8\x45\xC8\x29\xB2\xF3\xA1\x1E\x00\x00\x00\x00\x00\x00\x00\x00")
    print("Serial (encoded): ", end='')
    print_vector(v2)
    serial = decode(v2)
    print("Serial (decoded): ", end='')
    print_vector(serial)
    print("Serial (ascii):  ", str(vector_to_bytes(serial))[2:-1])
