students = []

print("======================================")
print("       📊 STUDENT RESULT MANAGER")
print("======================================")

n = int(input("Enter number of students: "))

for i in range(n):

    print(f"\nStudent {i + 1}")

    name = input("Enter student name: ")

    math = float(input("Enter Math marks: "))
    python = float(input("Enter Python marks: "))
    english = float(input("Enter English marks: "))

    total = math + python + english
    percentage = total / 3

    if math < 40 or python < 40 or english < 40:
        result = "Fail ❌"
        grade = "F"
    else:
        result = "Pass ✅"

        if percentage >= 80:
            grade = "A"
        elif percentage >= 60:
            grade = "B"
        elif percentage >= 50:
            grade = "C"
        else:
            grade = "D"

    student = {
        "name": name,
        "total": total,
        "percentage": percentage,
        "grade": grade,
        "result": result
    }

    students.append(student)


print("\n======================================")
print("          📋 RESULT REPORT")
print("======================================")

for student in students:

    print("\nName       :", student["name"])
    print("Total      :", student["total"])
    print(f"Percentage : {student['percentage']:.2f}%")
    print("Grade      :", student["grade"])
    print("Result     :", student["result"])

print("\n✅ Result analysis completed!")
