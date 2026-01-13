#include <iostream>

using namespace std;

class Base{
private:
    int x;
protected:
    int y;

public:
    Base(){
        x = 0;
        y = 0;
        cout << "Base Default Constructor\n";
    }

    Base(int X, int Y){
        x = X;
        y = Y;
        cout << "Base Parameterized Constructor\n";
    }

    ~Base(){
        cout << "Base Destructor\n";
    }

    void setX(int X){
        x = X;
    }

    void setY(int Y){
        y = Y;
    }

    int getX(){ return x; }
    int getY(){ return y; }

    int sum(){
        return x + y;
    }
};

class Derived : public Base{
private:
    int z;

public:
    Derived(): Base(){
        z = 0;
        cout << "Derived Default Constructor\n";
    }

    Derived(int X, int Y, int Z) : Base(X, Y){
        z = Z;
        cout << "Derived Parameterized Constructor\n";
    }

    ~Derived(){
        cout << "Derived Destructor\n";
    }

    void setZ(int Z){
        z = Z;
    }

    int getZ(){ return z; }

    int sum(){
        return getX() + y + z;
    }
};

class Derived_Junior : public Derived{
private:
    int m;

public:
    Derived_Junior() : Derived() {
        m = 0;
        cout << "Derived_Junior Default Constructor\n";
    }

    Derived_Junior(int X, int Y, int Z, int M): Derived(X, Y, Z)
    {
        m = M;
        cout << "Derived_Junior Parameterized Constructor\n";
    }

    ~Derived_Junior() {
        cout << "Derived_Junior Destructor\n";
    }

    void setM(int M) { m = M; }
    int getM() { return m; }

    int sum() {
        return getX() + y + getZ() + m;
    }

};

int main() {

    Base b(1, 2);
    cout << "Base sum = " << b.sum() << endl;

    Derived d(1, 2, 3);
    cout << "Derived sum = " << d.sum() << endl;

    Derived_Junior dj(1, 2, 3, 4);
    cout << "Derived_Junior sum = " << dj.sum() << endl;

    return 0;
}
