#include <stdio.h>
#include <string.h>

struct Participant {
    char name[50];
    char event[50];
    int age;
};

int main() {
    struct Participant participants[100];
    int count = 0;
    int choice;

    do {
        printf("\n===== EVENT REGISTRATION MANAGER =====\n");
        printf("1. Register Participant\n");
        printf("2. Show All Participants\n");
        printf("3. Search by Event\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= 100) {
                printf("Registration limit reached!\n");
                continue;
            }

            printf("Enter participant name: ");
            scanf(" %[^\n]", participants[count].name);

            printf("Enter event name: ");
            scanf(" %[^\n]", participants[count].event);

            printf("Enter age: ");
            scanf("%d", &participants[count].age);

            count++;

            printf("Registration successful!\n");
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("No participants registered.\n");
            } else {
                printf("\n--- Registered Participants ---\n");

                for (int i = 0; i < count; i++) {
                    printf("\nParticipant %d\n", i + 1);
                    printf("Name  : %s\n", participants[i].name);
                    printf("Event : %s\n", participants[i].event);
                    printf("Age   : %d\n", participants[i].age);
                }
            }
        }

        else if (choice == 3) {
            char searchEvent[50];
            int found = 0;

            printf("Enter event name: ");
            scanf(" %[^\n]", searchEvent);

            for (int i = 0; i < count; i++) {
                if (strcmp(participants[i].event, searchEvent) == 0) {
                    printf("\nName: %s\n", participants[i].name);
                    printf("Age : %d\n", participants[i].age);
                    found = 1;
                }
            }

            if (!found) {
                printf("No participant found for this event.\n");
            }
        }

        else if (choice == 4) {
            printf("Thank you!\n");
        }

        else {
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
