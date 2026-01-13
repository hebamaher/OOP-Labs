#include <iostream>
using namespace std;

//Q8

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int len = 0;
    int i = 0;
    while(s[i] != '\0'){
        len++;
        i++;
    }
    cout << "Length of string = " << len<< endl;

    return 0;
}
