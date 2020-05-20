//
// Created by fred on 20/04/19.
//

#include "../cmpt_error.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


char vowels[] = {'a','e','i','o','u'};

void remove_Vowels(string &word) {
    for(char vowel : vowels) {
        word.erase(std::remove(word.begin(), word.end(), vowel), word.end());
    }
}

int main() {

    int haveIeOrEiOrBoth = 0;

    vector<string> words;
    string word;
    while (cin >> word) {
        remove_Vowels(word);
        if(!word.empty()) {
            words.push_back(word);
        }
//        cout << word << endl;
    } // while
    sort(words.begin(), words.end());
    cout <<"words[99999] :" << words[99999] << endl;

} // main