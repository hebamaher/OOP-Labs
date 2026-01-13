#include <iostream>
#include <MyLibrary.h>
#include<conio.h>

using namespace std;

#define X_OFFSET 5
#define Y_OFFSET 10
#define LINE_SIZE 20


#define LEFT_ARROW   75
#define RIGHT_ARROW  77
#define HOME_KEY     71
#define END_KEY      79
#define ESC_KEY      27
#define ENTER_KEY    13

string LineEditor() {
    int len = 0;
    char ch;
    char buffer[LINE_SIZE] = {0};
    int cursor = 0;
    bool ExitFlag = false;

    gotoxy(X_OFFSET + cursor, Y_OFFSET);
    textattr(0x70);

    do {
        gotoxy(X_OFFSET + cursor, Y_OFFSET);
        ch = _getch();

        switch (ch) {

        // ================== SPECIAL KEYS ==================
        case -32:
        case 0:
        case 224:
            ch = _getch();
            switch (ch) {

            case LEFT_ARROW:
                if (cursor > 0)
                    cursor--;
                break;

            case RIGHT_ARROW:
                if (cursor < len)
                    cursor++;
                //else
                    //cursor = 0;        // wrap to start
                break;

            case HOME_KEY:
                cursor = 0;
                break;

            case END_KEY:
                cursor = len;
                break;
            }
            continue;
        }

        switch(ch){

        case ESC_KEY:
            cout << endl;
            return string(buffer, len);

        case ENTER_KEY:
            cout << endl;
            return string(buffer, len);
        }

        if (ch >= 32 && ch <= 126) {

        // Overwrite inside existing text → DO NOT grow length
        if (cursor < len) {
            buffer[cursor] = ch;
        }
        // Typing at the end → append
        else if (cursor == len && len < LINE_SIZE) {
            buffer[len] = ch;
            len++;
        }
        else {
            // Full line → ignore input
            continue;
        }

        cursor++;

        // Redraw the line
        gotoxy(X_OFFSET, Y_OFFSET);
        for (int i = 0; i < len; i++)
            cout << buffer[i];

        // Clear rest
        for (int i = len; i < LINE_SIZE; i++)
            cout << ' ';

        // Move cursor back
        gotoxy(X_OFFSET + cursor, Y_OFFSET);
}

    } while (!ExitFlag);

    return "";
}

int main() {
    cout << "Type something: ";

    string result = LineEditor();

    cout << "\n"<<result << "\n";

    return 0;
}
