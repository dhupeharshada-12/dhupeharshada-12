#include <stdio.h>

int main() {
    int n, i;
    float temperature[100];
    float sum = 0, average;
    float highest, lowest;

    printf("===== TEMPERATURE STATISTICS ANALYZER =====\n");

    printf("Enter number of readings (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid number of readings!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter temperature %d: ", i + 1);
        scanf("%f", &temperature[i]);

        sum += temperature[i];
    }

    highest = lowest = temperature[0];

    for (i = 1; i < n; i++) {
        if (temperature[i] > highest) {
            highest = temperature[i];
        }

        if (temperature[i] < lowest) {
            lowest = temperature[i];
        }
    }

    average = sum / n;

    printf("\n===== ANALYSIS REPORT =====\n");
    printf("Total Readings: %d\n", n);
    printf("Highest Temperature: %.2f\n", highest);
    printf("Lowest Temperature: %.2f\n", lowest);
    printf("Average Temperature: %.2f\n", average);
    printf("Temperature Range: %.2f\n", highest - lowest);

    return 0;
}
