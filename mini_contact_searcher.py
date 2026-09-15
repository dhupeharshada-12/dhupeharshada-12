contacts = {}


def add_contact():
    name = input("Enter name: ")
    phone = input("Enter phone number: ")

    contacts[name] = phone

    print("✅ Contact added successfully!")


def show_contacts():
    if not contacts:
        print("📱 No contacts available.")
        return

    print("\n========== CONTACTS ==========")

    for name, phone in contacts.items():
        print(f"{name} : {phone}")


def search_contact():
    keyword = input("Search name or phone: ").lower()

    found = False

    for name, phone in contacts.items():

        if keyword in name.lower() or keyword in phone:
            print("\n🔎 Contact Found!")
            print("Name :", name)
            print("Phone:", phone)

            found = True

    if not found:
        print("❌ Contact not found.")


while True:

    print("\n================================")
    print("       📞 MINI CONTACT SEARCHER")
    print("================================")
    print("1. Add Contact")
    print("2. Show Contacts")
    print("3. Search Contact")
    print("4. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        add_contact()

    elif choice == "2":
        show_contacts()

    elif choice == "3":
        search_contact()

    elif choice == "4":
        print("👋 Goodbye!")
        break

    else:
        print("❌ Invalid choice!")
