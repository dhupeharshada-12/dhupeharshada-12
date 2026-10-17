import os
import shutil
from datetime import datetime

BACKUP_FOLDER = "my_backups"


def create_backup():
    source = input("Enter the file path to back up: ").strip()
    source = os.path.abspath(
        os.path.expanduser(source.strip('"'))
    )

    if not os.path.isfile(source):
        print("Error: File not found!")
        return

    os.makedirs(BACKUP_FOLDER, exist_ok=True)

    filename = os.path.basename(source)
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")

    name, extension = os.path.splitext(filename)
    backup_name = f"{name}_{timestamp}{extension}"

    destination = os.path.join(BACKUP_FOLDER, backup_name)

    try:
        shutil.copy2(source, destination)
        print("\nBackup created successfully!")
        print("Saved at:", destination)

    except OSError as error:
        print("Backup failed:", error)


def show_backups():
    if not os.path.isdir(BACKUP_FOLDER):
        print("No backup folder found.")
        return

    files = sorted(os.listdir(BACKUP_FOLDER))

    if not files:
        print("No backups available.")
        return

    print("\n===== AVAILABLE BACKUPS =====")

    for number, filename in enumerate(files, start=1):
        path = os.path.join(BACKUP_FOLDER, filename)

        if os.path.isfile(path):
            size = os.path.getsize(path)
            print(f"{number}. {filename} ({size} bytes)")


def main():
    while True:
        print("\n===== SMART FILE BACKUP MANAGER =====")
        print("1. Create Backup")
        print("2. View Backups")
        print("3. Exit")

        choice = input("Enter your choice: ").strip()

        if choice == "1":
            create_backup()

        elif choice == "2":
            show_backups()

        elif choice == "3":
            print("Thank you for using Backup Manager!")
            break

        else:
            print("Invalid choice. Please select 1, 2, or 3.")


if __name__ == "__main__":
    main()
