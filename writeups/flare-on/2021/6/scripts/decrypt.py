import os


def xor(a, b):
	result = bytearray()
	for i, x in enumerate(a):
		result.append(x ^ b[i % len(b)])
	return result


for name in os.listdir("decoded"):
	print(name)
	with open(f"decoded/{name}", "rb") as f:
		data = f.read()

	data = xor(data, b"meoow")

	with open(f"decrypted/{name}", "wb") as f:
		f.write(data)