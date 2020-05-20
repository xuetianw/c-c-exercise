//
// Created by fred on 16/01/19.
//

#ifndef HELLOWORLD_CMPT_ERROR_H
#define HELLOWORLD_CMPT_ERROR_H

#include <string>
#include <stdexcept>

// C++ already has function called error, and so we put our error function
// inside a namespace called cmpt. Thus, to use this error function, we will
// write its full name, cmpt::error.
namespace cmpt {

// runtime_error is a pre-defined C++ object meant to be "thrown" when an
// error occurs while a program is running. When it is thrown, the program
// will end and print the given error message.
    void error(const std::string& message)
    {
        throw std::runtime_error(message);
    }

} // namespace cmpt

#endif //HELLOWORLD_CMPT_ERROR_H
