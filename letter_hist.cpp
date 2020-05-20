//
// Created by fred on 18/04/19.
//

// letter_hist.cpp

//////////////////////////////////////////////////////////////////////////////////////////
//
// Reads a file from stdin (using cin) and counts occurrences of all 26 letters
// A to Z. Case is ignored, so 'A' and 'a' are treated as the same letter.
//
// The result is displayed as a histogram.
//
// You can use file-redirection in the terminal window like this:
//
//    $ ./letter_hist < somefile.txt
//      a ***3
//      b 0
//      c *****5
//
//      ...
//
//      z **2
//
// You could also re-direct the output to a file like this:
//
//    $ ./letter_hist < somefile.txt > out.txt
//
// Now out.txt contains the output of the program.
//
//////////////////////////////////////////////////////////////////////////////////////////

#include "cmpt_error.h"
#include <iostream>
#include <vector>
#include <cctype>  // tolower

using namespace std;

bool is_lower_alpha(char c) { return ('a' <= c) && (c <= 'z'); }

bool is_upper_alpha(char c) { return ('A' <= c) && (c <= 'Z'); }

bool is_alpha(char c) { return is_lower_alpha(c) || is_upper_alpha(c); }

int main() {
    // create a vector of 26 ints all initialized to 0
    vector<int> alpha(26, 0);

    // read a word at a time from stdin
    string word;
    while (cin >> word) {
        for(char c : word) {
            if (is_alpha(c)) {
                int idx = tolower(c) - 'a';
                alpha[idx]++;
            }
        } // for
    } // while

    // print the results to stdout (cout)
    for(int i = 0; i < alpha.size(); i++) {
        string bar = string(alpha[i], '*');
        cout << char('a' + i) << " " << bar << alpha[i]<< "\n";
    }
} // main
