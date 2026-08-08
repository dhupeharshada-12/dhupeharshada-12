#include <stdio.h>

int main() {
    int choice, quantity;
    int totalItems = 0;
    float totalBill = 0;

    do {
        printf("\n===== RESTAURANT ORDER SYSTEM =====\n");
        printf("1. Pizza      - Rs. 200\n");
        printf("2. Burger     - Rs. 120\n");
        printf("3. Sandwich   - Rs. 100\n");
        printf("4. Pasta      - Rs. 150\n");
        printf("5. View Bill\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                totalBill += quantity * 200;
                totalItems += quantity;
                printf("Pizza added to order!\n");
                break;

            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                totalBill += quantity * 120;
                totalItems += quantity;
                printf("Burger added to order!\n");
                break;

            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                totalBill += quantity * 100;
                totalItems += quantity;
                printf("Sandwich added to order!\n");
                break;

            case 4:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                totalBill += quantity * 150;
                totalItems += quantity;
                printf("Pasta added to order!\n");
                break;

            case 5:
                printf("\n========== BILL ==========\n");
                printf("Total Items : %d\n", totalItems);
                printf("Total Bill  : Rs. %.2f\n", totalBill);
                printf("==========================\n");
                break;

            case 6:
                printf("\nThank you! Visit again.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
