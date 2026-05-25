#include <iostream>
using namespace std;

int main()
{
    int totalSeats = 50;
    int bookedSeats = 0;
    int choice, seats;

    do
    {
        cout << "\n===== Movie Ticket Booking System =====" << endl;

        cout << "1. Show Available Seats" << endl;
        cout << "2. Book Tickets" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Available Seats: "
                     << totalSeats - bookedSeats << endl;
                break;

            case 2:
                cout << "Enter Number of Tickets: ";
                cin >> seats;

                if(bookedSeats + seats <= totalSeats)
                {
                    bookedSeats += seats;

                    cout << "Tickets Booked Successfully!" << endl;

                    cout << "Remaining Seats: "
                         << totalSeats - bookedSeats << endl;
                }
                else
                {
                    cout << "Not Enough Seats Available!" << endl;
                }

                break;

            case 3:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 3);

    return 0;
}
