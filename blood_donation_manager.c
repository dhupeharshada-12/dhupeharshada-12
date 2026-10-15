#include <stdio.h>
#include <string.h>

#define MAX_DONORS 100

struct Donor {
    char name[50];
    char bloodGroup[5];
    char city[50];
    char phone[20];
};

struct Donor donors[MAX_DONORS];
int donorCount = 0;

void addDonor() {
    if (donorCount >= MAX_DONORS) {
        printf("\nDonor records are full!\n");
        return;
    }

    struct Donor d;

    printf("\nEnter donor name: ");
    scanf(" %49[^\n]", d.name);

    printf("Enter blood group (e.g. A+, O-): ");
    scanf(" %4s", d.bloodGroup);

    printf("Enter city: ");
    scanf(" %49[^\n]", d.city);

    printf("Enter contact number: ");
    scanf(" %19s", d.phone);

    donors[donorCount] = d;
    donorCount++;

    printf("\nDonor record added successfully!\n");
}

void displayDonors() {
    if (donorCount == 0) {
        printf("\nNo donor records available.\n");
        return;
    }

    printf("\n===== DONOR RECORDS =====\n");

    for (int i = 0; i < donorCount; i++) {
        printf("\nDonor %d\n", i + 1);
        printf("Name: %s\n", donors[i].name);
        printf("Blood Group: %s\n", donors[i].bloodGroup);
        printf("City: %s\n", donors[i].city);
        printf("Contact: %s\n", donors[i].phone);
        printf("-------------------------\n");
    }
}

void searchByBloodGroup() {
    char group[5];
    int found = 0;

    printf("\nEnter blood group to search: ");
    scanf(" %4s", group);

    printf("\n===== SEARCH RESULTS =====\n");

    for (int i = 0; i < donorCount; i++) {
        if (strcmp(donors[i].bloodGroup, group) == 0) {
            printf("Name: %s\n", donors[i].name);
            printf("Blood Group: %s\n", donors[i].bloodGroup);
            printf("City: %s\n", donors[i].city);
            printf("-------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No matching donor record found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n===== BLOOD DONATION MANAGER =====\n");
        printf("1. Add Donor\n");
        printf("2. Display All Donors\n");
        printf("3. Search by Blood Group\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Clear invalid input */
            }

            continue;
        }

        switch (choice) {
            case 1:
                addDonor();
                break;

            case 2:
                displayDonors();
                break;

            case 3:
                searchByBloodGroup();
                break;

            case 4:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
