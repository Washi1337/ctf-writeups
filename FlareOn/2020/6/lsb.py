with open("sprite.bmp", "rb") as f:
    data = f.read()

result = []
current = ""
for j in range(0x36, 0x100):
    bit = data[j] & 1
    current += str(bit)
    if len(current) == 7:
        result.append(current)
        current = ""

print(result)
print("".join([chr(int(x, 2)) for x in result]))