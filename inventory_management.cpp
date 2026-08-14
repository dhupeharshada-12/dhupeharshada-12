#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    void addProduct() {
        cout << "\nEnter Product ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, name);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price: Rs. ";
        cin >> price;
    }

    int getId() const {
        return id;
    }

    void updateQuantity() {
        int newQuantity;

        cout << "Enter New Quantity: ";
        cin >> newQuantity;

        if (newQuantity >= 0) {
            quantity = newQuantity;
            cout << "Quantity Updated Successfully!\n";
        } else {
            cout << "Invalid Quantity!\n";
        }
    }

    void display() const {
        cout << "\n-----------------------------\n";
        cout << "Product ID : " << id << endl;
        cout << "Name       : " << name << endl;
        cout << "Quantity   : " << quantity << endl;
        cout << fixed << setprecision(2);
        cout << "Price      : Rs. " << price << endl;
    }
};

int main() {
    vector<Product> products;
    int choice;

    do {
        cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Quantity\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            Product p;
            p.addProduct();
            products.push_back(p);
            cout << "Product Added Successfully!\n";
        }

        else if (choice == 2) {
            if (products.empty()) {
                cout << "No Products Found!\n";
            } else {
                for (const Product &p : products)
                    p.display();
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter Product ID: ";
            cin >> id;

            bool found = false;

            for (const Product &p : products) {
                if (p.getId() == id) {
                    p.display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Product Not Found!\n";
        }

        else if (choice == 4) {
            int id;
            cout << "Enter Product ID: ";
            cin >> id;

            bool found = false;

            for (Product &p : products) {
                if (p.getId() == id) {
                    p.updateQuantity();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Product Not Found!\n";
        }

        else if (choice == 5) {
            cout << "Thank You!\n";
        }

        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
