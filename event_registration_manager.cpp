#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Participant {
    string name;
    string event;
    int age;
};

int main() {
    vector<Participant> participants;
    int choice;

    do {
        cout << "\n===== EVENT REGISTRATION MANAGER =====\n";
        cout << "1. Register Participant\n";
        cout << "2. Show All Participants\n";
        cout << "3. Search by Event\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Participant p;

            cin.ignore();

            cout << "Enter participant name: ";
            getline(cin, p.name);

            cout << "Enter event name: ";
            getline(cin, p.event);

            cout << "Enter age: ";
            cin >> p.age;

            participants.push_back(p);

            cout << "Registration successful!\n";
        }

        else if (choice == 2) {
            if (participants.empty()) {
                cout << "No participants registered.\n";
            } else {
                cout << "\n--- Registered Participants ---\n";

                for (int i = 0; i < participants.size(); i++) {
                    cout << "\nParticipant " << i + 1 << endl;
                    cout << "Name  : " << participants[i].name << endl;
                    cout << "Event : " << participants[i].event << endl;
                    cout << "Age   : " << participants[i].age << endl;
                }
            }
        }

        else if (choice == 3) {
            string searchEvent;
            bool found = false;

            cin.ignore();

            cout << "Enter event name to search: ";
            getline(cin, searchEvent);

            for (const auto &p : participants) {
                if (p.event == searchEvent) {
                    cout << "\nName: " << p.name;
                    cout << "\nAge : " << p.age << endl;
                    found = true;
                }
            }

            if (!found) {
                cout << "No participant found for this event.\n";
            }
        }

        else if (choice == 4) {
            cout << "Thank you!\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
