import json
import os
from datetime import datetime

FILE_NAME = "documents.json"


def load_documents():
    if os.path.exists(FILE_NAME):
        try:
            with open(FILE_NAME, "r") as file:
                return json.load(file)
        except (json.JSONDecodeError, OSError):
            print("Unable to load saved records.")
    return []


def save_documents(documents):
    with open(FILE_NAME, "w") as file:
        json.dump(documents, file, indent=4)


def add_document(documents):
    print("\n--- Add New Document ---")

    title = input("Enter document title: ").strip()
    category = input("Enter category: ").strip()
    description = input("Enter description: ").strip()

    if not title or not category:
        print("Title and category are required!")
        return

    document = {
        "id": len(documents) + 1,
        "title": title,
        "category": category,
        "description": description,
        "date_added": datetime.now().strftime("%Y-%m-%d")
    }

    documents.append(document)
    save_documents(documents)

    print("Document record added successfully!")


def view_documents(documents):
    print("\n--- All Documents ---")

    if not documents:
        print("No documents found.")
        return

    for doc in documents:
        print("\nDocument ID:", doc["id"])
        print("Title:", doc["title"])
        print("Category:", doc["category"])
        print("Description:", doc["description"])
        print("Date Added:", doc["date_added"])
        print("-----------------------------")


def search_document(documents):
    keyword = input("\nEnter title to search: ").strip().lower()

    results = [
        doc for doc in documents
        if keyword in doc["title"].lower()
    ]

    if not results:
        print("No matching documents found.")
        return

    print("\n--- Search Results ---")

    for doc in results:
        print(
            f"ID: {doc['id']} | "
            f"Title: {doc['title']} | "
            f"Category: {doc['category']}"
        )


def filter_by_category(documents):
    category = input("\nEnter category: ").strip().lower()

    results = [
        doc for doc in documents
        if doc["category"].lower() == category
    ]

    if not results:
        print("No documents in this category.")
        return

    print("\n--- Category Results ---")

    for doc in results:
        print(f"{doc['id']}. {doc['title']}")


def delete_document(documents):
    try:
        doc_id = int(input("\nEnter Document ID to delete: "))

        for doc in documents:
            if doc["id"] == doc_id:
                documents.remove(doc)
                save_documents(documents)
                print("Document record deleted successfully!")
                return

        print("Document ID not found.")

    except ValueError:
        print("Please enter a valid number.")


def show_summary(documents):
    print("\n--- Document Summary ---")

    print("Total Documents:", len(documents))

    categories = {}

    for doc in documents:
        category = doc["category"]
        categories[category] = categories.get(category, 0) + 1

    if not categories:
        print("No categories available.")
        return

    for category, count in categories.items():
        print(f"{category}: {count} document(s)")


def main():
    documents = load_documents()

    while True:
        print("\n====== SMART DOCUMENT MANAGER ======")
        print("1. Add Document")
        print("2. View All Documents")
        print("3. Search Document")
        print("4. Filter by Category")
        print("5. Delete Document")
        print("6. View Summary")
        print("7. Exit")

        choice = input("\nEnter your choice: ")

        if choice == "1":
            add_document(documents)

        elif choice == "2":
            view_documents(documents)

        elif choice == "3":
            search_document(documents)

        elif choice == "4":
            filter_by_category(documents)

        elif choice == "5":
            delete_document(documents)

        elif choice == "6":
            show_summary(documents)

        elif choice == "7":
            print("Thank you for using Smart Document Manager!")
            break

        else:
            print("Invalid choice! Please try again.")


if __name__ == "__main__":
    main()
