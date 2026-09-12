print("======================================")
print("       💧 WATER INTAKE TRACKER")
print("======================================")

name = input("Enter your name: ")

goal = float(input("Enter your daily water goal (ml): "))

if goal <= 0:
    print("❌ Goal must be greater than 0.")
else:
    total_water = 0
    entries = []

    print("\nEnter water intake in ml.")
    print("Type 0 when you are finished.\n")

    while True:
        amount = float(input("Water intake: "))

        if amount == 0:
            break

        if amount < 0:
            print("❌ Amount cannot be negative.")
            continue

        entries.append(amount)
        total_water += amount

    progress = (total_water / goal) * 100

    print("\n======================================")
    print("          💧 DAILY REPORT")
    print("======================================")

    print("Name          :", name)
    print("Entries       :", len(entries))
    print(f"Total Intake  : {total_water:.0f} ml")
    print(f"Daily Goal    : {goal:.0f} ml")
    print(f"Progress      : {progress:.1f}%")

    if total_water >= goal:
        print("Status        : 🎉 Goal Completed!")
    else:
        remaining = goal - total_water
        print("Status        : 💪 Keep Going!")
        print(f"Remaining     : {remaining:.0f} ml")

    print("\nStay hydrated and take regular breaks! 😊")
