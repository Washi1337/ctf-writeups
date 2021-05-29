import struct 

first_part = b"w3lc0mE_t0_Th3_l"

key = [
    (0x4b695809, 0x0000000f, 0x674a1dea),
    (0xe35b9b24, 0x00000011, 0xad92774c),
    (0x71adcd92, 0x00000011, 0x56c93ba6),
    (0x38d6e6c9, 0x00000011, 0x2b649dd3),
    (0x5a844444, 0x0000000c, 0x8b853750),
    (0x2d422222, 0x0000000c, 0x45c29ba8),
    (0x16a11111, 0x0000000c, 0x22e14dd4),
    (0xcdbfbfa8, 0x00000015, 0x8f47df53),
    (0xe6dfdfd4, 0x00000015, 0x47a3efa9),
    (0xf36fefea, 0x00000015, 0x23d1f7d4),
    (0x79b7f7f5, 0x00000015, 0x11e8fbea),
    (0xfa34ccda, 0x0000000f, 0x96c3044c),
    (0x7d1a666d, 0x0000000f, 0x4b618226),
    (0xf8620416, 0x0000000f, 0xbb87b8aa),
    (0x7c31020b, 0x0000000f, 0x5dc3dc55),
    (0x78f7b625, 0x00000012, 0xb0d69793),
]

key_inv = list(reversed(key))

def rol(value, count):
    return ((value >> count) | (value << (32 - count))) & 0xFFFFFFFF

def chmod(k, c):
    x = (c + k[0]) & 0xFFFFFFFF
    x = rol(x, k[1])
    x = x ^ k[2]
    return x

def feistel_block(key, data, offset):
    left, right = struct.unpack_from("II", data, offset)
    
    for i in range(0x10):
        left, right = right, left ^ chmod(key[i], right)

    struct.pack_into("II", data, offset, right, left)

def feistel(key, data):
    for i in range(0, len(data), 8):
        feistel_block(key, data, i)

second_part = bytearray(bytes.fromhex("64a06002ea8a877d6ce97ce4823f2d0c8cb7b5ebcf354f424fad2b4920287ce0"))
feistel(key_inv, second_part)

modulus = 0xd1cc3447d5a9e1e6adae92faaea8770db1fab16b1568ea13c3715f2aeba9d84f
h = 0xc10357c7a53fa2f1ef4a5bf03a2d156039e7a57143000c8d8f45985aea41dd31
g = 0x480022d87d1823880d9e4ef56090b54001d343720dd77cbc5bc5692be948236c

real_c1 = 0x480022d87d1823880d9e4ef56090b54001d343720dd77cbc5bc5692be948236c
real_c2 = 0xd036c5d4e7eda23afceffbad4e087a48762840ebb18e3d51e4146f48c04697eb

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

h_inverse = modinv(h, modulus)
message = (real_c2 * h_inverse) % modulus
third_part = bytes(reversed(bytes.fromhex(hex(message)[2:])))

flag = first_part + second_part + third_part
print(flag)