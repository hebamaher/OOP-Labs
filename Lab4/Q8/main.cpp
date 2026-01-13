#include <iostream>
#include <string>
using namespace std;

// Employee struct
struct Employee {
    int ID;
    string Name;
    float Salary;
    float Bonus;
    float Deduction;
};

// Department struct
struct Department {
    int deptId;
    string deptName;
    Employee employees[5];   // Maximum 5 employees in department
    int empCount;            // Tracks how many employees are added
};

int main() {
    Department dept;

    // Input department info
    cout << "Enter Department ID: ";
    cin >> dept.deptId;

    cin.ignore();
    cout << "Enter Department Name: ";
    getline(cin, dept.deptName);

    // Initialize employee count
    dept.empCount = 0;

    char choice;
    do {
        if (dept.empCount >= 5) {
            cout << "Department is full! Cannot add more employees.\n";
            break;
        }

        // Add employee
        Employee &e = dept.employees[dept.empCount];

        cout << "\nAdding Employee #" << (dept.empCount + 1) << "\n";
        cout << "ID: ";
        cin >> e.ID;

        cin.ignore();
        cout << "Name: ";
        getline(cin, e.Name);

        cout << "Salary: ";
        cin >> e.Salary;

        cout << "Bonus: ";
        cin >> e.Bonus;

        cout << "Deduction: ";
        cin >> e.Deduction;

        dept.empCount++;

        cout << "Add another employee? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Display department info
    cout << "\n===== Department Info =====\n";
    cout << "Dept ID: " << dept.deptId << "\n";
    cout << "Dept Name: " << dept.deptName << "\n";

    cout << "\nEmployees:\n";
    for (int i = 0; i < dept.empCount; i++) {
        Employee &e = dept.employees[i];
        double netSalary = e.Salary + e.Bonus - e.Deduction;

        cout << "\nEmployee #" << (i + 1) << "\n";
        cout << "ID: " << e.ID << "\n";
        cout << "Name: " << e.Name << "\n";
        cout << "Salary: " << e.Salary << "\n";
        cout << "Bonus: " << e.Bonus << "\n";
        cout << "Deduction: " << e.Deduction << "\n";
        cout << "Net Salary: " << netSalary << "\n";
    }

    return 0;
}
