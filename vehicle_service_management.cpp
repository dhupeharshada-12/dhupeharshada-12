#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Vehicle
{
private:
    int serviceId;
    string ownerName;
    string vehicleNumber;
    string serviceType;
    float serviceCharge;

public:
    void addService()
    {
        cout << "Enter Service ID: ";
        cin >> serviceId;
        cin.ignore();

        cout << "Enter Owner Name: ";
        getline(cin, ownerName);

        cout << "Enter Vehicle Number: ";
        getline(cin, vehicleNumber);

        cout << "Enter Service Type (Oil Change/Repair/Wash): ";
        getline(cin, serviceType);

        cout << "Enter Service Charge: ";
        cin >> serviceCharge;
    }

    int getServiceId()
    {
        return serviceId;
    }

    void display()
    {
        cout << "\n----------------------------------\n";
        cout << "Service ID      : " << serviceId << endl;
        cout << "Owner Name      : " << ownerName << endl;
        cout << "Vehicle Number  : " << vehicleNumber << endl;
        cout << "Service Type    : " << serviceType << endl;
        cout << fixed << setprecision(2);
        cout << "Service Charge  : Rs. " << serviceCharge << endl;
    }
};

int main()
{
    vector<Vehicle> services;
    int choice;

    do
    {
        cout << "\n====== Vehicle Service Management ======\n";
        cout << "1. Add Service Record\n";
        cout << "2. View All Records\n";
        cout << "3. Search by Service ID\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            Vehicle v;
            v.addService();
            services.push_back(v);
            cout << "Record Added Successfully!\n";
        }
        else if(choice == 2)
        {
            if(services.empty())
            {
                cout << "No Records Found!\n";
            }
            else
            {
                for(auto &v : services)
                    v.display();
            }
        }
        else if(choice == 3)
        {
            int id;
            cout << "Enter Service ID: ";
            cin >> id;

            bool found = false;

            for(auto &v : services)
            {
                if(v.getServiceId() == id)
                {
                    v.display();
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Record Not Found!\n";
        }

    } while(choice != 4);

    cout << "Thank You!\n";
    return 0;
}
