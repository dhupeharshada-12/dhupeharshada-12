#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    char str[10];
    int len, i;

    printf("\n enter a string = ");
    scanf("%s", str);

    len = strlen(str);

    for(i = len-1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    return 0;
}
