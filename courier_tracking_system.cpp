#include <iostream>
#include <vector>
using namespace std;

class Courier
{
private:
    int id;
    string sender;
    string receiver;
    string status;

public:
    void addCourier()
    {
        cout << "Enter Courier ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Sender Name: ";
        getline(cin, sender);

        cout << "Enter Receiver Name: ";
        getline(cin, receiver);

        status = "In Transit";
    }

    int getId()
    {
        return id;
    }

    void updateStatus()
    {
        cout << "1. In Transit\n";
        cout << "2. Out for Delivery\n";
        cout << "3. Delivered\n";
        cout << "Choose Status: ";

        int choice;
        cin >> choice;

        switch(choice)
        {
            case 1: status = "In Transit"; break;
            case 2: status = "Out for Delivery"; break;
            case 3: status = "Delivered"; break;
            default: cout << "Invalid Choice\n";
        }
    }

    void display()
    {
        cout << "\n-----------------------------\n";
        cout << "Courier ID : " << id << endl;
        cout << "Sender     : " << sender << endl;
        cout << "Receiver   : " << receiver << endl;
        cout << "Status     : " << status << endl;
    }
};

int main()
{
    vector<Courier> couriers;
    int choice;

    do
    {
        cout << "\n===== Courier Tracking System =====\n";
        cout << "1. Add Courier\n";
        cout << "2. Update Status\n";
        cout << "3. View All Couriers\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            Courier c;
            c.addCourier();
            couriers.push_back(c);
        }
        else if(choice == 2)
        {
            int id;
            cout << "Enter Courier ID: ";
            cin >> id;

            bool found = false;

            for(auto &c : couriers)
            {
                if(c.getId() == id)
                {
                    c.updateStatus();
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Courier Not Found!\n";
        }
        else if(choice == 3)
        {
            if(couriers.empty())
                cout << "No Courier Records Available.\n";
            else
            {
                for(auto &c : couriers)
                    c.display();
            }
        }

    } while(choice != 4);

    cout << "Thank You!\n";
    return 0;
}
