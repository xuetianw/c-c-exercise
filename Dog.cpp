//
// Created by fred on 13/02/19.
//

#include <iostream>
#include "Dog.h"

void Dog::print( ) const
{
    std::cout << "name: " << name << std::endl;
    std::cout << "breed: " << breed << std::endl;
}