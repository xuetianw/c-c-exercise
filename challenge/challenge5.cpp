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




int get_index(string str, vector<string> words){
    for(int i = 0; i < words.size(); i++) {
        if (words[i] == str) {
            return i;
        }
    }
    return -1;
}



int main() {

    std::vector <std::string> words;
    std::vector <int> occurances;

    int count = 0;
    string word;
    while (cin >> word) {
        int word_index = get_index(word, words);
        if( word_index == -1) {
            words.push_back(word);
            occurances.push_back(1);
        } else {
            (occurances[word_index])++;
        }
        count ++;
        cout << "count" << count << endl;
    } // while
//
////    for (auto i = umap.begin(); i != umap.end(); i++)
////        cout << i->first << "      " << i->second
////             << endl;
    int max_occurrence = 0;
    for (int i : occurances) {
        if (i > max_occurrence) {
            max_occurrence = i;
        }
        cout << 111 << endl;
    }

    for (int i = 0; i < occurances.size(); i++) {
        if (occurances[i] == max_occurrence) {
            cout << "times :" << occurances[i] << "word :" << words[i];
        }
    }


} // main