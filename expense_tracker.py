class ExpenseTracker:
    def __init__(self):
        self.expenses = []

    def add_expense(self):
        category = input("Enter Category: ")
        amount = float(input("Enter Amount: "))
        self.expenses.append((category, amount))
        print("Expense Added Successfully!\n")

    def view_expenses(self):
        if not self.expenses:
            print("No Expenses Found!\n")
            return

        print("\n------ Expense List ------")
        total = 0

        for i, expense in enumerate(self.expenses, start=1):
            print(f"{i}. {expense[0]} - ₹{expense[1]:.2f}")
            total += expense[1]

        print("--------------------------")
        print(f"Total Expense: ₹{total:.2f}\n")


tracker = ExpenseTracker()

while True:
    print("===== Expense Tracker =====")
    print("1. Add Expense")
    print("2. View Expenses")
    print("3. Exit")

    choice = input("Enter Choice: ")

    if choice == "1":
        tracker.add_expense()

    elif choice == "2":
        tracker.view_expenses()

    elif choice == "3":
        print("Thank You!")
        break

    else:
        print("Invalid Choice!\n")
