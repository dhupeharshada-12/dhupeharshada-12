print("======================================")
print("       📊 FILE STATISTICS ANALYZER")
print("======================================")

filename = input("Enter text file name: ")

try:
    with open(filename, "r") as file:
        content = file.read()

    lines = content.splitlines()
    words = content.split()
    characters = len(content)
    characters_without_spaces = len(
        content.replace(" ", "").replace("\n", "")
    )

    print("\n======================================")
    print("           📋 FILE REPORT")
    print("======================================")

    print("File Name              :", filename)
    print("Total Lines            :", len(lines))
    print("Total Words            :", len(words))
    print("Total Characters       :", characters)
    print("Characters Without Space:",
          characters_without_spaces)

    print("\n✅ File analysis completed!")

except FileNotFoundError:
    print("❌ File not found.")
    print("Please check the file name and try again.")
