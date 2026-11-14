#include <stdio.h>
#include <string.h>

#define MAX 100

struct Complaint {
    int id;
    char customerName[50];
    char issue[100];
    char status[20];
};

struct Complaint complaints[MAX];
int count = 0;
int nextId = 1;

void registerComplaint() {
    if (count >= MAX) {
        printf("\nComplaint storage is full!\n");
        return;
    }

    struct Complaint c;

    c.id = nextId++;

    printf("\nEnter Customer Name: ");
    scanf(" %49[^\n]", c.customerName);

    printf("Enter Complaint Details: ");
    scanf(" %99[^\n]", c.issue);

    strcpy(c.status, "Pending");

    complaints[count] = c;
    count++;

    printf("\nComplaint registered successfully!");
    printf("\nYour Complaint ID: %d\n", c.id);
}

void viewComplaints() {
    if (count == 0) {
        printf("\nNo complaints available.\n");
        return;
    }

    printf("\n===== COMPLAINT RECORDS =====\n");

    for (int i = 0; i < count; i++) {
        printf("\nComplaint ID: %d", complaints[i].id);
        printf("\nCustomer: %s", complaints[i].customerName);
        printf("\nIssue: %s", complaints[i].issue);
        printf("\nStatus: %s\n", complaints[i].status);
    }
}

void searchComplaint() {
    int id, found = 0;

    printf("\nEnter Complaint ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (complaints[i].id == id) {
            printf("\nComplaint Found!");
            printf("\nCustomer: %s", complaints[i].customerName);
            printf("\nIssue: %s", complaints[i].issue);
            printf("\nStatus: %s\n", complaints[i].status);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nComplaint not found!\n");
    }
}

void updateStatus() {
    int id, found = 0;
    int choice;

    printf("\nEnter Complaint ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (complaints[i].id == id) {
            printf("\n1. Pending");
            printf("\n2. In Progress");
            printf("\n3. Resolved");

            printf("\nSelect New Status: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    strcpy(complaints[i].status, "Pending");
                    break;

                case 2:
                    strcpy(complaints[i].status, "In Progress");
                    break;

                case 3:
                    strcpy(complaints[i].status, "Resolved");
                    break;

                default:
                    printf("\nInvalid status choice!\n");
                    return;
            }

            printf("\nComplaint status updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nComplaint not found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n\n===== SMART ELECTRICITY COMPLAINT TRACKER =====");
        printf("\n1. Register Complaint");
        printf("\n2. View All Complaints");
        printf("\n3. Search Complaint");
        printf("\n4. Update Complaint Status");
        printf("\n5. Exit");

        printf("\n\nEnter Your Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                registerComplaint();
                break;

            case 2:
                viewComplaints();
                break;

            case 3:
                searchComplaint();
                break;

            case 4:
                updateStatus();
                break;

            case 5:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
