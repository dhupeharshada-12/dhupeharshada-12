import pyshorteners

print("========== URL Shortener ==========")

long_url = input("Enter the Long URL: ")

try:
    shortener = pyshorteners.Shortener()

    short_url = shortener.tinyurl.short(long_url)

    print("\nShort URL:")
    print(short_url)

except Exception as e:
    print("Error:", e)
