#include<stdio.h>

int main()
{
    int A[4][4], B[4][4], C[4][4], i, j;

    printf("\nEnter the elements of first 4x4 matrix:\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter the elements of second 4x4 matrix:\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nSum of matrices:\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
