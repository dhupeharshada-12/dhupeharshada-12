#include <stdio.h>

int main()
{
    int route, passengers;
    float fare, total;

    printf("===== BUS ROUTE FARE FINDER =====\n");
    printf("1. City Center -> Railway Station\n");
    printf("2. City Center -> Airport\n");
    printf("3. City Center -> Bus Stand\n");
    printf("4. City Center -> University\n");

    printf("\nEnter route number: ");
    scanf("%d", &route);

    printf("Enter number of passengers: ");
    scanf("%d", &passengers);

    switch (route)
    {
        case 1:
            fare = 20;
            break;

        case 2:
            fare = 80;
            break;

        case 3:
            fare = 30;
            break;

        case 4:
            fare = 40;
            break;

        default:
            printf("Invalid route!\n");
            return 0;
    }

    if (passengers <= 0)
    {
        printf("Invalid number of passengers!\n");
        return 0;
    }

    total = fare * passengers;

    printf("\n----- TRIP DETAILS -----\n");
    printf("Fare per passenger: Rs. %.2f\n", fare);
    printf("Passengers: %d\n", passengers);
    printf("Total Fare: Rs. %.2f\n", total);

    return 0;
}
