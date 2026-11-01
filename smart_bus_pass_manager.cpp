#include <iostream>
#include <string>
using namespace std;

struct BusPass {
    int passID;
    string passengerName;
    string passType;
    int validityDays;
    bool active;
};

BusPass passes[100];
int totalPasses = 0;

void createPass() {
    if (totalPasses >= 100) {
        cout << "\nPass limit reached!\n";
        return;
    }

    BusPass p;

    cout << "\nEnter Pass ID: ";
    cin >> p.passID;

    for (int i = 0; i < totalPasses; i++) {
        if (passes[i].passID == p.passID) {
            cout << "Pass ID already exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Passenger Name: ";
    getline(cin, p.passengerName);

    cout << "Enter Pass Type (Student/Regular): ";
    getline(cin, p.passType);

    cout << "Enter Validity Days: ";
    cin >> p.validityDays;

    if (p.validityDays <= 0) {
        cout << "Invalid validity period!\n";
        return;
    }

    p.active = true;
    passes[totalPasses++] = p;

    cout << "\nBus pass created successfully!\n";
}

void displayPasses() {
    if (totalPasses == 0) {
        cout << "\nNo bus passes registered.\n";
        return;
    }

    cout << "\n========== BUS PASS RECORDS ==========\n";

    for (int i = 0; i < totalPasses; i++) {
        cout << "\nPass ID: " << passes[i].passID;
        cout << "\nPassenger: " << passes[i].passengerName;
        cout << "\nPass Type: " << passes[i].passType;
        cout << "\nValidity: " << passes[i].validityDays << " days";
        cout << "\nStatus: "
             << (passes[i].active ? "Active" : "Inactive");
        cout << "\n--------------------------------------\n";
    }
}

void searchPass() {
    int id;
    cout << "\nEnter Pass ID to search: ";
    cin >> id;

    for (int i = 0; i < totalPasses; i++) {
        if (passes[i].passID == id) {
            cout << "\nPass Found!";
            cout << "\nPassenger: " << passes[i].passengerName;
            cout << "\nPass Type: " << passes[i].passType;
            cout << "\nStatus: "
                 << (passes[i].active ? "Active" : "Inactive");
            cout << "\n";
            return;
        }
    }

    cout << "\nPass not found!\n";
}

void deactivatePass() {
    int id;
    cout << "\nEnter Pass ID to deactivate: ";
    cin >> id;

    for (int i = 0; i < totalPasses; i++) {
        if (passes[i].passID == id) {
            if (!passes[i].active) {
                cout << "Pass is already inactive.\n";
            } else {
                passes[i].active = false;
                cout << "Bus pass deactivated successfully!\n";
            }
            return;
        }
    }

    cout << "\nPass not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n====== SMART BUS PASS MANAGER ======\n";
        cout << "1. Create New Pass\n";
        cout << "2. Display All Passes\n";
        cout << "3. Search Pass\n";
        cout << "4. Deactivate Pass\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                createPass();
                break;

            case 2:
                displayPasses();
                break;

            case 3:
                searchPass();
                break;

            case 4:
                deactivatePass();
                break;

            case 5:
                cout << "\nThank you for using Smart Bus Pass Manager!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
