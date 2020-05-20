//
// Created by fred on 19/04/19.
//

#include "../cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool has_ie_ei(const string& word) {
    for (int i = 0; i < word.size(); i++) {
        if(word[i] == 'i') {
            if (i != word.size() - 1) {
                if(word[i+1] == 'e') {
                    return true;
                }
            }
        }
    }

    for (int i = 0; i < word.size(); i++) {
        if(word[i] == 'e') {
            if (i != word.size() - 1) {
                if(word[i+1] == 'i') {
                    return true;
                }
            }
        }
    }

    return false;
}


bool have_rule(string& word) {

    for (int i = 0; i < word.size(); i++) {
        if(word[i] == 'e') {
            if (i != word.size() - 1) {
                if(word[i + 1] == 'i') {
                    if ((i - 1 < 0) || (word[i - 1] != 'c')) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


int main() {

    int haveIeOrEiOrBoth = 0;
    string word;
    int count = 0;
    int count2 = 0;
    int count_rule = 0;
    while (cin >> word) {
        if (has_ie_ei(word)) {
            count ++;
            if (have_rule(word)) {
                count2++;
            }
        }
    } // while

    cout << count << endl;
    cout << count2 << endl;

} // main
