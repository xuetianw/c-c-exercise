//
// Created by fred on 22/03/19.
//

#include <vector>
#include <iostream>
#include "cmpt_error.h"

int index_of_max_rec(const std::vector<int>& v, int begin) {
    if (begin >= v.size()) cmpt::error("empty vector");

    if (begin == v.size() - 1) {  // only 1 element, so return it
        return begin;
    } else {
        int mi = index_of_max_rec(v, begin + 1);
        if (v[mi] > v[begin]) {
            return mi;
        } else {
            return begin;
        }
    }
}

// Pre-condition:
//    n >= 0
// Post-condition:
//    returns a to the power of n, i.e. a^n
// Note:
//    The bases cases can be compressed somewhat. However, we list them
//    individually to make it easier to see that all the cases have been
//    handled.
int power_iter(int a, int n) {
    if (n < 0) cmpt::error("exponent must be non-negative"); // check pre-condition

    if (a == 0 && n == 0) return 1;
    if (a == 0 && n != 0) return 0;
    if (a != 0 && n == 0) return 1;
    if (a == 1) return 1;
    int pow = 1;
    for(int i = 0; i < n; ++i) {
        pow *= a;
    }
    return pow;
}

int power_recur(int a, int n) {
    if (n < 0) cmpt::error("exponent must be non-negative"); // check pre-condition

    if (a == 0 && n == 0) return 1;
    if (a == 0 && n != 0) return 0;
    if (a != 0 && n == 0) return 1;
    if (a == 1) return 1;
    return a * power_recur(a, n - 1);
}


int power_recur_fast(int a, int n) {
    if (n < 0) cmpt::error("exponent must be non-negative"); // check pre-condition

    if (a == 0 && n == 0) return 1;
    if (a == 0 && n != 0) return 0;
    if (a != 0 && n == 0) return 1;
    if (a == 1) return 1;

    int half = power_recur_fast(a, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}

int index_of_max(const std::vector<int>& v) {
    if (v.empty()) cmpt::error("empty vector");

    int mi = 0;
    for(int i = 1; i < v.size(); i++) {
        if (v[i] > v[mi]) {
            mi = i;
        }
    }
    return mi;
}

int max(const std::vector<int>& v) {
    return v[index_of_max(v)];
}

//int index_of_max2(const std::vector<int>& v) {
//    if (v.empty()) cmpt::error("empty vector");
//
//    int mi = 0;
//    int i = 1;
//    while (i < v.size()) {
//        if (v[i] > v[mi]) {
//            mi = i;
//        }
//        i++;
//    }
//    return mi;
//}

//int index_of_max2(const std::vector<int>& v) {
//    if (v.empty()) cmpt::error("empty vector");
//
//    int mi = 0;              // 1
//    int i = 1;               // 1
//    while (i < v.size()) {   // n
//        if (v[i] > v[mi]) {  // n - 1
//            mi = i;          // ???
//        }
//        i++;                 // n - 1
//    }
//    return mi;               // 1
//}


int index_of_max_count(const std::vector<int>& v) {
    if (v.empty()) cmpt::error("empty vector");

    int mi = 0;
    int i = 1;
    int mi_assign_i_count = 0;
    while (i < v.size()) {
        if (v[i] > v[mi]) {
            mi = i;
            mi_assign_i_count++;
        }
        i++;
    }
    std::cout << "mi_assign_i_count = " << mi_assign_i_count << "\n";
    return mi;
}



std::vector<int> rand_vec(int n) {
    std::vector<int> result(n);
    for(int i = 0; i < n; i++) {
        result[i] = rand();  // rand() returns a random int
    }                        // from 0 to RAND_MAX
    return result;
}

void test() {
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        std::vector<int> v = rand_vec(1000000);
        index_of_max_count(v);
    }
}


int mult_count = 0;



void power_test(int a, int n) {
    mult_count = 0;
    power_recur_fast(a, n);
    std::cout << a << "^" << n << ", " << mult_count << " multiplications" << std::endl;
}




int main() {
    std::vector<int> temp{1,2,3};
    std::cout << index_of_max_rec(temp, 1) << std::endl;
    std::cout << power_iter(2, 3) << std::endl;
    std::cout << power_recur(2, 3) << std::endl;
    std::cout << power_recur_fast(2, 3) << std::endl;
    std::cout << index_of_max(temp) << std::endl;
    std::cout << max(temp) << std::endl;

    std::cout << index_of_max_count(temp) << std::endl;

    test();

    for(int i = 0; i <= 20; ++i) {
        power_test(2, i);
    }
}