#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double img;

public:
    // Constructors
    Complex() : real(0), img(0) {}
    Complex(double r, double i) : real(r), img(i) {}

    // Setters
    void setReal(double r) { real = r; }
    void setImg(double i) { img = i; }

    // Getters
    double getReal() const { return real; }
    double getImg() const { return img; }

     void read() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> img;
    }

    // Member Add function
    Complex Add(Complex C) {
        Complex result;
        result.real = real + C.real;
        result.img  = img  + C.img;
        return result;
    }
};

// ----------------------------
// Standalone Functions
// ----------------------------

// Standalone Add
Complex Add(Complex C1, Complex C2) {
    return Complex(C1.getReal() + C2.getReal(),
                   C1.getImg()  + C2.getImg());
}

// Standalone Subtract
Complex Subtract(Complex C1, Complex C2) {
    return Complex(C1.getReal() - C2.getReal(),
                   C1.getImg()  - C2.getImg());
}

// Better print function handling all cases
void print(Complex C) {
    double r = C.getReal();
    double i = C.getImg();

    // Case: both zero
    if (r == 0 && i == 0) {
        cout << "0\n";
        return;
    }

    // Case: only real part
    if (i == 0) {
        cout << r << "\n";
        return;
    }

    // Case: only imaginary part
    if (r == 0) {
        cout << i << "i\n";
        return;
    }

    // General case: real + imaginary
    if (i > 0)
        cout << r << "+" << i << "i\n";
    else
        cout << r << i << "i\n";  // i already negative
}


// ----------------------------
// Main to test all cases
// ----------------------------
int main() {
    //Complex C1(5, 3);
    //Complex C2(5, -3);
    //Complex C3(5, 0);
    //Complex C4(0, 3);
    //Complex C5(0, 0);

    Complex C1, C2, C3;

    cout << "Enter first complex number:\n";
    C1.read();
    print(C1);
    cout << "Enter second complex number:\n";
    C2.read();
    print(C2);
    cout <<"\n Summation: ";
    C3 = Add(C1,C2);
    print(C3);
    cout <<"\n Subtraction: ";
    C3 = Subtract(C1,C2);
    print(C3);

    return 0;
}
