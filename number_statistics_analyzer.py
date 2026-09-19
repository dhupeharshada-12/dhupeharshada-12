print("======================================")
print("       🔢 NUMBER STATISTICS ANALYZER")
print("======================================")

n = int(input("How many numbers do you want to enter? "))

if n <= 0:
    print("❌ Enter a valid number!")

else:
    numbers = []

    for i in range(n):
        number = float(input(f"Enter number {i + 1}: "))
        numbers.append(number)

    total = sum(numbers)
    average = total / len(numbers)
    largest = max(numbers)
    smallest = min(numbers)

    even_count = 0
    odd_count = 0

    for number in numbers:
        if number.is_integer():
            if int(number) % 2 == 0:
                even_count += 1
            else:
                odd_count += 1

    print("\n======================================")
    print("           📊 ANALYSIS REPORT")
    print("======================================")

    print("Numbers Entered :", numbers)
    print(f"Total           : {total:.2f}")
    print(f"Average         : {average:.2f}")
    print(f"Largest         : {largest:.2f}")
    print(f"Smallest        : {smallest:.2f}")
    print("Even Numbers    :", even_count)
    print("Odd Numbers     :", odd_count)

    print("\n✅ Analysis completed successfully!")
