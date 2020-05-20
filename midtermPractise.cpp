//
// Created by fred on 11/02/19.
//

#include <string>
#include <iostream>
#include <vector>

void example() {
    std::vector<float*> nums = {new float(1),
                           new float(2),
                           new float(3)
    };
    for(float* p : nums) {
        delete p;
    }


    // ... code that uses nums ...
}

int main() {

    int *a = new int(5);
    delete a;
    a = new int(5);
}