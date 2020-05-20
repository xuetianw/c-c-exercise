//
// Created by fred on 19/04/19.
//

#include <cassert>
#include <iostream>
#include <string>



#include "../cmpt_error.h"
using namespace std;

int get_num_of_vow(const string &word) {
    char vowals [5] = {'a','e','i', 'o', 'u'};
    int num_of_vowals = 0;
    for(char ch : word) {
        ch = char(tolower(ch));
        for (char vowal : vowals) {
            if (ch == vowal) {
                num_of_vowals++;
                break;
            }
        }
    }
    return num_of_vowals;
}

int main() {


    int* num_of_vows_arr = new int[180000];
    string* words = new string[180000];

//    // read a word at a time from stdin
//    std::unordered_map<string, int> umap;
    string word;
//
    int count = 0;
    while (cin >> word) {
        int num = get_num_of_vow(word);
        num_of_vows_arr[count] = num;
        words[count] = word;
        count++;
    } // while
//
////    for (auto i = umap.begin(); i != umap.end(); i++)
////        cout << i->first << "      " << i->second
////             << endl;
    int max = 0;
    for (int i = 0; i < 180000; i++) {
        if (num_of_vows_arr[i] > max) {
            max = num_of_vows_arr[i];
        }
    }
//
//    cout << string("--", 10)<< endl;
//    for (auto i = umap.begin(); i != umap.end(); i++) {
//        if (i->second == max) {
//            cout << i->first << "      " << i->second
//                 << endl;
//        }
//    }

    for (int i = 0; i < 180000; i++) {
        if (num_of_vows_arr[i] == max) {
            cout <<words[i] << "      " << num_of_vows_arr[i]
                 << endl;
        }
    }

    delete [] num_of_vows_arr;
    delete [] words;



} // main
