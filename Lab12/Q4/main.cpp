#include <iostream>
#include <graphics.h>

using namespace std;

class Shape{

protected:
    int color;

public:
    Shape(){
        color = WHITE;
    }
    Shape(int cl){
        color = cl;
    }

    int getColor() { return color; }

    void setColor(int cl) { color = cl;}

    virtual void Draw() = 0;
};

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

class Line : public Shape{

private:
    Point Start;
    Point End;

public:
    Line(){

    }

    Line(Point P1, Point P2, int c): Start(P1.getX(),P1.getY()), End(P2.getX(),P2.getY()), Shape(c) {
//        Start.setX(P1.getX());
//        Start.setX(P1.getX());
//        End.setX(P2.getX());
//        End.setY(P2.getY);
    }
    Line(int x1, int y1, int x2, int y2, int c): Start(x1,y1), End(x2,y2), Shape(c){
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
    //void setColor(int c) { color = c; }

    Point getStart(){ return Start; }
    Point getEnd(){ return End; }
    //int getColor() { return color; }

    void Draw() {
        setcolor(color);
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};

class Rect : public Shape{

private:
    Point UL;
    Point BR;

public:
    Rect(): UL(), BR(){
    }
    Rect(int x1, int y1, int x2, int y2, int c ): UL(x1,y1), BR(x2,y2), Shape(c){
        //color = c;
    }

    Rect(Point P1, Point P2, int c = WHITE): UL(P1.getX(),P1.getY()), BR(P2.getX(),P2.getY()), Shape(c){
        //color = c;
    }

    ~Rect(){

    }

    void setUL(Point p) { UL = p; }
    void setBR(Point p) { BR = p; }
    //void setColor(int c) { color = c; }

    Point getUL() { return UL; }
    Point getBR() { return BR; }
    //int getColor() { return color; }

    void Draw(){
        setcolor(color);
        rectangle(UL.getX(), UL.getY(), BR.getX(), BR.getY());
    }
};

class Circle : public Shape{

private:
    Point center;
    int radius;

public:
    Circle(): center() {
        radius = 0;
    }
    Circle(int x, int y, int r, int cl): center(x,y), Shape(cl){
        radius = r;
    }
    Circle(Point c, int r, int cl) : center(c), Shape(cl) {
        radius = r;
    }

    void setCenter(Point c) { center = c; }
    void setRadius(int r)   { radius = r; }

    Point getCenter() { return center; }
    int getRadius() { return radius; }

    void Draw(){
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture{

private:
    int Num;
    Shape** shapes;
public:
    Picture(){
        Num = 0;
        shapes = NULL;
    }

    Picture(Shape** sh, int n){
        shapes = sh;
        Num = n;
    }

    void setShapes(Shape** sh, int n){
        shapes = sh;
        Num = n;
    }

    void Paint(){
        for(int i=0; i<Num; i++){
            shapes[i]->Draw();
        }
    }

};
int main() {
    cout << "Hello Graphics World" <<endl;
    initwindow(400,500);

    Line L (Point(50,100), Point(200,250), RED);
    //L.Draw();

    Rect R(Point(20,30), Point(200,300), GREEN);
    //R.Draw();

    Circle C(Point(50,50), 20, BLUE);
    //C.Draw();


    Shape* shapes[3] = {&L, &R, &C};

    Picture P(shapes, 3);

    P.Paint();

    getch();
    closegraph();

    return 0;
}
