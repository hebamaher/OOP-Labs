#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double img;

public:
    // Constructors
    Complex(){
        this->real = 0;
        this->img = 0;
    }
    Complex(double r) {
        this->real = r;
        this->img = r;
    }
    Complex(double r, double i) {
        this->real = r;
        this->img = i;
    }

    void setReal(double r) { this->real = r; }
    void setImg(double i) { this->img = i; }

    double getReal() { return this->real; }
    double getImg() { return this->img; }

    Complex AddComplex(const Complex& C) {
        return Complex(this->real + C.real, this->img + C.img);
    }

    Complex SubComplex(const Complex& C) {
        return Complex(this->real - C.real, this->img - C.img);
    }

    ~Complex() {
         cout << "Destructor called for (" << this->real << "," << this->img << ")\n";
    }

    friend ostream& operator<<(ostream& os, const Complex& C);
    friend istream& operator>>(istream& is, Complex& C);
};

ostream& operator<<(ostream& os, const Complex& C) {
    if (C.real == 0 && C.img == 0)
        os << "0";
    else if (C.img == 0)
        os << C.real;
    else if (C.real == 0)
        os << C.img << "i";
    else
        os << C.real << (C.img > 0 ? "+" : "") << C.img << "i";

    return os;
}

istream& operator>>(istream& is, Complex& C) {
    cout << "Enter real part: ";
    is >> C.real;
    cout << "Enter imaginary part: ";
    is >> C.img;
    return is;
}

int main() {
    Complex C1, C2;

    cin >> C1;
    cin >> C2;

    cout << "C1 = " << C1 << endl;
    cout << "C2 = " << C2 << endl;

    Complex Sum = C1.AddComplex(C2);
    Complex Sub = C1.SubComplex(C2);

    cout << "Sum = " << Sum << endl;
    cout << "Sub = " << Sub << endl;

    return 0;
}
