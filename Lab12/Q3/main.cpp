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
    int color;

public:
    Line(){
        color = WHITE;
    }

    Line(Point P1, Point P2, int c = WHITE): Start(P1.getX(),P1.getY()), End(P2.getX(),P2.getY()){
//        Start.setX(P1.getX());
//        Start.setX(P1.getX());
//        End.setX(P2.getX());
//        End.setY(P2.getY);
        color = c;

    }
    Line(int x1, int y1, int x2, int y2, int c = WHITE): Start(x1,y1), End(x2,y2){
//        Start.setX(x1);
//        Start.setY(y1);
//        End.setX(x2);
//        End.setY(y2);
        color = c;
    }

   ~Line(){
    //cout << "\n Line Destructor";
   }

    void setStart(Point s) { Start = s; }
    void setEnd(Point e)  { End = e; }
    void setColor(int c) { color = c; }

    Point getStart(){ return Start; }
    Point getEnd(){ return End; }
    int getColor() { return color; }

    void Draw() {
        setcolor(color);
        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};

class Rect {
private:
    Point UL;
    Point BR;
    int color;

public:
    Rect(): UL(), BR(){
        color = WHITE;
    }
    Rect(int x1, int y1, int x2, int y2, int c = WHITE): UL(x1,y1), BR(x2,y2){
        color = c;
    }

    Rect(Point P1, Point P2, int c = WHITE): UL(P1.getX(),P1.getY()), BR(P2.getX(),P2.getY()){
        color = c;
    }

    ~Rect(){

    }

    void setUL(Point p) { UL = p; }
    void setBR(Point p) { BR = p; }
    void setColor(int c) { color = c; }

    Point getUL() { return UL; }
    Point getBR() { return BR; }
    int getColor() { return color; }

    void Draw(){
        setcolor(color);
        rectangle(UL.getX(), UL.getY(), BR.getX(), BR.getY());
    }
};

class Circle {
private:
    Point center;
    int radius;
    int color;

public:
    Circle(): center(){
        radius = 0;
        color = WHITE;
    }
    Circle(Point c, int r, int colorr = WHITE) : center(c) {
        radius = r;
        color = colorr;
    }

    void setCenter(Point c) { center = c; }
    void setRadius(int r)   { radius = r; }
    void setColor(int c) { color = c; }

    Point getCenter() { return center; }
    int getRadius() { return radius; }
    int getColor() { return color; }

    void Draw(){
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture{
private:
    int cNum;
    int rNum;
    int lNum;
    Circle* pCircles;
    Rect* pRects;
    Line* pLines;

public:
    Picture(){
        cNum = rNum = lNum = 0;
        pCircles = NULL;
        pRects = NULL;
        pLines = NULL;
    }

    Picture(int cn, int rn, int ln, Circle* cArr, Rect* rArr, Line* lArr){
        cNum = cn;
        rNum = rn;
        lNum = ln;
        pCircles = cArr;
        pRects = rArr;
        pLines = lArr;
    }

    void setCircles(int cn, Circle* cArr){
        cNum = cn;
        pCircles = cArr;
    }
    void setRects(int rn, Rect* rArr){
        rNum = rn;
        pRects = rArr;
    }
    void setLines(int ln, Line* lArr){
        lNum = ln;
        pLines = lArr;
    }
    void Paint(){
        int i;
        for(i=0; i<cNum; i++){
            pCircles[i].Draw();
        }
        for(i=0; i<rNum; i++){
            pRects[i].Draw();
        }
        for(i=0; i<lNum; i++){
            pLines[i].Draw();
        }
    }

};
int main() {
    cout << "Hello Graphics World" <<endl;
    initwindow(400,500);

    Line lArr[2] = {Line(Point(50,100), Point(200,250)), Line(Point(250,300), Point(300,350))};
    //L.Draw();

    Rect rArr[1] = {Rect(Point(20,30), Point(200,300))};
    //R.Draw();

    Circle cArr[1] = {Circle(Point(50,50), 20)};
    //C.Draw();
    Picture P(1, 1, 2, cArr, rArr, lArr);

    P.Paint();

    getch();
    closegraph();

    return 0;
}
