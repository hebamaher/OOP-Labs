#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MyLibrary.h"
using namespace std;

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

// Top-left of editor area on console
#define X_OFFSET 5
#define Y_OFFSET 3

// draw (or re-draw) the highlighted editing area (background)
void drawHighlightArea() {
    textattr(0x70); // highlighted attribute (background + foreground)
    for (int y = 0; y < MAX_LINES; y++) {
        gotoxy(X_OFFSET, Y_OFFSET + y);
        // print exactly MAX_COLS spaces to paint the background
        for (int x = 0; x < MAX_COLS; x++) cout << ' ';
    }
    textattr(0x07); // restore normal attribute
}

// helper to redraw current buffer lines into the highlighted area
void redrawLines(char lines[][MAX_COLS], int lens[], int lineCount) {
    // redraw the highlighted area first
    drawHighlightArea();

    // print each existing line inside the highlight (clipped to MAX_COLS)
    textattr(0x70); // print with same highlight so chars are visible
    for (int i = 0; i < lineCount; i++) {
        gotoxy(X_OFFSET, Y_OFFSET + i);
        // print only actual content (no extra spaces here — background already painted)
        for (int j = 0; j < lens[i]; j++)
            cout << lines[i][j];
    }
    textattr(0x07);
}

int MultiLineEditor(char lines[][MAX_COLS], int lens[], int &lineCount)
{
    int cx = 0;     // cursor x (column)
    int cy = 0;     // cursor y (row)

    // initialize all lines and lens
    for (int i = 0; i < MAX_LINES; ++i) {
        lines[i][0] = '\0';
        lens[i] = 0;
    }

    lineCount = 1;  // start with 1 empty line

    // draw initial highlight and empty box
    drawHighlightArea();
    gotoxy(X_OFFSET + cx, Y_OFFSET + cy);

    while (true) {

        // ensure cursor displayed inside the highlight area
        gotoxy(X_OFFSET + cx, Y_OFFSET + cy);
        char ch = _getch();

        // ESC finishes editing and returns total lines
        if (ch == ESC_KEY)
            return lineCount;

        // extended keys (arrows, delete, home, end, pgup, pgdn)
        if (ch == 0 || ch == -32 || ch == 224) {
            ch = _getch();

            if (ch == LEFT_ARROW) {
                if (cx > 0) cx--;
                else if (cx == 0 && cy > 0) {
                    // move to end of previous line
                    cy--;
                    cx = lens[cy];
                }
            }

            else if (ch == RIGHT_ARROW) {
                if (cx < lens[cy]) cx++;
                else if (cx == lens[cy] && cy < lineCount - 1) {
                    // move to start of next line
                    cy++;
                    cx = 0;
                }
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
                // delete inside line
                if (cx < lens[cy]) {
                    for (int i = cx; i < lens[cy] - 1; i++)
                        lines[cy][i] = lines[cy][i + 1];
                    lens[cy]--;
                    lines[cy][lens[cy]] = '\0';
                }
                // at end of line -> merge with next line if exists
                else if (cx == lens[cy] && cy < lineCount - 1) {
                    int currLen = lens[cy];
                    int nextLen = lens[cy + 1];
                    // append next line to current (clip if overflow)
                    int spaceLeft = MAX_COLS - currLen - 1;
                    int copyCount = nextLen;
                    if (copyCount > spaceLeft) copyCount = spaceLeft;

                    for (int i = 0; i < copyCount; i++)
                        lines[cy][currLen + i] = lines[cy + 1][i];

                    lens[cy] = currLen + copyCount;
                    lines[cy][lens[cy]] = '\0';

                    // shift remaining lines up
                    for (int r = cy + 1; r < lineCount - 1; r++) {
                        memcpy(lines[r], lines[r + 1], MAX_COLS);
                        lens[r] = lens[r + 1];
                    }
                    // clear last line
                    lines[lineCount - 1][0] = '\0';
                    lens[lineCount - 1] = 0;
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
                // go to first character in the current page -> first column of current visible area
                cx = 0;
                cy = 0;
            }

            else if (ch == PGDN_KEY) {
                // go to last character in the current page -> end of current line
                cy = lineCount - 1;
                cx = lens[cy];

            }

            // redraw content after handling special key
            redrawLines(lines, lens, lineCount);
            gotoxy(X_OFFSET + cx, Y_OFFSET + cy);
            continue;
        }

        // BACKSPACE
        if (ch == BACKSPACE) {
            if (cx > 0) {
                // delete char left of cursor
                cx--;
                for (int i = cx; i < lens[cy] - 1; i++)
                    lines[cy][i] = lines[cy][i + 1];
                lens[cy]--;
                lines[cy][lens[cy]] = '\0';
            }
            else if (cx == 0 && cy > 0) {
                // merge current line into previous
                int prevLen = lens[cy - 1];
                int currLen = lens[cy];
                int spaceLeft = MAX_COLS - prevLen - 1;
                int copyCount = currLen;
                if (copyCount > spaceLeft) copyCount = spaceLeft;

                for (int i = 0; i < copyCount; i++)
                    lines[cy - 1][prevLen + i] = lines[cy][i];

                lens[cy - 1] = prevLen + copyCount;
                lines[cy - 1][lens[cy - 1]] = '\0';

                // shift lines up
                for (int r = cy; r < lineCount - 1; r++) {
                    memcpy(lines[r], lines[r + 1], MAX_COLS);
                    lens[r] = lens[r + 1];
                }
                // clear last
                lines[lineCount - 1][0] = '\0';
                lens[lineCount - 1] = 0;
                lineCount--;
                cy--;
                cx = prevLen; // move cursor to end of previous line
            }

            redrawLines(lines, lens, lineCount);
            gotoxy(X_OFFSET + cx, Y_OFFSET + cy);
            continue;
        }

        // ENTER -> insert new line after current
        if (ch == ENTER_KEY) {
            if (lineCount < MAX_LINES) {
                // shift lines down to make room
                for (int i = lineCount; i > cy + 1; i--) {
                    memcpy(lines[i], lines[i - 1], MAX_COLS);
                    lens[i] = lens[i - 1];
                }
                // split current line: move characters right of cursor to new line
                int rightCount = lens[cy] - cx;
                if (rightCount > 0) {
                    // move up to MAX_COLS-1 into new line
                    int copyCount = rightCount;
                    if (copyCount > MAX_COLS - 1) copyCount = MAX_COLS - 1;
                    for (int k = 0; k < copyCount; k++)
                        lines[cy + 1][k] = lines[cy][cx + k];
                    lens[cy + 1] = copyCount;
                    lines[cy + 1][lens[cy + 1]] = '\0';
                    // truncate current line
                    lens[cy] = cx;
                    lines[cy][lens[cy]] = '\0';
                } else {
                    // new line empty
                    lines[cy + 1][0] = '\0';
                    lens[cy + 1] = 0;
                }
                lineCount++;
                cy++;
                cx = 0;
            }
            redrawLines(lines, lens, lineCount);
            gotoxy(X_OFFSET + cx, Y_OFFSET + cy);
            continue;
        }

        // printable characters
        if (ch >= 32 && ch <= 126) {
            if (lens[cy] < MAX_COLS - 1) { // space for char + null
                // shift right
                for (int i = lens[cy]; i > cx; i--)
                    lines[cy][i] = lines[cy][i - 1];
                lines[cy][cx] = ch;
                lens[cy]++;
                lines[cy][lens[cy]] = '\0';
                cx++;
            }
            // else ignore (line full)
            redrawLines(lines, lens, lineCount);
            gotoxy(X_OFFSET + cx, Y_OFFSET + cy);
            continue;
        }

        // other keys ignored

    } // while

    return lineCount;
}

int main()
{
    char lines[MAX_LINES][MAX_COLS];
    int lens[MAX_LINES];
    int lineCount = 0;
    int finalLines = MultiLineEditor(lines, lens, lineCount);

    // after editing print result (clear screen)
    clrscr();
    cout << "\n\n Final Text \n";
    for (int i = 0; i < finalLines; i++)
        cout << lines[i] << endl;

    return 0;
}
