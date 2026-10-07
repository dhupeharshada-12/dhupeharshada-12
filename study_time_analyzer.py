 print("===== STUDY TIME ANALYZER =====")

subjects = {}

n = int(input("Enter number of subjects: "))

for i in range(n):
    subject = input(f"Enter subject {i + 1}: ")
    hours = float(input(f"Enter study hours for {subject}: "))
    subjects[subject] = hours

total_hours = sum(subjects.values())
average_hours = total_hours / len(subjects)

print("\n===== STUDY REPORT =====")

for subject, hours in subjects.items():
    print(subject, ":", hours, "hours")

print("\nTotal Study Hours:", total_hours)
print("Average per Subject:", round(average_hours, 2), "hours")

most_studied = max(subjects, key=subjects.get)

print("Most Studied Subject:", most_studied)

if average_hours >= 3:
    print("Status: Excellent study routine! 📚")
elif average_hours >= 1:
    print("Status: Good, keep improving! 👍")
else:
    print("Status: Try to increase your study time.")
