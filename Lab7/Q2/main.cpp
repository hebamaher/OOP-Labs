#include <iostream>
#include <cstring>
using namespace std;

class myTestClass {
public:

    // Add 2 integers
    int Add(int a, int b) {
        return a + b;
    }

    // Add 3 integers
    int Add(int a, int b, int c) {
        return a + b + c;
    }

    // Add (concatenate) 3 characters
    void Add(char c1, char c2, char c3) {
        cout << c1 << c2 << c3 << endl;
    }

    // Add (concatenate) 2 C-strings
    void Add(char* str1, char* str2) {
        cout << str1 << " " << str2 <<endl;
    }
};

int main() {
    myTestClass obj;

    // Test integer overloads
    cout << "Add(3, 4) = " << obj.Add(3, 4) << endl;
    cout << "Add(1, 2, 3) = " << obj.Add(1, 2, 3) << endl;

    // Test char overload
    obj.Add('A', 'B', 'C');

    // Test string overload
    char* s1 = "Hello ";
    char* s2 = "World!";
    obj.Add(s1, s2);

    return 0;
}
