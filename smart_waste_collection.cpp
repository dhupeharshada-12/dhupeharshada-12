#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct WasteRecord {
    int id;
    string location;
    string wasteType;
    double quantity;
};

void displayRecord(const WasteRecord& record) {
    cout << "\nRecord ID: " << record.id << '\n';
    cout << "Location: " << record.location << '\n';
    cout << "Waste Type: " << record.wasteType << '\n';
    cout << "Quantity: " << fixed << setprecision(2)
         << record.quantity << " kg\n";
    cout << "-----------------------------\n";
}

int main() {
    vector<WasteRecord> records;
    int nextId = 1001;
    int choice;

    do {
        cout << "\n===== SMART WASTE COLLECTION MANAGER =====\n";
        cout << "1. Add Collection Record\n";
        cout << "2. View All Records\n";
        cout << "3. Search Record by ID\n";
        cout << "4. Calculate Total Waste\n";
        cout << "5. Show Waste Type Summary\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                WasteRecord record;
                record.id = nextId++;

                cout << "Enter collection location: ";
                getline(cin, record.location);

                cout << "Enter waste type (Plastic/Paper/Organic): ";
                getline(cin, record.wasteType);

                cout << "Enter collected quantity in kg: ";

                if (!(cin >> record.quantity)) {
                    cout << "Invalid quantity!\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n'
                    );
                    nextId--;
                    break;
                }

                cin.ignore(
                    numeric_limits<streamsize>::max(), '\n'
                );

                if (record.location.empty() ||
                    record.wasteType.empty() ||
                    record.quantity <= 0) {
                    cout << "Please enter valid record details.\n";
                    nextId--;
                    break;
                }

                records.push_back(record);

                cout << "Record added successfully!\n";
                cout << "Your Record ID: " << record.id << '\n';
                break;
            }

            case 2:
                if (records.empty()) {
                    cout << "No collection records available.\n";
                } else {
                    for (const WasteRecord& record : records) {
                        displayRecord(record);
                    }
                }
                break;

            case 3: {
                int searchId;
                bool found = false;

                cout << "Enter record ID: ";

                if (!(cin >> searchId)) {
                    cout << "Invalid ID!\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n'
                    );
                    break;
                }

                cin.ignore(
                    numeric_limits<streamsize>::max(), '\n'
                );

                for (const WasteRecord& record : records) {
                    if (record.id == searchId) {
                        displayRecord(record);
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Record not found!\n";
                }
                break;
            }

            case 4: {
                double total = 0;

                for (const WasteRecord& record : records) {
                    total += record.quantity;
                }

                cout << fixed << setprecision(2);
                cout << "Total Waste Collected: "
                     << total << " kg\n";
                break;
            }

            case 5: {
                if (records.empty()) {
                    cout << "No records available.\n";
                    break;
                }

                string type;
                double total = 0;

                cout << "Enter waste type to summarize: ";
                getline(cin, type);

                for (const WasteRecord& record : records) {
                    if (record.wasteType == type) {
                        total += record.quantity;
                    }
                }

                cout << fixed << setprecision(2);
                cout << "Total " << type << " Waste: "
                     << total << " kg\n";
                break;
            }

            case 6:
                cout << "Thank you for using Waste Collection Manager!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
