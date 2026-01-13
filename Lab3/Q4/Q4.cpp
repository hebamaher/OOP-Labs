#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    cout << "Press any key: ";

    int ch = getch();  // read first code

    if(ch == 0 || ch == 224 || ch==-32) {
        // extended key -> read second code
        int ext = getch();
        cout << "\nExtended key pressed.\nASCII value: " << ext << endl;
    }
    else {
        cout << "\nNormal key pressed.\nASCII value: " << ch << endl;
    }

    return 0;
}

