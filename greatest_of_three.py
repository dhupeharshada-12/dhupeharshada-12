print("Please enter three different values\n")

num1, num2, num3 = map(int, input("Enter three values: ").split())

print("num1 =", num1)
print("num2 =", num2)
print("num3 =", num3)

if num1 > num2:
    if num1 > num3:
        print("num1 is the greatest among three")
    else:
        print("num3 is the greatest among three")
elif num2 > num3:
    print("num2 is the greatest among three")
else:
    print("num3 is the greatest among three")
