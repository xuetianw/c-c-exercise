//
// Created by fred on 19/04/19.
//

#include "../cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>



//In the given wordlist, how many different words contain at least one c, one
//a, and one t in that order? Before and after each of these letters, there
//can be 0 or more other letters (even other occurrences of c, a, or t).
//
//Here are a few example words that match the rules: cat, broadcast,
//chatter, cachet, ....

using namespace std;


bool check_word (const string &word) {
    int c_index = -1;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == 'c') {
            c_index = i;
            break;
        }
    }
    if(c_index == -1) {
        return false;
    }
    int a_index = -1;
    for (int i = c_index; i < word.size(); i++) {
        if (word[i] == 'a') {
            a_index = i;
            break;
        }
    }
    if(a_index == -1) {
        return false;
    }
    int t_index = -1;
    for (int i = a_index; i < word.size(); i++) {
        if (word[i] == 't') {
            t_index = i;
            break;
        }
    }
    if(t_index == -1) {
        return false;
    }
    return true;

}

int main() {


    string* words = new string[180000];

//    // read a word at a time from stdin
    string word;
//
    int count = 0;
    while (cin >> word) {
        if (check_word(word)) {
            count++;
        }
    } // while
//

    delete [] words;

    cout << count;



} // main