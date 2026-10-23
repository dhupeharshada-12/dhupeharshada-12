#include <stdio.h>

#define MAX_ORDERS 100

struct Order {
    int token;
    char item[50];
    int quantity;
    float price;
};

int main() {
    struct Order orders[MAX_ORDERS];
    int count = 0;
    int choice, searchToken, i, found;
    float total;

    do {
        printf("\n===== SMART CANTEEN TOKEN MANAGER =====\n");
        printf("1. Add New Order\n");
        printf("2. Display All Orders\n");
        printf("3. Search Order by Token\n");
        printf("4. Calculate Total Sales\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1:
                if (count >= MAX_ORDERS) {
                    printf("Order limit reached!\n");
                    break;
                }

                printf("Enter token number: ");
                scanf("%d", &orders[count].token);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (orders[i].token == orders[count].token) {
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Token number already exists!\n");
                    break;
                }

                printf("Enter food item (single word): ");
                scanf("%49s", orders[count].item);

                printf("Enter quantity: ");
                scanf("%d", &orders[count].quantity);

                printf("Enter price per item: ");
                scanf("%f", &orders[count].price);

                if (orders[count].quantity <= 0 ||
                    orders[count].price < 0) {
                    printf("Invalid quantity or price!\n");
                    break;
                }

                printf("Order added successfully!\n");
                count++;
                break;

            case 2:
                if (count == 0) {
                    printf("No orders available.\n");
                } else {
                    printf("\n--- All Canteen Orders ---\n");

                    for (i = 0; i < count; i++) {
                        printf("\nToken: %d\n", orders[i].token);
                        printf("Food: %s\n", orders[i].item);
                        printf("Quantity: %d\n", orders[i].quantity);
                        printf("Amount: Rs. %.2f\n",
                               orders[i].quantity * orders[i].price);
                    }
                }
                break;

            case 3:
                printf("Enter token number to search: ");
                scanf("%d", &searchToken);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (orders[i].token == searchToken) {
                        printf("\nOrder Found!\n");
                        printf("Token: %d\n", orders[i].token);
                        printf("Food: %s\n", orders[i].item);
                        printf("Quantity: %d\n", orders[i].quantity);
                        printf("Amount: Rs. %.2f\n",
                               orders[i].quantity * orders[i].price);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Order not found!\n");
                }
                break;

            case 4:
                total = 0;

                for (i = 0; i < count; i++) {
                    total += orders[i].quantity * orders[i].price;
                }

                printf("Total Sales: Rs. %.2f\n", total);
                break;

            case 5:
                printf("Thank you for using Canteen Token Manager!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
