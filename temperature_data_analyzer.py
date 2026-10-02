print("===== TEMPERATURE DATA ANALYZER =====")

temperatures = []

n = int(input("How many temperature readings? "))

for i in range(n):
    temp = float(input(f"Enter temperature {i + 1}: "))
    temperatures.append(temp)

highest = max(temperatures)
lowest = min(temperatures)
average = sum(temperatures) / len(temperatures)

print("\n--- Temperature Report ---")
print("Readings:", temperatures)
print("Highest Temperature:", highest)
print("Lowest Temperature:", lowest)
print("Average Temperature:", round(average, 2))

if average >= 35:
    print("Status: Hot")
elif average >= 25:
    print("Status: Normal")
else:
    print("Status: Cool")
