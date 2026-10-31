#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 100

struct Room {
    int roomNumber;
    char roomType[30];
    float price;
    int isBooked;
};

void displayRoom(struct Room room) {
    printf("\nRoom Number: %d\n", room.roomNumber);
    printf("Room Type: %s\n", room.roomType);
    printf("Price Per Night: Rs. %.2f\n", room.price);
    printf("Status: %s\n",
           room.isBooked ? "Booked" : "Available");
    printf("----------------------------\n");
}

int main() {
    struct Room rooms[MAX_ROOMS];
    int count = 0;
    int choice;

    do {
        printf("\n===== SMART HOTEL ROOM MANAGER =====\n");
        printf("1. Add Room\n");
        printf("2. View All Rooms\n");
        printf("3. Search Room\n");
        printf("4. Book Room\n");
        printf("5. Cancel Booking\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {

            case 1: {
                if (count >= MAX_ROOMS) {
                    printf("Room storage is full!\n");
                    break;
                }

                int number;
                int duplicate = 0;

                printf("Enter room number: ");
                scanf("%d", &number);

                for (int i = 0; i < count; i++) {
                    if (rooms[i].roomNumber == number) {
                        duplicate = 1;
                        break;
                    }
                }

                if (duplicate) {
                    printf("Room number already exists!\n");
                    break;
                }

                rooms[count].roomNumber = number;

                printf("Enter room type: ");
                scanf(" %29[^\n]", rooms[count].roomType);

                printf("Enter price per night: ");
                scanf("%f", &rooms[count].price);

                if (rooms[count].price <= 0) {
                    printf("Invalid room price!\n");
                    break;
                }

                rooms[count].isBooked = 0;

                count++;

                printf("Room added successfully!\n");
                break;
            }

            case 2:
                if (count == 0) {
                    printf("No rooms registered.\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        displayRoom(rooms[i]);
                    }
                }
                break;

            case 3: {
                int number;
                int found = 0;

                printf("Enter room number to search: ");
                scanf("%d", &number);

                for (int i = 0; i < count; i++) {
                    if (rooms[i].roomNumber == number) {
                        displayRoom(rooms[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Room not found!\n");
                }
                break;
            }

            case 4: {
                int number;
                int found = 0;

                printf("Enter room number to book: ");
                scanf("%d", &number);

                for (int i = 0; i < count; i++) {
                    if (rooms[i].roomNumber == number) {
                        found = 1;

                        if (rooms[i].isBooked) {
                            printf("Room is already booked!\n");
                        } else {
                            rooms[i].isBooked = 1;
                            printf("Room booked successfully!\n");
                        }
                        break;
                    }
                }

                if (!found) {
                    printf("Room not found!\n");
                }
                break;
            }

            case 5: {
                int number;
                int found = 0;

                printf("Enter room number to cancel booking: ");
                scanf("%d", &number);

                for (int i = 0; i < count; i++) {
                    if (rooms[i].roomNumber == number) {
                        found = 1;

                        if (!rooms[i].isBooked) {
                            printf("Room is not currently booked!\n");
                        } else {
                            rooms[i].isBooked = 0;
                            printf("Booking cancelled successfully!\n");
                        }
                        break;
                    }
                }

                if (!found) {
                    printf("Room not found!\n");
                }
                break;
            }

            case 6:
                printf("Thank you for using Hotel Room Manager!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
