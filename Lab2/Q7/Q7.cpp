#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    cout << "Enter a sentence: ";

    char ch;
    int alphabets = 0;
    int words = 0;
    bool inWord = false;

    while (ch != '\r') {
        ch = _getche();

        // Count alphabets
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
            alphabets++;
        }

        // Word detection
        if (ch != ' ' && !inWord){
            words++;
            inWord = true;
        }

        if (ch == ' '){
            inWord = false;
        }
    }

    cout << "\nNumber of alphabets: " << alphabets << endl;
    cout << "Number of words: " << words << endl;

    return 0;
}

