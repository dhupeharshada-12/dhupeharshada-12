def encrypt(text, key):
    result = ""
    for char in text:
        result += chr(ord(char) + key)
    return result

def decrypt(text, key):
    result = ""
    for char in text:
        result += chr(ord(char) - key)
    return result

while True:
    print("\n====== TEXT ENCRYPTION & DECRYPTION ======")
    print("1. Encrypt Text")
    print("2. Decrypt Text")
    print("3. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        text = input("Enter Text: ")
        key = int(input("Enter Secret Key: "))
        encrypted = encrypt(text, key)
        print("Encrypted Text:", encrypted)

    elif choice == "2":
        text = input("Enter Encrypted Text: ")
        key = int(input("Enter Secret Key: "))
        decrypted = decrypt(text, key)
        print("Decrypted Text:", decrypted)

    elif choice == "3":
        print("Thank You!")
        break

    else:
        print("Invalid Choice!")
