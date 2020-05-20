//
// Created by fred on 30/01/19.
//

#include "cmpt_error.h"
#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    double x = 0.0;
    double y = 0.0;

    Point() { }

    Point(double a, double b)
            : x(a), y(b)
    { }

    double dist_to(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx*dx + dy*dy);
    }

}; // Point

class Color_point : public Point {
    int r = 0;
    int g = 0;
    int b = 0;
public:
    Color_point(double x, double y, int init_r, int init_g, int init_b)
            : Point(x, y),   // call constructor of parent class
              r(init_r), g(init_g), b(init_b)
    {
        if (r < 0 || r > 255) cmpt::error("red out of range");
        if (g < 0 || g > 255) cmpt::error("green out of range");
        if (b < 0 || b > 255) cmpt::error("blue out of range");
    }

    int red() const { return r; }
    int green() const { return g; }
    int blue() const { return b; }
}; // Color_point


int main() {
    Color_point a{1, 20, 100, 50, 75};
    cout << a.x << " " << a.y << "\n";
    cout << a.red() << " " << a.green() << " " << a.blue() << "\n";

    Color_point b{0, 0, 0, 0, 0};
    cout << a.dist_to(b) << " " << b.dist_to(a) << "\n";

    // Point and Color_point can both be used with dist_to method
    Point p(1, 1);
    cout << a.dist_to(p) << " " << p.dist_to(a) << "\n";
}