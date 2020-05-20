//
// Created by fred on 2020-03-23.
//

#include <iostream>
#include <string>

std::string_view func() {
    std::string_view good("a string literal");   // OK: "good" points to a static array
    return good;
}


int main() {
    std::string_view bad = func();
    std::string_view cop = bad;
    bad =  std::string_view("tee");
    std::cout << bad << std::endl;
    std::cout << cop << std::endl;
}