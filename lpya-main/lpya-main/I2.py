import math


def encryptMessage(key, message):
    ciphertext = [''] * key

    for col in range(key):
        position = col

        while position < len(message):
            ciphertext[col] += message[position]
            position += key

    return ''.join(ciphertext)


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


myMessage = 'Transposition Cipher'
myKey = 3

ciphertext = encryptMessage(myKey, myMessage)
print("Cipher Text is ==> ", ciphertext)

pt = decryptMessage(myKey, ciphertext)
print("Plain Text is ==> ", pt)
