expenses = {}

print("======================================")
print("       💰 EXPENSE CATEGORY ANALYZER")
print("======================================")

n = int(input("How many expenses do you want to enter? "))

if n <= 0:
    print("❌ Invalid number of expenses!")

else:
    for i in range(n):

        print(f"\nExpense {i + 1}")

        category = input("Enter category: ").title()
        amount = float(input("Enter amount: ₹"))

        if amount < 0:
            print("❌ Amount cannot be negative.")
            continue

        if category in expenses:
            expenses[category] += amount
        else:
            expenses[category] = amount

    print("\n======================================")
    print("          📊 EXPENSE REPORT")
    print("======================================")

    total = 0

    for category, amount in expenses.items():
        print(f"{category:<20} : ₹{amount:.2f}")
        total += amount

    print("--------------------------------------")
    print(f"{'Total Expense':<20} : ₹{total:.2f}")

    if total > 0:
        highest_category = max(expenses, key=expenses.get)

        print("Highest Category      :", highest_category)
        print(f"Highest Spending      : ₹{expenses[highest_category]:.2f}")

    print("\n✅ Expense analysis completed!")
