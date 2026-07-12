import time

paragraph = (
    "Python is a powerful programming language used for web development, "
    "artificial intelligence, automation, and data science."
)

print("========== Typing Speed Test ==========\n")
print("Type the following paragraph exactly as shown:\n")
print(paragraph)
print("\nPress Enter when you are ready...")
input()

start_time = time.time()

typed_text = input("\nStart Typing:\n")

end_time = time.time()

time_taken = end_time - start_time

word_count = len(typed_text.split())
wpm = (word_count / time_taken) * 60

correct_chars = 0
for i in range(min(len(paragraph), len(typed_text))):
    if paragraph[i] == typed_text[i]:
        correct_chars += 1

accuracy = (correct_chars / len(paragraph)) * 100

print("\n========== RESULT ==========")
print(f"Time Taken : {time_taken:.2f} seconds")
print(f"Words Typed: {word_count}")
print(f"Typing Speed: {wpm:.2f} WPM")
print(f"Accuracy   : {accuracy:.2f}%")
