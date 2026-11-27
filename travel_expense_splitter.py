import json

FILE_NAME = "travel_expenses.json"

def load_data():
    try:
        with open(FILE_NAME, "r") as file:
            return json.load(file)
    except (FileNotFoundError, json.JSONDecodeError):
        return {"members": [], "expenses": []}

def save_data(data):
    with open(FILE_NAME, "w") as file:
        json.dump(data, file, indent=4)

def add_member(data):
    name = input("Enter member name: ").strip()

    if not name:
        print("Name cannot be empty.")
        return

    if name.lower() in [m.lower() for m in data["members"]]:
        print("Member already exists.")
        return

    data["members"].append(name)
    save_data(data)
    print("Member added successfully!")

def add_expense(data):
    if not data["members"]:
        print("Add members first.")
        return

    title = input("Enter expense title: ").strip()

    try:
        amount = float(input("Enter expense amount: "))
        if amount <= 0:
            print("Amount must be greater than zero.")
            return
    except ValueError:
        print("Invalid amount.")
        return

    print("\nMembers:")
    for i, member in enumerate(data["members"], 1):
        print(f"{i}. {member}")

    payer = input("Enter the name of the person who paid: ").strip()

    if payer not in data["members"]:
        print("Member not found.")
        return

    expense = {
        "title": title,
        "amount": amount,
        "paid_by": payer
    }

    data["expenses"].append(expense)
    save_data(data)
    print("Expense recorded successfully!")

def display_expenses(data):
    if not data["expenses"]:
        print("No expenses recorded.")
        return

    print("\n--- Travel Expenses ---")

    for i, expense in enumerate(data["expenses"], 1):
        print(f"{i}. {expense['title']}")
        print(f"   Amount: Rs. {expense['amount']:.2f}")
        print(f"   Paid by: {expense['paid_by']}")

def calculate_balance(data):
    members = data["members"]
    expenses = data["expenses"]

    if not members:
        print("No members registered.")
        return

    total = sum(expense["amount"] for expense in expenses)

    share = total / len(members)

    paid = {member: 0.0 for member in members}

    for expense in expenses:
        paid[expense["paid_by"]] += expense["amount"]

    print("\n===== Expense Summary =====")
    print(f"Total Expenses: Rs. {total:.2f}")
    print(f"Per Person Share: Rs. {share:.2f}")

    print("\nIndividual Balances:")

    for member in members:
        balance = paid[member] - share

        if balance > 0:
            print(f"{member}: Receives Rs. {balance:.2f}")
        elif balance < 0:
            print(f"{member}: Owes Rs. {-balance:.2f}")
        else:
            print(f"{member}: Settled")

def main():
    data = load_data()

    while True:
        print("\n===== Travel Expense Splitter =====")
        print("1. Add Member")
        print("2. Add Expense")
        print("3. View Expenses")
        print("4. Calculate Balances")
        print("5. Exit")

        choice = input("Enter choice: ").strip()

        if choice == "1":
            add_member(data)

        elif choice == "2":
            add_expense(data)

        elif choice == "3":
            display_expenses(data)

        elif choice == "4":
            calculate_balance(data)

        elif choice == "5":
            print("Program closed.")
            break

        else:
            print("Invalid choice.")

if __name__ == "__main__":
    main()
