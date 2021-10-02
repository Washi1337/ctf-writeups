import struct 
import os
from Crypto.Cipher import ARC4

data = [
    0x7465726365732041,
    0x6c206f6e20736920,
    0x2061207265676e6f,
    0x6f20746572636573,
    0x656d6f732065636e,
    0x776f6e6b20656e6f,
    0x74692073
]

rc4_key = b"".join([struct.pack("Q", d) for d in data])[:0x34]

def KSA(key):
    keylength = len(key)
    S = list(range(256))
    j = 0
    for i in range(256):
        j = (j + S[i] + key[i % keylength]) % 256
        S[i], S[j] = S[j], S[i]  # swap

    return S

def PRGA(S):
    i = 0
    j = 0
    old_K = 0
    while True:
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        K = S[(S[i] + S[j]) % 256]
        yield K ^ old_K
        old_K = K

def RC4(key):
    S = KSA(key)
    return PRGA(S)

def decrypt(ct, key):
    cipher = RC4(key)
    pt = bytearray()
    for c in ct:
        pt.append(c ^ next(cipher))
    return pt

INPUT_DIR = "Documents"
OUTPUT_DIR = "Result"

for name in os.listdir(INPUT_DIR):
    ciphertext = open(f"{INPUT_DIR}/{name}", "rb").read()
    plaintext = decrypt(ciphertext, rc4_key).rstrip(b'\00')
    open(f"{OUTPUT_DIR}/{name}", "wb").write(plaintext)
