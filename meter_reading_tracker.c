#include <stdio.h>

int main()
{
    int previous, current, units;
    float bill;

    printf("Enter previous meter reading: ");
    scanf("%d", &previous);

    printf("Enter current meter reading: ");
    scanf("%d", &current);

    if (current < previous)
    {
        printf("Invalid meter reading!\n");
        return 0;
    }

    units = current - previous;

    if (units <= 100)
        bill = units * 2.50;
    else if (units <= 200)
        bill = 100 * 2.50 + (units - 100) * 4.00;
    else
        bill = 100 * 2.50 + 100 * 4.00 + (units - 200) * 6.00;

    printf("\n--- Electricity Bill ---\n");
    printf("Units Consumed: %d\n", units);
    printf("Total Bill: Rs. %.2f\n", bill);

    return 0;
}
