//
// Created by fred on 03/03/19.
//

// file cats.h

#include <iostream>
#include <string>

int add(int a, int b) {
    return a + b;
}

std::string add(const char *a, const char *b) {
    std::string result(a);
    result += b;
    return result;
}

template <>
const char *max(const char *a, const char *b) {
    return strcmp(a, b) > 0 ? a : b;
}

int main() {
    std::cout << add(5, 9) << std::endl;
    std::cout << add("hello ", "world") << std::endl;
}