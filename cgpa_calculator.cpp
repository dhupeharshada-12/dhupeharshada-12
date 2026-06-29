#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int subjects;
    float gradePoint, total = 0, cgpa;

    cout << "========== CGPA Calculator ==========" << endl;
    cout << "Enter Number of Subjects: ";
    cin >> subjects;

    for(int i = 1; i <= subjects; i++)
    {
        cout << "Enter Grade Point for Subject " << i << " (0 - 10): ";
        cin >> gradePoint;

        if(gradePoint < 0 || gradePoint > 10)
        {
            cout << "Invalid Grade Point! Enter again." << endl;
            i--;
            continue;
        }

        total += gradePoint;
    }

    cgpa = total / subjects;

    cout << fixed << setprecision(2);
    cout << "\nYour CGPA is: " << cgpa << endl;

    if(cgpa >= 9.0)
        cout << "Grade: O (Outstanding)" << endl;
    else if(cgpa >= 8.0)
        cout << "Grade: A+" << endl;
    else if(cgpa >= 7.0)
        cout << "Grade: A" << endl;
    else if(cgpa >= 6.0)
        cout << "Grade: B" << endl;
    else if(cgpa >= 5.0)
        cout << "Grade: C" << endl;
    else
        cout << "Grade: F (Fail)" << endl;

    return 0;
}
