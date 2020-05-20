//
// Created by fred on 19/04/19.
//

#include "../cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

// magic.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The solution we use here is brute force: there are 9!=362880 ways that 9
// numbers can be arranged, and the program simply generates each possible
// arrangement (using the standard next_permutation function) and tests if it
// is magic.

// For simplicity, the grid is stored as a list of 9 ints, in row-major order
// like this:
//
// 0 1 2
// 3 4 5
// 6 7 8
// vector<int> num;


void display(const vector<int>& v) {
    cout << v[0] << " " << v[1] << " " << v[2] << "\n"
         << v[3] << " " << v[4] << " " << v[5] << "\n"
         << v[6] << " " << v[7] << " " << v[8] << "\n\n";
}

// 0 1 2
// 3 4 5
// 6 7 8
bool is_magic(const vector<int>& v) {
    int r1 = v[0] + v[1] + v[2];
    int r2 = v[3] + v[4] + v[5];
    int r3 = v[6] + v[7] + v[8];

    int c1 = v[0] + v[3] + v[6];
    int c2 = v[1] + v[4] + v[7];
    int c3 = v[2] + v[5] + v[8];

    int d1 = v[0] + v[4] + v[8];
    int d2 = v[2] + v[4] + v[6];

    return             r1 == r2 && r1 == r3 &&
                       r1 == c1 && r1 == c2 && r1 == c3 &&
                       r1 == d1 && r1 == d2;
}

int check_grid(vector<int> grid, bool show_sol=false) {
    sort(begin(grid), end(grid));
    int num_sols = 0;
    do {
        if (is_magic(grid)) {
            num_sols++;
            if (show_sol) display(grid);
        }
    } while (next_permutation(begin(grid), end(grid)));
    return num_sols;
}

void test1() {
    vector<int> num = { 16, 37, 1, 3, 18, 33, 35, -1, 20 };
    int num_sols = check_grid(num, true);
    for(int n : num) cout << n << " ";
    cout << "\n";
    cout << "# solutions: " << num_sols << "\n";
}

int main() {
    test1();
} // main