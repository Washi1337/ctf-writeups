from string_decrypter import *

original_sid = "S-1-5-21-3823548243-3100178540-2044283163-1006"
decrypter = StringDecrypter(original_sid)

for i in range(0xff):
    idx = (i << 8) | i
    x = decrypter.get_string(idx, 3)
    if x == "DiMap":
        print(x, hex(idx))