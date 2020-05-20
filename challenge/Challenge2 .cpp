//
// Created by fred on 19/04/19.
//

#include "../cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>


using namespace std;

bool checkHas39s(int number) {
    string num_string = to_string(number);
    int num_of_numes = 0;
    for (char ch : num_string) {
        if (ch == '9') {
            num_of_numes++;
        }
    }
    return num_of_numes == 3;
}

int main () {
    int sum = 0;
    for (int i = 0; i < 1000000; i++) {
        if (checkHas39s(i)) {
            sum += i;
            cout << i << endl;
        }
    }
    cout << sum << endl;
    return 0;
}