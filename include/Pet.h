//
// Created by fred on 13/02/19.
//

#ifndef CMPT135_PET_H
#define CMPT135_PET_H

#include <string>

class Pet
{
public:
    std::string name;
    virtual void print( ) const;
};
#endif //CMPT135_PET_H
