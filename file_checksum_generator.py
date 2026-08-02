import hashlib
import os

def calculate_checksum(file_path, algorithm):
    hash_obj = hashlib.new(algorithm)

    with open(file_path, "rb") as file:
        while chunk := file.read(4096):
            hash_obj.update(chunk)

    return hash_obj.hexdigest()

print("========== File Checksum Generator ==========")

file_path = input("Enter File Path: ")

if not os.path.isfile(file_path):
    print("File not found!")
    exit()

print("\nChoose Hash Algorithm")
print("1. MD5")
print("2. SHA1")
print("3. SHA256")

choice = input("Enter your choice: ")

algorithms = {
    "1": "md5",
    "2": "sha1",
    "3": "sha256"
}

if choice in algorithms:
    checksum = calculate_checksum(file_path, algorithms[choice])
    print(f"\n{algorithms[choice].upper()} Checksum:")
    print(checksum)
else:
    print("Invalid Choice!")
