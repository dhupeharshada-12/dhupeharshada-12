positive_words = [
    "happy", "great", "awesome", "excellent",
    "love", "good", "amazing", "wonderful",
    "success", "beautiful"
]

negative_words = [
    "sad", "bad", "hate", "terrible",
    "awful", "angry", "poor", "worst",
    "failure", "boring"
]


def analyze_sentiment(sentence):
    words = sentence.lower().split()

    positive_count = 0
    negative_count = 0

    for word in words:
        word = word.strip(".,!?;:")

        if word in positive_words:
            positive_count += 1

        elif word in negative_words:
            negative_count += 1

    if positive_count > negative_count:
        sentiment = "Positive 😊"

    elif negative_count > positive_count:
        sentiment = "Negative 😟"

    else:
        sentiment = "Neutral 😐"

    return {
        "sentiment": sentiment,
        "positive_words": positive_count,
        "negative_words": negative_count
    }


def main():
    print("===== SMART SENTIMENT ANALYZER =====")

    while True:
        sentence = input(
            "\nEnter a sentence (or type 'exit' to quit): "
        ).strip()

        if sentence.lower() == "exit":
            print("Thank you for using Sentiment Analyzer!")
            break

        if not sentence:
            print("Please enter a sentence.")
            continue

        result = analyze_sentiment(sentence)

        print("\n----- ANALYSIS RESULT -----")
        print("Sentence:", sentence)
        print("Sentiment:", result["sentiment"])
        print("Positive words:", result["positive_words"])
        print("Negative words:", result["negative_words"])


if __name__ == "__main__":
    main()
