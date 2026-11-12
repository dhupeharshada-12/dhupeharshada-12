import re
import string

def check_password(password):
    score = 0
    suggestions = []

    # Check password length
    if len(password) >= 12:
        score += 2
    elif len(password) >= 8:
        score += 1
    else:
        suggestions.append("Use at least 8 characters.")

    # Check uppercase letters
    if re.search(r"[A-Z]", password):
        score += 1
    else:
        suggestions.append("Add an uppercase letter.")

    # Check lowercase letters
    if re.search(r"[a-z]", password):
        score += 1
    else:
        suggestions.append("Add a lowercase letter.")

    # Check digits
    if re.search(r"[0-9]", password):
        score += 1
    else:
        suggestions.append("Add a number.")

    # Check special characters
    if any(char in string.punctuation for char in password):
        score += 1
    else:
        suggestions.append("Add a special character.")

    # Determine strength
    if score >= 6:
        strength = "Strong"
    elif score >= 4:
        strength = "Moderate"
    else:
        strength = "Weak"

    return strength, suggestions


def main():
    print("=" * 40)
    print(" SMART PASSWORD SECURITY CHECKER")
    print("=" * 40)

    password = input("Enter a password to check: ")

    strength, suggestions = check_password(password)

    print("\nPassword Strength:", strength)

    if suggestions:
        print("\nSuggestions:")
        for suggestion in suggestions:
            print("-", suggestion)
    else:
        print("\nYour password meets all basic checks!")

    print("\nNote: This is a basic rule-based checker.")
    print("It does not guarantee that a password is secure.")


if __name__ == "__main__":
    main()
