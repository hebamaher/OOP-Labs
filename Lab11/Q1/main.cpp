#include <iostream>

using namespace std;

class GeoShape {
private:
    double dim1;
    double dim2;

public:
    GeoShape() {
        dim1 = dim2 = 0;
        cout << "GeoShape Default Constructor\n";
    }

    GeoShape(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
        cout << "GeoShape Parameterized Constructor\n";
    }

    ~GeoShape() {
        cout << "GeoShape Destructor\n";
    }

    void setDim1(double d1) { dim1 = d1; }
    void setDim2(double d2) { dim2 = d2; }

    double getDim1() { return dim1; }
    double getDim2() { return dim2; }

    double CalcArea() {
        return 0;
    }
};


class Rectangle : public GeoShape {
public:
    Rectangle() : GeoShape() {
        cout << "Rectangle Default Constructor\n";
    }

    Rectangle(double w, double h) : GeoShape(w, h) {
        cout << "Rectangle Parameterized Constructor\n";
    }

    ~Rectangle() {
        cout << "Rectangle Destructor\n";
    }

    double CalcArea() {
        return getDim1() * getDim2();
    }
};


class Square : protected GeoShape {
public:
    Square() : GeoShape() {
        cout << "Square Default Constructor\n";
    }

    Square(double side) : GeoShape(side, side) {
        cout << "Square Parameterized Constructor\n";
    }

    ~Square() {
        cout << "Square Destructor\n";
    }

    double getDim1() { return GeoShape::getDim1(); }
    void setDim1(double d1) { GeoShape::setDim1(d1); }


    double CalcArea() {
        return getDim1() * getDim2();
    }
};


class Circle : protected GeoShape {
public:
    Circle() : GeoShape() {
        cout << "Circle Default Constructor\n";
    }

    Circle(double r) : GeoShape(r, r) {
        cout << "Circle Parameterized Constructor\n";
    }

    ~Circle() {
        cout << "Circle Destructor\n";
    }

    double getDim1() { return GeoShape::getDim1(); }
    void setDim1(double d1) { GeoShape::setDim1(d1); }

    double CalcArea() {
        return 3.14159 * getDim1() * getDim1();
    }
};


class Triangle : public GeoShape {
public:
    Triangle() : GeoShape() {
        cout << "Triangle Default Constructor\n";
    }

    Triangle(double base, double height) : GeoShape(base, height) {
        cout << "Triangle Parameterized Constructor\n";
    }

    ~Triangle() {
        cout << "Triangle Destructor\n";
    }

    double CalcArea() {
        return 0.5 * getDim1() * getDim2();
    }
};

int main() {

    Rectangle r(1, 2);
    cout << "Rectangle Area = " << r.CalcArea() << endl << endl;

    Square s(1);
    cout << "Square Area = " << s.CalcArea() << endl << endl;

    s.setDim1(10);
    s.setDim2(20);
    cout << "Square Dimension " << s.getDim1() << endl << endl;

    Circle c(1);
    cout << "Circle Area = " << c.CalcArea() << endl << endl;

    Triangle t(1, 2);
    cout << "Triangle Area = " << t.CalcArea() << endl << endl;

    return 0;
}
