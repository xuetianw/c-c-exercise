//
// Created by fred on 16/01/19.
//

#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// print a vector<string> in a nice format
ostream& operator<<(ostream& os, const vector<string>& v) {
    int n = v.size();
    if (n == 0) {         // empty vector
        os << "{}";
    } else if (n == 1) {  // vector with 1 element
        os << "{" << v[0] << "}";
    } else {              // vector with 2 or more elements
        os << "{" << v[0];
        for(int i = 1; i < v.size(); ++i) {
            os << ", " << v[i];
        }
        os << "}";
    }
    return os;
}

// By default, C++ passes parameters by value, i.e. it makes a copy of the
// value passed to the function. One consequence of that is that a function
// cannot modify the value of a passed-in variable, and so swap cannot be
// written using pass-by-value parameters.
void swap_wrong(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// If you pass a function a *pointer* to a variable, then the function *can*
// modify the value of the variable being pointed to.
//
// For example:
//
//    int x = 2;
//    int y = 3;
//    swap_pointer(&x, &y);  // must pass address of x and y
//    cout << x << " " << y; // prints 3 2
//
// The pointers themselves are passed by value, and so the function can't
// change the original pointers. It can only change the value the pointers
// point to.
//
// It helps to draw a diagram showing how the function call works.
void swap_pointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Using the & operator as shown, C++ lets you pass variables by reference.
// This means no copy of the variable's value is made, and the function can
// modify the value of the variable if it needs to.
//
// For example:
//
//    int x = 2;
//    int y = 3;
//    swap_reference(x, y);
//    cout << x << " " << y; // prints 3 2
//
// The advantage of this approach is that you don't need to write &x and &y
// when calling swap_reference.
void swap_reference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Pass by reference works with any C++ data type. The "="" operator in the
// statement "a = b;" makes a copy of the entire vector<string>, which could
// be time-consuming if it's big!
//
// Also notice that the name of this function is swap_reference, which is the
// same as the name of the previous function. C++ can always tell which one
// you mean to call by checking the type of the parameters that are passed.
void swap_reference(vector<string>& a, vector<string>& b) {
    vector<string> temp = a;
    a = b;
    b = temp;
}

// C++  generics (i.e. templates), are a way to pass a *type* as a parameter
// to function. Here, T is any type that can be constructed and works with
// "=". This includes all basic C++ types, and most standard library types.
// Thus, swap_generic will swap any two objects of the same type.
//
// Modern C++ has embraced generics, and they are used throughout the standard
// library. Many of the newer features of C++ were added to facilitate the use
// of generic programming.
template<class T>
void swap_generic(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 3;
    int y = 5;

    cout << "x = " << x << ", y = " << y << "\nswap_wrong(x, y)\n";
    swap_wrong(x, y);
    cout << "x = " << x << ", y = " << y << "\n\n";

    x = 3;
    y = 5;
    cout << "x = " << x << ", y = " << y << "\nswap_pointer(x, y)\n";
    swap_pointer(&x, &y);
    cout << "x = " << x << ", y = " << y << "\n\n";

    x = 3;
    y = 5;
    cout << "x = " << x << ", y = " << y << "\nswap_reference(x, y)\n";
    swap_reference(x, y);
    cout << "x = " << x << ", y = " << y << "\n\n";

    vector<string> v = {"cat", "dog", "sun"};
    vector<string> w = {"on", "off", "yes", "no", "up", "down"};
    cout << "v = " << v << ", w = " << w << "\nswap_reference(v, w)\n";
    swap_reference(v, w);
    cout << "v = " << v << ", w = " << w << "\n\n";

    string s = "butterfly";
    string t = "frog";
    cout << "s = " << s << ", t = " << t << "\nswap_generic(s, t)\n";
    swap_generic(s, t);
    cout << "s = " << s << ", t = " << t << "\n\n";

    x = 3;
    y = 5;
    cout << "x = " << x << ", y = " << y << "\nswap_generic(x, y)\n";
    swap_generic(x, y);
    cout << "x = " << x << ", y = " << y << "\n\n";

    int a = 5;
    int &b = a;
    a = 6;
    cout <<b;
}