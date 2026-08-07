#include <stdio.h>

int main() {
    int choice;
    int seats = 40;
    int booked = 0;
    int tickets;
    float price = 250.0;
    float total;

    do {
        printf("\n===== BUS TICKET BOOKING SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. View Available Seats\n");
        printf("3. View Booking Summary\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter number of tickets: ");
                scanf("%d", &tickets);

                if (tickets > 0 && tickets <= (seats - booked)) {
                    booked += tickets;
                    total = tickets * price;

                    printf("\nBooking Successful!\n");
                    printf("Tickets Booked : %d\n", tickets);
                    printf("Total Amount   : Rs. %.2f\n", total);
                }
                else {
                    printf("Invalid number of tickets or insufficient seats!\n");
                }
                break;

            case 2:
                printf("\nAvailable Seats: %d\n", seats - booked);
                break;

            case 3:
                printf("\n===== BOOKING SUMMARY =====\n");
                printf("Total Seats    : %d\n", seats);
                printf("Booked Seats   : %d\n", booked);
                printf("Available Seats: %d\n", seats - booked);
                printf("Ticket Price   : Rs. %.2f\n", price);
                break;

            case 4:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
