from collections import Counter
import re

print("====================================")
print("       WORD FREQUENCY ANALYZER")
print("====================================")

text = input("\nEnter a sentence or paragraph:\n")

words = re.findall(r'\b[a-zA-Z]+\b', text.lower())

if not words:
    print("\nNo words found!")
else:
    frequency = Counter(words)

    print("\n========== WORD FREQUENCY ==========")

    for word, count in frequency.most_common():
        print(f"{word:<15} : {count}")

    print("\n====================================")
    print("Total Words      :", len(words))
    print("Unique Words     :", len(frequency))

    most_common_word, highest_count = frequency.most_common(1)[0]

    print("Most Used Word   :", most_common_word)
    print("Used             :", highest_count, "time(s)")
