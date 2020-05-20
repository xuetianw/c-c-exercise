//
// Created by fred on 19/04/19.
//

#include "../cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

bool if_prime(int num) {
    if (num == 1 || num == 2) {
        return true;
    }
    for (int i = 2; i <= num /2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int reverse_num(int n) {
    int reversedNumber = 0, remainder;
    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    return reversedNumber;
}

int main() {
    int i = 0;
    int j = 1;
    while (i < 15000) {
        if (if_prime(j) && (j != reverse_num(j)) && if_prime(reverse_num(j)) ) {
            i++;
            cout << "i :" << i << "prime" << j << endl;
            break;
        }
        j++;
    }
    cout << j << endl;
}