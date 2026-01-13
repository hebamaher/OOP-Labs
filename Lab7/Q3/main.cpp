#include <iostream>
using namespace std;

class Stack {
private:
    int* Stk;      // array
    int Top;       // top of stack index
    int Size;      // capacity

public:

    // Constructor
    Stack(int size = 5) {
        Size = size;
        Stk = new int[Size];
        Top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] Stk;
    }

    // Push
    void Push(int val) {
        if (Top == Size - 1) {
            cout << "Stack is Full\n";
            return;
        }
        Stk[++Top] = val;
    }

    // Pop
    int Pop() {
        if (Top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return Stk[Top--];
    }

    // Peak
    int Peak() {
        if (Top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return Stk[Top];
    }

    // PrintStack
    void PrintStack() {
        if (Top == -1) {
            cout << "Stack is Empty\n";
            return;
        }
        for (int i = Top; i >= 0; i--)
            cout << Stk[i] << " ";
        cout << endl;
    }

    // Reverse -> returns a new stack
    Stack Reverse() {
        Stack temp(Size);
        for (int i = 0; i <= Top; i++) {
            temp.Stk[i] = Stk[Top - i];
        }
        temp.Top = Top;
        return temp;
    }
};

int main() {
    Stack S1(5);

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);

    cout << S1.Peak() << endl; //30
    cout << S1.Peak() << endl; //30

    cout << S1.Pop() << endl; //30
    cout << S1.Pop() << endl; //20

    Stack S2(5);

    S2.Push(3);
    S2.Push(4);
    S2.Push(5);
    S2.Push(6);

    cout << S2.Reverse().Pop() << endl; // 3

    return 0;
}
