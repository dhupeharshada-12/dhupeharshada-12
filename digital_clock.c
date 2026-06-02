#include<stdio.h>
#include<time.h>

int main()
{
    time_t t;
    struct tm *current;

    t = time(NULL);
    current = localtime(&t);

    printf("Current Time: %02d:%02d:%02d\n",
           current->tm_hour,
           current->tm_min,
           current->tm_sec);

    return 0;
}
