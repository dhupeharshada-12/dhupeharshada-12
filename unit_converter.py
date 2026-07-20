def length_converter():
    print("\nLength Converter")
    print("1. Kilometers to Meters")
    print("2. Meters to Kilometers")

    choice = input("Enter choice: ")

    if choice == "1":
        km = float(input("Enter Kilometers: "))
        print(f"{km} km = {km * 1000} meters")

    elif choice == "2":
        m = float(input("Enter Meters: "))
        print(f"{m} meters = {m / 1000} km")

    else:
        print("Invalid Choice!")

while True:
    print("\n===== UNIT CONVERTER =====")
    print("1. Length Converter")
    print("2. Exit")

    option = input("Enter your option: ")

    if option == "1":
        length_converter()

    elif option == "2":
        print("Thank You!")
        break

    else:
        print("Invalid Option!")
