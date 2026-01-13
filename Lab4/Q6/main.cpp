#include <iostream>
using namespace std;

double power(double base, int exp) {
    if (exp == 0)       // any number ^ 0 = 1
        return 1;

    if (exp > 0)
        return base * power(base, exp - 1);   // positive exponent

    // exp < 0 → use reciprocal
    return 1.0 / power(base, -exp);
}

int main() {
    double base;
    int exponent;

    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    double result = power(base, exponent);

    cout << base << " ^ " << exponent << " = " << result << endl;

    return 0;
}
