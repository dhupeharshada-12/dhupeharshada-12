import os
import shutil

print("===================================")
print("          FILE ORGANIZER")
print("===================================")

folder_path = input("Enter folder path: ")

if not os.path.isdir(folder_path):
    print("❌ Folder not found!")
    exit()

file_categories = {
    "Images": [".jpg", ".jpeg", ".png", ".gif"],
    "Documents": [".pdf", ".doc", ".docx", ".txt"],
    "Videos": [".mp4", ".mkv", ".avi"],
    "Audio": [".mp3", ".wav"],
    "Programs": [".py", ".c", ".cpp", ".java"],
    "Others": []
}

for file_name in os.listdir(folder_path):

    file_path = os.path.join(folder_path, file_name)

    if os.path.isfile(file_path):

        extension = os.path.splitext(file_name)[1].lower()
        category = "Others"

        for folder, extensions in file_categories.items():
            if extension in extensions:
                category = folder
                break

        category_path = os.path.join(folder_path, category)

        if not os.path.exists(category_path):
            os.makedirs(category_path)

        destination = os.path.join(category_path, file_name)

        shutil.move(file_path, destination)

        print(f"✅ Moved: {file_name} → {category}")

print("\n🎉 Files organized successfully!")
