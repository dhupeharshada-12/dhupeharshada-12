import json
import os

print("========== JSON Data Viewer ==========")

file_name = input("Enter JSON file name: ")

if os.path.exists(file_name):
    try:
        with open(file_name, "r", encoding="utf-8") as file:
            data = json.load(file)

        print("\n===== JSON CONTENT =====")
        print(json.dumps(data, indent=4))

    except json.JSONDecodeError:
        print("Invalid JSON file!")
    except Exception as e:
        print("Error:", e)

else:
    print("File not found!")
