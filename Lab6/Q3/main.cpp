#include <iostream>
using namespace std;

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    int** arr = new int*[students];

    for(int i=0; i<students; i++){
        arr[i] = new int[subjects];
    }

    cout << "Enter marks:\n";
    for(int i = 0; i < students; i++){
        for(int j = 0; j < subjects; j++){
            cout << "Student " << i+1 << ", Subject " << j+1 << ": ";
            cin >> arr[i][j];
        }
    }

    // Sum of each row
    cout << "\nSum of each student:\n";
    for(int i = 0; i < students; i++) {
        int sum = 0;
        for(int j = 0; j < subjects; j++){
            sum += arr[i][j];
        }
        cout << "Student " << i + 1 << ": " << sum << endl;
    }

    // Average of each column
    cout << "\nAverage of each subject:\n";
    for(int j = 0; j < subjects; j++) {
        int sum = 0;
        for(int i = 0; i < students; i++){
            sum += arr[i][j];
        }
        cout << "Subject " << j + 1 << ": " << (sum / students) << endl;
    }
    for (int i = 0; i < students; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

