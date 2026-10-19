#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

class Student {
public:
    string name;
    double percentage;
    double familyIncome;
    bool eligible;

    Student(string n, double p, double income) {
        name = n;
        percentage = p;
        familyIncome = income;
        eligible = (percentage >= 75 && familyIncome <= 300000);
    }

    void display() const {
        cout << left << setw(20) << name
             << setw(15) << percentage
             << setw(18) << familyIncome
             << (eligible ? "Eligible" : "Not Eligible")
             << '\n';
    }
};

class ScholarshipManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        string name;
        double percentage, income;

        cout << "Enter student name: ";
        getline(cin >> ws, name);

        if (name.empty()) {
            cout << "Name cannot be empty.\n";
            return;
        }

        cout << "Enter academic percentage: ";
        if (!(cin >> percentage) ||
            percentage < 0 || percentage > 100) {
            cout << "Enter a percentage between 0 and 100.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cout << "Enter annual family income (INR): ";
        if (!(cin >> income) || income < 0) {
            cout << "Enter a valid non-negative income.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        students.emplace_back(name, percentage, income);

        cout << "Student record added successfully!\n";
        cout << "Eligibility under demo rules: "
             << (students.back().eligible
                     ? "Eligible\n" : "Not Eligible\n");
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        cout << "\n========== STUDENT RECORDS ==========\n";
        cout << left << setw(20) << "Name"
             << setw(15) << "Percentage"
             << setw(18) << "Family Income"
             << "Status\n";

        cout << string(65, '-') << '\n';

        for (const Student& student : students) {
            student.display();
        }
    }

    void displayEligible() const {
        bool found = false;

        cout << "\n===== ELIGIBLE STUDENTS =====\n";

        for (const Student& student : students) {
            if (student.eligible) {
                student.display();
                found = true;
            }
        }

        if (!found) {
            cout << "No students meet the demo criteria.\n";
        }
    }

    void sortByPercentage() {
        sort(students.begin(), students.end(),
             [](const Student& a, const Student& b) {
                 return a.percentage > b.percentage;
             });

        cout << "Students sorted by percentage (highest first).\n";
        displayAll();
    }
};

int main() {
    ScholarshipManager manager;
    int choice;

    do {
        cout << "\n===== SCHOLARSHIP MANAGER =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Display Eligible Students\n";
        cout << "4. Sort by Percentage\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                manager.addStudent();
                break;

            case 2:
                manager.displayAll();
                break;

            case 3:
                manager.displayEligible();
                break;

            case 4:
                manager.sortByPercentage();
                break;

            case 5:
                cout << "Scholarship Manager closed. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
