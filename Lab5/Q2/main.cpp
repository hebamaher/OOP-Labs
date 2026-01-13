#include <iostream>
using namespace std;

int SumArray(int arr[], int size) {
    int sum = 0;

    cout << "\nArray elements\n";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " "; //Pointer notation
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[100];

    cout << "Enter array elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];        // Array notation
    }

    int result = SumArray(arr, size);

    cout << "\nSum = " << result << endl;

    return 0;
}
