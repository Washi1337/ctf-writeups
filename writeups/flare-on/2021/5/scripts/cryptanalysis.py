import os
import itertools

# M1 ^ K = C1
# M2 ^ K = C2
# C2 ^ C1 = (M1 ^ K) ^ (M2 ^ K) = M1 ^ M2  
#   if result == 0 then M1 == M2 (useful for detecting padding)
#   if result == M1 then |M1| > |M2|
#   if result == M2 then |M2| > |M1|

BASE_DIR = "Documents"
RESULT_DIR = "Cryptanalysis"

def xor(data1, data2):
    return bytes([a^b for a,b in zip(data1, data2)])

# Read all files.
messages = dict()
for name in os.listdir(BASE_DIR):
    with open(f"{BASE_DIR}/{name}", "rb") as f:
        messages[name] = f.read()


# Find shortest message.
best_match = 9999
name1, name2 = (None, None)
for (n1, d1), (n2, d2) in itertools.combinations(messages.items(), 2):    
    xored = xor(d1, d2)
    for i in range(len(d1) - 1, -1, -1):
        if d1[i] != d2[i]:
            if best_match > i:
                best_match = i
                name1, name2 = n1, n2
            break

print(f"Found best candidates: {name1} and {name2} ({best_match} non-matching chars)")

# Decrypt (parts of the) messages.
m2 = messages[name2]
for n1, m1 in messages.items():
    xored = xor(m1, m2).rstrip(b'\x00')
    with open(f"{RESULT_DIR}/{n1}","wb") as f:
        f.write(xored)

