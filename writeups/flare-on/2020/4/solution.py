#
# Decrypt strings
#

def rigmarole(d): 
    result = ""
    for i in range(0, len(d), 4):
        c1 = int(d[i:i+2], 16)
        c2 = int(d[i+2:i+4], 16)
        c = c1 - c2 
        result += chr(c)
    return result 

with open("F.L.txt", "r") as f:
    data = f.read().split('.')
    
for j in range(len(data)):
    print(j, rigmarole(data[j]))

#
# Decrypt data.
#

def decrypt(data, start, length):
    result = bytearray([0]*length)
    quean = 0
    for cattywampus in range(start, len(data), 4):
        result[quean] = int(data[cattywampus:cattywampus+2], 16) ^ key[quean % len(key)]
        quean += 1
        if quean == len(result):
            break
    return result

with open("F.T.txt", "r") as f:
    data = f.read()

key = bytes([0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE])
result = decrypt(data, 0, 168667)

with open("stomp.mp3", "wb") as f:
    f.write(result)

key = bytes(reversed(b"FLARE-ON"))
result = decrypt(data, 2, 285729)

with open("v.png", "wb") as f:
    f.write(result)
