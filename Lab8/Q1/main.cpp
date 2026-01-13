#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double img;

public:
    // Constructors
    Complex(){
        real = 0;
        img = 0;
        cout << "Costructor Called for (" << this->real << "," << this->img << ")\n";
    }
    Complex(double r, double i){
        real = r;
        img = i;
        cout << "Costructor Called for (" << this->real << "," << this->img << ")\n";
    }
    Complex(double r){
        real = r;
        img = r;
        cout << "Costructor Called for (" << this->real << "," << this->img << ")\n";
    }
    Complex(const Complex &c){
        this->real = c.real;
        this->img = c.img;
        cout << "Copy Costructor Called for (" << this->real << "," << this->img << ")\n";
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

    // Member functions
    Complex addComplex(Complex C);
    Complex subtractComplex(Complex C);
    void printComplex();

    ~Complex() {
        cout << "Destructor Called for (" << this->real << "," << this->img << ")\n";
    }
};

// Standalone Add
Complex Complex::addComplex(Complex C) {
    Complex result;
    result.real = this->real + C.real;
    result.img  = this->img  + C.img;
    return result;
}

// Standalone Subtract
Complex Complex::subtractComplex(Complex C) {
    Complex result;
    result.real = this->real - C.real;
    result.img  = this->img  - C.img;
    return result;
}

// Better print function handling all cases
void Complex::printComplex() {
    // Case: both zero
    if (this->real == 0 && this->img == 0) {
        cout << "0\n";
        return;
    }

    // Case: only real part
    if (this->img == 0) {
        cout << this->real << "\n";
        return;
    }

    // Case: only imaginary part
    if (this->real == 0) {
        cout << this->img << "i\n";
        return;
    }

    // General case: real + imaginary
    if (this->img > 0)
        cout << this->real << "+" << this->img << "i\n";
    else
        cout << this->real << this->img << "i\n";  // i already negative
}

int main() {

    //Complex C1, C2, C3;

    Complex C1(3,4), C2(5), C3;
    C3 = C1.addComplex(C2);

	//C1.printComplex();
	//C2.printComplex();
	//C3.printComplex();

    return 0;
}
