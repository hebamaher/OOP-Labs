#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int mn = arr[0], mx = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] < mn) mn = arr[i];
        if(arr[i] > mx) mx = arr[i];
    }

    cout << "Minimum = " << mn << endl;
    cout << "Maximum = " << mx << endl;

    return 0;
}

