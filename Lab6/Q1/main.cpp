#include <iostream>
using namespace std;

int* IncrementArrayFixed() {
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++)
        arr[i] += 1;

    return arr; // local array
}
int* IncrementArrayDynamic() {
    int* arr = new int[5];

    for(int i = 0; i < 5; i++)
        arr[i] = i + 1;   // fill array
    for(int i = 0; i < 5; i++)
        arr[i] += 1;

    return arr;
}

int main() {

    //int* p = IncrementArrayFixed();

    int* p = IncrementArrayDynamic();

    for(int i = 0; i < 5; i++)
        cout << p[i] << " ";
    cout << endl;

    delete[] p;
    return 0;
}
