import json
import os

FILE_NAME = "inventory_data.json"


def load_inventory():
    if os.path.exists(FILE_NAME):
        try:
            with open(FILE_NAME, "r") as file:
                return json.load(file)
        except (json.JSONDecodeError, OSError):
            print("Unable to load inventory. Starting with empty records.")

    return []


def save_inventory(inventory):
    with open(FILE_NAME, "w") as file:
        json.dump(inventory, file, indent=4)


def add_product(inventory):
    print("\n--- Add New Product ---")

    product_id = input("Enter Product ID: ").strip()

    if not product_id:
        print("Product ID cannot be empty!")
        return

    if any(p["id"] == product_id for p in inventory):
        print("Product ID already exists!")
        return

    name = input("Enter Product Name: ").strip()
    category = input("Enter Category: ").strip()

    if not name or not category:
        print("Name and category are required!")
        return

    try:
        quantity = int(input("Enter Quantity: "))
        price = float(input("Enter Price: "))

        if quantity < 0 or price < 0:
            print("Quantity and price cannot be negative!")
            return

    except ValueError:
        print("Please enter valid numeric values!")
        return

    product = {
        "id": product_id,
        "name": name,
        "category": category,
        "quantity": quantity,
        "price": price
    }

    inventory.append(product)
    save_inventory(inventory)

    print("Product added successfully!")


def display_products(inventory):
    print("\n--- Inventory Records ---")

    if not inventory:
        print("No products available.")
        return

    for product in inventory:
        print("\nProduct ID:", product["id"])
        print("Name:", product["name"])
        print("Category:", product["category"])
        print("Quantity:", product["quantity"])
        print("Price: ₹", product["price"])
        print("Total Value: ₹",
              product["quantity"] * product["price"])


def search_product(inventory):
    keyword = input("\nEnter product name: ").strip().lower()

    results = [
        p for p in inventory
        if keyword in p["name"].lower()
    ]

    if not results:
        print("Product not found!")
        return

    for product in results:
        print(
            f"\nID: {product['id']} | "
            f"Name: {product['name']} | "
            f"Quantity: {product['quantity']}"
        )


def update_stock(inventory):
    product_id = input("\nEnter Product ID: ").strip()

    for product in inventory:
        if product["id"] == product_id:

            try:
                amount = int(input("Enter stock change (+/-): "))

                if product["quantity"] + amount < 0:
                    print("Insufficient stock!")
                    return

                product["quantity"] += amount
                save_inventory(inventory)

                print("Stock updated successfully!")
                return

            except ValueError:
                print("Please enter a valid integer!")
                return

    print("Product ID not found!")


def low_stock_alert(inventory):
    threshold = 5

    print("\n--- Low Stock Alerts ---")

    low_stock = [
        p for p in inventory
        if p["quantity"] <= threshold
    ]

    if not low_stock:
        print("All products have sufficient stock.")
        return

    for product in low_stock:
        print(
            f"{product['name']} - "
            f"Only {product['quantity']} units left!"
        )


def inventory_summary(inventory):
    total_products = len(inventory)
    total_units = sum(p["quantity"] for p in inventory)
    total_value = sum(
        p["quantity"] * p["price"] for p in inventory
    )

    print("\n--- Inventory Summary ---")
    print("Total Products:", total_products)
    print("Total Units:", total_units)
    print("Total Inventory Value: ₹", round(total_value, 2))


def main():
    inventory = load_inventory()

    while True:
        print("\n====== SMART INVENTORY MANAGER ======")
        print("1. Add Product")
        print("2. Display Products")
        print("3. Search Product")
        print("4. Update Stock")
        print("5. Low Stock Alert")
        print("6. Inventory Summary")
        print("7. Exit")

        choice = input("\nEnter your choice: ")

        if choice == "1":
            add_product(inventory)

        elif choice == "2":
            display_products(inventory)

        elif choice == "3":
            search_product(inventory)

        elif choice == "4":
            update_stock(inventory)

        elif choice == "5":
            low_stock_alert(inventory)

        elif choice == "6":
            inventory_summary(inventory)

        elif choice == "7":
            print("Thank you for using Smart Inventory Manager!")
            break

        else:
            print("Invalid choice! Try again.")


if __name__ == "__main__":
    main()
