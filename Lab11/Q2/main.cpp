#include <iostream>
#include <graphics.h>

using namespace std;

class Point {
private:
    int x, y;

public:
    Point(){
        x = y = 0;
    }
    Point(int X){
        x = y = X;
    }
    Point(int X, int Y) {
        x = X;
        y = Y;
    }
    ~Point(){
        //cout<<"\n Point Destructor";
    }

    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }

    int getX()  { return x; }
    int getY()  { return y; }

    void Draw() {
        //cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

class Line {
private:
    Point Start;
    Point End;

public:
    Line(){

    }

    Line(Point P1, Point P2): Start(P1.getX(),P1.getY()), End(P2.getX(),P2.getY()){
//        Start.setX(P1.getX());
//        Start.setX(P1.getX());
//        End.setX(P2.getX());
//        End.setY(P2.getY);
    }
    Line(int x1, int y1, int x2, int y2): Start(x1,y1), End(x2,y2){
//        Start.setX(x1);
//        Start.setY(y1);
//        End.setX(x2);
//        End.setY(y2);
    }

   ~Line(){
    //cout << "\n Line Destructor";
   }

    void setStart(Point s) { Start = s; }
    void setEnd(Point e)  { End = e; }

    Point getStart(){ return Start; }
    Point getEnd(){ return End; }

    void Draw() {
        setcolor(RED);
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};

class Rect {
private:
    Point UL;
    Point BR;

public:
    Rect(): UL(), BR(){

    }
    Rect(int x1, int y1, int x2, int y2): UL(x1,y1), BR(x2,y2){

    }

    Rect(Point P1, Point P2): UL(P1.getX(),P1.getY()), BR(P2.getX(),P2.getY()){

    }

    ~Rect(){

    }

    void setUL(Point p) { UL = p; }
    void setBR(Point p) { BR = p; }

    Point getUL() { return UL; }
    Point getBR() { return BR; }

    void Draw(){
        setcolor(WHITE);
        rectangle(UL.getX(), UL.getY(), BR.getX(), BR.getY());
    }
};

class Circle {
private:
    Point center;
    int radius;

public:
    Circle(): center(){
        radius = 0;
    }
    Circle(Point c, int r) : center(c) {
        radius = r;
    }

    void setCenter(Point c) { center = c; }
    void setRadius(int r)   { radius = r; }

    Point getCenter() { return center; }
    int getRadius() { return radius; }

    void Draw(){
        setcolor(YELLOW);
        circle(center.getX(), center.getY(), radius);
    }
};

int main() {
    cout << "Hello Graphics World" <<endl;
    initwindow(400,500);

    Line L(10,20,30,60);
    L.Draw();

    Rect R(Point(20,30), Point(200,300));
    R.Draw();

    Circle C(Point(50,50), 20);
    C.Draw();

    getch();
    closegraph();

    return 0;
}
