#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Expense {
private:
    string category;
    double amount;

public:
    Expense(string c, double a) {
        category = c;
        amount = a;
    }

    string getCategory() const {
        return category;
    }

    double getAmount() const {
        return amount;
    }

    void display() const {
        cout << left << setw(15) << category
             << "Rs. " << fixed << setprecision(2)
             << amount << endl;
    }
};

int main() {
    vector<Expense> expenses;
    int choice;

    do {
        cout << "\n===== EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Show Total Expense\n";
        cout << "4. Search by Category\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            string category;
            double amount;

            cin.ignore();

            cout << "\nEnter Category: ";
            getline(cin, category);

            cout << "Enter Amount: Rs. ";
            cin >> amount;

            if (amount > 0) {
                expenses.emplace_back(category, amount);
                cout << "Expense Added Successfully!\n";
            } else {
                cout << "Invalid Amount!\n";
            }
        }

        else if (choice == 2) {
            if (expenses.empty()) {
                cout << "\nNo Expenses Found!\n";
            } else {
                cout << "\n===== EXPENSE LIST =====\n";

                for (const Expense &expense : expenses) {
                    expense.display();
                }
            }
        }

        else if (choice == 3) {
            double total = 0;

            for (const Expense &expense : expenses) {
                total += expense.getAmount();
            }

            cout << "\nTotal Expense: Rs. "
                 << fixed << setprecision(2)
                 << total << endl;
        }

        else if (choice == 4) {
            string searchCategory;
            bool found = false;

            cin.ignore();

            cout << "\nEnter Category to Search: ";
            getline(cin, searchCategory);

            for (const Expense &expense : expenses) {
                if (expense.getCategory() == searchCategory) {
                    expense.display();
                    found = true;
                }
            }

            if (!found) {
                cout << "No Expense Found in This Category!\n";
            }
        }

        else if (choice == 5) {
            cout << "\nThank You!\n";
        }

        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
