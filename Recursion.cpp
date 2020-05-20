//
// Created by fred on 08/03/19.
//


#include <iostream>
#include <vector>

using namespace std;

void a() {
    std :: cout << "Hello!\n";
    a();
}

void b(int n) {
    std :: cout << n << ": hello!\n";
    b(n + 1);  // notice n + 1 is passed as the parameter
}

void c(int n) {
    if (n >= 10) {
        // all done: do nothing
    } else {
        std::cout << n << ": hello!\n";
        c(n + 1);
    }
}

void d(int n) {
    if (n <= 0) {
        // all done: do nothing
    } else {
        std::cout << n << ": hello!\n";
        d(n - 1);
    }
}

void say_hello(int n) {
    if (n > 0) {
        std::cout << n << ": hello!\n";
        say_hello(n - 1);
    }
}

void say(const std::string& msg, int n) {
    if (n > 0) {
        std::cout << n << ": " << msg << "\n";
        say(msg, n - 1);
    }
}

// prints the numbers from n down to 1
void count_down(int n) {
    if (n > 0) {
        cout << n << "\n";
        count_down(n - 1);
    }
}

// prints the numbers from 1 up to n
void count_up(int n) {
    if (n > 0) {
        count_up(n - 1);
        cout << n << "\n";
    }
}

int S(int n) {
    if (n == 0) {            // base case
        return 0;
    } else {
        return n + S(n - 1);   // recursive case
    }
}

// Returns a new vector w of length v.size() - 1 such that
// w[0] == v[1], w[1] == v[2], ..., w[v.size() - 2] == v[v.size() - 1].
// In other words, it returns a copy of v with the first element
// removed.
std::vector<int> rest(const std::vector<int>& v) {
    vector<int> result;
    for (int i = 1; i < v.size(); ++i) {  // i starts at 1
        result.push_back(v[i]);
    }
    return result;
}

// Returns v[begin] + v[begin + 1] + ... + v[end - 1]
int sum2(const vector<int>& v, int begin, int end) {
    if (begin >= end) {
        return 0;
    } else {
        return v[begin] + sum2(v, begin + 1, end);
    }
}

// Returns the sum of all the elements in v
int sum2(const vector<int>& v) {
    return sum2(v, 0, v.size());
}

// Returns v[begin] + v[begin + 1] + ... + v[end - 1]
int sum3(const vector<int>& v, int begin) {
    if (begin >= v.size()) {
        return 0;
    } else {
        return v[begin] + sum3(v, begin + 1);
    }
}

// Returns the sum of all the elements in v
int sum3(const vector<int>& v) {
    return sum3(v, 0);
}

// Pre-condition:
//     all ints in v are >= 0
// Post-condition:
//     If v[0], v[1], ... v[n-1] are all even (n is v's size),
//     true is returned. Otherwise, false is returned.
//     If v is empty, true is returned
bool all_even(const vector<int>& v) {
    // ...
}

int main() {
//    a();
//    count_down(5);
//    count_up(5);
    std::cout<<S(5);
};
