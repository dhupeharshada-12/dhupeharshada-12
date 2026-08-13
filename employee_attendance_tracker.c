#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    int presentDays;
    int absentDays;
};

int main() {
    struct Employee employees[50];
    int count = 0;
    int choice;

    do {
        printf("\n===== EMPLOYEE ATTENDANCE TRACKER =====\n");
        printf("1. Add Employee\n");
        printf("2. Mark Attendance\n");
        printf("3. View Attendance\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count < 50) {
                    printf("\nEnter Employee ID: ");
                    scanf("%d", &employees[count].id);

                    printf("Enter Employee Name: ");
                    scanf(" %[^\n]", employees[count].name);

                    employees[count].presentDays = 0;
                    employees[count].absentDays = 0;

                    count++;

                    printf("Employee Added Successfully!\n");
                } else {
                    printf("Employee limit reached!\n");
                }
                break;

            case 2: {
                int id, status;
                int found = 0;

                printf("\nEnter Employee ID: ");
                scanf("%d", &id);

                for (int i = 0; i < count; i++) {
                    if (employees[i].id == id) {
                        printf("Enter 1 for Present, 0 for Absent: ");
                        scanf("%d", &status);

                        if (status == 1)
                            employees[i].presentDays++;
                        else
                            employees[i].absentDays++;

                        printf("Attendance Updated!\n");
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Employee Not Found!\n");

                break;
            }

            case 3:
                if (count == 0) {
                    printf("No Employees Found!\n");
                } else {
                    printf("\n===== ATTENDANCE REPORT =====\n");

                    for (int i = 0; i < count; i++) {
                        printf("\nEmployee ID   : %d\n", employees[i].id);
                        printf("Name          : %s\n", employees[i].name);
                        printf("Present Days  : %d\n", employees[i].presentDays);
                        printf("Absent Days   : %d\n", employees[i].absentDays);
                    }
                }
                break;

            case 4:
                printf("\nThank you!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
