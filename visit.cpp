//
// Created by fred on 03/03/19.
//

#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

// the variant to visit
using var_t = std::variant<int, long, double, std::string>;

// helper type for the visitor #3
template<class T> struct always_false : std::false_type {};

// helper type for the visitor #4
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

struct A {};
struct B {};
using MyVariant = std::variant<A, B>;

struct MyVisitor {


    std::ostream& os_;

    MyVisitor(std::ostream& os) : os_{os} {}
    void operator()(A const& a) {
        os_ << "It's an A!";
    }
    void operator()(B const& b) {
        os_ << "It's a B!";
    }
};

template <typename T>
auto get_value(T t) {
    if constexpr (std::is_pointer_v<T>)
        return *t; // deduces return type to int for T = int*
    else
        return t;  // deduces return type to int for T = int
}

std::ostream& operator<< (std::ostream& os, MyVariant const& v) {
    std::visit(MyVisitor{os}, v);
    return os;
}
struct Fluid { };
struct LightItem { };
struct HeavyItem { };
struct FragileItem { };
template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;
#include <iostream>
#include <functional>

using namespace std;


template<typename T>
void f(T param) {
    param[0] = 'a';
}
// template with by-value parameter

//template<typename T>
//void f(T& param) {
//    param[0] = 33;
//}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept // below on
{
    return N;
}

void print_num(int i)
{
    std::cout << i << '\n';
}


void someFunc(int, double) {

}

class Student {
public:
    Student();

    Student(int age) : age(age) {}

private:
    int age;
};

void test(int* arr) {

}
int main() {
    Student* student2;
    std::cout << student2 << std::endl;
//    test({ 11, 23, 9 });
//    std::initializer_list;
    Student student;
    Student student1(2);
    Student student3{2};

    int arr1[20];
    arraySize(arr1);
    f2(arr1);
    std::cout << arr1[0] << std::endl;
    std::function<void()> f_display_42 = []() { print_num(42); };

    std::function<void(int, double)> test = someFunc;
    auto x3 = { 27 };

//    std::function<void (&)(int, double)> tes = someFunc;
    std::vector<int> v;


    auto resetV =
            [&v](const auto& newValue) { v = newValue; };
    const char name[] = "J. P. Briggs"; // name's type is
    int* arr = new int[5];
    f(arr);
    arr[0] = 4;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    f(arr);
    std::cout<< arr[0] << std::endl;

    std::variant<LightItem, HeavyItem> basicPackA;
    std::variant<LightItem, HeavyItem> basicPackB;

    std::visit(overload{
            [](LightItem&, LightItem& ) { cout << "2 light items\n"; },
            [](LightItem&, HeavyItem& ) { cout << "light & heavy items\n"; },
            [](HeavyItem&, LightItem& ) { cout << "heavy & light items\n"; },
            [](HeavyItem&, HeavyItem& ) { cout << "2 heavy items\n"; },
    }, basicPackA, basicPackB);

    std::variant<int, long, float> vd;
    vd = 11L;
//    std :: cout << std::get<0>(vd);


    std::vector<var_t> vec = {10, 15l, 1.5, "hello"};
    for(auto& v: vec) {

        // 1. void visitor, only called for side-effects (here, for I/O)
        std::visit([](auto&& arg){std::cout << arg << std::endl;}, v);

        // 2. value-returning visitor, demonstrates the idiom of returning another variant
        var_t w = std::visit([](auto&& arg) -> var_t {return arg + arg;}, v);



        // 3. type-matching visitor: a lambda that handles each type differently
        std::cout << ". After doubling, variant holds ";
        std::visit([](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, int>)
                std::cout << "int with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, long>)
                std::cout << "long with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, double>)
                std::cout << "double with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, std::string>)
                std::cout << "std::string with value " << std::quoted(arg) << '\n';
            else
                static_assert(always_false<T>::value, "non-exhaustive visitor!");
        }, w);
    }

    for (auto& v: vec) {
        // 4. another type-matching visitor: a class with 3 overloaded operator()'s
        std::visit(overloaded {
                [](auto arg) { std::cout << arg << ' '; },
                [](double arg) { std::cout << std::fixed << arg << ' '; },
                [](const std::string& arg) { std::cout << std::quoted(arg) << ' '; },
        }, v);
    }


}