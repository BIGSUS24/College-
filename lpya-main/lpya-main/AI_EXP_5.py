print("Simple Question and Answering Program")
print("=====================================")

print("\nYou can ask the following questions:")
print("1. Hi")
print("2. How are you?")
print("3. Are you working?")
print("4. What is your name?")
print("5. What did you do yesterday?")
print("6. Quit\n")

while True:
    question = input("Enter your question: ").lower()

    if question == "hi":
        print("Hello")

    elif question in ["how are you?", "how do you do?"]:
        print("I am fine")

    elif question in ["are you working?", "are you doing any job?"]:
        print("Yes, I am working")

    elif question == "what is your name?":
        print("My name is Emilia")
        name = input("Enter your name: ")
        print("Nice meeting you", name)

    elif question == "what did you do yesterday?":
        print("I saw Bahubali 5 times")

    elif question == "quit":
        print("Goodbye!")
        break

    else:
        print("I don't understand. Please choose from the given questions.")