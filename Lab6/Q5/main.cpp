#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MyLibrary.h"

using namespace std;

#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define HOME_KEY 71
#define END_KEY 79
#define DELETE_KEY 83
#define BACKSPACE_KEY 8
#define ENTER_KEY 13
#define ESC_KEY 27

#define X_OFFSET 10
#define Y_OFFSET 5

string LineEditor(int maxWidth)
{
    int len = 0;
    int cursor = 0;
    char ch;

    char* buffer = new char[maxWidth];

    textattr(0x70);
    gotoxy(X_OFFSET, Y_OFFSET);

    while (true)
    {
        gotoxy(X_OFFSET + cursor, Y_OFFSET);
        ch = _getch();

        if (ch == -32 || ch == 0 || ch == 224)
        {
            ch = _getch();

            switch (ch)
            {
            case LEFT_ARROW:
                if (cursor > 0)
                    cursor--;
                break;

            case RIGHT_ARROW:
                if (cursor < len)
                    cursor++;
                break;

            case HOME_KEY:
                cursor = 0;
                break;

            case END_KEY:
                cursor = len;
                break;

            case DELETE_KEY:
                if (cursor < len)
                {
                    for (int i = cursor; i < len - 1; i++)
                        buffer[i] = buffer[i + 1];

                    len--;
                }
                break;
            }
        }
        else
        {
            switch (ch)
            {
            case ENTER_KEY:
                cout << endl;
                buffer[len] = '\0';
                return string(buffer);

            case ESC_KEY:
                cout << endl;
                buffer[len] = '\0';
                return string(buffer);

            case BACKSPACE_KEY:
                if (cursor > 0)
                {
                    for (int i = cursor - 1; i < len - 1; i++)
                        buffer[i] = buffer[i + 1];

                    cursor--;
                    len--;
                }
                break;

            default:
                if (ch >= 32 && ch <= 126)
                {
                    // Overwrite inside existing text → DO NOT grow length
                    if (cursor < len) {
                    buffer[cursor] = ch;
                }
                    // Typing at the end -> append
                    else if (cursor == len && len < maxWidth) {
                    buffer[len] = ch;
                    len++;
                }
                else {
                // Full line -> ignore input
                continue;
                }

                cursor++;

                }
                break;
            }
        }

        gotoxy(X_OFFSET, Y_OFFSET);
        for (int i = 0; i < len; i++)
            cout << buffer[i];

        // Clear remaining
        for (int i = len; i < maxWidth; i++)
            cout << ' ';

        gotoxy(X_OFFSET + cursor, Y_OFFSET);
    }

    delete[] buffer;
    return "";
}

int main() {
    int width;
    cout << "Enter max width of line editor: ";
    cin >> width;

    cout << "Type something: ";

    string result = LineEditor(width);

    cout << "\n"<<result << "\n";

    return 0;
}

