#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    // Constructors
    Complex(){
        real = 0;
        img = 0;
        //cout << "Costructor Called for (" << this->real << "," << this->img << ")\n";
    }
    Complex(double r, double i){
        real = r;
        img = i;
        //cout << "Costructor Called for (" << this->real << "," << this->img << ")\n";
    }
    Complex(double r){
        real = r;
        img = r;
        //cout << "Costructor Called for (" << this->real << "," << this->img << ")\n";
    }
    Complex(const Complex &c){
        this->real = c.real;
        this->img = c.img;
        //cout << "Copy Costructor Called for (" << this->real << "," << this->img << ")\n";
    }

    // Setters
    void setReal(double r) { real = r; }
    void setImg(double i) { img = i; }

    // Getters
    double getReal() { return real; }
    double getImg() { return img; }

     void read() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> img;
    }

    ~Complex() {
        //cout << "Destructor Called for (" << this->real << "," << this->img << ")\n";
    }

     Complex addComplex(Complex C) {
        Complex result;
        result.real = this->real + C.real;
        result.img  = this->img  + C.img;
        return result;
    }

     Complex subtractComplex(Complex C) {
        Complex result;
        result.real = this->real - C.real;
        result.img  = this->img  - C.img;
        return result;
    }

    void printComplex() {
        if (this->real == 0 && this->img == 0) {
            cout << "0\n";
            return;
        }

        if (this->img == 0) {
            cout << this->real << "\n";
            return;
        }

        if (this->real == 0) {
            cout << this->img << "i\n";
            return;
        }

        if (this->img > 0)
            cout << this->real << "+" << this->img << "i\n";
        else
            cout << this->real << this->img << "i\n";  // i already negative
    }

    Complex operator-(const Complex& other) {
        Complex result;
        result.real = real - other.real;
        result.img = img - other.img;
        return result;
    }

    Complex operator-(int val) {
        Complex result;
        result.real = real - val;
        result.img = img;
        return result;
    }

    friend Complex operator-(int val, const Complex& c) {
        Complex result;
        result.real = val - c.real;
        result.img = -c.img;
        return result;
    }

    Complex& operator-=(const Complex& other) {
        this->real -= other.real;
        this->img -= other.img;
        return *this;
    }

    // C--
    Complex& operator--() {
        real--;
        img--;
        return *this;
    }

    //--C
    Complex operator--(int) {
        Complex temp(*this);
        this->real--;
        this->img--;
        return temp;
    }

    bool operator==(const Complex& other) {
        return real == other.real && img == other.img;
    }

    bool operator!=(const Complex& other) {
        return real != other.real || img != other.img;
    }

    bool operator<(const Complex& other) {
        return (real*real + img*img) < (other.real*other.real + other.img*other.img);
    }

    bool operator<=(const Complex& other) {
        return (real*real + img*img) < (other.real*other.real + other.img*other.img) || (real*real + img*img) == (other.real*other.real + other.img*other.img);
    }

    bool operator>(const Complex& other) {
        return (real*real + img*img) > (other.real*other.real + other.img*other.img);
    }

    bool operator>=(const Complex& other) {
        return (real*real + img*img) > (other.real*other.real + other.img*other.img) || (real*real + img*img) == (other.real*other.real + other.img*other.img);;
    }

    int operator[](char c) {
        if (c == 'R' || c == 'r')
            return real;
        else if (c == 'I' || c == 'i')
            return img;
        else
            return 0;
    }
};

int main() {
    Complex C1(1,2), C2(3), C3;

    C3 = C1.addComplex(C2);
    C3.printComplex();

    C3 = C1 - C2;
    C3.printComplex();

    C3 = 5 - C2;
    C3.printComplex();

    C3 = C2 - 5;
    C3.printComplex();

    C1 -= C2;
    C1.printComplex();

    C2 = --C1;
    C2.printComplex();

    C2 = C1--;
    C2.printComplex();
    C1.printComplex();

    cout << "C1 == C2: " << (C1 == C2) << "\n";
    cout << "C1 != C2: " << (C1 != C2) << "\n";
    cout << "C1 >  C2: " << (C1 > C2) << "\n";
    cout << "C1 >= C2: " << (C1 >= C2) << "\n";
    cout << "C1 <  C2: " << (C1 < C2) << "\n";
    cout << "C1 <= C2: " << (C1 <= C2) << "\n";

    cout << "C1 real: " << C1['R'] << ", imaginary: " << C1['I'] << "\n";

    return 0;
}
