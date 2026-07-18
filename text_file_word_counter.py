import os

print("========== Text File Word Counter ==========")

file_name = input("Enter text file path: ")

if os.path.exists(file_name):
    with open(file_name, "r", encoding="utf-8") as file:
        text = file.read()

    words = text.split()
    lines = text.splitlines()
    characters = len(text)

    print("\n===== File Statistics =====")
    print("Total Lines      :", len(lines))
    print("Total Words      :", len(words))
    print("Total Characters :", characters)
else:
    print("File not found!")
