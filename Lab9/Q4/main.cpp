#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

class Complex {
private:
    double real, img;
public:
    Complex(double r = 0, double i = 0) {
        real = r;
        img = i;
    }

    void Print(){
        cout << real << " + " << img << "i";
    }
};

template <typename T>
class Stack {
private:
    T* stk;
    int top;
    int capacity;
public:
    Stack(int size = 10) {
        capacity = size;
        stk = new T[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] stk;
    }

    void push(const T& value) {
        if (top == capacity - 1) {
            cout << "\nStack Overflow!\n";
            return;
        }
        stk[++top] = value;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return T(); // return default constructed value
        }
        return stk[top--];
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }
};


int main() {
    int a=3, b=5;
    Swap<int>(a,b);
    cout << "\nAfter Swap: " << a << ", " << b << endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout << "\nAfter Swap: " << Ch1 << ", " << Ch2 << endl;

    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);

    cout << "\nComplex1 After Swap: ";
    C1.Print();
    cout << "\nComplex2 After Swap: ";
    C2.Print();
    cout << endl;

    Stack<int> S;
    S.push(10);
    S.push(20);
    cout << "\nPopped from int stack: " << S.pop() << endl;

    Stack<char> S2(3);
    S2.push('A');
    S2.push('B');
    S2.push('C');
    cout << "Popped from char stack: " << S2.pop() << endl;

    Stack<Complex> S3(4);
    S3.push(C1);
    S3.push(C2);
    Complex C = S3.pop();
    cout << "Popped from Complex stack: ";
    C.Print();
    cout << endl;

    return 0;
}
