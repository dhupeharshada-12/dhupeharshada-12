import random

quotes = [
    "Success is the sum of small efforts repeated daily.",
    "Believe in yourself and all that you are.",
    "Dream big and dare to fail.",
    "Every day is a new opportunity to learn.",
    "Stay positive, work hard, and make it happen.",
    "The best way to predict the future is to create it.",
    "Consistency is more important than perfection.",
    "Never stop learning because life never stops teaching."
]

print("========== Random Quote Generator ==========")

while True:
    print("\n1. Generate Quote")
    print("2. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        print("\nQuote of the Day:")
        print(random.choice(quotes))

    elif choice == "2":
        print("Thank you!")
        break

    else:
        print("Invalid choice! Please try again.")
