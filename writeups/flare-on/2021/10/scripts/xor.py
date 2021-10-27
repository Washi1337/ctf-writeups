import sys

path = sys.argv[1]
key = int(sys.argv[2])
buffer = bytearray(open(path, "rb").read())
for i in range(len(buffer)):
    buffer[i] = buffer[i] ^ key
print(buffer.decode())
