from decrypt_bss import decrypt
from string_decrypter import compute_sid_hash
from malduck import serpent

data = bytearray(open("../artifacts/DiMap.bin", "rb").read())

sid = "S-1-5-21-3823548243-3100178540-2044283163-1006"
seed = compute_sid_hash(sid)
decrypt(data, 0, len(data), seed & 0xFFFFFFFF)

data = serpent.cbc.decrypt(b"GSPyrv3C79ZbR0k1", data)
open("../artifacts/DiMap_decrypted.bin", "wb").write(data)