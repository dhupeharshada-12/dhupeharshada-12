#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int empId;
    string name;
    float basicSalary;
    float hra, da, tax, netSalary;

public:
    void input()
    {
        cout << "Enter Employee ID: ";
        cin >> empId;

        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }

    void calculate()
    {
        hra = basicSalary * 0.20;
        da = basicSalary * 0.10;
        tax = basicSalary * 0.05;

        netSalary = basicSalary + hra + da - tax;
    }

    void display()
    {
        cout << "\n========== PAYSLIP ==========\n";
        cout << "Employee ID   : " << empId << endl;
        cout << "Employee Name : " << name << endl;
        cout << fixed << setprecision(2);
        cout << "Basic Salary  : Rs. " << basicSalary << endl;
        cout << "HRA           : Rs. " << hra << endl;
        cout << "DA            : Rs. " << da << endl;
        cout << "Tax           : Rs. " << tax << endl;
        cout << "Net Salary    : Rs. " << netSalary << endl;
    }
};

int main()
{
    Employee emp;

    emp.input();
    emp.calculate();
    emp.display();

    return 0;
}
