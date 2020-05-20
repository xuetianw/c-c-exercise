//
// Created by fred on 31/01/19.
//

// a2.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <put your full name here!>
// St.# : <put your full SFU student number here>
// Email: <put your SFU email address here>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include "cmpt_error.h"    // These are the only permitted includes!
#include <iostream>        //
#include <string>          // Don't include anything else.
#include <algorithm>
#include <cassert>

using namespace std;

//
// ... write your code here here ...
//
class str_vec{
private:
    int _capacity;
    int _size;
    string *stringArr = NULL;
public:
    //default constructor
    str_vec() : _capacity(10), _size(0), stringArr(new string[_capacity]) {}

    //constructor
    str_vec(int size , const string &newString) {
        if (size < 0) {
            cmpt::error("size cannot be less than 0");
        } else {
            this->_capacity = 10;
            this->_size = size;
            stringArr = new string[_capacity];
            for (int i = 0; i < size; i++) {
                stringArr[i] = newString;
            }
        }
    }

    // Copy constructor
    str_vec(const str_vec& other)
            : _capacity(other._capacity), stringArr(new string[_capacity])
    {
        _size = other._size;
        for(int i = 0; i < _size; ++i) {
            stringArr[i] = other.stringArr[i];
        }
    }
    ~str_vec() {
        if (stringArr != NULL) {
            delete []stringArr;
        }
    }

    int capacity() const {
        return _capacity;
    }

    int size() const {
        return _size;
    }

    double pct_used() {
        return this->_size/this->_capacity;
    }

    //// convert arr's underlying array to a string
    string to_str () const{
        string result = "{";
        for (int i = 0; i < _size - 1; i++) {
            result += '"' ;
            result += stringArr[i];
            result += '"' ;
            result += ",";
        }
        if (_size != 0) {
            result += '"' ;
            result += stringArr[_size-1];
            result += '"' ;
        }
        result += "}";
        return result;
    }

    void print() const {
        cout << to_str ();
    }

    void println() const {
        cout << to_str () << endl;
    }


    string get(int i) {
        if (i < 0 || i > _size-1) {
            cmpt::error("i is less than 0, or i is greater than size()-1");
        }
        return stringArr[i];
    }

    void set(int i, string s) {
        if (i < 0 || i > _size-1) {
            cmpt::error("i is less than 0, or i is greater than size()-1");
        }
        stringArr[i] = s;
    }

    void append(const string s) {
        if (stringArr == NULL) {
            stringArr = new string[_capacity];
        }
        stringArr[_size] = s;
        _size++;
    }

    void prepend(const string s) {
        if (stringArr == NULL) {
            stringArr = new string[_capacity];
        }
        for (int i = _size-1; i >= 0 ; i--) {
            stringArr[i+1] = stringArr[i];
        }
        stringArr[0] = s;
        _size++;
    }


    void reverse() {
        for (int i = 0; i < _size / 2; i++){
            swap(stringArr[i], stringArr[_size - i - 1]);
        }
    }

    void sort() {
        std::sort(stringArr, stringArr + _size);
    }


    void clear() {
        _size = 0;
        delete [] stringArr;
        stringArr = NULL;
    }


    void shrink_to_fit() {
        string *temp = new string[_size];
        for (int i = 0; i< _size; i++) {
            temp[i] = stringArr[i];
        }
        delete [] stringArr;
        _capacity = _size;
        stringArr = new string[_capacity];
        for (int i = 0; i < _size; i++) {
            stringArr[i] = temp[i];
        }
        delete [] temp;
    }

    bool operator==(const str_vec& s) {
        for (int i = 0; i < _size; i++) {
            if (stringArr[i] != s.stringArr[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const str_vec& s) {
        for (int i = 0; i < _size; i++) {
            if (stringArr[i] != s.stringArr[i]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    cout << "Hello, world!\n";

    //
    // ... put code for testing your functions here ...
    //
    str_vec arr;

// arr is str_vec of size 5, each entry contain the string "cat"
    cout<<"hello"<< endl;

    str_vec arr2(5, "cat");

    str_vec arr3 = arr2;

    str_vec empty;

    cout << empty.size() << ' '       // 0
         << empty.capacity() << ' '   // 10
         << empty.pct_used() << '\n'; // 0



    string s = arr2.to_str(); // s is the string {"cat", "cat", "cat"}

    cout << s << endl;

    arr2.print();    // prints {"cat", "cat", "cat"} on cout (no \n at end)
    arr2.println();  // prints {"cat", "cat", "cat"} on cout (\n at end)

//    arr = str_vec(3, "cat");
//    string s = arr.to_str(); // s is the string {"cat", "cat", "cat"}

    arr2.set(1, "dog");  // arr is now {"cat", "dog", "cat"}

    string s1 = arr2.get(1);  // s1 is "dog"
    string s2 = arr2.get(2);  // s2 is "cat"

    cout << s1 <<endl;
    cout << s2 <<endl;



    arr3.append("apple");  // {"apple"}
    arr3.append("orange"); // {"apple", "orange"}
    arr3.prepend("up");    // {"up", "apple", "orange"}
    arr3.prepend("down");  // {"down", up", "apple", "orange"}

    arr3.println();

    arr3.sort();
    arr3.println();


    arr.append("d");
    arr.append("b");
    arr.append("a");
    arr.append("c");  // {"d", "b", "a", "c"}
    arr.println();

    arr.sort();       // {"a", "b", "c", "d"}
    arr.println();

    arr.reverse();    // {"d", "c", "b", "a"}
    arr.println();


    str_vec arr5;         // {}, size 0, capacity 10
    arr5.append("a");     // {"a"}, size 1, capacity 10
    arr5.append("b");     // {"a", "b"}, size 2, capacity 10

    arr5.shrink_to_fit(); // {"a", "b"}, size 2, capacity 2

    arr5.clear();         // {}, size 0, capacity 2


    str_vec a(3, "cat");
    str_vec b(3, "cat");

    if (a == b) cout << "same\n";       // prints "same"
    if (a != b) cout << "different\n";  // prints nothing

    a.set(0, "feline");
    std::cout<<"__"<<endl;
    if (a == b) cout << "same\n";       // prints nothing
    if (a != b) cout << "different\n";  // prints differen
}