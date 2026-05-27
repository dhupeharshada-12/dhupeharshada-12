#include <iostream>
using namespace std;

int main()
{
    int choice, quantity;
    float totalBill = 0;

    do
    {
        cout << "\n===== Shopping Billing System =====" << endl;

        cout << "1. Rice    - ₹50/kg" << endl;
        cout << "2. Sugar   - ₹40/kg" << endl;
        cout << "3. Oil     - ₹120/litre" << endl;
        cout << "4. Milk    - ₹30/litre" << endl;
        cout << "5. Exit & Show Bill" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter Quantity: ";
                cin >> quantity;

                totalBill += quantity * 50;
                break;

            case 2:
                cout << "Enter Quantity: ";
                cin >> quantity;

                totalBill += quantity * 40;
                break;

            case 3:
                cout << "Enter Quantity: ";
                cin >> quantity;

                totalBill += quantity * 120;
                break;

            case 4:
                cout << "Enter Quantity: ";
                cin >> quantity;

                totalBill += quantity * 30;
                break;

            case 5:
                cout << "\n===== Final Bill =====" << endl;

                cout << "Total Amount: ₹" << totalBill << endl;

                cout << "Thank You for Shopping!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 5);

    return 0;
}
