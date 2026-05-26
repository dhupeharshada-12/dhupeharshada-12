#include<stdio.h>

int main()
{
    int customerID;
    char customerName[50];
    float units, billAmount;

    printf("===== Electricity Bill System =====\n");

    printf("Enter Customer ID: ");
    scanf("%d", &customerID);

    printf("Enter Customer Name: ");
    scanf("%s", customerName);

    printf("Enter Electricity Units Consumed: ");
    scanf("%f", &units);

    if(units <= 100)
    {
        billAmount = units * 5;
    }
    else if(units <= 300)
    {
        billAmount = units * 7;
    }
    else
    {
        billAmount = units * 10;
    }

    printf("\n===== Bill Details =====\n");

    printf("Customer ID: %d\n", customerID);
    printf("Customer Name: %s\n", customerName);
    printf("Units Consumed: %.2f\n", units);
    printf("Total Bill Amount: %.2f\n", billAmount);

    return 0;
}
