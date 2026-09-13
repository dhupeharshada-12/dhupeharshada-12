notes = []


def add_note():
    title = input("Enter note title: ")
    content = input("Enter note: ")

    note = {
        "title": title,
        "content": content
    }

    notes.append(note)
    print("✅ Note added successfully!")


def show_notes():
    if not notes:
        print("📝 No notes available.")
        return

    print("\n========== YOUR NOTES ==========")

    for i, note in enumerate(notes, start=1):
        print(f"\n{i}. {note['title']}")
        print("   " + note["content"])


def search_notes():
    keyword = input("Enter keyword to search: ").lower()

    found = False

    for note in notes:
        if (keyword in note["title"].lower()
                or keyword in note["content"].lower()):

            print("\n🔎 Note Found")
            print("Title  :", note["title"])
            print("Content:", note["content"])

            found = True

    if not found:
        print("❌ No matching note found.")


while True:

    print("\n================================")
    print("       📝 NOTES MANAGER")
    print("================================")
    print("1. Add Note")
    print("2. View Notes")
    print("3. Search Notes")
    print("4. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        add_note()

    elif choice == "2":
        show_notes()

    elif choice == "3":
        search_notes()

    elif choice == "4":
        print("👋 Thank you for using Notes Manager!")
        break

    else:
        print("❌ Invalid choice. Please try again.")
