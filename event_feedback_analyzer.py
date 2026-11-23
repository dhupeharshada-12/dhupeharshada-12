import json
from collections import Counter

FILE_NAME = "feedback_data.json"

def load_feedback():
    try:
        with open(FILE_NAME, "r") as file:
            return json.load(file)
    except (FileNotFoundError, json.JSONDecodeError):
        return []

def save_feedback(data):
    with open(FILE_NAME, "w") as file:
        json.dump(data, file, indent=4)

def add_feedback(data):
    name = input("Enter participant name: ").strip()
    if not name:
        print("Name cannot be empty.")
        return

    try:
        rating = int(input("Enter rating (1-5): "))
        if not 1 <= rating <= 5:
            print("Rating must be between 1 and 5.")
            return
    except ValueError:
        print("Invalid rating.")
        return

    comment = input("Enter feedback comment: ").strip()

    feedback = {
        "name": name,
        "rating": rating,
        "comment": comment
    }

    data.append(feedback)
    save_feedback(data)
    print("Feedback added successfully!")

def display_feedback(data):
    if not data:
        print("No feedback records available.")
        return

    print("\n--- Feedback Records ---")

    for i, item in enumerate(data, 1):
        print(f"\nRecord {i}")
        print(f"Name: {item['name']}")
        print(f"Rating: {item['rating']}/5")
        print(f"Comment: {item['comment']}")

def analyze_feedback(data):
    if not data:
        print("No feedback available for analysis.")
        return

    ratings = [item["rating"] for item in data]
    average = sum(ratings) / len(ratings)

    positive = sum(1 for r in ratings if r >= 4)
    neutral = sum(1 for r in ratings if r == 3)
    negative = sum(1 for r in ratings if r <= 2)

    words = []

    for item in data:
        words.extend(item["comment"].lower().split())

    common_words = Counter(words).most_common(5)

    print("\n--- Feedback Analysis ---")
    print(f"Total Feedback: {len(data)}")
    print(f"Average Rating: {average:.2f}/5")
    print(f"Positive Ratings: {positive}")
    print(f"Neutral Ratings: {neutral}")
    print(f"Low Ratings: {negative}")

    print("\nMost Common Words:")
    for word, count in common_words:
        print(f"{word}: {count}")

def main():
    data = load_feedback()

    while True:
        print("\n===== Event Feedback Analyzer =====")
        print("1. Add Feedback")
        print("2. View Feedback")
        print("3. Analyze Feedback")
        print("4. Exit")

        choice = input("Enter your choice: ").strip()

        if choice == "1":
            add_feedback(data)

        elif choice == "2":
            display_feedback(data)

        elif choice == "3":
            analyze_feedback(data)

        elif choice == "4":
            print("Program closed.")
            break

        else:
            print("Invalid choice.")

if __name__ == "__main__":
    main()
