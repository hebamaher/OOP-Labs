#include <iostream>
using namespace std;

struct Employee {
    int ID;
    string Name;
    float Salary;
    float Bonus;
    float Deduction;
};

Employee AddNewEmployee() {
    Employee e;

    cout << "Enter Employee ID: ";
    cin >> e.ID;

    cout << "Enter Employee Name: ";
    cin >> e.Name;

    cout << "Enter Salary: ";
    cin >> e.Salary;

    cout << "Enter Bonus: ";
    cin >> e.Bonus;

    cout << "Enter Deduction: ";
    cin >> e.Deduction;

    return e;
}

void DisplayEmployee(Employee e) {
    float netSalary = e.Salary + e.Bonus - e.Deduction;

    cout << "\n===== Employee Data =====\n";
    cout << "ID: " << e.ID << endl;
    cout << "Name: " << e.Name << endl;
    cout << "Net Salary: " << netSalary << endl;
}

int main() {
    Employee emp;

    emp = AddNewEmployee();
    DisplayEmployee(emp);

    return 0;
}
