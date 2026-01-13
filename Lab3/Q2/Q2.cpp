#include <iostream>
using namespace std;

int main() {
    int arr[3][4]; //3 row, 4 col

    cout << "Enter marks (3 students × 4 subjects):\n";
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++)
            cin >> arr[i][j];

    // Sum of each row
    cout << "\nSum of each row:\n";
    for(int i = 0; i < 3; i++) {
        int sum = 0;
        for(int j = 0; j < 4; j++)
            sum += arr[i][j];
        cout << "Row " << i + 1 << ": " << sum << endl;
    }

    // Average of each column
    cout << "\nAverage of each column:\n";
    for(int j = 0; j < 4; j++) {
        int sum = 0;
        for(int i = 0; i < 3; i++)
            sum += arr[i][j];
        cout << "Column " << j + 1 << ": " << (sum / 3.0) << endl;
    }

    return 0;
}

