spain     = 9   + 7  + 4
singapore = 19  + 25 + 6
indonesia = 0   + 2  + 1

s = spain + singapore + indonesia

key = bytearray([
    0x45, 
    0x34, 
    0x51, 
    0x35, 
    0x64,
    0x36,
    0x66, 
    0x60, 
    115, 
    52,
    108,
    68,
    0x35,
    s
])

target = "b3c20caa9a1a82add9503e0eac43f741793d2031eb1c6e830274ed5ea36238bf"

import hashlib
if hashlib.sha256(key).hexdigest() == target:
    print("found", key)
