books = []

def add_book():
    title = input("Enter book title: ")
    author = input("Enter author name: ")

    book = {
        "title": title,
        "author": author,
        "status": "Available"
    }

    books.append(book)
    print("✅ Book added successfully!")


def show_books():
    if len(books) == 0:
        print("📚 No books available.")
        return

    print("\n========== BOOK LIST ==========")

    for i, book in enumerate(books, start=1):
        print(f"{i}. {book['title']} - {book['author']} "
              f"[{book['status']}]")


def search_book():
    keyword = input("Enter book title to search: ").lower()

    found = False

    for book in books:
        if keyword in book["title"].lower():
            print("\n📖 Book Found!")
            print("Title :", book["title"])
            print("Author:", book["author"])
            print("Status:", book["status"])
            found = True

    if not found:
        print("❌ Book not found.")


def issue_book():
    title = input("Enter book title to issue: ").lower()

    for book in books:
        if book["title"].lower() == title:

            if book["status"] == "Available":
                book["status"] = "Issued"
                print("✅ Book issued successfully!")
            else:
                print("⚠️ Book is already issued.")

            return

    print("❌ Book not found.")


def return_book():
    title = input("Enter book title to return: ").lower()

    for book in books:
        if book["title"].lower() == title:

            if book["status"] == "Issued":
                book["status"] = "Available"
                print("✅ Book returned successfully!")
            else:
                print("⚠️ This book is already available.")

            return

    print("❌ Book not found.")


while True:

    print("\n================================")
    print("     📚 PERSONAL LIBRARY")
    print("================================")
    print("1. Add Book")
    print("2. Show Books")
    print("3. Search Book")
    print("4. Issue Book")
    print("5. Return Book")
    print("6. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        add_book()

    elif choice == "2":
        show_books()

    elif choice == "3":
        search_book()

    elif choice == "4":
        issue_book()

    elif choice == "5":
        return_book()

    elif choice == "6":
        print("👋 Thank you for using Personal Library Tracker!")
        break

    else:
        print("❌ Invalid choice. Try again.")
