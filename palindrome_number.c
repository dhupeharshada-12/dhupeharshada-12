#include<stdio.h>

int main()
{
    int num, original, reverse = 0, rem;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    while(num != 0)
    {
        rem = num % 10;
        reverse = reverse * 10 + rem;
        num = num / 10;
    }

    if(original == reverse)
        printf("Palindrome Number");
    else
        printf("Not a Palindrome Number");

    return 0;
}
