#include <iostream>
#include <MyLibrary.h>
#include<conio.h>

#define SIZE    5
//Q5

using namespace std;

bool filled[SIZE] = {false};

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

void AddNewEmployee(Employee empArr[], int &size) {
    int index;
    cout << "Enter Employee's Index: ";
    cin >> index;
    if(index<SIZE){
        if (filled[index]){
            cout << "Index already Existed";
        }
        else{
            filled[index] = true;
            size++;

            Employee e;

            drawEmployeeForm();

            gotoxy(20, 5);
            cin >> e.ID;

            gotoxy(50, 5);
            cin.ignore();            // VERY IMPORTANT → clear leftover '\n'
            getline(cin, e.Name);

            gotoxy(20, 9);
            cin >> e.Salary;

            gotoxy(50, 9);
            cin >> e.Bonus;

            gotoxy(20, 13);
            cin >> e.Deduction;

            empArr[index] = e;
            }
    }
    else{
        cout << "Out of Bound";
    }
}

void displayEmployee(Employee empArr[], int size) {
    int empIndex;
    if (size == 0) {
        cout << "No employees to display.\n";
        return;
    }
    cout << "Enter Employee's Index" <<endl;
    cin >> empIndex;

    if(!filled[empIndex]){
        cout << "Invalid Employee ID\n";
    }
    else{
        float netSalary = empArr[empIndex].Salary + empArr[empIndex].Bonus - empArr[empIndex].Deduction;
        cout << "\n===== Employee Data =====\n";
        cout << "ID: " << empArr[empIndex].ID << endl;
        cout << "Name: " << empArr[empIndex].Name << endl;
        cout << "Net Salary: " << netSalary << endl;
    }
}

void displayAllEmployees(Employee empArr[], int size){
    if (size == 0) {
        cout << "No employees to display.\n";
        return;
    }
    for (int i = 0; i < SIZE; i++) {
            if(filled[i]){
                float netSalary = empArr[i].Salary + empArr[i].Bonus - empArr[i].Deduction;
                cout << "\n===== Employee Data =====\n";
                cout << "ID: " << empArr[i].ID << endl;
                cout << "Name: " << empArr[i].Name << endl;
                cout << "Net Salary: " << netSalary << endl;
            }
    }
}
void deleteEmployee(Employee empArr[], int &size){
    int empIndex;

    if (size == 0) {
        cout << "All Employees are already deleted.\n";
        return;
    }

    cout << "Enter Employee's Index" <<endl;
    cin >> empIndex;

        if(!filled[empIndex]){
            cout << "Invalid Employee Index\n";
        }
        else{
            filled[empIndex] = false;
            empArr[empIndex] = Employee();
            size--;
            cout << "Employee deleted successfully.\n";
        }
}

void deleteAllEmployees(Employee empArr[], int &size) {
    for (int i = 0; i < SIZE; i++) {
        empArr[i] = Employee(); // reset struct
        filled[i] = false;
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
    int index=0;
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
                    AddNewEmployee(empArr, size);
                    _getch();
                    break;

                case 1:  // Display
                    clrscr();
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
