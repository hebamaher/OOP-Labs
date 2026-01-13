#include <iostream>
using namespace std;

class ShiftQueue {
private:
    int* Q;
    int Size;
    int Tail;  // number of elements

public:

    // Default constructor
    ShiftQueue() {
        Size = 5;
        Q = new int[Size];
        Tail = 0;
    }

    // Parameterized constructor
    ShiftQueue(int size) {
        Size = size;
        Q = new int[Size];
        Tail = 0;
    }

    // Destructor
    ~ShiftQueue() {
        delete[] Q;
    }

    bool IsFull() {
        return Tail == Size;
    }

    bool IsEmpty() {
        return Tail == 0;
    }

    void EnQueue(int val) {
        if (IsFull()) {
            cout << "Queue is Full\n";
            return;
        }
        Q[Tail++] = val;
    }

    int DeQueue() {
        if (IsEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        int val = Q[0];

        // Shift Left
        for (int i = 0; i < Tail - 1; i++)
            Q[i] = Q[i + 1];

        Tail--;
        return val;
    }
};

class CircularQueue {
private:
    int* Q;
    int Size;
    int Head;
    int Tail;
    int Count;  // number of stored items

public:

    // Default constructor
    CircularQueue() {
        Size = 5;
        Q = new int[Size];
        Head = 0;
        Tail = 0;
        Count = 0;
    }

    // Parameterized constructor
    CircularQueue(int size) {
        Size = size;
        Q = new int[Size];
        Head = 0;
        Tail = 0;
        Count = 0;
    }

    // Destructor
    ~CircularQueue() {
        delete[] Q;
    }

    bool IsFull() {
        return Count == Size;
    }

    bool IsEmpty() {
        return Count == 0;
    }

    void EnQueue(int val) {
        if (IsFull()) {
            cout << "Queue is Full\n";
            return;
        }

        Q[Tail] = val;
        Tail = (Tail + 1) % Size;
        Count++;
    }

    int DeQueue() {
        if (IsEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        int val = Q[Head];
        Head = (Head + 1) % Size;
        Count--;
        return val;
    }
};

int main() {
    cout << " Shifting Queue \n";
    ShiftQueue Q1(5);

    Q1.EnQueue(10);
    Q1.EnQueue(20);
    Q1.EnQueue(30);
    cout << Q1.DeQueue() << endl; // 10
    cout << Q1.DeQueue() << endl; // 20

    cout << "\n Circular Queue \n";
    CircularQueue Q2(5);

    Q2.EnQueue(1);
    Q2.EnQueue(2);
    Q2.EnQueue(3);
    Q2.EnQueue(4);

    cout << Q2.DeQueue() << endl; // 1
    cout << Q2.DeQueue() << endl; // 2

    Q2.EnQueue(9);
    Q2.EnQueue(8);

    cout << Q2.DeQueue() << endl; // 3

    return 0;
}
