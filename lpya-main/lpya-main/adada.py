import math

# Encryption Function

def encryptMessage(key, message):
    ciphertext = [''] * key

    # Traverse through each column
    for col in range(key):
        position = col

        # Read characters at interval of key
        while position < len(message):
            ciphertext[col] += message[position]
            position += key

    return ''.join(ciphertext)


# Decryption Function

def decryptMessage(key, message):
    numOfColumns = math.ceil(len(message) / key)
    numOfRows = key
    numOfShadedBoxes = (numOfColumns * numOfRows) - len(message)

    plaintext = [''] * numOfColumns

    col = 0
    row = 0

    for symbol in message:
        plaintext[col] += symbol
        col += 1

        if (col == numOfColumns) or \
           (col == numOfColumns - 1 and row >= numOfRows - numOfShadedBoxes):
            col = 0
            row += 1

    return ''.join(plaintext)


# Driver Code

message = input("Enter Message: ")
key = int(input("Enter Key: "))

ciphertext = encryptMessage(key, message)
print("Encrypted Text:", ciphertext)

plaintext = decryptMessage(key, ciphertext)
print("Decrypted Text:", plaintext)
