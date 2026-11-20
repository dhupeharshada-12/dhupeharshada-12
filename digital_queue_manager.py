import json
import os

FILE_NAME = "queue_data.json"


def load_queue():
    if os.path.exists(FILE_NAME):
        try:
            with open(FILE_NAME, "r") as file:
                return json.load(file)
        except (json.JSONDecodeError, OSError):
            return []
    return []


def save_queue(queue):
    with open(FILE_NAME, "w") as file:
        json.dump(queue, file, indent=4)


def generate_token(queue):
    existing_tokens = [customer["token"] for customer in queue]
    return max(existing_tokens, default=0) + 1


def add_customer(queue):
    name = input("Enter Customer Name: ").strip()

    if not name:
        print("Name cannot be empty!")
        return

    token = generate_token(queue)

    customer = {
        "token": token,
        "name": name,
        "status": "Waiting"
    }

    queue.append(customer)
    save_queue(queue)

    print("\nCustomer added successfully!")
    print("Token Number:", token)


def view_queue(queue):
    print("\n===== CURRENT QUEUE =====")

    waiting = [customer for customer in queue
               if customer["status"] == "Waiting"]

    if not waiting:
        print("No customers are waiting.")
        return

    for customer in waiting:
        print(
            f"Token: {customer['token']} | "
            f"Name: {customer['name']} | "
            f"Status: {customer['status']}"
        )


def serve_customer(queue):
    for customer in queue:
        if customer["status"] == "Waiting":
            customer["status"] = "Served"
            save_queue(queue)

            print("\nCustomer Served Successfully!")
            print("Token:", customer["token"])
            print("Name:", customer["name"])
            return

    print("\nNo customers available to serve.")


def search_customer(queue):
    try:
        token = int(input("Enter Token Number: "))
    except ValueError:
        print("Invalid token number!")
        return

    for customer in queue:
        if customer["token"] == token:
            print("\nCustomer Found!")
            print("Token:", customer["token"])
            print("Name:", customer["name"])
            print("Status:", customer["status"])
            return

    print("Customer not found.")


def show_summary(queue):
    total = len(queue)
    waiting = sum(1 for c in queue if c["status"] == "Waiting")
    served = sum(1 for c in queue if c["status"] == "Served")

    print("\n===== QUEUE SUMMARY =====")
    print("Total Customers:", total)
    print("Waiting Customers:", waiting)
    print("Served Customers:", served)


def main():
    queue = load_queue()

    while True:
        print("\n===== DIGITAL QUEUE MANAGER =====")
        print("1. Add Customer")
        print("2. View Waiting Queue")
        print("3. Serve Next Customer")
        print("4. Search Customer")
        print("5. Queue Summary")
        print("6. Exit")

        choice = input("Enter Your Choice: ")

        if choice == "1":
            add_customer(queue)

        elif choice == "2":
            view_queue(queue)

        elif choice == "3":
            serve_customer(queue)

        elif choice == "4":
            search_customer(queue)

        elif choice == "5":
            show_summary(queue)

        elif choice == "6":
            print("Thank you for using Digital Queue Manager!")
            break

        else:
            print("Invalid choice! Try again.")


if __name__ == "__main__":
    main()
