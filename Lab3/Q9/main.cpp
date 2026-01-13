#include <iostream>
using namespace std;

//Q9

int main() {
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    int rowSizes[rows];

    for (int i = 0; i < rows; i++) {
        cout << "Enter number of elements in row " << i + 1 << ": ";
        cin >> rowSizes[i];
    }

    int maxCols = 0;
    for (int i = 0; i < rows; i++) {
        if (rowSizes[i] > maxCols)
            maxCols = rowSizes[i];
    }

    int jagged[rows][maxCols];

    for (int i = 0; i < rows; i++) {
        cout << "Enter elements for row " << i + 1 << ":\n";
        for (int j = 0; j < rowSizes[i]; j++) {
            cin >> jagged[i][j];
        }
    }

    cout << "\nJagged Array Elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rowSizes[i]; j++) {
            cout << jagged[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
