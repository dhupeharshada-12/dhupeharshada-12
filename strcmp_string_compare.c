#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int n;
    char str1[10],str2[10];
    printf("\n enter first string =");
    scanf("%s",str1);
    printf("\n enter second string =");
    scanf("%s",str2);
    n=strcmp(str1,str2);
    if(n<0)
    {
        printf("str1 is less than str2");
    }
    else if(n>0)
    {
        printf("str1 is greater than str2");
    }
    else
    {
        printf("\n str1 is equal to str2");
    }
    return 0;
}
