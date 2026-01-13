#include <iostream>
using namespace std;

void Calculate(int X, int Y, int* SumPtr, int* SubPtr, int* MultipPtr, int* DivPtr) {
    *SumPtr = X + Y;
    *SubPtr = X - Y;
    *MultipPtr = X * Y;

    if (Y != 0)
        *DivPtr = X / Y;

}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int sum, sub, mult, div;

    Calculate(a, b, &sum, &sub, &mult, &div);

    cout << "\nResults:\n";
    cout << "Sum = " << sum << endl;
    cout << "Subtract = " << sub << endl;
    cout << "Multiply = " << mult << endl;
    cout << "Division = " << div << endl;

    return 0;
}
