from datetime import datetime

activities = []


def record_activity():
    username = input("Enter username: ").strip()

    if not username:
        print("Username cannot be empty!")
        return

    print("1. Login Successful")
    print("2. Login Failed")

    choice = input("Select login status: ")

    if choice == "1":
        status = "Successful"
    elif choice == "2":
        status = "Failed"
    else:
        print("Invalid status selection!")
        return

    activity = {
        "username": username,
        "status": status,
        "time": datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    }

    activities.append(activity)
    print("Login activity recorded successfully!")


def view_activities():
    if not activities:
        print("No login activities recorded.")
        return

    print("\n===== LOGIN ACTIVITY HISTORY =====")

    for index, activity in enumerate(activities, start=1):
        print(f"\nRecord Number: {index}")
        print(f"Username: {activity['username']}")
        print(f"Status: {activity['status']}")
        print(f"Time: {activity['time']}")


def search_user():
    username = input("Enter username to search: ").strip()

    found = False

    for activity in activities:
        if activity["username"].lower() == username.lower():
            print("\nActivity Found!")
            print(f"Username: {activity['username']}")
            print(f"Status: {activity['status']}")
            print(f"Time: {activity['time']}")
            found = True

    if not found:
        print("No activity found for this username.")


def show_summary():
    total = len(activities)
    successful = sum(
        activity["status"] == "Successful"
        for activity in activities
    )
    failed = sum(
        activity["status"] == "Failed"
        for activity in activities
    )

    print("\n===== ACTIVITY SUMMARY =====")
    print(f"Total Attempts: {total}")
    print(f"Successful Logins: {successful}")
    print(f"Failed Logins: {failed}")


def main():
    while True:
        print("\n===== LOGIN ACTIVITY MONITOR =====")
        print("1. Record Login Activity")
        print("2. View All Activities")
        print("3. Search by Username")
        print("4. View Activity Summary")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            record_activity()
        elif choice == "2":
            view_activities()
        elif choice == "3":
            search_user()
        elif choice == "4":
            show_summary()
        elif choice == "5":
            print("Thank you for using Login Activity Monitor!")
            break
        else:
            print("Invalid choice! Please try again.")


if __name__ == "__main__":
    main()
