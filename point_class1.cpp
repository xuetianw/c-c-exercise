//
// Created by fred on 18/04/19.
//

// point_class1.cpp

#include "cmpt_error.h"
#include <iostream>
#include <cmath>

using namespace std;

//
// Point represents a 2-dimensional (x, y). This codes gives examples of:
//
// - using a struct instead of a class
//
// - member initialization
//
// - default constructor and copy constructor
//
// - a mutating method that scales a point
//
// - a convenient operator<< for printing
//
// - a dist(a, b) function that returns the distance between two points
//
// - operator+(a, b) that returns the sum of two points as a new point
//

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

    // multiply x and y by r
    void scale(double r) {
        x *= r;
        y *= r;
    }

    // returns a new Point that is the sum of a and b
    Point operator+(const Point& b) {
        return Point{x + b.x, y + b.y};
    }

}; // struct Point

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
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

    cout << a << " + " << b << " = " << a + b << "\n";
}

int main() {
     test1();
     test2();
}