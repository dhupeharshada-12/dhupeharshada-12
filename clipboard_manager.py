import pyperclip

clipboard_history = []

while True:
    print("\n====== Clipboard Manager ======")
    print("1. Save Current Clipboard")
    print("2. View Clipboard History")
    print("3. Copy History Item")
    print("4. Clear History")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        text = pyperclip.paste()

        if text:
            clipboard_history.append(text)
            print("Clipboard content saved!")
        else:
            print("Clipboard is empty.")

    elif choice == "2":
        if not clipboard_history:
            print("No clipboard history found.")
        else:
            print("\nClipboard History:")
            for i, item in enumerate(clipboard_history, start=1):
                print(f"{i}. {item}")

    elif choice == "3":
        if not clipboard_history:
            print("No history available.")
        else:
            index = int(input("Enter item number to copy: ")) - 1

            if 0 <= index < len(clipboard_history):
                pyperclip.copy(clipboard_history[index])
                print("Copied to clipboard!")
            else:
                print("Invalid selection.")

    elif choice == "4":
        clipboard_history.clear()
        print("Clipboard history cleared.")

    elif choice == "5":
        print("Goodbye!")
        break

    else:
        print("Invalid choice!")
