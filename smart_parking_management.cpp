#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Vehicle
{
public:
    int slot;
    string number;
    string type;
    int hours;
    bool occupied;

    Vehicle()
    {
        occupied = false;
    }
};

int main()
{
    Vehicle parking[10];
    int choice, total = 0;

    while (true)
    {
        cout << "\n========== SMART PARKING MANAGEMENT ==========\n";
        cout << "1. Park Vehicle\n";
        cout << "2. View Parking Status\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Remove Vehicle\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                if(total == 10)
                {
                    cout << "Parking Full!\n";
                    break;
                }

                int slot;
                cout << "Enter Slot (1-10): ";
                cin >> slot;

                if(slot < 1 || slot > 10)
                {
                    cout << "Invalid Slot!\n";
                    break;
                }

                if(parking[slot-1].occupied)
                {
                    cout << "Slot Already Occupied!\n";
                    break;
                }

                parking[slot-1].slot = slot;

                cout << "Enter Vehicle Number: ";
                cin >> parking[slot-1].number;

                cout << "Enter Vehicle Type (Car/Bike): ";
                cin >> parking[slot-1].type;

                cout << "Enter Parking Hours: ";
                cin >> parking[slot-1].hours;

                parking[slot-1].occupied = true;
                total++;

                cout << "Vehicle Parked Successfully.\n";
                break;
            }

            case 2:
            {
                cout << "\n---------------------------------------------\n";
                cout << left << setw(8) << "Slot"
                     << setw(15) << "Vehicle"
                     << setw(12) << "Type"
                     << setw(8) << "Hours";
                cout << "\n---------------------------------------------\n";

                for(int i=0;i<10;i++)
                {
                    if(parking[i].occupied)
                    {
                        cout << left << setw(8) << parking[i].slot
                             << setw(15) << parking[i].number
                             << setw(12) << parking[i].type
                             << setw(8) << parking[i].hours
                             << endl;
                    }
                }
                break;
            }

            case 3:
            {
                string num;
                bool found=false;

                cout << "Enter Vehicle Number: ";
                cin >> num;

                for(int i=0;i<10;i++)
                {
                    if(parking[i].occupied && parking[i].number==num)
                    {
                        cout << "\nVehicle Found\n";
                        cout << "Slot : " << parking[i].slot << endl;
                        cout << "Type : " << parking[i].type << endl;
                        cout << "Hours: " << parking[i].hours << endl;
                        found=true;
                    }
                }

                if(!found)
                    cout<<"Vehicle Not Found\n";

                break;
            }

            case 4:
            {
                string num;
                bool found=false;

                cout<<"Enter Vehicle Number: ";
                cin>>num;

                for(int i=0;i<10;i++)
                {
                    if(parking[i].occupied && parking[i].number==num)
                    {
                        int fee = parking[i].hours * 50;

                        cout<<"\nVehicle Removed Successfully\n";
                        cout<<"Parking Fee = Rs. "<<fee<<endl;

                        parking[i].occupied=false;
                        total--;
                        found=true;
                    }
                }

                if(!found)
                    cout<<"Vehicle Not Found\n";

                break;
            }

            case 5:
                cout<<"Thank You!\n";
                return 0;

            default:
                cout<<"Invalid Choice!\n";
        }
    }
}
