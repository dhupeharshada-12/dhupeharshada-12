#include <stdio.h>

int main() {
    int pin, choice;
    float balance = 10000.0;
    float amount;

    printf("========== ATM SIMULATION ==========\n");

    printf("Enter your PIN: ");
    scanf("%d", &pin);

    if (pin != 1234) {
        printf("Incorrect PIN! Access Denied.\n");
        return 0;
    }

    printf("\nLogin Successful!\n");

    do {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nCurrent Balance: Rs. %.2f\n", balance);
                break;

            case 2:
                printf("\nEnter Deposit Amount: Rs. ");
                scanf("%f", &amount);

                if (amount > 0) {
                    balance += amount;
                    printf("Amount Deposited Successfully!\n");
                    printf("New Balance: Rs. %.2f\n", balance);
                } else {
                    printf("Invalid Amount!\n");
                }
                break;

            case 3:
                printf("\nEnter Withdrawal Amount: Rs. ");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("Invalid Amount!\n");
                }
                else if (amount > balance) {
                    printf("Insufficient Balance!\n");
                }
                else {
                    balance -= amount;
                    printf("Please Collect Your Cash.\n");
                    printf("Remaining Balance: Rs. %.2f\n", balance);
                }
                break;

            case 4:
                printf("\nThank you for using the ATM!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
