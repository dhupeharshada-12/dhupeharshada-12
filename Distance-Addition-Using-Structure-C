#include<stdio.h>

struct distance
{
    int feet;
    float inch;
} dist1, dist2, sum;

int main()
{
    printf("1st distance\n");

    printf("Enter feet: ");
    scanf("%d", &dist1.feet);

    printf("Enter inch: ");
    scanf("%f", &dist1.inch);

    printf("\n2nd distance\n");

    printf("Enter feet: ");
    scanf("%d", &dist2.feet);

    printf("Enter inch: ");
    scanf("%f", &dist2.inch);

    sum.feet = dist1.feet + dist2.feet;
    sum.inch = dist1.inch + dist2.inch;

    if(sum.inch >= 12)
    {
        sum.feet++;
        sum.inch = sum.inch - 12;
    }

    printf("\nSum of distance = %d' - %.2f\"", sum.feet, sum.inch);

    return 0;
}
