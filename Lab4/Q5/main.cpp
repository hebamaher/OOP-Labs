#include <iostream>
#include <MyLibrary.h>
#include<conio.h>

#define SIZE    5
//Q5

using namespace std;

void drawEmployeeForm() {
    //system("cls");
    gotoxy(5, 5);  cout << "ID        : ";
    gotoxy(35, 5);  cout << "Name     : ";
    gotoxy(5, 9);  cout << "Salary    : ";
    gotoxy(35, 9); cout << "Bonus     : ";
    gotoxy(5, 13); cout << "Deduction : ";
}

struct Employee {
    int ID;
    string Name;
    float Salary;
    float Bonus;
    float Deduction;
};

Employee AddNewEmployee() {
    Employee e;

    drawEmployeeForm();

    gotoxy(20, 5);
    //cout << "Enter Employee ID: ";
    cin >> e.ID;

    gotoxy(50, 5);
    //cout << "Enter Employee Name: ";
    cin.ignore();            // VERY IMPORTANT → clear leftover '\n'
    getline(cin, e.Name);


    gotoxy(20, 9);
    //cout << "Enter Salary: ";
    cin >> e.Salary;

    gotoxy(50, 9);
    //cout << "Enter Bonus: ";
    cin >> e.Bonus;

    gotoxy(20, 13);
    //cout << "Enter Deduction: ";
    cin >> e.Deduction;

    return e;
}

void displayEmployee(Employee empArr[], int size) {
    int empID;
    int index = -1;

    if (size == 0) {
        cout << "No employees to display.\n";
        return;
    }
    cout << "Enter Employee's ID" <<endl;
    cin >> empID;

    for(int i=0; i<size; i++){
        if(empID == empArr[i].ID){
            index = i;
            break;
        }
    }
    if(index == -1){
        cout << "Invalid Employee ID\n";
    }
    else{
        float netSalary = empArr[index].Salary + empArr[index].Bonus - empArr[index].Deduction;
        cout << "\n===== Employee Data =====\n";
        cout << "ID: " << empArr[index].ID << endl;
        cout << "Name: " << empArr[index].Name << endl;
        cout << "Net Salary: " << netSalary << endl;
    }
}

void displayAllEmployees(Employee empArr[], int size){
    if (size == 0) {
        cout << "No employees to display.\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        float netSalary = empArr[i].Salary + empArr[i].Bonus - empArr[i].Deduction;
        cout << "\n===== Employee Data =====\n";
        cout << "ID: " << empArr[i].ID << endl;
        cout << "Name: " << empArr[i].Name << endl;
        cout << "Net Salary: " << netSalary << endl;
    }
}
void deleteEmployee(Employee empArr[], int &size){
    int index = -1;
    int empID;

    if (size == 0) {
        cout << "All Employees are already deleted.\n";
        return;
    }

    cout << "Enter Employee's ID" <<endl;
    cin >> empID;


    for(int i=0; i<size; i++){
        if(empID == empArr[i].ID){
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Invalid Employee ID\n";
    }

    // 2) Shift left
    for (int i = index; i < SIZE - 1; i++) {
        empArr[i] = empArr[i + 1];
    }
    cout << "Employee deleted successfully.\n";
    size--;
}

void deleteAllEmployees(Employee empArr[], int &size) {
    for (int i = 0; i < size; i++) {
    empArr[i] = Employee(); // reset struct
    }
    cout << "All employees deleted!\n";
    size = 0;
}

int main()
{
    string menu[6] = {"New", "Display", "Display All", "Delete", "Delete All", "Exit"};
    int cur = 0;        // current selected menu index
    int ExitFlag = 0;   // exit flag for loop
    int ch;
    int j=0;

    Employee empArr[SIZE];
    int size = 0;
    do {
        textattr(0x07); // normal text color
        clrscr();       // clear screen

        for(int i=0; i<6; i++) {
            if(cur == i)
                textattr(0x70); // highlighted color
            else
                textattr(0x07); // normal color

            gotoxy(50, i*3+7);  // position the menu
            cout << menu[i];     // print menu item
        }
    ch = _getch();
    switch(ch) {
        case -32: case 0: case 224:
            ch = _getch();
            switch(ch) {
                case 72:  // up arrow
                    cur--;
                    if(cur < 0) cur = 5;
                    break;
                case 80:  // down arrow
                    cur++;
                    if(cur > 5) cur = 0;
                    break;

                case 71: //home
                    cur = 0;
                    break;
                case 79: //end
                    cur = 5;
                    break;
            }
            break;

        case 13:  // Enter
            switch(cur) {
                case 0: // New
                    clrscr();
                    //cout << "\n This is New Page....";
                    if(j<SIZE){
                        Employee emp = AddNewEmployee();
                        empArr[j] = emp;
                        j++;
                        if(j>size){
                            size++;
                        }
                    }
                    else{
                        cout << "Out of Bound";
                    }
                    _getch();
                    break;

                case 1:  // Display
                    clrscr();
                    //cout << "\n This is Display Page....";
                    displayEmployee(empArr,size);
                    _getch();
                    break;
                case 2: // Display All
                    clrscr();
                    displayAllEmployees(empArr,size);
                    _getch();
                    break;
                case 3: // Delete
                    clrscr();
                    deleteEmployee(empArr,size);
                    _getch();
                    break;
                case 4: //Delete All
                    clrscr();
                    deleteAllEmployees(empArr,size);
                    _getch();
                    break;
                case 5: //Exit
                    ExitFlag = 1;
                    clrscr();
                    cout << "\n Bye Bye....";
                    _getch();
                    break;
            }
            break;

                case 9: //tab
                    cur++;
                    if (cur>5)
                    cur=0;

                    break;
                case 27: //esc
                    ExitFlag=1;
                    break;
    }

    }while(ExitFlag==0);
    return 0;
}
