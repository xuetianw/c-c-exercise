//
// Created by fred on 25/02/19.
//

// C++ program to demonstrate lambda expression in C++

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
#include <chrono>
#include <deque>
#include <memory>

// Function to print vector
void printVector(const std::vector<int>& v) {
    // lambda expression to print vector
    std::for_each(v.begin(), v.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
}

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
            // Lambda expression begins
              [](float a, float b) {
                  return (std::abs(a) < std::abs(b));
              } // end of lambda expression
    );
}

template<typename... Ts>
void processVals(const Ts& ... params) {
// these are C++
// source code
// ellipses
// this means "some
// code goes here"
}

class Widget {
public:
    int a;
};

void process(const Widget&& lvalArg) {

}

void process(Widget& rvalArg) {

}

template<typename T>
void logAndProcess(T&& param) {
    std::cout << param.a << std::endl;
    process(std::forward<T>(param));
}

template<typename T>
void logAndProcess(T& param) {
    std::cout << param.a << std::endl;
    process(std::forward<T>(param));
}

template<typename T>
void f(T&& param) {

}


class Int {
    int x;
public:
    explicit Int(int x = 0) : x{x} {
        std::cout << "conversion constructor" << std::endl;
    }

    explicit operator std::string() {
        std::cout << "conversion operator" << std::endl;
        return std::to_string(x);
    }
};

template<typename T>
// simplified version of std::vector
class vector {
public:
    T& operator[](std::size_t index) {

    }
};


template<typename Container, typename Index>
decltype(auto)
authAndAccess(Container& c, Index i) {
    return c[i];
}

const int theAnswer = 42;
auto x = theAnswer;
auto y = &theAnswer;

template<typename T>
class TD {

};

// declaration only for TD;
// TD == "Type Displayer"
template<typename It>
// algorithm to dwim ("do what I mean")
void dwim(It b, It e)
// for all elements in range from
{
// b to e
    while (b != e) {
        typename std::iterator_traits<It>::value_type
                currValue = *b;
    }
}
// param is a universal reference

auto derefUPLess =
        [](auto p1,
           auto p2) { return p1 < p2; };


int main() {

    std::vector<std::string> vs; // container of std::string
    std::string temp = "xyzzy";
    vs.push_back(temp); // add string literal

//    int test = 5;
//    std::function<bool(const std::unique_ptr<Widget>&,
//                       const std::unique_ptr<Widget>&)> func;
//    bool (*derefUPLess)(const std::unique_ptr<Widget>&, const std::unique_ptr<Widget>&);
//    derefUPLess    = [](const std::unique_ptr<Widget>& p1,
//                               const std::unique_ptr<Widget>& p2) { return (p1->a + test) < p2->a; };


//    derefUPLess(1, 2);
//    std::string a = "sadf";
//    std::string b = "fsd";
//
//    derefUPLess(1, 2);
//    derefUPLess(1, 2);


    TD<decltype(x)> xType;
    TD<decltype(y)> yType;
    TD<int>;
    TD<const int*>;
    std::deque<int> d;

    authAndAccess(d, 5) = 10;
// authenticate user, return d[5],
// then assign 10 to it;
// this won't compile!


//    Int obj(3);
//
//    std::string str = obj;
//    obj = 20;
//
//    std::string str2 = static_cast<std::string>(obj);
//    obj = static_cast<Int>(30);



    std::cout << widget.a;

    char c;
    int* p = (int*) &c;
    *p = 5;

//    int* ip = static_cast<int*>(&c);



//    f(5);
    int a = 3;
    f(a);
    Widget w{5};
    logAndProcess(w);
    logAndProcess(std::move(w));

    std::vector<int> values;

    std::vector<int>::const_iterator it =
            std::find(values.begin(), values.end(), 1983);
    values.insert(it, 1998);

    for (auto& au : values) {
        std::cout << au << std::endl;
    }

//    int foo [5] = { 16, 2, 77, 40, 12071 };
//    for (const auto& ele : foo) {
//        std::cout<<ele;
//    }

// call with lvalue
// call with rvalue


//    // below snippet find first number greater than 4
//    // find_if searches for an element for which
//    // function(third argument) returns true
//    std::vector<int>::iterator p = std::find_if(v.begin(), v.end(), [](int i) {
//        return i > 4;
//    });
//    std::cout << "First number greater than 4 is : " << *p << std::endl;
//
//    using FilterContainer =
//    std::vector<std::function<bool(int)>>;
//    FilterContainer filters;
//
//    filters.push_back([](int value) { return value % 5 == 0; });

//
//
//    // function to sort vector, lambda expression is for sorting in
//    // non-decreasing order Compiler can make out return type as
//    // bool, but shown here just for explanation
//    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
//    {
//        return a > b;
//    });
//
//    printVector(v);
//
//    // function to count numbers greater than or equal to 5
//    int count_5 = count_if(v.begin(), v.end(), [](int a)
//    {
//        return (a >= 5);
//    });
//    cout << "The number of elements greater than or equal to 5 is : "
//         << count_5 << endl;
//
//    // function for removing duplicate element (after sorting all
//    // duplicate comes together)
//    p = unique(v.begin(), v.end(), [](int a, int b)
//    {
//        return a == b;
//    });
//
//    // resizing vector to make size equal to total different number
//    v.resize(distance(v.begin(), p));
//    printVector(v);
//
//    // accumulate function accumulate the container on the basis of
//    // function provided as third argument
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int f = std::accumulate(arr, arr + 10, 1, [](int i, int j)
//    {
//        return i * j;
//    });
//
//    cout << "Factorial of 10 is : " << f << endl;
//
//    //	 We can also access function by storing this into variable
//    auto square = [](int i)
//    {
//        return i * i;
//    };
//
//    cout << "Square of 5 is : " << square(5) << endl;


//    vector<int> v1 = {3, 1, 7, 9};
//    vector<int> v2 = {10, 2, 7, 16, 9};
//
//    //  access v1 and v2 by reference
//    auto pushinto = [&] (int m)
//    {
//        v1.push_back(m);
//        v2.push_back(m);
//    };
//
//    // it pushes 20 in both v1 and v2
//    pushinto(20);
//
//    // access v1 by copy
//    [v1]()
//    {
//        for (auto p = v1.begin(); p != v1.end(); p++)
//        {
//            cout << *p << " ";
//        }
//    };
//
//    int N = 5;
//
//    // below snippet find first number greater than N
//    // [N]  denotes,   can access only N by value
//    vector<int>:: iterator p = find_if(v1.begin(), v1.end(), [N](int i)
//    {
//        return i > N;
//    });

}
