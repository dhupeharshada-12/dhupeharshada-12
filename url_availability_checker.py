import requests

print("========== URL Availability Checker ==========")

url = input("Enter Website URL (e.g. https://www.google.com): ")

try:
    response = requests.get(url, timeout=5)

    print("\nStatus Code:", response.status_code)

    if response.status_code == 200:
        print("✅ Website is Online")
    else:
        print("⚠️ Website responded with status:", response.status_code)

except requests.exceptions.RequestException:
    print("❌ Website is Offline or URL is Invalid")
