#include <iostream>
#include <MyLibrary.h>
#include<conio.h>

//Q5

using namespace std;

int main()
{
    char menu[3][8] = {"New", "Display", "Exit"};
    int cur = 0;        // current selected menu index
    int ExitFlag = 0;   // exit flag for loop
    int ch;
    do {
        textattr(0x07); // normal text color
        clrscr();       // clear screen

        for(int i=0; i<3; i++) {
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
                    if(cur < 0) cur = 2;
                    break;
                case 80:  // down arrow
                    cur++;
                    if(cur > 2) cur = 0;
                    break;

                    case 71: //home
                    cur = 0;
                    break;
                case 79: //end
                    cur = 2;
                    break;
            }
            break;

        case 13:  // Enter
            switch(cur) {
                case 0:  // New
                    clrscr();
                    cout << "\n This is New Page....";
                    _getch();
                    break;
                case 1:  // Display
                    clrscr();
                    cout << "\n This is Display Page....";
                    _getch();
                    break;
                case 2:  // Exit
                    ExitFlag = 1;
                    clrscr();
                    cout << "\n Bye Bye....";
                    _getch();
                    break;
            }
            break;

                case 9: //tab
                    cur++;
                    if (cur>2)
                    cur=0;

                    break;
                case 27: //esc
                    ExitFlag=1;
                    break;
    }

    }while(ExitFlag==0);
    return 0;
}
