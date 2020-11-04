import struct 
import sys

BASE_ADDRESS = 0x8048000

file_name = sys.argv[1]
va = int(sys.argv[2],16)
code = sys.argv[3]

with open(file_name, "rb") as f:
    data = bytearray(f.read())

file_offset = va - BASE_ADDRESS

patch = open(code, "rb").read()
for i in range(len(patch)):
    data[file_offset + i] = patch[i]

with open(file_name + ".patched", "wb") as f:
    f.write(data)
