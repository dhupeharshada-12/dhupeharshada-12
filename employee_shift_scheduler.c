#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    char shift[20];
    int hours;
};

int main() {
    struct Employee employees[50];
    int count = 0;
    int choice;

    do {
        printf("\n===== EMPLOYEE SHIFT SCHEDULER =====\n");
        printf("1. Add Employee\n");
        printf("2. Show Employees\n");
        printf("3. Search by Shift\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= 50) {
                printf("Employee limit reached!\n");
                continue;
            }

            printf("Enter employee name: ");
            scanf(" %[^\n]", employees[count].name);

            printf("Enter shift (Morning/Evening/Night): ");
            scanf(" %[^\n]", employees[count].shift);

            printf("Enter working hours: ");
            scanf("%d", &employees[count].hours);

            count++;

            printf("Employee added successfully!\n");
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("No employees added.\n");
            } else {
                printf("\n--- Employee Schedule ---\n");

                for (int i = 0; i < count; i++) {
                    printf("\nEmployee %d\n", i + 1);
                    printf("Name   : %s\n", employees[i].name);
                    printf("Shift  : %s\n", employees[i].shift);
                    printf("Hours  : %d\n", employees[i].hours);
                }
            }
        }

        else if (choice == 3) {
            char searchShift[20];
            int found = 0;

            printf("Enter shift to search: ");
            scanf(" %[^\n]", searchShift);

            printf("\nEmployees in %s shift:\n", searchShift);

            for (int i = 0; i < count; i++) {
                if (strcmp(employees[i].shift, searchShift) == 0) {
                    printf("- %s (%d hours)\n",
                           employees[i].name,
                           employees[i].hours);
                    found = 1;
                }
            }

            if (!found) {
                printf("No employee found for this shift.\n");
            }
        }

        else if (choice == 4) {
            printf("Program closed.\n");
        }

        else {
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
