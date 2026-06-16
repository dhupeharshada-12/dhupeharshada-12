#include<stdio.h>

void findLargest(int *a, int *b)
{
    if(*a > *b)
        printf("Largest Number = %d", *a);
    else
        printf("Largest Number = %d", *b);
}

int main()
{
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    findLargest(&num1, &num2);

    return 0;
}
