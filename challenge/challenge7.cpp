//
// Created by fred on 19/04/19.
//
#include "../cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    string word;
    int count = 0;
    while (cin >> word) {
        std::sort(word.begin(), word.end());
        string test_string = "appropriate";
        std::sort(test_string.begin(), test_string.end());
        cout << word << endl;
        if ( test_string != word) {
            count ++;
        }
    } // while
    cout << "number of Appropriate Anagrams is :"
            "" << count<<endl;
}