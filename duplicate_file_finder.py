import os
import hashlib

def file_hash(file_path):
    hasher = hashlib.md5()

    with open(file_path, "rb") as file:
        while chunk := file.read(4096):
            hasher.update(chunk)

    return hasher.hexdigest()

folder = input("Enter Folder Path: ")

hashes = {}
duplicates = []

for root, dirs, files in os.walk(folder):
    for file in files:
        path = os.path.join(root, file)

        try:
            h = file_hash(path)

            if h in hashes:
                duplicates.append((path, hashes[h]))
            else:
                hashes[h] = path

        except:
            pass

print("\n========== Duplicate Files ==========")

if duplicates:
    for dup, original in duplicates:
        print(f"\nDuplicate : {dup}")
        print(f"Original  : {original}")
else:
    print("No Duplicate Files Found.")
