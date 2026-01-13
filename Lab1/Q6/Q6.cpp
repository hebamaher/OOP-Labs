#include <iostream>
using namespace std;

int main() {
    int a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> b;

    switch(op) {
        case '+':
            cout << "Result = " << a + b;
            break;
        case '-':
            cout << "Result = " << a - b;
            break;
        case '*':
            cout << "Result = " << (long)a * b;
            break;
        case '/':
            if (b != 0)
                cout << "Result = " << (double)a / b;
            else
                cout << "Error: Division by zero!";
            break;
        default:
            cout << "Invalid operator!";
    }
    return 0;
}
