//
// Created by fred on 30/01/19.
//

#include "cmpt_error.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class A
{
public:
    A(int) { }      // converting constructor
    A(int, int) { } // converting constructor (C++11)
    operator bool() const { return true; }
};

struct B
{
    explicit B(int) { }
    explicit B(int, int) { }
    explicit operator bool() const { return true; }
};

struct Foo {
    int mem;
    explicit Foo(int n) : mem(n) {}
};

class X2 {
    int i {666};
    string s {"qqq"};
    int j {0};
public:
    X2() = default;        // all members are initialized to their defaults
    X2(int ii) :i{ii} {}   // s and j initialized to their defaults
    // ...
};

class C {   // Good
    string s1;
public:
//    C(const char* p) : s1{p} { }    // GOOD: directly construct (and the C-sting is explicitly named)
    // ...
    C(const std::string_view p) { s1 = p; }   // BAD: default constructor followed by assignment

};


//int main()
//{
//    std::string s1("test"); // constructor from const char*
//    std::string s2(10, 'a');
//
//    std::unique_ptr<int> p(new int(1)); // OK: explicit constructors allowed
////  std::unique_ptr<int> p = new int(1); // error: constructor is explicit
//
//    Foo f(2); // f is direct-initialized:
//    // constructor parameter n is copy-initialized from the rvalue 2
//    // f.mem is direct-initialized from the parameter n
////  Foo f2 = 2; // error: constructor is explicit
//
//    std::cout << s1 << ' ' << s2 << ' ' << *p << ' ' << f.mem  << '\n';
//}

std::string_view funct (){
    std::string_view str2 = "lllloooonnnngggg"; //A really long string
    return str2;
}

int main()
{
    A a1 = 1;      // OK: copy-initialization selects A::A(int)
    A a2(2);       // OK: direct-initialization selects A::A(int)
    A a3 {4, 5};   // OK: direct-list-initialization selects A::A(int, int)
    A a4 = {4, 5}; // OK: copy-list-initialization selects A::A(int, int)
    A a5 = (A)1;   // OK: explicit cast performs static_cast
    if (a1) ;      // OK: A::operator bool()
    bool na1 = a1; // OK: copy-initialization selects A::operator bool()
    bool na2 = static_cast<bool>(a1); // OK: static_cast performs direct-initialization

  B b1 (1);      // error: copy-initialization does not consider B::B(int)
    B b2(2);       // OK: direct-initialization selects B::B(int)
    B b3 {4, 5};   // OK: direct-list-initialization selects B::B(int, int)
//  B b4 = {4, 5}; // error: copy-list-initialization does not consider B::B(int,int)
    B b5 = (B)1;   // OK: explicit cast performs static_cast
    if (b2) ;      // OK: B::operator bool()
//  bool nb1 = b2; // error: copy-initialization does not consider B::operator bool()
    bool nb2 = static_cast<bool>(b2); // OK: static_cast performs direct-initialization
//    std::string_view str = funct();
//    std::string_view temp = str;
//    temp = nullptr;
//
//    std::cout << str << endl;
//    std::cout << "1111" << endl;

//    std::cout << temp << endl;

    std::string str = "   A lot of space";
    std::string_view strView = str;
    strView.remove_prefix(std::min(strView.find_first_not_of(" "), strView.size()));
    std::cout << "str      :  " << str << std::endl
              << "strView  : " << strView << std::endl;

    std::cout << std::endl;

    char arr[] = {'A',' ','l','o','t',' ','o','f',' ','s','p','a','c','e','\0', '\0', '\0'};
    std::string_view strView2(arr, sizeof arr);
    auto trimPos = strView2.find('\0');
    if(trimPos != strView2.npos) strView2.remove_suffix(strView2.size() - trimPos);
    std::cout << "arr     : " << arr << ", size=" << sizeof arr << std::endl
              << "strView2: " << strView2 << ", size=" << strView2.size() << std::endl;

}