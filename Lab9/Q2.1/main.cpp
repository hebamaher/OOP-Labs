#include <iostream>
using namespace std;

class Stack {
private:
    int* Stk;
    int Tos;
    int Size;

    static int counter;

public:
    Stack(int size = 5) {
        Size = size;
        Tos = 0;
        Stk = new int[Size];
        counter++;
    }

    Stack(const Stack& other){
        Size = other.Size;
        Tos = other.Tos;
        Stk = new int[Size];
        for (int i = 0; i < Tos; i++)
            Stk[i] = other.Stk[i];
        counter++;
        //cout << "Copy Constructor Called\n";
    }

    ~Stack() {
        delete[] Stk;
        counter--;
        //cout << "Destructor Called\n";
    }

    static int getCounter() {
        return counter;
    }

    bool IsFull() { return Tos == Size; }
    bool IsEmpty() { return Tos == 0; }

    void Push(int value) {
        if (IsFull()) {
            cout << "Stack Is Full!\n";
            return;
        }
        Stk[Tos++] = value;
    }

    int Pop() {
        if (IsEmpty()) {
            cout << "Stack Is Empty!\n";
            return -1;
        }
        return Stk[--Tos];
    }

    int Peak() {
        if (IsEmpty())
            return -1;
        return Stk[Tos - 1];
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] Stk;

            Size = other.Size;
            Tos = other.Tos;
            Stk = new int[Size];
            for (int i = 0; i < Tos; i++)
                Stk[i] = other.Stk[i];
        }
        return *this;
    }

    Stack operator+(const Stack& other) {
        Stack result(Size + other.Size);

        for (int i = 0; i < Tos; i++)
            result.Push(Stk[i]);
        for (int i = 0; i < other.Tos; i++)
            result.Push(other.Stk[i]);
        return result;
    }

    int& operator[](int index) {
        if (index < 0 || index >= Tos){
            cout<<"Index out of bounds\n";
            return Stk[0];
        }
        return Stk[index];
    }

    void Print() {
        cout << "Stack = ";
        for (int i = Tos - 1; i >= 0; i--)
            cout << Stk[i] << " ";
        cout << endl;
    }
};

int Stack::counter = 0;

int main() {
    Stack S1, S2;
    cout << "Counter: " << Stack::getCounter() << endl;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Print();

    S2 = S1;
    S2.Print();

    Stack S3 = S1 + S2;
    S3.Print();

    cout << "S1[0] = " << S1[0] << endl;
    S1[0] = 0;
    S1.Print();

    cout << "\nCounter: " << Stack::getCounter() << endl;

    return 0;
}
