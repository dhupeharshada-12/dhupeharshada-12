#include<stdio.h>

int main()
{
    int totalRooms = 20;
    int bookedRooms = 0;
    int choice, rooms;

    do
    {
        printf("\n===== Hotel Room Booking System =====\n");

        printf("1. Show Available Rooms\n");
        printf("2. Book Rooms\n");
        printf("3. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Available Rooms: %d\n",
                       totalRooms - bookedRooms);
                break;

            case 2:
                printf("Enter Number of Rooms to Book: ");
                scanf("%d", &rooms);

                if(bookedRooms + rooms <= totalRooms)
                {
                    bookedRooms += rooms;

                    printf("Room Booking Successful!\n");

                    printf("Remaining Rooms: %d\n",
                           totalRooms - bookedRooms);
                }
                else
                {
                    printf("Not Enough Rooms Available!\n");
                }

                break;

            case 3:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 3);

    return 0;
}
