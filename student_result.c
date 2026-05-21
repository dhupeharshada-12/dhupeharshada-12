#include<stdio.h>

int main()
{
    int rollno;
    char name[50];
    float sub1, sub2, sub3, total, percentage;

    printf("===== Student Result System =====\n");

    printf("Enter Roll Number: ");
    scanf("%d",&rollno);

    printf("Enter Student Name: ");
    scanf("%s",name);

    printf("Enter Marks of Subject 1: ");
    scanf("%f",&sub1);

    printf("Enter Marks of Subject 2: ");
    scanf("%f",&sub2);

    printf("Enter Marks of Subject 3: ");
    scanf("%f",&sub3);

    total = sub1 + sub2 + sub3;
    percentage = total / 3;

    printf("\n===== Student Result =====\n");

    printf("Roll Number : %d\n",rollno);
    printf("Student Name : %s\n",name);

    printf("Total Marks : %.2f\n",total);
    printf("Percentage : %.2f%%\n",percentage);

    if(percentage >= 75)
        printf("Grade : A\n");

    else if(percentage >= 60)
        printf("Grade : B\n");

    else if(percentage >= 40)
        printf("Grade : C\n");

    else
        printf("Grade : Fail\n");

    return 0;
}
