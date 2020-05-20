//
// Created by fred on 30/01/19.
//

// stringable.cpp

#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <Pet.h>
#include <Dog.h>

using namespace std;
//
//// Stringable is an abstract base class (ABC)
//class Stringable {
//private:
//    virtual string to_str() const = 0;
//};
//
//class Window : public Stringable {
//private:
//    string name;
//    int w; // width
//    int h; // height
//public:
//    Window(const string& init_name, int init_w, int init_h)
//            : name(init_name), w(init_w), h(init_h)
//    {}
//
//    string to_str() const override{
//        return "Window(" + name + ", "
//               + to_string(w) + ", "
//               + to_string(h) + ")";
//    }
//}; // Window
//
//// RGB color
//class Color : public Stringable {
//private:
//    int r = 0;   // red, 0 to 255
//    int g = 0;   // green, 0 to 255
//    int b = 0;   // blue, 0 to 255
//public:
//    Color() { }  // default constructor
//
//    Color(int init_r, int init_g, int init_b)
//            : r(init_r), g(init_g), b(init_b)
//    {
//        if (r < 0 || r > 255) cmpt::error("red out of range");
//        if (g < 0 || g > 255) cmpt::error("green out of range");
//        if (b < 0 || b > 255) cmpt::error("blue out of range");
//    }
//
//    Color(const Color& other)  // copy constructor
//            : Color(other.r, other.g, other.b)
//    { }
//
//    int red() const { return r; }
//    int green() const { return g; }
//    int blue() const { return b; }
//
//    string to_str() const {
//        return "rgb(" + to_string(r) + ", "
//               + to_string(g) + ", "
//               + to_string(b) + ")";
//    }
//}; // Color
//
//struct Point : public Stringable {
//    double x = 0.0;
//    double y = 0.0;
//
//    Point() { }
//
//    Point(double a, double b)
//            : x(a), y(b)
//    { }
//
//    string to_str() const {
//        return "(" + to_string(x) + ", "
//               + to_string(y) + ")";
//    }
//
//}; // Point
//
////ostream& operator<<(ostream& out, const Stringable& s) {
////    out << s.to_str();
////    return out;
////}
//
//
//class A { public: void Foo() {} };
//class B : public A {};
//class C : public A {};
//class D : public B, public C {};
//
//
//class DayOfYear {
//private:
//    int month;
//public:
//    constexpr int getMonth() {
//        return month;
//    }
//
//    void setMonth(const int month) {
//        DayOfYear::month = month;
//    }
//
//    int getDay() const {
//        return day;
//    }
//
//    void setDay(int day) {
//        DayOfYear::day = day;
//    }
//
//private:
//    int day;
//};
//
//// Example 2: A more modern base class, using
//// Template Method to separate interface from
//// internals.
////
//
//class Gadget {
//
//};
//
//class Widget
//{
//public:
//    // Stable, nonvirtual interface.
//    //
//    int Process( Gadget& ); // uses DoProcess...()
//    bool IsDone(); // uses DoIsDone()
//    // ...
//
//private:
//    // Customization is an implementation detail that may
//    // or may not directly correspond to the interface.
//    // Each of these functions might optionally be
//    // pure virtual, and if so might or might not have
//    // an implementation in Widget; see Item 27 in [1].
//    //
//    virtual int DoProcessPhase1( Gadget& );
//    virtual int DoProcessPhase2( Gadget& );
//    virtual bool DoIsDone();
//    // ...
//};
//
//
class Parent {
public:
    void foo() { barImpl(); }
    void bar() { barImpl(); }
private:
    virtual void barImpl() = 0;
};

class child : public Parent {
public:
    void test() {
        foo();
        barImpl();
    }

    void barImpl() override {
        cout << "test" <<endl;
    }
};


//class Parent {
//private:
//    virtual void foo() {};
//};

class Base
{
private:
    int x;
    virtual void fun() = 0;
public:
    int getX() {
        fun();
    }
};


// This class inherits from Base and implements fun()
class Derived: public Base
{
private:
    int y;
    void fun() override{ cout << "fun() called"; }

public:
};
//
class Printable {
public:
    // prints the object to cout
    void print() const {
        printImpl();
    };

    // prints the object to cout followed by "\n"
    void println() const {
        printImpl();
        std :: cout << "\n";
    }

    // virtual destructor
    virtual ~Printable() { }

private:
    virtual void printImpl() const = 0;

}; // class Printable
//
//
class Point : public Printable {
private:
    // ...

public:
    // ...

    ~Point() {
        print();
        std :: cout << " destroyed\n";
    }

    // ...
}; // class Point

int main() {
    child a;
//    Window w("Test", 100, 150);
//    cout << w << "\n";
//
//    Color c(100, 100, 120);
//    cout << c << "\n";
//
//    Point p{5, -2};
//    cout << p << "\n";
//
//    Point origin;
//    cout << origin << "\n";


//    Pet *ppet;
//    Dog *pdog;
//
//    pdog = new Dog;
//    pdog->name = "Tiny";
//    pdog->breed = "Great Dane";
//    ppet = pdog;
//
////    ppet->print( );
//    pdog->print( );
}