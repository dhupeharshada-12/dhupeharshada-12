#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Complaint {
    int id;
    string passengerName;
    string category;
    string description;
    string status;
};

int main() {
    vector<Complaint> complaints;
    int choice;
    int nextId = 1001;

    do {
        cout << "\n===== SMART RAILWAY COMPLAINT MANAGER =====\n";
        cout << "1. Register Complaint\n";
        cout << "2. View All Complaints\n";
        cout << "3. Search Complaint\n";
        cout << "4. Update Complaint Status\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                Complaint c;
                c.id = nextId++;
                c.status = "Pending";

                cout << "Enter passenger name: ";
                getline(cin, c.passengerName);

                cout << "Enter complaint category: ";
                getline(cin, c.category);

                cout << "Enter complaint description: ";
                getline(cin, c.description);

                complaints.push_back(c);

                cout << "\nComplaint registered successfully!\n";
                cout << "Your Complaint ID: " << c.id << "\n";
                break;
            }

            case 2: {
                if (complaints.empty()) {
                    cout << "No complaints registered yet.\n";
                    break;
                }

                cout << "\n--- All Complaints ---\n";

                for (const Complaint& c : complaints) {
                    cout << "\nComplaint ID: " << c.id << "\n";
                    cout << "Passenger: " << c.passengerName << "\n";
                    cout << "Category: " << c.category << "\n";
                    cout << "Description: " << c.description << "\n";
                    cout << "Status: " << c.status << "\n";
                    cout << "-----------------------------\n";
                }
                break;
            }

            case 3: {
                int searchId;
                bool found = false;

                cout << "Enter Complaint ID: ";

                if (!(cin >> searchId)) {
                    cout << "Invalid ID!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                for (const Complaint& c : complaints) {
                    if (c.id == searchId) {
                        cout << "\nComplaint Found!\n";
                        cout << "Passenger: " << c.passengerName << "\n";
                        cout << "Category: " << c.category << "\n";
                        cout << "Description: " << c.description << "\n";
                        cout << "Status: " << c.status << "\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Complaint not found!\n";
                }
                break;
            }

            case 4: {
                int updateId;
                bool found = false;

                cout << "Enter Complaint ID to update: ";

                if (!(cin >> updateId)) {
                    cout << "Invalid ID!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                for (Complaint& c : complaints) {
                    if (c.id == updateId) {
                        cout << "Enter new status (Pending/In Progress/Resolved): ";
                        getline(cin, c.status);

                        cout << "Complaint status updated successfully!\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Complaint not found!\n";
                }
                break;
            }

            case 5:
                cout << "Thank you for using Railway Complaint Manager!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
