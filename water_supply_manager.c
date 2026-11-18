#include <stdio.h>

#define MAX 100

struct Customer {
    int id;
    char name[50];
    float units;
    float bill;
    int paid;
};

struct Customer customers[MAX];
int count = 0;
int nextId = 1;

float calculateBill(float units) {
    float bill = 0;

    if (units <= 10) {
        bill = units * 5;
    }
    else if (units <= 30) {
        bill = (10 * 5) + (units - 10) * 8;
    }
    else {
        bill = (10 * 5) + (20 * 8)
             + (units - 30) * 12;
    }

    return bill;
}

void addCustomer() {
    if (count >= MAX) {
        printf("\nCustomer storage is full!\n");
        return;
    }

    struct Customer c;

    c.id = nextId++;

    printf("\nEnter Customer Name: ");
    scanf(" %49[^\n]", c.name);

    printf("Enter Water Consumption (units): ");

    if (scanf("%f", &c.units) != 1 || c.units < 0) {
        printf("Invalid consumption value!\n");
        return;
    }

    c.bill = calculateBill(c.units);
    c.paid = 0;

    customers[count] = c;
    count++;

    printf("\nCustomer registered successfully!");
    printf("\nCustomer ID: %d", c.id);
    printf("\nWater Bill: Rs. %.2f\n", c.bill);
}

void viewCustomers() {
    if (count == 0) {
        printf("\nNo customer records found.\n");
        return;
    }

    printf("\n===== WATER CONSUMPTION RECORDS =====\n");

    for (int i = 0; i < count; i++) {
        printf("\nCustomer ID: %d", customers[i].id);
        printf("\nName: %s", customers[i].name);
        printf("\nConsumption: %.2f units", customers[i].units);
        printf("\nBill Amount: Rs. %.2f", customers[i].bill);
        printf("\nPayment: %s\n",
               customers[i].paid ? "Paid" : "Unpaid");
    }
}

void searchCustomer() {
    int id;

    printf("\nEnter Customer ID: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            printf("\nCustomer Found!");
            printf("\nName: %s", customers[i].name);
            printf("\nUnits: %.2f", customers[i].units);
            printf("\nBill: Rs. %.2f", customers[i].bill);
            printf("\nPayment: %s\n",
                   customers[i].paid ? "Paid" : "Unpaid");
            return;
        }
    }

    printf("\nCustomer not found!\n");
}

void markPayment() {
    int id;

    printf("\nEnter Customer ID: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {

            if (customers[i].paid) {
                printf("\nBill is already paid!\n");
            }
            else {
                customers[i].paid = 1;
                printf("\nPayment marked as successful!\n");
            }

            return;
        }
    }

    printf("\nCustomer not found!\n");
}

void showSummary() {
    float totalBill = 0;
    int paidCount = 0;
    int unpaidCount = 0;

    for (int i = 0; i < count; i++) {
        totalBill += customers[i].bill;

        if (customers[i].paid)
            paidCount++;
        else
            unpaidCount++;
    }

    printf("\n===== WATER SUPPLY SUMMARY =====");
    printf("\nTotal Customers: %d", count);
    printf("\nTotal Bill Amount: Rs. %.2f", totalBill);
    printf("\nPaid Customers: %d", paidCount);
    printf("\nUnpaid Customers: %d\n", unpaidCount);
}

int main() {
    int choice;

    do {
        printf("\n\n===== SMART WATER SUPPLY MANAGER =====");
        printf("\n1. Add Customer");
        printf("\n2. View All Customers");
        printf("\n3. Search Customer");
        printf("\n4. Mark Bill as Paid");
        printf("\n5. View Summary");
        printf("\n6. Exit");

        printf("\n\nEnter Your Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addCustomer();
                break;

            case 2:
                viewCustomers();
                break;

            case 3:
                searchCustomer();
                break;

            case 4:
                markPayment();
                break;

            case 5:
                showSummary();
                break;

            case 6:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
