#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MyLibrary.h"
using namespace std;

// ---------------- Console helpers ----------------


// ---------------- Key codes ----------------
#define LEFT_ARROW   75
#define RIGHT_ARROW  77
#define UP_ARROW     72
#define DOWN_ARROW   80
#define PGUP_KEY     73
#define PGDN_KEY     81
#define HOME_KEY     71
#define END_KEY      79
#define DEL_KEY      83
#define ENTER_KEY    13
#define ESC_KEY      27
#define BACKSPACE    8

#define MAX_COLS    20
#define MAX_LINES   20

void highlightArea(int left, int top, int right, int bottom, int bgColor, int fgColor)
{
    int attr = bgColor * 16 + fgColor;

    for (int y = top; y <= bottom; y++)
    {
        gotoxy(left, y);
        textattr(attr);

        // Fill the line with spaces to color the whole area
        for (int x = left; x <= right; x++)
        {
            cout << " ";
        }
    }
    // Restore default text attributes
    textattr(0x07); // Light gray on black
}

int MultiLineEditor(char lines[][MAX_COLS], int lens[], int &lineCount)
{
    int cx = 0;     // cursor x
    int cy = 0;     // cursor y

    lineCount = 1;  // start with 1 empty line
    lines[0][0] = '\0';
    lens[0] = 0;

    for (int y = 0; y <= 20; y++)
    {
        gotoxy(cx, cy);
        textattr(0x70);

        // Fill the line with spaces to color the whole area
        for (int x = 0; x <= 20; x++)
        {
            cout << " ";
        }
    }
    while (true) {

        gotoxy(cx, cy);
        char ch = _getch();

        if (ch == ESC_KEY)
            return lineCount;

        if (ch == 0 || ch == -32 || ch == 224) {
            ch = _getch();

            if (ch == LEFT_ARROW) {
                if (cx > 0) cx--;
            }

            else if (ch == RIGHT_ARROW) {
                if (cx < lens[cy]) cx++;
            }

            else if (ch == UP_ARROW) {
                if (cy > 0) {
                    cy--;
                    if (cx > lens[cy]) cx = lens[cy];
                }
            }

            else if (ch == DOWN_ARROW) {
                if (cy < lineCount - 1) {
                    cy++;
                    if (cx > lens[cy]) cx = lens[cy];
                }
            }

            else if (ch == DEL_KEY) {
                if (cx < lens[cy]) {
                    for (int i = cx; i < lens[cy] - 1; i++)
                        lines[cy][i] = lines[cy][i + 1];
                    lens[cy]--;
                    lines[cy][lens[cy]] = '\0';
                }
                // At end of line → merge with next line
                else if (cx == lens[cy] && cy < lineCount - 1) {

                    int currLen = lens[cy];
                    int nextLen = lens[cy + 1];

                    // Append next line to current
                    for (int i = 0; i < nextLen; i++)
                        lines[cy][currLen + i] = lines[cy + 1][i];

                lens[cy] = currLen + nextLen;
                lines[cy][lens[cy]] = '\0';

                // Shift remaining lines UP
                for (int r = cy + 1; r < lineCount - 1; r++) {
                    memcpy(lines[r], lines[r + 1], MAX_COLS);
                    lens[r] = lens[r + 1];
                }

                lineCount--;
                }
            }

            else if (ch == HOME_KEY) {
                cx = 0;
            }

            else if (ch == END_KEY) {
                 cx = lens[cy];
            }
            else if (ch == PGUP_KEY) {
                cy = 0;
                cx = 0;
            }

            else if (ch == PGDN_KEY) {
                cy = lineCount - 1;
                cx = lens[cy];
            }

            // redraw screen
            system("cls");
            for (int i = 0; i < lineCount; i++)
                cout << lines[i] << endl;
            continue;
        }

        if (ch == BACKSPACE) {
            if (cx > 0) {
                cx--;
                for (int i = cx; i < lens[cy] - 1; i++)
                    lines[cy][i] = lines[cy][i + 1];
                lens[cy]--;
                lines[cy][lens[cy]] = '\0';
            }
            else if (cx == 0 && cy > 0) {

                int prevLen = lens[cy - 1];
                int currLen = lens[cy];

                // Append current line to previous line
                for (int i = 0; i < currLen; i++)
                    lines[cy - 1][prevLen + i] = lines[cy][i];

                lens[cy - 1] = prevLen + currLen;
                lines[cy - 1][lens[cy - 1]] = '\0';

                // Shift all lines UP
                for (int r = cy; r < lineCount - 1; r++) {
                    memcpy(lines[r], lines[r + 1], MAX_COLS);
                    lens[r] = lens[r + 1];
                }

            lineCount--;
            cy--;                // move to previous line
            cx = prevLen;        // cursor at old line’s end
            }
        }

        else if (ch == ENTER_KEY) {
            if (lineCount < MAX_LINES) {
                // shift lines down
                for (int i = lineCount; i > cy + 1; i--) {
                    strcpy(lines[i], lines[i - 1]);
                    lens[i] = lens[i - 1];
                }

                // create empty new line
                lineCount++;
                cy++;
                cx = 0;
                lines[cy][0] = '\0';
                lens[cy] = 0;
            }
        }
        else if (ch >= 32 && ch <= 126) {
            if (lens[cy] < MAX_COLS - 1) {
                // shift right
                for (int i = lens[cy]; i > cx; i--)
                    lines[cy][i] = lines[cy][i - 1];

                lines[cy][cx] = ch;
                cx++;
                lens[cy]++;
                lines[cy][lens[cy]] = '\0';
            }
        }
        system("cls");
        for (int i = 0; i < lineCount; i++)
            cout << lines[i] << endl;
    }
}

int main()
{
    char lines[20][20];
    int lens[20];
    int lineCount = 0;
    int finalLines = MultiLineEditor(lines, lens, lineCount);

    cout << "\n\n==== Final Text ====\n";
    for (int i = 0; i < finalLines; i++)
        cout << lines[i] << endl;

    return 0;
}
