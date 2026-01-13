#include <iostream>
using namespace std;

//Q7
int main() {
    string s, result = "";
    cout << "Enter a string: ";
    getline(cin, s);
    int size = s.length();

    for(int i=0; i<size; i++) {
        if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') )
            result += s[i];
    }

    cout << "String with alphabet characters only: " << result << endl;

    return 0;
}
