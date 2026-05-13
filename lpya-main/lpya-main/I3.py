from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

# DES requires 8-byte key
key = b'8bytekey'

# Create DES object
cipher = DES.new(key, DES.MODE_ECB)

# Input message
plaintext = input("Enter Plain Text: ").encode()

# Padding because DES works on 8-byte blocks
padded_text = pad(plaintext, DES.block_size)

# Encryption
ciphertext = cipher.encrypt(padded_text)

print("Encrypted Text:", ciphertext)

# Decryption
cipher = DES.new(key, DES.MODE_ECB)

decrypted_text = unpad(cipher.decrypt(ciphertext), DES.block_size)

print("Decrypted Text:", decrypted_text.decode())