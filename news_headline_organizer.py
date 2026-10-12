
headlines = []

def add_headline():
    title = input("Enter news headline: ").strip()
    category = input("Enter category (Sports, Tech, Education, etc.): ").strip()

    if not title or not category:
        print("Headline and category cannot be empty!")
        return

    news = {
        "title": title,
        "category": category
    }

    headlines.append(news)
    print("Headline added successfully!")

def show_headlines():
    if not headlines:
        print("No headlines available.")
        return

    print("\n===== ALL NEWS HEADLINES =====")

    for number, news in enumerate(headlines, start=1):
        print(f"{number}. [{news['category']}] {news['title']}")

def search_headline():
    keyword = input("Enter keyword to search: ").strip().lower()

    if not keyword:
        print("Please enter a keyword.")
        return

    results = [
        news for news in headlines
        if keyword in news["title"].lower()
        or keyword in news["category"].lower()
    ]

    if results:
        print("\n===== SEARCH RESULTS =====")
        for news in results:
            print(f"[{news['category']}] {news['title']}")
    else:
        print("No matching headlines found.")

def show_categories():
    if not headlines:
        print("No categories available yet.")
        return

    categories = sorted({
        news["category"].title()
        for news in headlines
    })

    print("\nAvailable categories:")
    for category in categories:
        print("-", category)

def main():
    while True:
        print("\n===== NEWS HEADLINE ORGANIZER =====")
        print("1. Add headline")
        print("2. View all headlines")
        print("3. Search headlines")
        print("4. Show categories")
        print("5. Exit")

        choice = input("Enter your choice: ").strip()

        if choice == "1":
            add_headline()
        elif choice == "2":
            show_headlines()
        elif choice == "3":
            search_headline()
        elif choice == "4":
            show_categories()
        elif choice == "5":
            print("Thank you for using News Headline Organizer!")
            break
        else:
            print("Invalid choice. Please enter 1 to 5.")

if __name__ == "__main__":
    main()
  
