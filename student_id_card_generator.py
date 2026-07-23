import random

print("========== Student ID Card Generator ==========")

name = input("Enter Student Name: ")
course = input("Enter Course: ")
college = input("Enter College Name: ")

student_id = "STU" + str(random.randint(1000, 9999))

print("\n========== STUDENT ID CARD ==========")
print(f"Student ID : {student_id}")
print(f"Name       : {name}")
print(f"Course     : {course}")
print(f"College    : {college}")
print("====================================")
