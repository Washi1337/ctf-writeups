import binascii
import os
import json
import shutil
import subprocess

dirs = os.listdir("antioch/")

crc_mapping = dict()

for d in dirs:
    base_dir = "antioch/" + d
    if not os.path.isdir(base_dir):
        continue

    data = json.loads(open(base_dir + "/json","r").read())
    if "author" not in data:
        continue

    crc = binascii.crc32(data["author"].encode() + b'\n')
    crc_mapping[crc] = d


table = [
    0xB59395A9, 0x1BB5AB29, 0xE,
    0x5EFDD04B, 0x3F8468C8, 0x12,
    0xECED85D0, 0x82D23D48, 0x2,
    0xD8549214, 0x00472EE5, 0x1D,
    0x2C2F024D, 0xC9A060AA, 0xC,
    0x018A5232, 0x0024D235, 0xD,
    0x72B88A33, 0x81576613, 0x14, 
    0x674404E2, 0x5169E129, 0xB,
    0x307A73B5, 0xE560E13E, 0x1C, 
    0x13468704, 0x2358E4A9, 0x15, 
    0x94F6471B, 0xD6341A53, 0x5, 
    0xEDA1CF75, 0xBAFA91E5, 0x18,
    0xBBAC124D, 0xA697641D, 0x19, 
    0xF707E4C3, 0xEF185643, 0x7, 
    0xD702596F, 0x79C28915, 0xA, 
    0x86A10848, 0x59108FDC, 0x1,
    0xD640531C, 0xEF3DE1E8, 0x13, 
    0x7B665DB3, 0xA3A903B0, 0x3, 
    0xAB1321CC, 0xEEEDEAD7, 0x4, 
    0x4F6066D8, 0x9C8A3D07, 0x11,
    0x256047CA, 0x4085BE9E, 0x9, 
    0x3FC91ED3, 0x379549C9, 0x8, 
    0xA424AFE4, 0xEF871347, 0x1B, 
    0x550901DA, 0x01FCEC6B, 0x10,
    0x10A29E2D, 0xE76056AA, 0x16, 
    0x56CBC85F, 0x356F1A68, 0xF, 
    0x80DFE3A6, 0x9D0AB536, 0x1E, 
    0xE657D4E1, 0xB4E9FD30, 0x17,
    0x2BA1E1D4, 0xBE66D918, 0x1A, 
    0x7D33089B, 0x67C1F585, 0x6,
]

entries = []
for i in range(0, len(table), 3):
    entries.append((table[i], table[i+1], table[i+2]))
entries = list(sorted(entries, key=lambda x: x[2]))[2:]

order = [crc_mapping[entry[0]] for entry in entries]

if not os.path.isdir("/tmp/recovered_filesystem"):
    os.mkdir("/tmp/recovered_filesystem")

for d in order:
    tar_file = f"antioch/{d}/layer.tar"
    print(tar_file)
    subprocess.call(["tar", "-xf", tar_file, "-C", "/tmp/recovered_filesystem"])