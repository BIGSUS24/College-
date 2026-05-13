# RSA Algorithm Implementation

# Step 1: Choose Prime Numbers
p = 53
q = 59

# Step 2: Calculate n
n = p * q
print("Value of n =", n)

# Step 3: Calculate Euler Totient Function
phi = (p - 1) * (q - 1)
print("Phi =", phi)

# Step 4: Choose e
# e should be coprime with phi

e = 3
print("Public Key (e,n) =", (e, n))

# Step 5: Calculate d
# d = modular inverse of e

d = 2011
print("Private Key (d,n) =", (d, n))

# Message
msg = 89
print("Original Message =", msg)

# Encryption
cipher = pow(msg, e, n)
print("Encrypted Message =", cipher)

# Decryption
plain = pow(cipher, d, n)
print("Decrypted Message =", plain)