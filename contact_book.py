contacts = {}

while True:
    print("\n===== Contact Book =====")
    print("1. Add Contact")
    print("2. View Contacts")
    print("3. Search Contact")
    print("4. Delete Contact")
    print("5. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        name = input("Enter Name: ")
        number = input("Enter Phone Number: ")

        contacts[name] = number

        print("Contact Added!")

    elif choice == "2":

        if len(contacts) == 0:
            print("No Contacts Found")

        else:
            print("\nSaved Contacts:")

            for name, number in contacts.items():
                print(name, ":", number)

    elif choice == "3":
        search = input("Enter Name to Search: ")

        if search in contacts:
            print("Phone Number:", contacts[search])

        else:
            print("Contact Not Found")

    elif choice == "4":
        delete = input("Enter Name to Delete: ")

        if delete in contacts:
            del contacts[delete]

            print("Contact Deleted")

        else:
            print("Contact Not Found")

    elif choice == "5":
        print("Goodbye!")
        break

    else:
        print("Invalid Choice")
