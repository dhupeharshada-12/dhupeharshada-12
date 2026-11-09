#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Room {
    int roomNumber;
    int capacity;
    vector<string> students;
};

vector<Room> rooms;

void addRoom() {
    Room room;

    cout << "\nEnter Room Number: ";
    cin >> room.roomNumber;

    for (const Room &r : rooms) {
        if (r.roomNumber == room.roomNumber) {
            cout << "Room number already exists!\n";
            return;
        }
    }

    cout << "Enter Room Capacity: ";
    cin >> room.capacity;

    if (room.capacity <= 0) {
        cout << "Capacity must be greater than zero!\n";
        return;
    }

    rooms.push_back(room);

    cout << "Room added successfully!\n";
}

void displayRooms() {
    if (rooms.empty()) {
        cout << "\nNo rooms available.\n";
        return;
    }

    cout << "\n========== HOSTEL ROOM DETAILS ==========\n";

    for (const Room &room : rooms) {
        cout << "\nRoom Number: " << room.roomNumber;
        cout << "\nCapacity: " << room.capacity;
        cout << "\nOccupied: " << room.students.size();
        cout << "\nAvailable Beds: "
             << room.capacity - room.students.size();

        cout << "\nStudents: ";

        if (room.students.empty()) {
            cout << "None";
        } else {
            for (const string &name : room.students) {
                cout << "\n- " << name;
            }
        }

        cout << "\n-----------------------------------------\n";
    }
}

void allocateRoom() {
    int roomNumber;

    cout << "\nEnter Room Number: ";
    cin >> roomNumber;

    for (Room &room : rooms) {
        if (room.roomNumber == roomNumber) {

            if (room.students.size() >=
                static_cast<size_t>(room.capacity)) {
                cout << "Room is full!\n";
                return;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string name;

            cout << "Enter Student Name: ";
            getline(cin, name);

            if (name.empty()) {
                cout << "Student name cannot be empty!\n";
                return;
            }

            room.students.push_back(name);

            cout << "Room allocated successfully!\n";
            return;
        }
    }

    cout << "Room not found!\n";
}

void searchRoom() {
    int roomNumber;

    cout << "\nEnter Room Number to Search: ";
    cin >> roomNumber;

    for (const Room &room : rooms) {
        if (room.roomNumber == roomNumber) {
            cout << "\nRoom Found!";
            cout << "\nRoom Number: " << room.roomNumber;
            cout << "\nCapacity: " << room.capacity;
            cout << "\nOccupied Beds: " << room.students.size();
            cout << "\nAvailable Beds: "
                 << room.capacity - room.students.size();
            cout << "\n";
            return;
        }
    }

    cout << "Room not found!\n";
}

void removeStudent() {
    int roomNumber;

    cout << "\nEnter Room Number: ";
    cin >> roomNumber;

    for (Room &room : rooms) {
        if (room.roomNumber == roomNumber) {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string name;

            cout << "Enter Student Name to Remove: ";
            getline(cin, name);

            for (auto it = room.students.begin();
                 it != room.students.end(); ++it) {

                if (*it == name) {
                    room.students.erase(it);
                    cout << "Student removed successfully!\n";
                    return;
                }
            }

            cout << "Student not found in this room!\n";
            return;
        }
    }

    cout << "Room not found!\n";
}

void showSummary() {
    int totalCapacity = 0;
    int occupiedBeds = 0;

    for (const Room &room : rooms) {
        totalCapacity += room.capacity;
        occupiedBeds += static_cast<int>(room.students.size());
    }

    cout << "\n====== HOSTEL SUMMARY ======\n";
    cout << "Total Rooms: " << rooms.size();
    cout << "\nTotal Beds: " << totalCapacity;
    cout << "\nOccupied Beds: " << occupiedBeds;
    cout << "\nAvailable Beds: "
         << totalCapacity - occupiedBeds << "\n";
}

int main() {
    int choice;

    do {
        cout << "\n====== SMART HOSTEL MANAGER ======\n";
        cout << "1. Add New Room\n";
        cout << "2. Display All Rooms\n";
        cout << "3. Allocate Room\n";
        cout << "4. Search Room\n";
        cout << "5. Remove Student\n";
        cout << "6. Hostel Summary\n";
        cout << "7. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number!\n";
            continue;
        }

        switch (choice) {
            case 1:
                addRoom();
                break;

            case 2:
                displayRooms();
                break;

            case 3:
                allocateRoom();
                break;

            case 4:
                searchRoom();
                break;

            case 5:
                removeStudent();
                break;

            case 6:
                showSummary();
                break;

            case 7:
                cout << "\nThank you for using Smart Hostel Manager!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
