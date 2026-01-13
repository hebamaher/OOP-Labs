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
    Employee emp[5];

    cout << "Enter data for 5 employees:\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";

        cout << "ID: ";
        cin >> emp[i].ID;

        cout << "Name: ";
        cin >> emp[i].Name;

        cout << "Salary: ";
        cin >> emp[i].Salary;

        cout << "Bonus: ";
        cin >> emp[i].Bonus;

        cout << "Deduction: ";
        cin >> emp[i].Deduction;
    }

    cout << "\n===== Employees Data =====\n";

    for (int i = 0; i < 5; i++) {
        float netSalary = emp[i].Salary + emp[i].Bonus - emp[i].Deduction;

        cout << "\nEmployee " << i + 1 << ":\n";
        cout << "ID: " << emp[i].ID << endl;
        cout << "Name: " << emp[i].Name << endl;
        cout << "Net Salary: " << netSalary << endl;
    }

    return 0;
}
