//
// Created by fred on 30/01/19.
//

#include <iostream>
using namespace std;

class Printable {
public:
    // prints the object to cout followed by "\n"
    void println() const {
        print();
        std::cout << "\n";
    }

private:

    virtual void print() const = 0;

    void func2 () {
        return;
    }
}; // class Printable

class Point : public Printable {
private:
    double x;
    double y;

public:

    void func () {
        print();
    }
    // default constructor
    Point() : x(0), y(0) { }

    // copy constructor
    Point(const Point& other) : x(other.x), y(other.y) { }

    Point(double a, double b) : x(a), y(b) { }

    // getters
    double get_x() const { return x; }
    double get_y() const { return y; }

    void print() const override {
        cout << '(' << x << ", " << y << ')';
    }

    void func2() {

    }

}; // class Point

int main(){
    Point a{1, 2};
    a.println();
    a.print();
}
