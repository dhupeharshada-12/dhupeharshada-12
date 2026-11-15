#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class LostItem {
public:
    int id;
    string itemName;
    string location;
    string description;
    string status;

    LostItem(int itemId, string name, string place,
             string details, string itemStatus) {
        id = itemId;
        itemName = name;
        location = place;
        description = details;
        status = itemStatus;
    }

    void display() const {
        cout << "\nItem ID: " << id;
        cout << "\nItem Name: " << itemName;
        cout << "\nLocation: " << location;
        cout << "\nDescription: " << description;
        cout << "\nStatus: " << status << endl;
    }
};

class LostFoundManager {
private:
    vector<LostItem> items;
    int nextId = 1;

public:
    void addItem() {
        string name, location, description;
        int choice;

        cout << "\n1. Lost Item";
        cout << "\n2. Found Item";
        cout << "\nChoose type: ";

        if (!(cin >> choice) || (choice != 1 && choice != 2)) {
            cout << "Invalid choice!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Item Name: ";
        getline(cin, name);

        cout << "Enter Location: ";
        getline(cin, location);

        cout << "Enter Description: ";
        getline(cin, description);

        string status = (choice == 1) ? "Lost" : "Found";

        items.emplace_back(
            nextId++, name, location, description, status
        );

        cout << "\nRecord added successfully!";
        cout << "\nYour Item ID: " << nextId - 1 << endl;
    }

    void viewItems() const {
        if (items.empty()) {
            cout << "\nNo records available.\n";
            return;
        }

        cout << "\n===== LOST & FOUND RECORDS =====\n";

        for (const LostItem& item : items) {
            item.display();
        }
    }

    void searchItem() const {
        int id;

        cout << "\nEnter Item ID: ";

        if (!(cin >> id)) {
            cout << "Invalid ID!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        for (const LostItem& item : items) {
            if (item.id == id) {
                cout << "\nRecord Found!";
                item.display();
                return;
            }
        }

        cout << "\nRecord not found!\n";
    }

    void updateStatus() {
        int id;

        cout << "\nEnter Item ID: ";

        if (!(cin >> id)) {
            cout << "Invalid ID!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        for (LostItem& item : items) {
            if (item.id == id) {
                item.status = "Claimed";
                cout << "\nItem status updated to Claimed!\n";
                return;
            }
        }

        cout << "\nRecord not found!\n";
    }
};

int main() {
    LostFoundManager manager;
    int choice;

    do {
        cout << "\n===== SMART RAILWAY LOST & FOUND =====";
        cout << "\n1. Add Lost/Found Item";
        cout << "\n2. View All Records";
        cout << "\n3. Search Item";
        cout << "\n4. Mark Item as Claimed";
        cout << "\n5. Exit";

        cout << "\nEnter Your Choice: ";

        if (!(cin >> choice)) {
            cout << "\nPlease enter a valid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                manager.addItem();
                break;

            case 2:
                manager.viewItems();
                break;

            case 3:
                manager.searchItem();
                break;

            case 4:
                manager.updateStatus();
                break;

            case 5:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
