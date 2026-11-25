#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Donation {
    int id;
    string donorName;
    double amount;
};

struct Distribution {
    string receiver;
    double amount;
    string purpose;
};

class DonationManager {
private:
    vector<Donation> donations;
    vector<Distribution> distributions;
    int nextId = 1;

public:
    void addDonation() {
        Donation d;

        d.id = nextId++;

        cout << "Enter donor name: ";
        getline(cin, d.donorName);

        cout << "Enter donation amount: ";
        if (!(cin >> d.amount) || d.amount <= 0) {
            cout << "Invalid donation amount!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            nextId--;
            return;
        }
        cin.ignore(10000, '\n');

        donations.push_back(d);
        cout << "Donation recorded successfully!\n";
    }

    double getTotalDonations() const {
        double total = 0;

        for (const Donation& d : donations)
            total += d.amount;

        return total;
    }

    double getTotalDistributed() const {
        double total = 0;

        for (const Distribution& d : distributions)
            total += d.amount;

        return total;
    }

    void distributeDonation() {
        Distribution d;

        cout << "Enter receiver name: ";
        getline(cin, d.receiver);

        cout << "Enter distribution purpose: ";
        getline(cin, d.purpose);

        cout << "Enter distribution amount: ";
        if (!(cin >> d.amount) || d.amount <= 0) {
            cout << "Invalid amount!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }
        cin.ignore(10000, '\n');

        double available = getTotalDonations() - getTotalDistributed();

        if (d.amount > available) {
            cout << "Insufficient available funds!\n";
            cout << "Available balance: Rs. " << available << "\n";
            return;
        }

        distributions.push_back(d);
        cout << "Distribution recorded successfully!\n";
    }

    void displayDonations() const {
        if (donations.empty()) {
            cout << "No donations recorded.\n";
            return;
        }

        cout << "\n--- Donation Records ---\n";

        for (const Donation& d : donations) {
            cout << "ID: " << d.id
                 << " | Donor: " << d.donorName
                 << " | Amount: Rs. " << d.amount << "\n";
        }
    }

    void displayDistributions() const {
        if (distributions.empty()) {
            cout << "No distribution records.\n";
            return;
        }

        cout << "\n--- Distribution Records ---\n";

        for (const Distribution& d : distributions) {
            cout << "Receiver: " << d.receiver
                 << " | Purpose: " << d.purpose
                 << " | Amount: Rs. " << d.amount << "\n";
        }
    }

    void displaySummary() const {
        double donated = getTotalDonations();
        double distributed = getTotalDistributed();
        double balance = donated - distributed;

        cout << "\n===== Donation Summary =====\n";
        cout << fixed << setprecision(2);
        cout << "Total Donations: Rs. " << donated << "\n";
        cout << "Total Distributed: Rs. " << distributed << "\n";
        cout << "Available Balance: Rs. " << balance << "\n";
    }
};

int main() {
    DonationManager manager;
    int choice;

    while (true) {
        cout << "\n===== Donation Distribution Manager =====\n";
        cout << "1. Add Donation\n";
        cout << "2. Distribute Donation\n";
        cout << "3. View Donations\n";
        cout << "4. View Distribution Records\n";
        cout << "5. Donation Summary\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                manager.addDonation();
                break;

            case 2:
                manager.distributeDonation();
                break;

            case 3:
                manager.displayDonations();
                break;

            case 4:
                manager.displayDistributions();
                break;

            case 5:
                manager.displaySummary();
                break;

            case 6:
                cout << "Program closed.\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
