#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    // Allocate array of row sizes
    int* rowSizes = new int[rows];

    // Read sizes of each row
    for (int i = 0; i < rows; i++) {
        cout << "Enter number of elements in row " << i + 1 << ": ";
        cin >> rowSizes[i];
    }

    // Allocate jagged array (pointer to pointer)
    int** jagged = new int*[rows];

    for (int i = 0; i < rows; i++) {
        jagged[i] = new int[rowSizes[i]];   // Allocate each row with its size
    }

    // Input values
    for (int i = 0; i < rows; i++) {
        cout << "Enter elements for row " << i + 1 << ":\n";
        for (int j = 0; j < rowSizes[i]; j++) {
            cin >> jagged[i][j];
        }
    }

    // Output jagged array
    cout << "\nJagged Array Elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rowSizes[i]; j++) {
            cout << jagged[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        delete[] jagged[i];    // delete each row
    }
    delete[] jagged;           // delete row pointer
    delete[] rowSizes;         // delete sizes

    return 0;
}
