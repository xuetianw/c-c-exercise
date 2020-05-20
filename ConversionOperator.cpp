//
// Created by fred on 2020-05-06.
//
#include <iostream>
#include <cmath>
#include <memory>
#include <unordered_map>

using namespace std;
class Complex
{
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i)
    {}

    // magnitude : usual function style
    double mag()
    {
        return getMag();
    }

    // magnitude : conversion operator
    operator double ()
    {
        return getMag();
    }

private:
    // class helper to get magnitude
    double getMag()
    {
        return sqrt(real * real + imag * imag);
    }
};
template<typename T>
void f2(T& param) {
//    param[0] = 1;
    std::cout << "asdasd" << std::endl;
}
void someFunc(int, double) {

}

class Base {
public:
    virtual void mf1() const;
    virtual void mf2(int x);
    virtual void mf3() &;
    virtual void mf4() const;
};

class Derived: public Base {
public:
    virtual void mf1() const override;
    virtual void mf2(int x) override;
    virtual void mf3() & override;
    void mf4() const override;
};


int main()
{
    Base* base = new Derived();
    base->mf1();
    f2(someFunc);

    typedef void (*FP)(int, const std::string&);
    FP fp;
    FP fp1;

    // a Complex object
    Complex com(3.0, 4.0);

    // print magnitude
    cout << com.mag() << endl;
    // same can be done like this
    cout << com << endl;

    int* a;

    cout << (NULL == 0) << endl;
}