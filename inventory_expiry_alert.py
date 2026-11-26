import json
from datetime import datetime, date

FILE_NAME = "inventory_expiry_data.json"

def load_data():
    try:
        with open(FILE_NAME, "r") as file:
            return json.load(file)
    except (FileNotFoundError, json.JSONDecodeError):
        return []

def save_data(items):
    with open(FILE_NAME, "w") as file:
        json.dump(items, file, indent=4)

def add_product(items):
    name = input("Enter product name: ").strip()

    if not name:
        print("Product name cannot be empty.")
        return

    try:
        quantity = int(input("Enter quantity: "))
        if quantity < 0:
            print("Quantity cannot be negative.")
            return

        expiry = input("Enter expiry date (YYYY-MM-DD): ")
        expiry_date = datetime.strptime(expiry, "%Y-%m-%d").date()

    except ValueError:
        print("Invalid quantity or date format.")
        return

    product = {
        "name": name,
        "quantity": quantity,
        "expiry_date": expiry_date.isoformat()
    }

    items.append(product)
    save_data(items)
    print("Product added successfully!")

def display_products(items):
    if not items:
        print("Inventory is empty.")
        return

    print("\n--- Inventory Records ---")

    for i, item in enumerate(items, 1):
        print(f"\nProduct {i}")
        print(f"Name: {item['name']}")
        print(f"Quantity: {item['quantity']}")
        print(f"Expiry Date: {item['expiry_date']}")

def check_expiry(items):
    if not items:
        print("No inventory records.")
        return

    today = date.today()
    found = False

    print("\n--- Expiry Alerts ---")

    for item in items:
        expiry = datetime.strptime(
            item["expiry_date"], "%Y-%m-%d"
        ).date()

        days_left = (expiry - today).days

        if days_left < 0:
            message = "EXPIRED"
        elif days_left <= 30:
            message = f"EXPIRING SOON ({days_left} days left)"
        else:
            continue

        print(f"{item['name']} | Qty: {item['quantity']} | {message}")
        found = True

    if not found:
        print("No expired or soon-to-expire products.")

def search_product(items):
    search = input("Enter product name: ").strip().lower()

    matches = [
        item for item in items
        if search in item["name"].lower()
    ]

    if not matches:
        print("Product not found.")
        return

    for item in matches:
        print(f"\nName: {item['name']}")
        print(f"Quantity: {item['quantity']}")
        print(f"Expiry: {item['expiry_date']}")

def main():
    items = load_data()

    while True:
        print("\n===== Inventory Expiry Alert System =====")
        print("1. Add Product")
        print("2. View Inventory")
        print("3. Check Expiry Alerts")
        print("4. Search Product")
        print("5. Exit")

        choice = input("Enter choice: ").strip()

        if choice == "1":
            add_product(items)

        elif choice == "2":
            display_products(items)

        elif choice == "3":
            check_expiry(items)

        elif choice == "4":
            search_product(items)

        elif choice == "5":
            print("Program closed.")
            break

        else:
            print("Invalid choice.")

if __name__ == "__main__":
    main()
