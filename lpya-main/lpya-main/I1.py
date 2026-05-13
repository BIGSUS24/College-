# Experiment No - 01 Program
# Information Security

str1 = "Hello World"

print("\nAND ing Operation with 127 ==> ", end=" ")
for ch in str1:
    print(chr(ord(ch) & 127), end="")

print("\nXOR ing Operation with 127 ==> ", end=" ")
for ch in str1:
    print(chr(ord(ch) ^ 127), end="")

print("\nOR ing Operation with 127 ==> ", end=" ")
for ch in str1:
    print(chr(ord(ch) | 127), end="")

print()
