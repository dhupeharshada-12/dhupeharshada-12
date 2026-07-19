from datetime import datetime

print("========== Age Calculator ==========")

try:
    birth_date = input("Enter your Date of Birth (DD-MM-YYYY): ")

    dob = datetime.strptime(birth_date, "%d-%m-%Y")
    today = datetime.today()

    years = today.year - dob.year
    months = today.month - dob.month
    days = today.day - dob.day

    if days < 0:
        months -= 1
        previous_month = today.month - 1 if today.month > 1 else 12

        if previous_month in [1, 3, 5, 7, 8, 10, 12]:
            days += 31
        elif previous_month == 2:
            days += 28
        else:
            days += 30

    if months < 0:
        years -= 1
        months += 12

    print("\n========== RESULT ==========")
    print(f"Age: {years} Years, {months} Months, {days} Days")

except ValueError:
    print("Invalid date format! Please use DD-MM-YYYY.")
