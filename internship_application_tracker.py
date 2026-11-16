import json
import os

FILE_NAME = "internship_data.json"


def load_data():
    if os.path.exists(FILE_NAME):
        try:
            with open(FILE_NAME, "r") as file:
                return json.load(file)
        except (json.JSONDecodeError, OSError):
            print("Could not read saved data. Starting with an empty list.")

    return []


def save_data(applications):
    with open(FILE_NAME, "w") as file:
        json.dump(applications, file, indent=4)


def add_application(applications):
    print("\n===== ADD INTERNSHIP APPLICATION =====")

    company = input("Enter Company Name: ").strip()
    role = input("Enter Internship Role: ").strip()
    date = input("Enter Application Date: ").strip()

    if not company or not role or not date:
        print("All fields are required!")
        return

    application = {
        "id": max((app["id"] for app in applications), default=0) + 1,
        "company": company,
        "role": role,
        "date": date,
        "status": "Applied"
    }

    applications.append(application)
    save_data(applications)

    print("\nApplication added successfully!")
    print("Application ID:", application["id"])


def view_applications(applications):
    print("\n===== ALL APPLICATIONS =====")

    if not applications:
        print("No applications found.")
        return

    for app in applications:
        print("\nApplication ID:", app["id"])
        print("Company:", app["company"])
        print("Role:", app["role"])
        print("Date:", app["date"])
        print("Status:", app["status"])


def search_application(applications):
    company = input("\nEnter Company Name to Search: ").strip().lower()

    found = False

    for app in applications:
        if company in app["company"].lower():
            print("\nApplication Found!")
            print("ID:", app["id"])
            print("Company:", app["company"])
            print("Role:", app["role"])
            print("Status:", app["status"])
            found = True

    if not found:
        print("No matching application found.")


def update_status(applications):
    try:
        app_id = int(input("\nEnter Application ID: "))
    except ValueError:
        print("Please enter a valid ID.")
        return

    for app in applications:
        if app["id"] == app_id:
            print("\n1. Applied")
            print("2. Under Review")
            print("3. Interview")
            print("4. Selected")
            print("5. Rejected")

            choice = input("Choose New Status: ")

            statuses = {
                "1": "Applied",
                "2": "Under Review",
                "3": "Interview",
                "4": "Selected",
                "5": "Rejected"
            }

            if choice in statuses:
                app["status"] = statuses[choice]
                save_data(applications)
                print("Status updated successfully!")
            else:
                print("Invalid status choice.")

            return

    print("Application ID not found.")


def show_summary(applications):
    print("\n===== APPLICATION SUMMARY =====")

    total = len(applications)
    print("Total Applications:", total)

    statuses = [
        "Applied",
        "Under Review",
        "Interview",
        "Selected",
        "Rejected"
    ]

    for status in statuses:
        count = sum(
            1 for app in applications
            if app["status"] == status
        )
        print(f"{status}: {count}")


def main():
    applications = load_data()

    while True:
        print("\n===== INTERNSHIP APPLICATION TRACKER =====")
        print("1. Add Application")
        print("2. View Applications")
        print("3. Search Application")
        print("4. Update Application Status")
        print("5. Application Summary")
        print("6. Exit")

        choice = input("\nEnter Your Choice: ")

        if choice == "1":
            add_application(applications)

        elif choice == "2":
            view_applications(applications)

        elif choice == "3":
            search_application(applications)

        elif choice == "4":
            update_status(applications)

        elif choice == "5":
            show_summary(applications)

        elif choice == "6":
            print("\nThank you for using the tracker!")
            break

        else:
            print("Invalid choice! Try again.")


if __name__ == "__main__":
    main()
