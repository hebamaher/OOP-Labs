#include <iostream>
#include "MyLibrary.h"
#include <conio.h>
using namespace std;

int main() {
    char choice;
    do{
        clrscr();
        gotoxy(50,10);
        cout << "===== MENU =====\n";
        gotoxy(50,11);
        cout << "a. Good Morning\n";
        gotoxy(50,12);
        cout << "b. Good Evening\n";
        gotoxy(50,13);
        cout << "c. Exit\n";
        gotoxy(50,14);
        cout << "Enter your choice: ";
        cin >> choice;
        clrscr();
        switch (choice) {
            clrscr();
            case 'A':
            case 'a':
                gotoxy(50,10);
                cout << "Good Morning" << endl;
                break;

            case 'B':
            case 'b':
                clrscr();
                gotoxy(50,10);
                cout << "Good Evening";
                break;

            case 'C':
            case 'c':
                clrscr();
                gotoxy(50,10);
                cout << "Exit" << endl;
                return 0;
                break;

            default:
                clrscr();
                gotoxy(50,10);
                cout << "Invalid choice" << endl;
        }
        getch();
    }while(choice != 'c' || choice != 'C');
    return 0;
}

