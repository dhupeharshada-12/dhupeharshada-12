print("======================================")
print("       📚 STUDY PROGRESS TRACKER")
print("======================================")

name = input("Enter your name: ")

n = int(input("Enter number of subjects: "))

if n <= 0:
    print("Invalid number of subjects!")
else:
    subjects = []
    scores = []

    total = 0

    for i in range(n):
        subject = input(f"\nEnter subject {i + 1}: ")
        score = float(input(f"Enter score for {subject}: "))

        if score < 0 or score > 100:
            print("Score must be between 0 and 100!")
            continue

        subjects.append(subject)
        scores.append(score)
        total += score

    if len(scores) > 0:

        average = total / len(scores)

        highest_index = scores.index(max(scores))
        highest_subject = subjects[highest_index]
        highest_score = scores[highest_index]

        if average >= 80:
            performance = "Excellent 🌟"
        elif average >= 60:
            performance = "Good 👍"
        elif average >= 40:
            performance = "Needs Improvement 📖"
        else:
            performance = "Keep Practicing 💪"

        print("\n======================================")
        print("          📊 PROGRESS REPORT")
        print("======================================")

        print("Student Name :", name)
        print("Subjects     :", len(scores))
        print(f"Total Score  : {total:.2f}")
        print(f"Average      : {average:.2f}")
        print(f"Highest Score: {highest_score:.2f}")
        print("Best Subject :", highest_subject)
        print("Performance  :", performance)

        print("\nKeep learning and improving! 🚀")
