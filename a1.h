//
// Created by fred on 17/01/19.
//

#ifndef CMPT135_A1_H
#define CMPT135_A1_H
// a1.h

//
// Don't modify this file in any way!!
//

#include <string>


struct str_array {
    std::string* arr;    // pointer to the underlying array
    int size;       // # of elements from user's perspective
    int capacity;   // length of underlying array
};
#endif //CMPT135_A1_H
