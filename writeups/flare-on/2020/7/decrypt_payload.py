from arc4 import ARC4

# Layer 1

with open("encrypted_payload.bin", "rb") as f:
    data = f.read()
data = data[4:]

arc4 = ARC4("killervulture123")
data = arc4.decrypt(data)

with open("payload.bin", "wb") as f:
    f.write(data)

# Layer 2

with open("encrypted_response.bin", "rb") as f:
    data = f.read()

arc4 = ARC4("intrepidmango")
data = arc4.decrypt(data)

with open("accounts.txt", "wb") as f:
    f.write(data)