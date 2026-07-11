study_log = []

while True:
    print("\n====== STUDY TIME TRACKER ======")
    print("1. Add Study Session")
    print("2. View Study Sessions")
    print("3. Total Study Time")
    print("4. Subject-wise Report")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        subject = input("Enter Subject Name: ")
        hours = float(input("Enter Study Hours: "))

        study_log.append({
            "subject": subject,
            "hours": hours
        })

        print("Study session added successfully!")

    elif choice == "2":
        if len(study_log) == 0:
            print("No study sessions found.")
        else:
            print("\nSubject\t\tHours")
            print("-" * 30)
            for session in study_log:
                print(f"{session['subject']}\t\t{session['hours']}")

    elif choice == "3":
        total = sum(session["hours"] for session in study_log)
        print(f"\nTotal Study Time: {total:.2f} hours")

    elif choice == "4":
        if len(study_log) == 0:
            print("No data available.")
        else:
            subjects = {}
            for session in study_log:
                subject = session["subject"]
                hours = session["hours"]

                if subject in subjects:
                    subjects[subject] += hours
                else:
                    subjects[subject] = hours

            print("\nSubject-wise Report")
            print("-" * 30)
            for subject, hours in subjects.items():
                print(f"{subject}: {hours:.2f} hours")

    elif choice == "5":
        print("Thank you for using Study Time Tracker!")
        break

    else:
        print("Invalid choice! Please try again.")
