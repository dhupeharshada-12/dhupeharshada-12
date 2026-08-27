import time

print("===================================")
print("       STUDY SESSION TIMER")
print("===================================")

minutes = int(input("Enter study time in minutes: "))

if minutes <= 0:
    print("Please enter a valid time.")
else:
    total_seconds = minutes * 60

    print("\nStudy session started! 📚")
    print("Stay focused! 💪")

    while total_seconds > 0:
        mins = total_seconds // 60
        secs = total_seconds % 60

        print(f"\rTime Remaining: {mins:02d}:{secs:02d}", end="")
        time.sleep(1)

        total_seconds -= 1

    print("\n\n🎉 Study session completed!")
    print("Great job! Take a short break.")
