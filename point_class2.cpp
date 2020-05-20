//
// Created by fred on 18/04/19.
//

// point_class2.cpp

#include "cmpt_error.h"
#include <iostream>
#include <cmath>

using namespace std;

//
// This is based on point_class1.cpp, and differs as follows:
//
// - a destructor with a debugging message has been added
//
// - the destructor uses *this to use operator<< for printing
//
// - declarations of both Point and operator<< are needed for the code to
//   compile
//

// declaration
//
// must declare Point to be a struct so that the declaration of operator<<
// that follows will compile
struct Point;

// declaration
//
// must declare operator<< here because it is used in ~Point below
ostream& operator<<(ostream& out, const Point& p);


struct Point {
    double x = 0;  // member initialization
    double y = 0;  // i.e. x and y are set to 0 by default

    // default constructor
    Point() // x and y are initialized above
    { }

    Point(double a, double b)
            : x(a), y(b)         // initializer list
    { }

    // copy constructor
    Point(const Point& other)
            : Point(other.x, other.y)  // constructor delegation
    { }


    // this is a special variable added to every object by the C++ compiler;
    // this points to the object itself, and so here this has type Point*
    ~Point() {
        cout << "Point destructor called: " << *this << "\n";
    }

    // multiply x and y by r
    void scale(double r) {
        x *= r;
        y *= r;
    }

}; // struct Point

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

// returns a new Point that is the sum of a and b
Point operator+(const Point& a, const Point& b) {
    return Point{a.x + b.x, a.y + b.y};
}

// returns the distance between p and q
double dist(const Point& p, const Point& q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx*dx + dy*dy);
}

void test1() {
    Point p;
    cout << "p = " << p << "\n";
    cout << "  p.x: " << p.x << "\n";
    cout << "  p.y: " << p.y << "\n";

    Point c(p);
    cout << "c = " << c << "\n";
    cout << "  c.x: " << c.x << "\n";
    cout << "  c.y: " << c.y << "\n";

    Point pts[5];  // only compiles if Point has a default constructor
    for(int i = 0; i < 5; ++i) {
        cout << "pts[" << i << "] = " << pts[i] << "\n";
    }
}

void test2() {
    Point a(1, 2);
    Point b(5, -2);

    cout << "distance between " << a << " and " << b << " = "
         << dist(a, b) << "\n";

    // a + b returns a Point, and after it is printed its destructor is called
    cout << a << " + " << b << " = " << a + b << "\n";

    // b's destructor is called
    // a's destructor is called
}

int main() {
    // test1();
    test2();
}