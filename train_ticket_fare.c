#include <stdio.h>

int main()
{
    int age, distance, passengers;
    float fare, total;

    printf("Enter passenger age: ");
    scanf("%d", &age);

    printf("Enter travel distance (km): ");
    scanf("%d", &distance);

    printf("Enter number of passengers: ");
    scanf("%d", &passengers);

    if (distance <= 50)
        fare = 50;
    else if (distance <= 100)
        fare = 100;
    else if (distance <= 200)
        fare = 180;
    else
        fare = 250;

    if (age < 12)
        fare = fare * 0.50;
    else if (age >= 60)
        fare = fare * 0.70;

    total = fare * passengers;

    printf("\n--- Ticket Details ---\n");
    printf("Fare per passenger: %.2f\n", fare);
    printf("Passengers: %d\n", passengers);
    printf("Total Fare: %.2f\n", total);

    return 0;
}
