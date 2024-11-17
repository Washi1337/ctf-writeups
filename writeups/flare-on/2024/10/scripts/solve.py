from z3 import *

s = Solver()

key = [BitVec(f'key_{i}', 8) for i in range(16)]
second_half = key[8:]

# Obtained via bruteforcing the first half.
s.add(key[0] == ord("V"))
s.add(key[1] == ord("e"))
s.add(key[2] == ord("r"))
s.add(key[3] == ord("Y"))
s.add(key[4] == ord("D"))
s.add(key[5] == ord("u"))
s.add(key[6] == ord("m"))
s.add(key[7] == ord("B"))

sum3a = BitVecVal(1, 32)
sum3b = BitVecVal(0, 32)

for i in range(8):
	x = ZeroExt(24, second_half[i])
	sum3a = (sum3a + x)
	sum3b = (sum3b + sum3a)

s.add(sum3a == 0x374)
s.add(sum3b == 0xf91)

prime = 0x1000193
init = 0x811c9dc5

sum4 = BitVecVal(init, 32)
for i in range(16):
	x = key[i]
	sum4 *= prime
	sum4 ^= ZeroExt(24, x)
	
s.add(sum4 == 0x31f009d2)

result = s.check()
print(result)
if result == sat:
    model = s.model()
    final_key = bytearray(len(key))
    for i, k in enumerate(key):
        final_key[i] = model[k].as_long()
    print(final_key)

