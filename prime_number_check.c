#include<stdio.h>

int main()
{
    int num, i, flag = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num <= 1)
    {
        flag = 0;
    }
    else
    {
        for(i = 2; i <= num / 2; i++)
        {
            if(num % i == 0)
            {
                flag = 0;
                break;
            }
        }
    }

    if(flag)
        printf("%d is a Prime Number", num);
    else
        printf("%d is not a Prime Number", num);

    return 0;
}
