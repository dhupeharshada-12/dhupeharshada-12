#include <stdio.h>
#include <string.h>

#define MAX_PLANTS 100

struct Plant {
    int id;
    char name[50];
    char location[50];
    int wateringInterval;
    int daysSinceWatering;
};

struct Plant plants[MAX_PLANTS];
int totalPlants = 0;

void addPlant() {
    if (totalPlants >= MAX_PLANTS) {
        printf("\nGarden record limit reached!\n");
        return;
    }

    struct Plant p;

    printf("\nEnter Plant ID: ");
    scanf("%d", &p.id);

    for (int i = 0; i < totalPlants; i++) {
        if (plants[i].id == p.id) {
            printf("Plant ID already exists!\n");
            return;
        }
    }

    printf("Enter Plant Name: ");
    scanf(" %49[^\n]", p.name);

    printf("Enter Plant Location: ");
    scanf(" %49[^\n]", p.location);

    printf("Enter Watering Interval (days): ");
    scanf("%d", &p.wateringInterval);

    if (p.wateringInterval <= 0) {
        printf("Invalid watering interval!\n");
        return;
    }

    printf("Enter Days Since Last Watering: ");
    scanf("%d", &p.daysSinceWatering);

    if (p.daysSinceWatering < 0) {
        printf("Invalid number of days!\n");
        return;
    }

    plants[totalPlants++] = p;

    printf("\nPlant added successfully!\n");
}

void displayPlants() {
    if (totalPlants == 0) {
        printf("\nNo plant records available.\n");
        return;
    }

    printf("\n========== GARDEN PLANT RECORDS ==========\n");

    for (int i = 0; i < totalPlants; i++) {
        printf("\nPlant ID: %d", plants[i].id);
        printf("\nName: %s", plants[i].name);
        printf("\nLocation: %s", plants[i].location);
        printf("\nWatering Interval: %d days",
               plants[i].wateringInterval);
        printf("\nDays Since Watering: %d",
               plants[i].daysSinceWatering);

        if (plants[i].daysSinceWatering >=
            plants[i].wateringInterval) {
            printf("\nStatus: Watering Due");
        } else {
            printf("\nStatus: Not Due Yet");
        }

        printf("\n------------------------------------------\n");
    }
}

void searchPlant() {
    int id;

    printf("\nEnter Plant ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < totalPlants; i++) {
        if (plants[i].id == id) {
            printf("\nPlant Found!");
            printf("\nName: %s", plants[i].name);
            printf("\nLocation: %s", plants[i].location);
            printf("\nWatering Interval: %d days\n",
                   plants[i].wateringInterval);
            return;
        }
    }

    printf("\nPlant not found!\n");
}

void waterPlant() {
    int id;

    printf("\nEnter Plant ID: ");
    scanf("%d", &id);

    for (int i = 0; i < totalPlants; i++) {
        if (plants[i].id == id) {
            plants[i].daysSinceWatering = 0;
            printf("\nPlant watering record updated!\n");
            return;
        }
    }

    printf("\nPlant not found!\n");
}

void updateDays() {
    int days;

    printf("\nEnter number of days passed: ");
    scanf("%d", &days);

    if (days <= 0) {
        printf("Please enter a positive number.\n");
        return;
    }

    for (int i = 0; i < totalPlants; i++) {
        plants[i].daysSinceWatering += days;
    }

    printf("\nGarden records updated successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\n====== SMART GARDEN MONITOR ======\n");
        printf("1. Add New Plant\n");
        printf("2. Display All Plants\n");
        printf("3. Search Plant\n");
        printf("4. Mark Plant as Watered\n");
        printf("5. Update Days Passed\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlant();
                break;

            case 2:
                displayPlants();
                break;

            case 3:
                searchPlant();
                break;

            case 4:
                waterPlant();
                break;

            case 5:
                updateDays();
                break;

            case 6:
                printf("\nThank you for using Smart Garden Monitor!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
