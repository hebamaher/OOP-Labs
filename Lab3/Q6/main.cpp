#include <iostream>
using namespace std;

//Q6
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    int size = s.size();
    int freq[256] = {0};

    // Count frequencies
    for (int i = 0; i < size; i++)
        freq[s[i]]++;

    cout << "\nCharacter Frequencies:\n";
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0)
            cout << "'" << (char)i << "' : " << freq[i] << endl;
    }

    return 0;
}
