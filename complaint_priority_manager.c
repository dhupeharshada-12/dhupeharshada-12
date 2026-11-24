#include <stdio.h>
#include <string.h>

#define MAX 100

struct Complaint {
    int id;
    char title[100];
    int priority;
    char status[20];
};

struct Complaint complaints[MAX];
int count = 0;
int nextId = 1;

void addComplaint() {
    if (count >= MAX) {
        printf("Complaint storage is full!\n");
        return;
    }

    struct Complaint c;

    c.id = nextId++;

    printf("Enter complaint title: ");
    fgets(c.title, sizeof(c.title), stdin);
    c.title[strcspn(c.title, "\n")] = '\0';

    printf("Priority (1-High, 2-Medium, 3-Low): ");
    if (scanf("%d", &c.priority) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    if (c.priority < 1 || c.priority > 3) {
        printf("Invalid priority!\n");
        return;
    }

    strcpy(c.status, "Pending");
    complaints[count++] = c;

    printf("Complaint added successfully!\n");
}

void displayComplaints() {
    if (count == 0) {
        printf("No complaints found.\n");
        return;
    }

    printf("\n--- Complaint Records ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\n", complaints[i].id);
        printf("Title: %s\n", complaints[i].title);
        printf("Priority: %s\n",
            complaints[i].priority == 1 ? "High" :
            complaints[i].priority == 2 ? "Medium" : "Low");
        printf("Status: %s\n", complaints[i].status);
    }
}

void updateStatus() {
    int id;
    printf("Enter complaint ID: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    for (int i = 0; i < count; i++) {
        if (complaints[i].id == id) {
            printf("1. Pending\n2. Resolved\n");
            printf("Choose new status: ");

            int choice;
            if (scanf("%d", &choice) != 1) {
                printf("Invalid input!\n");
                while (getchar() != '\n');
                return;
            }
            getchar();

            if (choice == 1)
                strcpy(complaints[i].status, "Pending");
            else if (choice == 2)
                strcpy(complaints[i].status, "Resolved");
            else {
                printf("Invalid choice!\n");
                return;
            }

            printf("Status updated successfully!\n");
            return;
        }
    }

    printf("Complaint ID not found.\n");
}

void displayByPriority() {
    if (count == 0) {
        printf("No complaints found.\n");
        return;
    }

    printf("\n--- Priority Sorted Complaints ---\n");

    for (int p = 1; p <= 3; p++) {
        for (int i = 0; i < count; i++) {
            if (complaints[i].priority == p) {
                printf("ID: %d | Title: %s | Priority: %d | Status: %s\n",
                       complaints[i].id,
                       complaints[i].title,
                       complaints[i].priority,
                       complaints[i].status);
            }
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Complaint Priority Manager =====\n");
        printf("1. Add Complaint\n");
        printf("2. Display All Complaints\n");
        printf("3. Update Complaint Status\n");
        printf("4. Display by Priority\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice) {
            case 1:
                addComplaint();
                break;
            case 2:
                displayComplaints();
                break;
            case 3:
                updateStatus();
                break;
            case 4:
                displayByPriority();
                break;
            case 5:
                printf("Program closed.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
