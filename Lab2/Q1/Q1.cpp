#include <iostream>
using namespace std;

int main() {
    int num;
    int sum = 0;

    while (sum <= 100) {
        cout << "Enter a number: ";
        cin >> num;
        sum += num;
    }

    cout << "Sum exceeded 100. Final sum = " << sum << endl;
    return 0;
}

