#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class Vehicle {
public:
    int slotNumber;
    string ownerName;
    string vehicleNumber;
    string vehicleType;
    int hours;
    double charge;

    Vehicle(int slot, string owner, string number,
            string type, int duration) {

        slotNumber = slot;
        ownerName = owner;
        vehicleNumber = number;
        vehicleType = type;
        hours = duration;
        charge = calculateCharge();
    }

    double calculateCharge() const {
        double rate;

        if (vehicleType == "Car")
            rate = 30;
        else if (vehicleType == "Bike")
            rate = 15;
        else
            rate = 50;

        return rate * hours;
    }

    void display() const {
        cout << "\nParking Slot: " << slotNumber;
        cout << "\nOwner: " << ownerName;
        cout << "\nVehicle Number: " << vehicleNumber;
        cout << "\nVehicle Type: " << vehicleType;
        cout << "\nParking Hours: " << hours;
        cout << "\nParking Charge: Rs. "
             << fixed << setprecision(2) << charge << endl;
    }
};

class ParkingManager {
private:
    vector<Vehicle> vehicles;
    const int totalSlots = 20;

public:
    void parkVehicle() {
        if (vehicles.size() >= totalSlots) {
            cout << "\nParking is full!\n";
            return;
        }

        string owner, number, type;
        int hours;

        cout << "\nEnter Owner Name: ";
        getline(cin, owner);

        cout << "Enter Vehicle Number: ";
        getline(cin, number);

        cout << "\n1. Car";
        cout << "\n2. Bike";
        cout << "\n3. Other";
        cout << "\nSelect Vehicle Type: ";

        int choice;

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        if (choice == 1)
            type = "Car";
        else if (choice == 2)
            type = "Bike";
        else if (choice == 3)
            type = "Other";
        else {
            cout << "Invalid vehicle type!\n";
            return;
        }

        cout << "Enter Parking Hours: ";

        if (!(cin >> hours) || hours <= 0) {
            cout << "Invalid parking duration!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (const Vehicle& v : vehicles) {
            if (v.vehicleNumber == number) {
                cout << "\nVehicle is already registered!\n";
                return;
            }
        }

        int slot = 1;

        for (const Vehicle& v : vehicles) {
            if (v.slotNumber == slot)
                slot++;
            else
                break;
        }

        vehicles.emplace_back(
            slot, owner, number, type, hours
        );

        cout << "\nVehicle parked successfully!";
        cout << "\nAssigned Slot: " << slot;
        cout << "\nParking Charge: Rs. "
             << vehicles.back().charge << endl;
    }

    void viewVehicles() const {
        if (vehicles.empty()) {
            cout << "\nNo vehicles parked.\n";
            return;
        }

        cout << "\n===== PARKED VEHICLES =====\n";

        for (const Vehicle& v : vehicles) {
            v.display();
        }
    }

    void searchVehicle() const {
        string number;

        cout << "\nEnter Vehicle Number: ";
        getline(cin, number);

        for (const Vehicle& v : vehicles) {
            if (v.vehicleNumber == number) {
                cout << "\nVehicle Found!";
                v.display();
                return;
            }
        }

        cout << "\nVehicle not found!\n";
    }

    void removeVehicle() {
        string number;

        cout << "\nEnter Vehicle Number to Remove: ";
        getline(cin, number);

        for (auto it = vehicles.begin();
             it != vehicles.end(); ++it) {

            if (it->vehicleNumber == number) {
                cout << "\nVehicle removed successfully!";
                cout << "\nFinal Parking Charge: Rs. "
                     << it->charge << endl;

                vehicles.erase(it);
                return;
            }
        }

        cout << "\nVehicle not found!\n";
    }

    void showSummary() const {
        cout << "\n===== PARKING SUMMARY =====";
        cout << "\nTotal Parking Slots: " << totalSlots;
        cout << "\nOccupied Slots: " << vehicles.size();
        cout << "\nAvailable Slots: "
             << totalSlots - vehicles.size() << endl;
    }
};

int main() {
    ParkingManager manager;
    int choice;

    do {
        cout << "\n===== SMART PARKING MANAGER =====";
        cout << "\n1. Park Vehicle";
        cout << "\n2. View Parked Vehicles";
        cout << "\n3. Search Vehicle";
        cout << "\n4. Remove Vehicle";
        cout << "\n5. Parking Summary";
        cout << "\n6. Exit";

        cout << "\nEnter Your Choice: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                manager.parkVehicle();
                break;

            case 2:
                manager.viewVehicles();
                break;

            case 3:
                manager.searchVehicle();
                break;

            case 4:
                manager.removeVehicle();
                break;

            case 5:
                manager.showSummary();
                break;

            case 6:
                cout << "\nThank you for using Smart Parking Manager!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
