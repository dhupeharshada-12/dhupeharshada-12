import json
import os
from datetime import date

FILE_NAME = "job_applications.json"


def load_applications():
    if os.path.exists(FILE_NAME):
        try:
            with open(FILE_NAME, "r") as file:
                return json.load(file)
        except (json.JSONDecodeError, OSError):
            print("Could not read saved records. Starting fresh.")
    return []


def save_applications(applications):
    with open(FILE_NAME, "w") as file:
        json.dump(applications, file, indent=4)


def add_application(applications):
    print("\n--- Add Job Application ---")

    company = input("Company name: ").strip()
    role = input("Job role: ").strip()

    if not company or not role:
        print("Company name and job role cannot be empty.")
        return

    application = {
        "company": company,
        "role": role,
        "date": str(date.today()),
        "status": "Applied"
    }

    applications.append(application)
    save_applications(applications)

    print("Job application added successfully!")


def view_applications(applications):
    print("\n--- All Job Applications ---")

    if not applications:
        print("No applications found.")
        return

    for index, app in enumerate(applications, start=1):
        print(f"\nApplication {index}")
        print("Company:", app["company"])
        print("Role:", app["role"])
        print("Date:", app["date"])
        print("Status:", app["status"])


def update_status(applications):
    view_applications(applications)

    if not applications:
        return

    try:
        number = int(input("\nEnter application number: "))

        if number < 1 or number > len(applications):
            print("Invalid application number.")
            return

        print("\n1. Applied")
        print("2. Interview")
        print("3. Selected")
        print("4. Rejected")

        choice = input("Choose new status: ")

        statuses = {
            "1": "Applied",
            "2": "Interview",
            "3": "Selected",
            "4": "Rejected"
        }

        if choice in statuses:
            applications[number - 1]["status"] = statuses[choice]
            save_applications(applications)
            print("Application status updated!")
        else:
            print("Invalid status choice.")

    except ValueError:
        print("Please enter a valid number.")


def search_company(applications):
    company = input("\nEnter company name: ").strip().lower()

    results = [
        app for app in applications
        if company in app["company"].lower()
    ]

    if not results:
        print("No matching company found.")
        return

    print("\n--- Search Results ---")

    for app in results:
        print(
            f"{app['company']} | {app['role']} | "
            f"{app['date']} | {app['status']}"
        )


def show_summary(applications):
    print("\n--- Application Summary ---")

    total = len(applications)

    print("Total Applications:", total)

    for status in ["Applied", "Interview", "Selected", "Rejected"]:
        count = sum(
            1 for app in applications
            if app["status"] == status
        )
        print(f"{status}: {count}")


def main():
    applications = load_applications()

    while True:
        print("\n====== SMART JOB APPLICATION TRACKER ======")
        print("1. Add Job Application")
        print("2. View All Applications")
        print("3. Update Application Status")
        print("4. Search Company")
        print("5. View Application Summary")
        print("6. Exit")

        choice = input("\nEnter your choice: ")

        if choice == "1":
            add_application(applications)

        elif choice == "2":
            view_applications(applications)

        elif choice == "3":
            update_status(applications)

        elif choice == "4":
            search_company(applications)

        elif choice == "5":
            show_summary(applications)

        elif choice == "6":
            print("Thank you for using Job Application Tracker!")
            break

        else:
            print("Invalid choice! Please try again.")


if __name__ == "__main__":
    main()
