import hashlib
import requests

print("========== Password Leak Checker ==========")

password = input("Enter Password: ")

sha1_password = hashlib.sha1(password.encode()).hexdigest().upper()

prefix = sha1_password[:5]
suffix = sha1_password[5:]

url = f"https://api.pwnedpasswords.com/range/{prefix}"

try:
    response = requests.get(url)

    found = False

    if response.status_code == 200:
        hashes = response.text.splitlines()

        for line in hashes:
            hash_suffix, count = line.split(":")

            if hash_suffix == suffix:
                print(f"\n⚠️ This password has appeared in data breaches {count} times.")
                found = True
                break

        if not found:
            print("\n✅ Good news! This password was not found in the database.")

    else:
        print("Unable to check password.")

except Exception as e:
    print("Error:", e)
