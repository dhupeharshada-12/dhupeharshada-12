#include<stdio.h>

int main()
{
    int matrix[4][4];
    int i, j;
    int primaryDiagonalsum = 0, secondaryDiagonalsum = 0;

    printf("\nEnter the elements of 4x4 matrix:\n");

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("Element [%d][%d] = ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nEntered 4x4 Matrix:\n");

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<4; i++)
    {
        primaryDiagonalsum += matrix[i][i];
        secondaryDiagonalsum += matrix[i][3-i];
    }

    printf("\nSum of primary diagonal elements = %d", primaryDiagonalsum);
    printf("\nSum of secondary diagonal elements = %d", secondaryDiagonalsum);
    printf("\nTotal diagonal sum = %d", primaryDiagonalsum + secondaryDiagonalsum);

    return 0;
}
