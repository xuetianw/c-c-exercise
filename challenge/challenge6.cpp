//
// Created by fred on 19/04/19.
//

#include "../cmpt_error.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;



vector<int> convert_to_vector(string str) {
    vector<int> result;
    for (char i : str) {
        if (i != ' ') {

            result.push_back(int(i) -48);
        }
    }
    return result;
}

int main() {

    std::string str;
    vector<int> columns[500];
    vector<int> rows[1000];

    int count = 0;
    while (std::getline(cin, str)) {
        // output the line
        rows[count] = convert_to_vector(str);

        // now we loop back and get the next line in 'str'
        count++;
    }

    for(int i = 0; i < 500; i++) {
        for (int j = 0; j < 1000; j++) {
            columns[i].push_back(0);
        }
    }

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 500; j++) {
            columns[j][i] = rows[i][j];
        }
    }

    vector<int> sum_of_each_column(500);

    for (int i = 0; i < 500; i++) {
        int sum_of_colum = 0;
        for (int j = 0; j < 1000; j++) {
            sum_of_colum += columns[i][j];
        }
        sum_of_each_column[i] = sum_of_colum;
    }

    int max_sum = 0;
    for (int i = 0; i < 500; i++) {
        if (sum_of_each_column[i] > max_sum) {
            max_sum = sum_of_each_column[i];
        };
    }

    cout << "max_sum : " << max_sum << endl;
    for (int i = 0; i < 500; i++) {
        if (sum_of_each_column[i] == max_sum) {
            cout << "i :" << i << endl;
        };
    }


}