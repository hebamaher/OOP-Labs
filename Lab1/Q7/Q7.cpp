#include <iostream>
using namespace std;

int main() {
    int dividend, divisor;

    cout << "Enter dividend: ";
    cin >> dividend;

    cout << "Enter divisor: ";
    cin >> divisor;

    if (divisor == 0) {
        cout << "Error: Division by zero!";
        return 0;
    }

    int quotient = dividend / divisor;
    int remainder = dividend % divisor;

    cout << "Quotient = " << quotient << endl;
    cout << "Remainder = " << remainder;

    return 0;
}

