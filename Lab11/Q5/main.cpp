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

    void Draw(int color) {
        setcolor(color);
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

    Rect(Point P1, Point P2): UL(P1.getX(),P1.getY()), BR(P1.getX(),P1.getY()){

    }

    ~Rect(){

    }

    void setUL(Point p) { UL = p; }
    void setBR(Point p) { BR = p; }

    Point getUL() { return UL; }
    Point getBR() { return BR; }

    void Draw(int color){
        setcolor(color);
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

    void Draw(int color){
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

void DrawMan(bool happy) {
    setcolor(WHITE);

    // Head
    circle(70, 150, 20);

    // Face
    if(happy) {
        arc(70, 155, 200, 340, 10);      // smiling
    } else {
        arc(70, 165, 20, 160, 10);       // sad
    }

    setcolor(WHITE);
    circle(60, 145, 5);
    circle(80, 145, 5);

    // Body
    line(70, 170, 70, 230);

    // Arms
    line(70, 190, 110, 210);             // right arm to switch wire
    line(70, 190, 40, 210);              // left arm

    // Legs
    line(70, 230, 50, 270);
    line(70, 230, 90, 270);

    // Switch wire
    setcolor(LIGHTGRAY);
    line(110, 210, 180, 200);            // wire to lamp base

    // Switch button
    rectangle(105, 205, 115, 215);
}


void DrawTable() {
    setcolor(BROWN);
    rectangle(100, 250, 320, 270);     // tabletop
    rectangle(140, 270, 160, 330);    // left leg
    rectangle(240, 270, 260, 330);    // right leg
}

void DrawLamp(bool isOn) {
    setcolor(DARKGRAY);
    rectangle(180, 200, 220, 250);     // lamp base

    line(200, 200, 200, 150);          // lamp stand

    // Lamp head
    setcolor(isOn ? YELLOW : LIGHTGRAY);
    circle(200, 130, 20);              // bulb

    if(isOn) {
        // glowing effect
        line(200, 100, 200, 70);
        line(180, 110, 150, 90);
        line(220, 110, 250, 90);
    }
}

int main()
{
    initwindow(400, 400);

    bool lampOn = false;   // start with OFF

    // Draw everything
    DrawTable();
    DrawLamp(lampOn);
    DrawMan(lampOn);

    getch();

    // Turn lamp ON (happy)
    cleardevice();
    lampOn = true;
    DrawTable();
    DrawLamp(lampOn);
    DrawMan(lampOn);

    getch();
    closegraph();
    return 0;
}
