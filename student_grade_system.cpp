#include <iostream>
using namespace std;

int main()
{
    string name;
    int roll;
    float sub1, sub2, sub3, total, percentage;

    cout << "===== Student Grade Management System =====\n";

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Roll Number: ";
    cin >> roll;

    cout << "Enter Marks of Subject 1: ";
    cin >> sub1;

    cout << "Enter Marks of Subject 2: ";
    cin >> sub2;

    cout << "Enter Marks of Subject 3: ";
    cin >> sub3;

    total = sub1 + sub2 + sub3;
    percentage = total / 3;

    cout << "\n===== Student Result =====\n";
    cout << "Name : " << name << endl;
    cout << "Roll Number : " << roll << endl;
    cout << "Total Marks : " << total << endl;
    cout << "Percentage : " << percentage << "%" << endl;

    if (percentage >= 90)
        cout << "Grade : A+" << endl;

    else if (percentage >= 75)
        cout << "Grade : A" << endl;

    else if (percentage >= 60)
        cout << "Grade : B" << endl;

    else if (percentage >= 40)
        cout << "Grade : C" << endl;

    else
        cout << "Grade : Fail" << endl;

    cout << "\nThank You!" << endl;

    return 0;
}
