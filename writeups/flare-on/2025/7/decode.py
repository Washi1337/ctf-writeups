from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
import hashlib
import time
import socket
import os
import json


# ------------------
# Handshake
# ------------------

LOOKUP_TABLE =  b'\x52\x09\x6a\xd5\x30\x36\xa5\x38\xbf\x40\xa3\x9e\x81\xf3\xd7\xfb\x7c\xe3\x39\x82\x9b\x2f\xff\x87\x34\x8e\x43\x44\xc4\xde\xe9\xcb\x54\x7b\x94\x32\xa6\xc2\x23\x3d\xee\x4c\x95\x0b\x42\xfa\xc3\x4e\x08\x2e\xa1\x66\x28\xd9\x24\xb2\x76\x5b\xa2\x49\x6d\x8b\xd1\x25\x72\xf8\xf6\x64\x86\x68\x98\x16\xd4\xa4\x5c\xcc\x5d\x65\xb6\x92\x6c\x70\x48\x50\xfd\xed\xb9\xda\x5e\x15\x46\x57\xa7\x8d\x9d\x84\x90\xd8\xab\x00\x8c\xbc\xd3\x0a\xf7\xe4\x58\x05\xb8\xb3\x45\x06\xd0\x2c\x1e\x8f\xca\x3f\x0f\x02\xc1\xaf\xbd\x03\x01\x13\x8a\x6b\x3a\x91\x11\x41\x4f\x67\xdc\xea\x97\xf2\xcf\xce\xf0\xb4\xe6\x73\x96\xac\x74\x22\xe7\xad\x35\x85\xe2\xf9\x37\xe8\x1c\x75\xdf\x6e\x47\xf1\x1a\x71\x1d\x29\xc5\x89\x6f\xb7\x62\x0e\xaa\x18\xbe\x1b\xfc\x56\x3e\x4b\xc6\xd2\x79\x20\x9a\xdb\xc0\xfe\x78\xcd\x5a\xf4\x1f\xdd\xa8\x33\x88\x07\xc7\x31\xb1\x12\x10\x59\x27\x80\xec\x5f\x60\x51\x7f\xa9\x19\xb5\x4a\x0d\x2d\xe5\x7a\x9f\x93\xc9\x9c\xef\xa0\xe0\x3b\x4d\xae\x2a\xf5\xb0\xc8\xeb\xbb\x3c\x83\x53\x99\x61\x17\x2b\x04\x7e\xba\x77\xd6\x26\xe1\x69\x14\x63\x55\x21\x0c\x7d'

timestamp = time.strftime("%Y%m%d%H")
name = os.getlogin()
host = socket.gethostname()

plaintext = f"{timestamp}{name}@{host}"
bearer = bytes([LOOKUP_TABLE[(ord(c) ^ 0x5a + i + 1) & 0xFF] for i, c in enumerate(plaintext)])

print(bearer.hex())

# ------------------
# Decrypt handshake
# ------------------

INVERSE_LOOKUP_TABLE = bytearray(len(LOOKUP_TABLE))
for i in range(len(LOOKUP_TABLE)):
    INVERSE_LOOKUP_TABLE[LOOKUP_TABLE[i]] = i

bearer = bytes.fromhex("e4b8058f06f7061e8f0f8ed15d23865ba2427b23a695d9b27bc308a26d") # From PCAP
plaintext = bytes([((INVERSE_LOOKUP_TABLE[b] - (i + 1)) & 0xFF) ^ 0x5a for i, b in enumerate(bearer)]).decode()
timestamp_length = len("YYYYmmddHH")
timestamp = plaintext[:timestamp_length]
[user, host] = plaintext[timestamp_length:].split('@')

print(f"{timestamp=}")
print(f"{user=}")
print(f"{host=}")


# ------------------
# Decrypt sysinfo
# ------------------

received_user = "peanut"

def construct_aes_key(userhost, user, hour: int):
    h1 = hashlib.sha256(userhost.encode()).digest()
    h2 = hashlib.sha256(f"{user}{hour:02}".encode()).digest()
    return bytes(a ^ b for a, b in zip(h1, h2))

def aes_decrypt(encrypted_data: bytes, user, host, received_user, hour) -> bytes:
    iv = bytes.fromhex("00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F")
    key = construct_aes_key(f"{user}@{host}", received_user, hour)
    cipher = AES.new(key, AES.MODE_CBC, iv=iv)
    return unpad(cipher.decrypt(encrypted_data), 16)

data = bytes.fromhex("3b001a3d06733da13984c89fe99ffc936128497575d01feab284eba5da0bd909d11be82b443705dc61cd307635ff27998d65e911837716ed7c190504472831cc78c19f578ff339cfa7e046695a98fcb4bfaf4a586294a86c72113d06733e3542c14dc0451af3fc79b1f1a2e9b26e4723a21a5b632b1d434e51ab070cb53373fcff024ba26f9cfd673284fc47bd768e2262a394559ff0194b9b4103951f14bcb8")
print(aes_decrypt(data, user, host, received_user, 6))

# ------------------
# Decrypt packets
# ------------------

candidate_passwords = ["peanut", "TheBoss@THUNDERNODE", "miami"]

base_dir = "./dumps/http-objects"
for file in sorted(os.listdir(base_dir)):
    with open(f"{base_dir}/{file}", "rb") as f:
        encrypted_json = json.load(f)
        if "d" not in encrypted_json:
            continue

    encrypted_data = bytes.fromhex(encrypted_json["d"])
    print(f"--- {file} ---")
    for candidate in candidate_passwords:
        try:
            decrypted_data = aes_decrypt(encrypted_data, user, host, candidate, 6)
            print(decrypted_data.decode())
            with open(f"./dumps/decrypted/{file}", "wb") as f:
                f.write(decrypted_data)
            break
        except ValueError as e:
            # print(f"ERROR password {candidate} failed: {e}")
            pass
    else:
        print("ERROR Failed to decrypt")
