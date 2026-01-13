#include <iostream>
using namespace std;

class Stack {
private:
    int* Stk;      // array
    int Top;       // top of stack index
    int Size;      // capacity

public:

    // Constructor
    Stack(int size = 10) {
        cout << "parameterized constructor called\n";
        Size = size;
        Stk = new int[Size];
        Top = -1;
    }
    Stack(const Stack &st){
        cout << "copy constructor called\n";
        this->Size = st.Size;
        this->Top = st.Top;
        this->Stk = new int[Size];
        for(int i=0; i<st.Top; i++){
            this->Stk[i] = st.Stk[i];
        }
    }

    // Destructor
    ~Stack() {
        delete[] Stk;
    }

    // Push
    void push(int val) {
        if (Top == Size - 1) {
            cout << "Stack is Full\n";
            return;
        }
        Stk[++Top] = val;
    }

    // Pop
    int pop() {
        if (Top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return Stk[Top--];
    }

    // Peak
    int peak() {
        if (Top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return Stk[Top];
    }

    // PrintStack
    void printStack() {
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

    friend void viewContent(Stack stk);
};

void viewContent(Stack stk){
    for(int i=0; i<stk.Top; i++){
        cout << stk.Stk[i] << endl;
    }
    cout << endl;
}

int main() {
///************* Copy Ctor Case(1): Pass by value to function ********************
/*
    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    viewContent(S1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;

*/
///************* Copy Ctor Case(2): Return by value from function ********************
/*
    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    Stack SS = S1.Reverse();
    cout << SS.pop();

*/
///************* Copy Ctor Case(3): Create obj in terms of another obj "Explicitly" ********************

    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    Stack S3 ( S1 );

    for(int i=0; i<10; i++)
        S3.pop();


    for(int i=0; i<10; i++)
        S3.push(-1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;


return 0;
}
