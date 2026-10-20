#include <stdio.h>
#include <string.h>

#define MAX_DONATIONS 100

struct Donation {
    char donorName[50];
    char purpose[50];
    double amount;
};

struct Donation donations[MAX_DONATIONS];
int donationCount = 0;

void addDonation() {
    if (donationCount >= MAX_DONATIONS) {
        printf("\nDonation records are full!\n");
        return;
    }

    struct Donation d;

    printf("\nEnter donor name: ");
    scanf(" %49[^\n]", d.donorName);

    printf("Enter donation purpose: ");
    scanf(" %49[^\n]", d.purpose);

    printf("Enter donation amount: ");

    if (scanf("%lf", &d.amount) != 1 || d.amount <= 0) {
        printf("Invalid amount. Enter a value greater than zero.\n");

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* Clear invalid input */
        }

        return;
    }

    donations[donationCount] = d;
    donationCount++;

    printf("\nDonation recorded successfully!\n");
}

void displayDonations() {
    if (donationCount == 0) {
        printf("\nNo donation records available.\n");
        return;
    }

    double total = 0;

    printf("\n========== DONATION RECORDS ==========\n");
    printf("%-5s %-20s %-20s %12s\n",
           "No.", "Donor", "Purpose", "Amount");

    printf("------------------------------------------------------------\n");

    for (int i = 0; i < donationCount; i++) {
        printf("%-5d %-20s %-20s %12.2f\n",
               i + 1,
               donations[i].donorName,
               donations[i].purpose,
               donations[i].amount);

        total += donations[i].amount;
    }

    printf("------------------------------------------------------------\n");
    printf("Total Donations: %.2f\n", total);
}

void searchDonor() {
    if (donationCount == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    char searchName[50];
    int found = 0;

    printf("\nEnter donor name to search: ");
    scanf(" %49[^\n]", searchName);

    for (int i = 0; i < donationCount; i++) {
        if (strcmp(donations[i].donorName, searchName) == 0) {
            printf("\nRecord Found!\n");
            printf("Donor: %s\n", donations[i].donorName);
            printf("Purpose: %s\n", donations[i].purpose);
            printf("Amount: %.2f\n", donations[i].amount);

            found = 1;
        }
    }

    if (!found) {
        printf("No matching donor found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n===== DONATION RECORD MANAGER =====\n");
        printf("1. Add Donation\n");
        printf("2. Display All Donations\n");
        printf("3. Search Donor\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Clear invalid input */
            }

            continue;
        }

        switch (choice) {
            case 1:
                addDonation();
                break;

            case 2:
                displayDonations();
                break;

            case 3:
                searchDonor();
                break;

            case 4:
                printf("Donation Manager closed. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
