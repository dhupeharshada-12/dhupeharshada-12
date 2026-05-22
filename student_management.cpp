#include<iostream>
using namespace std;

class Student
{
    int rollNo;
    string name;
    float marks;

public:

    void getData()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayData()
    {
        cout << "\n===== Student Details =====" << endl;

        cout << "Roll Number : " << rollNo << endl;
        cout << "Student Name : " << name << endl;
        cout << "Marks : " << marks << endl;

        if(marks >= 75)
            cout << "Grade : A" << endl;

        else if(marks >= 60)
            cout << "Grade : B" << endl;

        else if(marks >= 40)
            cout << "Grade : C" << endl;

        else
            cout << "Grade : Fail" << endl;
    }
};

int main()
{
    Student s;

    cout << "===== Student Management System =====" << endl;

    s.getData();
    s.displayData();

    return 0;
}
