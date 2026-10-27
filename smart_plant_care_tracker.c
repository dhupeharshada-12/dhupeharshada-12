#include <stdio.h>
#include <string.h>

#define MAX_PLANTS 100

struct Plant {
    int id;
    char name[50];
    int wateringInterval;
    int daysSinceWatering;
};

int main() {
    struct Plant plants[MAX_PLANTS];

    int count = 0;
    int nextId = 101;
    int choice;

    do {
        printf("\n===== SMART PLANT CARE TRACKER =====\n");
        printf("1. Add Plant\n");
        printf("2. View All Plants\n");
        printf("3. Search Plant by ID\n");
        printf("4. Update Watering Record\n");
        printf("5. Show Plants Needing Water\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1:
                if (count >= MAX_PLANTS) {
                    printf("Plant storage is full!\n");
                    break;
                }

                plants[count].id = nextId++;

                printf("Enter plant name (one word): ");
                scanf("%49s", plants[count].name);

                printf("Enter watering interval in days: ");
                if (scanf("%d", &plants[count].wateringInterval) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                if (plants[count].wateringInterval <= 0) {
                    printf("Interval must be greater than zero!\n");
                    break;
                }

                printf("Days since last watering: ");
                if (scanf("%d", &plants[count].daysSinceWatering) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                if (plants[count].daysSinceWatering < 0) {
                    printf("Days cannot be negative!\n");
                    break;
                }

                printf("Plant added successfully!\n");
                printf("Plant ID: %d\n", plants[count].id);

                count++;
                break;

            case 2:
                if (count == 0) {
                    printf("No plants registered yet.\n");
                    break;
                }

                printf("\n--- Plant Records ---\n");

                for (int i = 0; i < count; i++) {
                    printf("\nPlant ID: %d\n", plants[i].id);
                    printf("Name: %s\n", plants[i].name);
                    printf("Watering Interval: %d days\n",
                           plants[i].wateringInterval);
                    printf("Days Since Watering: %d\n",
                           plants[i].daysSinceWatering);

                    if (plants[i].daysSinceWatering >=
                        plants[i].wateringInterval) {
                        printf("Reminder: Check whether watering is needed.\n");
                    } else {
                        printf("Status: Within the planned interval.\n");
                    }
                }
                break;

            case 3: {
                int searchId;
                int found = 0;

                printf("Enter plant ID: ");
                scanf("%d", &searchId);

                for (int i = 0; i < count; i++) {
                    if (plants[i].id == searchId) {
                        printf("\nPlant Found!\n");
                        printf("Name: %s\n", plants[i].name);
                        printf("Watering Interval: %d days\n",
                               plants[i].wateringInterval);
                        printf("Days Since Watering: %d\n",
                               plants[i].daysSinceWatering);

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Plant not found!\n");
                }
                break;
            }

            case 4: {
                int updateId;
                int found = 0;

                printf("Enter plant ID: ");
                scanf("%d", &updateId);

                for (int i = 0; i < count; i++) {
                    if (plants[i].id == updateId) {
                        plants[i].daysSinceWatering = 0;
                        printf("Watering record updated!\n");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Plant not found!\n");
                }
                break;
            }

            case 5: {
                int found = 0;

                printf("\n--- Plants to Check ---\n");

                for (int i = 0; i < count; i++) {
                    if (plants[i].daysSinceWatering >=
                        plants[i].wateringInterval) {
                        printf("ID: %d | Plant: %s\n",
                               plants[i].id, plants[i].name);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("No plants have reached their planned interval.\n");
                }
                break;
            }

            case 6:
                printf("Thank you for using Plant Care Tracker!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
