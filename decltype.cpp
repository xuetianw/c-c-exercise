//
// Created by fred on 2020-05-07.
//

#include <iostream>

class Widget{

};


template<typename T>
void f(const T& param) {

}

int main()  {

    int x = 27;
    const int cx = x;
    int* rx = &x; // as before
// as before
// as before
    f(x); // T is int, param's type is const int&
    f(cx); // T is int, param's type is const int&
    f(rx); // T is int, param's type is const int&

    *rx = 5;
    std::cout << x << '\n';

//    const int i = 0; // decltype(i) is const int
////    bool f(const Widget& w); // decltype(w) is const Widget&
//    Widget w;
//    std::cout << typeid(w).name()<< '\n';
////    std::cout << "int is: " << typeof(w) << '\n';
//
//    const int ci = 0;
//    std::cout << typeid(w).name() << '\n';

//// decltype(f) is bool(const Widget&)
//    struct Point {
//        int x, y;
//    }; // decltype(Point::x) is int
//// decltype(Point::y) is int
//    Widget w; // decltype(w) is Widget
//    if (f(w)) ... // decltype(f(w)) is bool
//    template<typename T>
//// simplified version of std::vector
//    class vector {
//    public:
//        ...
//        T& operator[](std::size_t index);
//        ...
//    };
//    vector<int> v;
//    ...
//    if (v[0] == 0) ...
//// decltype(v) is vector<int>
//// decltype(v[0]) is int&
    return 0;
}