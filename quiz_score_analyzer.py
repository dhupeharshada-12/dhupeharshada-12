print("======================================")
print("        📊 QUIZ SCORE ANALYZER")
print("======================================")

name = input("Enter your name: ")

total_questions = int(input("Enter total questions: "))

if total_questions <= 0:
    print("❌ Invalid number of questions!")

else:
    correct = 0

    for i in range(1, total_questions + 1):
        answer = input(f"Question {i} - Correct? (y/n): ").lower()

        if answer == "y":
            correct += 1

    wrong = total_questions - correct
    accuracy = (correct / total_questions) * 100

    print("\n======================================")
    print("           📋 QUIZ REPORT")
    print("======================================")

    print("Player          :", name)
    print("Total Questions :", total_questions)
    print("Correct Answers :", correct)
    print("Wrong Answers   :", wrong)
    print(f"Accuracy        : {accuracy:.2f}%")

    if accuracy >= 80:
        print("Performance     : 🌟 Excellent")
    elif accuracy >= 60:
        print("Performance     : 👍 Good")
    elif accuracy >= 40:
        print("Performance     : 📖 Keep Practicing")
    else:
        print("Performance     : 💪 Need More Practice")

    print("\n🎯 Keep learning and improving!")
