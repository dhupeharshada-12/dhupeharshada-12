import os

def print_tree(path, indent=""):
    try:
        items = sorted(os.listdir(path))

        for index, item in enumerate(items):
            full_path = os.path.join(path, item)

            connector = "└── " if index == len(items) - 1 else "├── "
            print(indent + connector + item)

            if os.path.isdir(full_path):
                extension = "    " if index == len(items) - 1 else "│   "
                print_tree(full_path, indent + extension)

    except PermissionError:
        print(indent + "Access Denied")

folder = input("Enter Folder Path: ")

if os.path.exists(folder):
    print("\nDirectory Tree\n")
    print(folder)
    print_tree(folder)
else:
    print("Folder not found!")
