# Simple AI Chatbot (Rule-based beginner project)

print("🤖 AI Chatbot: Hello! I am your assistant.")
print("Type 'bye' to exit.\n")

while True:
    user = input("You: ").lower()

    if user == "hello":
        print("Bot: Hello! How can I help you?")
    
    elif user == "how are you":
        print("Bot: I am fine 😊 What about you?")
    
    elif user == "your name":
        print("Bot: I am a simple AI chatbot created in Python.")
    
    elif user == "help":
        print("Bot: You can ask me simple questions like hello, how are you, your name.")
    
    elif user == "bye":
        print("Bot: Goodbye! Have a nice day 👋")
        break
    
    else:
        print("Bot: Sorry, I don't understand that yet.")
