#include <iostream>
using namespace std;

struct Employee {
    int ID;
    string Name;
    float Salary;
    float Bonus;
    float Deduction;
};

int main() {
    Employee emp;

    cout << "Enter Employee ID: ";
    cin >> emp.ID;

    cout << "Enter Employee Name: ";
    cin >> emp.Name;

    cout << "Enter Salary: ";
    cin >> emp.Salary;

    cout << "Enter Bonus: ";
    cin >> emp.Bonus;

    cout << "Enter Deduction: ";
    cin >> emp.Deduction;

    float netSalary = emp.Salary + emp.Bonus - emp.Deduction;

    cout << "\n===== Employee Data =====\n";
    cout << "ID: " << emp.ID << endl;
    cout << "Name: " << emp.Name << endl;
    cout << "Net Salary: " << netSalary << endl;

    return 0;
}
