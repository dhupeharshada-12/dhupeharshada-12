import time

paragraph = """Python is a versatile programming language used in web development,
artificial intelligence, automation, and data science."""

print("========== Typing Accuracy Analyzer ==========\n")
print("Type the following paragraph:\n")
print(paragraph)

input("\nPress Enter to start...")

start = time.time()

typed = input("\nStart typing:\n")

end = time.time()

time_taken = end - start

correct = 0
for i in range(min(len(paragraph), len(typed))):
    if paragraph[i] == typed[i]:
        correct += 1

accuracy = (correct / len(paragraph)) * 100

words = len(typed.split())
wpm = (words / time_taken) * 60 if time_taken > 0 else 0

mistakes = abs(len(paragraph) - len(typed))
mistakes += sum(
    1 for i in range(min(len(paragraph), len(typed)))
    if paragraph[i] != typed[i]
)

print("\n========== RESULT ==========")
print(f"Time Taken : {time_taken:.2f} seconds")
print(f"Typing Speed : {wpm:.2f} WPM")
print(f"Accuracy : {accuracy:.2f}%")
print(f"Mistakes : {mistakes}")
