#include <iostream>
#include <vector>
#include "MyLibrary.h"
using namespace std;

int main() {
    int n;
    cout << "Enter an odd number for the magic box: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Only odd numbers are allowed!" << endl;
        return 0;
    }

    int row = 1;
    int col = n / 2 + 1;

    int consoleWidth = 120;
    int consoleHeight = 30;

    int boxWidth = n * 3;
    int boxHeight = n * 3;

    int startCol = (consoleWidth - boxWidth) / 2;
    int startRow = (consoleHeight - boxHeight) / 2;

    for(int i=1; i<=n*n; i++){
        gotoxy(startCol + col*3, startRow + row*3);
        cout<<i;
        if(i%n == 0){
            row++;
            if(row>n)
                row=1;
        }
        else{
            row--;
            if(row == 0)
                row = n;
            col--;
            if(col == 0)
                col = n;
        }
    }
    return 0;
}

