//
// Created by fred on 17/01/19.
//

#include "a1.h"
#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//
// ... write your functions here ...
//
str_array make_empty(int cap = 10){
    str_array array;
    array.size = 0;
    array.capacity = cap;
    array.arr = new string [array.capacity];
    return array;
}


//To avoid memory leaks, programmers must remember to always call deallocate when they are finished with a str_array:

void deallocate(str_array& arr) {
    arr.size = 0;
    delete[] arr.arr;
    arr.arr = nullptr_t();
}

//deallocate(arr) calls delete[] on the underlying array, and also sets the array pointer to nullptr.
// Setting the array pointer to nullptr prevents memory corruption in cases when deallocate is called more than once on the same array.
//
//Be sure to run your test code with valgrind to make sure it has no memory leaks or errors!


//Write the following function:
//
//// Returns the percentage of the array that is in use.
double pct_used(const str_array& arr) {
    return arr.size/arr.capacity;
}
//This returns the size of the array divided by its capacity. For example, if arrs size is 5 and its capacity is 15, pct_used(arr) should return 0.333333.





//Implement this function:
//
//// convert arr's underlying array to a string
string to_str(const str_array& arr){
    string result = "{";
    for (int i = 0; i < arr.size - 1; i++) {
        result += '"' ;
        result += arr.arr[i];
        result += '"' ;
        result += ",";
    }
    if (arr.size != 0) {
        result += '"' ;
        result += arr.arr[arr.size-1];
        result += '"' ;
    }
    result += "}";
//    cout << result << "\n";
    return result;
}

//The string returned by to_str(arr) begins with a { and ends with }, and all the strings in it begin and end with ". Also, the strings are separated by “, “.
//
//For example, if arr represents an array with the strings "owl", "bug", and "cow", then to_str(arr) returns this string:
//
//{"owl", "bug", "cow"}
//If arr.size is 0, then "{}" is returned. If arr.size == 1, then there’s only one string in it and there are no commas.
//
//Important: Make sure the string returned by to_str follows exactly this format.
//
//Note that to_str only prints the first size elements of the underlying array.
//
//After you’ve implemented to_str, use it to write these two functions:
//
//// prints to_str(arr) to cout
void print(const str_array& arr) {
    cout << to_str(arr);

}
//
//// same as print, but also prints '\n' at the end
void println(const str_array& arr) {
    cout << to_str(arr) << "\n";
}
//These print functions are very easy to implement using to_str!


//Implement the get(arr, i) function, which returns the value at location i of the underlying array:
//
string get(const str_array& arr, int i) {
    if (i < 0) {
        cmpt::error ("size cannot be negative");
    } else if (i >= arr.size) {
        cmpt::error ("the value of the location cannot be bigger than the size");
    }
    return arr.arr[i];
}


//get should check the bounds of i, i.e. if i < 0 or i >= arr.size, then call cmpt::error to stop the program with a helpful error message.
//
//        Next, implement the set(arr, i, s) function, which assigns s to location i of the underlying array:
//
void set(str_array& arr, int i, const string& s) {
    if (i < 0) {
        cmpt::error ("size cannot be negative");
    } else if (i >= arr.size) {
        cmpt::error ("the value of the location cannot be bigger than the size");
    } else {
        arr.arr[i] = s;
    }
}

//As with set, check the bounds of i, i.e. if i < 0 or i >= arr.size, then call cmpt::error to stop the program with a helpful error message.



//The append function adds a new element to the right end of arr, re- sizing it if necessary:
//
void append(str_array& arr, const string& s) {
    // if the size is too small
    if (arr.size >= arr.capacity) {
        arr.capacity *= 2;
        // copying this to temp array
        string temp[arr.size];
        for (int i = 0; i < arr.size; i++) {
            temp[i] = arr.arr[i];
        }
        delete [] arr.arr;
        arr.arr = new string[arr.capacity];

        for (int i = 0; i < arr.size; i++) {
            arr.arr[i] = temp[i];
        }
    }
    arr.size ++;
    arr.arr[arr.size -1] = s;
//    cout << arr.arr[arr.size -1];
}
//If arr.size < arr.cap, then append should simply increment arr.size and put s at the first unused location at the end of arr.
//
//Implement the following function to test if two str_arrays are equal:
//
bool operator==(str_array a, str_array b) {
    if (a.size != b.size) {
        return false;
    } else {
        for (int i = 0; i < a.size; i++) {
            if (a.arr[i] != b.arr[i]) {
                return false;
            }
        }
        return true;
    }
}
//a and b are considered equal if they have the same size, and contain the same strings in the same order.


//Implement this function:
//
void clear(str_array& arr) {
    arr.size = 0;
}
//After calling clear(arr), the size of arr is 0. The underlying array doesn’t need to be changed.


//Implement the prepend function:
//
void prepend(str_array& arr, const string& s) {

    // if the size is too small
    if (arr.size >= arr.capacity) {
        arr.capacity *= 2;
        // copying this to temp array
        string temp[arr.size];
        for (int i = 0; i < arr.size; i++) {
            temp[i] = arr.arr[i];
        }
        delete [] arr.arr;
        arr.arr = new string[arr.capacity];

        for (int i = 0; i < arr.size; i++) {
            arr.arr[i] = temp[i];
        }
    }

    for (int i = arr.size -1; i >= 0 ; i--) {
        arr.arr[i+1] = arr.arr[i];
    }
    arr.size ++;
    arr.arr[0] = s;
//    cout << arr.arr[arr.size -1];

}
//It works just like append from above, but s is added as the first element of the array (and all the other elements are moved right one position).
//
//For example, if arr is {"up", "down", "mouse"}, then after calling prepend(arr, "cat") arr will be {"cat", up", "down", "mouse"}.

//
//Sometimes you might want to get rid of unused space in a dynamic array, so implement this function:
//
//// make the size and capacity of arr the same
void shrink_to_fit(str_array& arr) {
    string temp[arr.size];
    for (int i = 0; i < arr.size; i++) {
        temp[i] = arr.arr[i];
    }
    delete [] arr.arr;
    arr.arr = new string [arr.size];
    for (int i = 0; i < arr.size; i++) {
        arr.arr[i] = temp[i];
    }
    arr.capacity = arr.size;
}
//shrink_to_fit(arr) will, if necessary, re-size the underlying array to be the same as arr.size. In other words, it makes the size and the capacity the same; pct_used(arr) should return 1. None of the values in arr should be changed.
struct ListNode {
         int val;
         ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};


ListNode* removeElements(ListNode* head, int val) {
    ListNode *trav = head;

    while (trav != nullptr) {
        if (trav->val != val &&  trav == head) {

        }
    }



}

int main() {

//
//    str_array a = make_empty(3);
//    cout << a.size << "\n";
//    cout << a.capacity <<"\n";
//
//    a.size = 1;
//    a.arr[0] = "a";
//    cout << a.size << "\n";
//    cout << a.capacity <<"\n";
//
//    deallocate(a);
//
//    cout << a.size << "\n";
//    cout << a.capacity <<"\n";
//
//
//    cout << pct_used(a) << "\n";
////    deallocate(a);
//
//
//    a = make_empty(3);
//    a.size = 3;
//    a.arr[0] = "a";
//    a.arr[1] = "b";
//    a.arr[2] = "c";
//
//
//
//
//
//
//    string temp = to_str (a);
//    cout << temp <<"\n";
//
//
//    print(a);
//    println(a);
//
//    set(a, 1,"d");
//
//    println(a);
//
//    append(a,"f");
//    println(a);
//
//
//    cout << a.capacity <<"\n";
//
//
//
//    str_array b = make_empty(5);
//    append(b, "1");
//    append(b, "2");
//
//    cout << (b.size) << "\n";
//
//
//    str_array c = make_empty(4);
//    append(c, "1");
//    append(c, "2");
//    append(c, "3");
//
//
//    cout << (c.size) << "\n";
//
//    cout << (b == c) << "\n";
//
//    prepend(c, "4");
//    prepend(c, "5");
//    prepend(c, "4");
//
//    prepend(c, "4");
//
//    prepend(c, "4");
//    prepend(c, "4");
//    prepend(c, "4");
//    prepend(c, "4");
//    prepend(c, "4");
//
//    println(c);
//
//    cout << c.size <<"\n";
//    cout << c.capacity;
//
//    shrink_to_fit(c);
//    println(c);
//    cout << c.size <<"\n";
//    cout << c.capacity;
//
//
//    deallocate(a);
//    deallocate(b);
//    deallocate(c);
//
//
//
//
//
//
////    cout << "Hello, world!\n";
//
//
////    make_empty(50);
//
//
//    //
//    // ... put code for testing your functions here ...
//    //
//
////    string temp[] = {"a", "b", "c"};
////    string result = "";
////    for (int i = 0; i < 2; i++) {
////        cout << i;
////        cout << temp[i];
////        result += temp[i];
////    }
////    cout<<"\n";
////    cout<< result;
////    string ccc = "{'owl', 'bug', 'cow'}";




}