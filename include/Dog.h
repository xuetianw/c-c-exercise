//
// Created by fred on 13/02/19.
//

#ifndef CMPT135_DOG_H
#define CMPT135_DOG_H

#include "Pet.h"

class Dog : public Pet
{
public:
    std::string breed;
    virtual void print( ) const; //keyword virtual not needed,
//but put here for clarity.
};
#endif //CMPT135_DOG_H
