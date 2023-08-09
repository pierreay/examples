#!/usr/bin/env python3

from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

# * Encryption

data = b'secret data padd'

key = get_random_bytes(16)
cipher = AES.new(key, AES.MODE_ECB)
ciphertext = cipher.encrypt(data)

file_out = open("encrypted.bin", "wb")
file_out.write(ciphertext)
file_out.close()

# * Decryption

file_in = open("encrypted.bin", "rb")
ciphertext = file_in.read()
file_in.close()

cipher = AES.new(key, AES.MODE_ECB)
data = cipher.decrypt(ciphertext)

print("data={}".format(data))
