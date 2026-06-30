#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Medicine
{
private:
    int id;
    string name;
    double price;
    int stock;

public:
    void addMedicine()
    {
        cout << "\nEnter Medicine ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Medicine Name: ";
        getline(cin, name);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Stock: ";
        cin >> stock;
    }

    void displayMedicine()
    {
        cout << left << setw(10) << id
             << setw(25) << name
             << setw(15) << price
             << setw(10) << stock << endl;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    int getStock()
    {
        return stock;
    }

    double getPrice()
    {
        return price;
    }

    void updateStock(int qty)
    {
        stock -= qty;
    }

    void editMedicine()
    {
        cin.ignore();

        cout << "Enter New Name: ";
        getline(cin, name);

        cout << "Enter New Price: ";
        cin >> price;

        cout << "Enter New Stock: ";
        cin >> stock;
    }
};

int main()
{
    Medicine med[100];

    int count = 0;
    int choice;

    while(true)
    {
        cout << "\n========== MEDICAL STORE MANAGEMENT ==========\n";
        cout << "1. Add Medicine\n";
        cout << "2. View Medicines\n";
        cout << "3. Search Medicine\n";
        cout << "4. Sell Medicine\n";
        cout << "5. Update Medicine\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
