#include<stdio.h>
#include<conio.h>

void add();
void sub();
void mul();
void divi();

int main()
{
    clrscr();

    mul();
    add();
    sub();
    divi();

    getch();
    return 0;
}

void add()
{
    int a, b;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("\nAddition of %d and %d = %d\n", a, b, a + b);
}

void mul()
{
    int a, b;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("\nMultiplication of %d and %d = %d\n", a, b, a * b);
}

void sub()
{
    int a, b;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("\nSubtraction of %d and %d = %d\n", a, b, a - b);
}

void divi()
{
    int a, b;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);

    if(b != 0)
        printf("\nDivision of %d and %d = %d\n", a, b, a / b);
    else
        printf("\nDivision by zero is not allowed.\n");
}
