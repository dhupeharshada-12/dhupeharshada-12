#include<stdio.h>

int main()
{
    int choice, pin = 1234;
    int enteredPin;
    float balance = 5000, amount;

    printf("===== ATM MACHINE =====\n");

    printf("Enter ATM PIN: ");
    scanf("%d",&enteredPin);

    if(enteredPin != pin)
    {
        printf("Incorrect PIN");
        return 0;
    }

    do
    {
        printf("\n===== MENU =====\n");

        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Current Balance = %.2f\n",balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f",&amount);

                balance = balance + amount;

                printf("Deposit Successful\n");
                printf("Updated Balance = %.2f\n",balance);
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f",&amount);

                if(amount <= balance)
                {
                    balance = balance - amount;

                    printf("Withdrawal Successful\n");
                    printf("Remaining Balance = %.2f\n",balance);
                }
                else
                {
                    printf("Insufficient Balance\n");
                }

                break;

            case 4:
                printf("Thank You for Using ATM\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 4);

    return 0;
}
