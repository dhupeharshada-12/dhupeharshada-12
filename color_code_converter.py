def hex_to_rgb(hex_code):
    hex_code = hex_code.lstrip("#")
    return tuple(int(hex_code[i:i+2], 16) for i in (0, 2, 4))

def rgb_to_hex(r, g, b):
    return "#{:02X}{:02X}{:02X}".format(r, g, b)

while True:
    print("\n====== Color Code Converter ======")
    print("1. HEX to RGB")
    print("2. RGB to HEX")
    print("3. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        hex_code = input("Enter HEX Code (e.g. #FF5733): ")
        try:
            rgb = hex_to_rgb(hex_code)
            print("RGB Value:", rgb)
        except:
            print("Invalid HEX Code!")

    elif choice == "2":
        try:
            r = int(input("Enter Red (0-255): "))
            g = int(input("Enter Green (0-255): "))
            b = int(input("Enter Blue (0-255): "))

            if all(0 <= x <= 255 for x in (r, g, b)):
                print("HEX Code:", rgb_to_hex(r, g, b))
            else:
                print("RGB values must be between 0 and 255.")
        except ValueError:
            print("Please enter valid numbers.")

    elif choice == "3":
        print("Thank You!")
        break

    else:
        print("Invalid Choice!")
