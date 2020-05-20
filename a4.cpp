//
// Created by fred on 22/03/19.
//

// a4.cpp

#include <cassert>
#include <tgmath.h>
#include "a4.h"  // no other includes are allowed!


void sum_recur(vector<int> &vector, ::vector<int>& vector1, ::vector<int>& vector2, long size);

using namespace std;

//
// put your implementation of the 20 function headers from "a4.h" here
//

int sum_of_squares(int n) {
    if (n == 1) {
        return 1;
    }
    return n * n + sum_of_squares(n-1);
}

void sum_of_squares_test() {
    assert(1 == sum_of_squares(1));
    assert(5 == sum_of_squares(2));
//    cout<<sum_of_squares(3) <<endl;
    assert(14 == sum_of_squares(3));
    assert(30 == sum_of_squares(4));
}


int sum_of_evens(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 2 * n + sum_of_evens(n - 1);
    }
}

void sum_of_evens_test() {
    assert(0 == sum_of_evens(0));
//    cout << sum_of_evens(2)<<endl;
//    cout << sum_of_evens(3) <<endl;
    assert(6 == sum_of_evens(2));
    assert(12 == sum_of_evens(3));
}


string fill(char c, int n) {
    if (n == 0) {
        return string("");
    }
    return string(1, c) + fill(c, n - 1);
}

void fill_test(){
    assert(fill('a', 1) == "a");
    assert(fill('m', 2) == "mm");
    assert(fill('c', 3) == "ccc");
}

bool all_digits(const string& s) {
    if (s.length() == 0) {
        return true;
    } else {
        string temp(1, s.at(0));
        try {
            std::stoi(temp);
        } catch (exception &e) {
            return false;
        }
        return all_digits(s.substr(1, s.size()-1));
    }
}

void all_digits_test() {
    string test1 = "123";
    assert(all_digits(test1));
    string test2 = "1s4";
    assert(!all_digits(test2));
    string test3 = "ssrf";
    assert(!all_digits(test3));
    string test4 = "3332123";
    assert(all_digits(test4));
}

string shrink(const string& s) {
    if (s.length() != 0){
        string temp(1, s.at(0));
        if (temp != " ") {
            string sub = s.substr(1,s.length()-1);
            return temp + shrink(sub);
        } else {
            string sub = s.substr(1,s.length()-1);
            return "" + shrink(sub) ;
        }
    }
    return "";
}

void shrink_test(){
    assert(shrink("ab cd") == "abcd");
    assert(shrink(" acd") == "acd");
    assert(shrink("acd ") == "acd");
}


vector<int> sum_pos_helper(const vector<int> &v) {
    vector<int> temp(v.size() -1);
    for (int i = 1; i < v.size(); i++) {
        temp[i -1] = (v[i]);
    }
    return temp;
}

int sum_pos(const vector<int>& v) {
    if (!v.empty()) {
        if (v[0] > 0) {
            vector<int> vector_from_second = sum_pos_helper(v);
            return v[0] + sum_pos(vector_from_second);
        } else {
            vector<int> vector_from_second = sum_pos_helper(v);
            return  sum_pos(vector_from_second);;
        }
    } else {
        return 0;
    }
}

void sum_pos_test() {
    vector<int> a = {1,2,3,4,5};
    int resutl_a = sum_pos(a);
    vector<int> b = {-1,2,3,4,5};
    int result_b = sum_pos(b);
    vector<int> c = {2,3,4,5,-1};
    int result_c = sum_pos(c);

    assert(15 == resutl_a);
    assert(14 == result_b);
    assert(14 == result_c);
}


vector<int> sum_vec(const vector<int>& a, const vector<int>& b) {
    vector<int> temp;
    vector<int> vector1 = a;
    vector<int> vector2 = b;
    long size = a.size();
    sum_recur(temp, vector1, vector2, size);
    return temp;
}

void sum_recur(vector<int> &vector, ::vector<int>& vector1, ::vector<int>& vector2, long size) {
    if (vector.size() != size) {
        vector.push_back(vector1.at(0) + vector2.at(0));
        vector1.erase(vector1.begin());
        vector2.erase(vector2.begin());
        sum_recur(vector, vector1, vector2, size);
    } else {
        return;
    }
}

void sum_vec_test() {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {6,7,8,9,10};
    vector<int> temp = {7,9,11,13,15};
    vector<int> result = sum_vec(a, b);
    assert(temp == result);
}

vector<string> count_helper(const vector<string>& v) {
    vector<string> temp(v.size() -1);
    for (int i = 1; i < v.size(); i++) {
        temp[i -1] = (v[i]);
    }
    return temp;
}


int count(const vector<string>& v, const string& s) {
    if (!v.empty()) {
        if (v[0] == s) {
            return 1 + count(count_helper(v), s);
        } else{
            return count(count_helper(v), s);
        }
    } else {
        return 0;
    }
}

void count_test() {
    string str1 = "apple";
    string str2 = "banana";
    string str3 = "orange";
    vector<string> a = { str1, str2, str3};
    vector<string> b = { str1, str1, str3};
    vector<string> c = { str3, str3, str3};

    assert(count(a, str1) == 1);
    assert(count(b, str1) == 2);
    assert(count(c, str3) == 3);
}

void zip_helper(vector<string>& temp, string s, string t) {
    if (!s.empty()) {
        temp.push_back(string(1, s[0]) + string(1, t[0]));
        zip_helper(temp, s.substr(1, s.size() - 1), t.substr(1, t.size() -1));
    }
}

vector<string> zip(const string& s, const string& t) {
    vector<string> temp;
    zip_helper(temp, s, t);
    return temp;
}

void zip_test() {
    string a = "abc";
    string b = "xyz";
    vector<string> result = zip(a, b);
    vector<string> expected {"ax", "by", "cz"};
    assert(result == expected);
}



void get_sub_vector(vector<string> &v) {
    vector<string> temp;
    for (int i = 1; i < v.size(); i++) {
        temp.push_back(v[i]);
    }
    v = temp;
}

void join_helper(string &result, vector<string> v, const string& sep) {
    if (v.empty()) {
    } else if (v.size() == 1) {
        result += v.front();
        v.pop_back();
        join_helper (result, v, sep);
    } else {
        string element = v.at(0);
        get_sub_vector(v);
        result += element + sep;
        join_helper(result, v, sep);
    }
}

string join(const vector<string>& v, const string& sep) {
    string temp;
    join_helper(temp, v, sep);
    return temp;
}


void join_test() {
    string result = join({"cat", "dog", "house"}, ", ");
    string expected = "cat, dog, house";
    string result2 = join({"cat", "house"}, ", ");
    string expected2 = "cat, house";
    string expected3;
    string result3 = join({}, ", ");
    assert(expected == result);
    assert(expected2 == result2);
    assert(expected3 == result3);

}
int* test(){
    int* arr = new int(5);
    return arr;
}


// You can use this main function (which calls all the test functions), or
// re-write it any way you like. The marker will be using their own main
// function.
int main () {
    int* arr= new int [3];
    for (int i = 0; i < 3; i++) {
        arr[i] = i;
    }
    int *p = arr;
    cout << *p;
    p++;
    cout << *p;
    p++;
    cout << *p << endl;
    p++;
    int *pq = new int (5);
    delete pq;
    cout << "pq == nullptr :";
    cout << (pq == nullptr) << "\n";
    cout << "pq :";
    cout << pq << "\n";


    cout<<  sqrt(-1);
    sum_of_squares_test();
    sum_of_evens_test();
    fill_test();
    all_digits_test();
    shrink_test();
    sum_pos_test();
    sum_vec_test();
    count_test();
    zip_test();
    join_test();
}