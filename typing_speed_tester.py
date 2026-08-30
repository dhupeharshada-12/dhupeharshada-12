import time
import random

sentences = [
    "Python is easy to learn and powerful.",
    "Practice coding every day to improve your skills.",
    "Small projects help you understand programming.",
    "Consistency is more important than perfection.",
    "Learning new concepts makes you a better programmer."
]

sentence = random.choice(sentences)

print("======================================")
print("         TYPING SPEED TESTER")
print("======================================")

print("\nType the following sentence:")
print("\n" + sentence)

input("\nPress Enter when you are ready...")

print("\nStart typing!")

start_time = time.time()

user_text = input("\nYour Text: ")

end_time = time.time()

time_taken = end_time - start_time

words = len(user_text.split())

if time_taken > 0:
    wpm = (words / time_taken) * 60
else:
    wpm = 0

correct = 0

for i in range(min(len(sentence), len(user_text))):
    if sentence[i] == user_text[i]:
        correct += 1

accuracy = (correct / len(sentence)) * 100

print("\n========== RESULT ==========")
print(f"Time Taken : {time_taken:.2f} seconds")
print(f"Speed      : {wpm:.2f} WPM")
print(f"Accuracy   : {accuracy:.2f}%")

if accuracy >= 90:
    print("Excellent! 🎉")
elif accuracy >= 70:
    print("Good Job! 👍")
else:
    print("Keep Practicing! 💪")
