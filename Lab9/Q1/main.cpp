#include <iostream>
using namespace std;

int SUM(int x=0, int y=0, int z=0) {
    return x + y + z;
}

int main() {
    cout << "SUM() = " << SUM() << endl;
    cout << "SUM(1) = " << SUM(1) << endl;
    cout << "SUM(1, 2) = " << SUM(1, 2) << endl;
    cout << "SUM(1, 2, 3) = " << SUM(1, 2, 3) << endl;
    return 0;
}
