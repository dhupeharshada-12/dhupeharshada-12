MORSE_CODE = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..',
    'E': '.', 'F': '..-.', 'G': '--.', 'H': '....',
    'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..',
    'M': '--', 'N': '-.', 'O': '---', 'P': '.--.',
    'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
    'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
    'Y': '-.--', 'Z': '--..',
    '1': '.----', '2': '..---', '3': '...--',
    '4': '....-', '5': '.....', '6': '-....',
    '7': '--...', '8': '---..', '9': '----.',
    '0': '-----', ' ': '/'
}

REVERSE_MORSE = {value: key for key, value in MORSE_CODE.items()}

while True:
    print("\n===== MORSE CODE TRANSLATOR =====")
    print("1. Text to Morse")
    print("2. Morse to Text")
    print("3. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        text = input("Enter Text: ").upper()
        morse = " ".join(MORSE_CODE.get(ch, "?") for ch in text)
        print("Morse Code:", morse)

    elif choice == "2":
        morse = input("Enter Morse Code: ")
        text = "".join(REVERSE_MORSE.get(code, "?") for code in morse.split())
        print("Text:", text)

    elif choice == "3":
        print("Thank You!")
        break

    else:
        print("Invalid Choice!")
