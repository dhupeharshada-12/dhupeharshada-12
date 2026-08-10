#include <stdio.h>

int main() {
    char name[50];
    int bookId, lateDays;
    float fine = 0;

    printf("===== LIBRARY FINE CALCULATOR =====\n");

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Book ID: ");
    scanf("%d", &bookId);

    printf("Enter Number of Late Days: ");
    scanf("%d", &lateDays);

    if (lateDays <= 0) {
        fine = 0;
    }
    else if (lateDays <= 5) {
        fine = lateDays * 2;
    }
    else if (lateDays <= 10) {
        fine = (5 * 2) + ((lateDays - 5) * 5);
    }
    else {
        fine = (5 * 2) + (5 * 5) + ((lateDays - 10) * 10);
    }

    printf("\n========== FINE DETAILS ==========\n");
    printf("Student Name : %s\n", name);
    printf("Book ID      : %d\n", bookId);
    printf("Late Days    : %d\n", lateDays);
    printf("Total Fine   : Rs. %.2f\n", fine);
    printf("==================================\n");

    return 0;
}
