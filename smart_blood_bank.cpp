#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Donor {
    int donorID;
    string name;
    string bloodGroup;
    string city;
    string contact;
};

vector<Donor> donors;

bool validBloodGroup(string group) {
    string groups[] = {
        "A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"
    };

    for (string g : groups) {
        if (group == g) {
            return true;
        }
    }

    return false;
}

void addDonor() {
    Donor d;

    cout << "\nEnter Donor ID: ";
    cin >> d.donorID;

    for (const Donor &donor : donors) {
        if (donor.donorID == d.donorID) {
            cout << "Donor ID already exists!\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Donor Name: ";
    getline(cin, d.name);

    cout << "Enter Blood Group: ";
    cin >> d.bloodGroup;

    if (!validBloodGroup(d.bloodGroup)) {
        cout << "Invalid blood group!\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter City: ";
    getline(cin, d.city);

    cout << "Enter Contact Number: ";
    getline(cin, d.contact);

    if (d.name.empty() || d.city.empty() || d.contact.empty()) {
        cout << "Fields cannot be empty!\n";
        return;
    }

    donors.push_back(d);

    cout << "\nDonor registered successfully!\n";
}

void displayDonors() {
    if (donors.empty()) {
        cout << "\nNo donor records available.\n";
        return;
    }

    cout << "\n========== DONOR RECORDS ==========\n";

    for (const Donor &d : donors) {
        cout << "\nDonor ID: " << d.donorID;
        cout << "\nName: " << d.name;
        cout << "\nBlood Group: " << d.bloodGroup;
        cout << "\nCity: " << d.city;
        cout << "\nContact: " << d.contact;
        cout << "\n-----------------------------------\n";
    }
}

void searchByBloodGroup() {
    string group;

    cout << "\nEnter Blood Group: ";
    cin >> group;

    if (!validBloodGroup(group)) {
        cout << "Invalid blood group!\n";
        return;
    }

    bool found = false;

    cout << "\nDonors with Blood Group " << group << ":\n";

    for (const Donor &d : donors) {
        if (d.bloodGroup == group) {
            cout << "\nName: " << d.name;
            cout << "\nCity: " << d.city;
            cout << "\nContact: " << d.contact << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No matching donor records found.\n";
    }
}

void searchByID() {
    int id;

    cout << "\nEnter Donor ID: ";
    cin >> id;

    for (const Donor &d : donors) {
        if (d.donorID == id) {
            cout << "\nDonor Found!";
            cout << "\nName: " << d.name;
            cout << "\nBlood Group: " << d.bloodGroup;
            cout << "\nCity: " << d.city << "\n";
            return;
        }
    }

    cout << "\nDonor not found!\n";
}

void showBloodGroupSummary() {
    string groups[] = {
        "A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"
    };

    cout << "\n====== DONOR GROUP SUMMARY ======\n";

    for (string group : groups) {
        int count = 0;

        for (const Donor &d : donors) {
            if (d.bloodGroup == group) {
                count++;
            }
        }

        cout << group << " : " << count << " donor(s)\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n====== SMART BLOOD BANK MANAGER ======\n";
        cout << "1. Register Donor\n";
        cout << "2. Display All Donors\n";
        cout << "3. Search by Blood Group\n";
        cout << "4. Search by Donor ID\n";
        cout << "5. Blood Group Summary\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number!\n";
            continue;
        }

        switch (choice) {
            case 1:
                addDonor();
                break;

            case 2:
                displayDonors();
                break;

            case 3:
                searchByBloodGroup();
                break;

            case 4:
                searchByID();
                break;

            case 5:
                showBloodGroupSummary();
                break;

            case 6:
                cout << "\nThank you for using Smart Blood Bank Manager!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
