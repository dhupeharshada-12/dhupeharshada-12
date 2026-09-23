#include <stdio.h>

int main()
{
    int seats[3][5] = {
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1}
    };

    int row, seat;

    printf("Cinema Seat Layout\n");
    printf("1 = Available, 0 = Booked\n\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Row %d: ", i + 1);

        for (int j = 0; j < 5; j++)
        {
            printf("%d ", seats[i][j]);
        }

        printf("\n");
    }

    printf("\nEnter row number (1-3): ");
    scanf("%d", &row);

    printf("Enter seat number (1-5): ");
    scanf("%d", &seat);

    if (row < 1 || row > 3 || seat < 1 || seat > 5)
    {
        printf("Invalid seat selection!\n");
    }
    else if (seats[row - 1][seat - 1] == 1)
    {
        printf("Seat is available! 🎟️\n");
    }
    else
    {
        printf("Seat is already booked.\n");
    }

    return 0;
}
