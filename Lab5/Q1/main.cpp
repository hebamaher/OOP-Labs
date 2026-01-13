#include <iostream>
using namespace std;

void SwapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void SwapByAddress(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SwapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Enter two numbers x, y: ";
    cin >> x >> y;
    // SwapByValue(x, y);
    // SwapByAddress(&x, &y);
    SwapByReference(x, y);

    cout << "After Swap: x=" << x << " y=" << y << endl;
    return 0;
}
