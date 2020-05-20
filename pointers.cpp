//
// Created by fred on 17/01/19.
//

// pointers.cpp

#include "cmpt_error.h"
#include <iostream>

using namespace std;


void test1() {
    // Variable a has the type double. The value 6.02 is stored at some
    // location in the computer's memory.
    double a = 6.02;

    cout << "  a = " << a << "\n";

    // Variable pa has the type double*, i.e. pointer to a double. A double*
    // can store the address of a variable. In this case, pa stores the
    // address of variable.
    double* pa = &a;

    // The value of pa is the address of where in RAM a is stored. The
    // compiler and operating system determine the exact memory location of a,
    // and so we can't usually predict the value of pa. In fact, the value of
    // pa can change from run to run.
    cout << " pa = " << pa << "\n";

    // pa is the address of where in memory variable a is stored, and *a is
    // the value itself. This is important: having a pointer to a value means
    // you know the address of that value, and so you can access that variable
    // itself.
    cout << "*pa = " << *pa << "\n";

    // This statement modifies the value stored in a.
    *pa = 2.11;

    cout << "\n";
    cout << "  a = " << a << "\n";
    cout << "*pa = " << *pa << "\n";

    // You can have pointers to any type in C++, even pointers to pointers.
    // Here, variable ppa stores the address of pa. Thus, *ppa is the value of
    // pa, and **ppa is the value of a.
    double** ppa = &pa;

    cout << "\n";
    cout << " *ppa = " << *ppa << " (value of pa)\n";
    cout << "**ppa = " << **ppa << " (value of a)\n";
}


// C++ designates a region of your program's memory as the freestore, where
// memory can be allocated and de-allocated by the program as it runs. In C++,
// we use new to allocate memory on the freestore, and delete (or delete[], in
// the case of arrays) to deallocate memory on the freestore.
//
// While this seems simple enough, decades of experience have shown that this
// sort of manual memory management is notoriously hard to get right. Errors
// related to the mis-use of new and delete are the source of some of the most
// difficult programming bugs. This is a major reason we're using valgrind: to
// check that our programs don't have any memory errors.
//
// Later, we will see that C++ provides a number of useful techniques for
// simplifying memory management.
void test3() {
    // The expression new int(4) allocates one int on the freestore,
    // initializes that int to 4, and then returns a pointer to that int.
    int* p = new int(4);

    cout << "*p = " << *p << "\n";
    (*p)++;
    cout << "*p = " << *p << "\n";

    // When we are done with freestore memory, we de-allocate it, which means
    // we tell the freestore that the memory pointed to by p is no longer
    // needed and can, if necessary, be allocated later in future calls to
    // new.
    delete p;

    // If you don't delete p, then the memory that p pointed to stays
    // allocated and cannot be re-used. This is not a problem here since we
    // have allocated only a single byte. But in larger, long-running programs
    // losing memory in this way can eventually use up all of memory and crash
    // your program. This kind of error is called a **memory leak**, and it is
    // a very common error in C and C++. In C++, it is entirely up to the
    // programmer to prevent memory leaks. Explicitly calling delete is the
    // simplest way to do this, but in practice it turns out to be
    // surprisingly difficult to always call delete at the right time.
}

// Here's an example of a common problem you can run into with dynamic memory.
void test4() {
    int* p = new int(5);
    int* q = p;

    // Now p and q both point to the same int on the freestore.
    cout << "*p = " << *p << "\n";
    cout << "*q = " << *q << "\n";

    // If we call delete on p, then the int p was pointing to is now deleted.
    // But the pointer q does not know that!

    delete p; // ok, but dangerous: how does q know this has happened?

    *q = 2; // oops: q is not pointing to allocated memory!
    cout << "*q = " << *q << "\n";
}

// When I run test4 on my computer, there's no compiler error or run-time
// error:
//
//    $ ./pointers
//
//    ... program runs without any apparent problem ...
//
// That's a problem: there code is definitely incorrect! This is where
// valgrind is immensely useful. Running the program using valgrind catches
// the memory errors:
//
//   $ valgrind ./pointers
//
//   ... whoa! valgrind reports 2 memory errors ...
//

// These print functions will be used in the test5.
void print(int* arr, int size) {
    cout << "[";
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]";
}

void println(int* arr, int size) {
    print(arr, size);
    cout << "\n";
}

// Prints the elements in the range [begin, end), it prints *(begin + 0),
// *(begin + 1), *(begin + 2), ... *(end - 1).
//
// Notice that the range [begin, end) is asymmetric: *(begin + 0) is printed,
// but *(end + 0) is not printed.
void print(int* begin, int* end) {
    cout << "[";
    for(int* p = begin; p < end; ++p) {
        cout << *p << " ";
    }
    cout << "]";
}

void println(int* begin, int* end) {
    print(begin, end);
    cout << "\n";
}

// You can allocate arrays on the freestore using new and delete[] (note the
// square brackets at the end of delete).
void test5() {
    // arr points to a newly allocated array of 5 ints on the freestore. The
    // value of the ints is unknown.
    int* arr = new int[5];

    // We can access the individual elements of arr using pointer arithmetic
    // and the *-operator.
    *(arr + 0) = 1;
    *(arr + 1) = 2;
    *(arr + 2) = 3;
    *(arr + 3) = 4;
    *(arr + 4) = 5;

    // Equivalently, and often more conveniently, we can use the []-notation
    // to access individual elements. In general, the notation arr[i] is just
    // shorthand for *(arr + i).
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    // Print the elements of arr using pointer notation.
    for(int i = 0; i < 5; ++i) {
        cout << *(arr + i) << "\n";
    }

    int *p = arr;
    for(p; p < arr + 5; p++) {
        cout << *p <<endl;
    }

    // Print the elements of arr using []-notation.
    cout << "\n";
    for(int i = 0; i < 5; ++i) {
        cout << arr[i] << "\n";
    }

    // Print the elements of arr using a pointer (instead of an int) to point
    // to each element. In this case p is a pointer of type int* that initially
    // points to the first element of arr, and then each time through the loop
    // is incremented to point to the next element.
    cout << "\n";
    for(int* p = arr; p < arr + 5; p++) {
        cout << *p << "\n";
    }

    // Here we use a print function that takes as input and int* pointing to
    // the first element of the array, and the size of the array.
    cout << "\n";
    println(arr, 5);

    // Here we use a more general version of the print function that takes as
    // input a pointer to the first element we want to print, and a pointer to
    // one past the last element we want to print.
    cout << "\n";
    println(arr, arr + 5);

    // De-allocate arr using delete[] (not delete!) so that future calls to
    // could re-use this memory. You must use the []-bracket delete[] since
    // new was called using []-brackets.
    delete[] arr;
}

// sets all the values of arr to val
void fill(int* arr, int val, int size) {
    for(int i = 0; i < size; ++i) {
        arr[i] = val;
    }
}

// returns a pointer to a newly allocated array
int* make_int_arr(int size, int val = 0) {
    int* arr = new int[size];
    for(int i = 0; i < size; ++i) {
        arr[i] = val;
    }
    return arr;
}

void test6() {
    // arr1 points to a newly created array of 5 ints on the freestore.
    int* arr1 = new int[5];

    // Set all the values of arr1 to 0.
    fill(arr1, 0, 5);

    // Print it to cout.
    println(arr1, 5);

    // make_int_arr(6, 0) returns a pointer to a newly allocated array of 6
    // ints on the freestore, all initialized to 0. This is the standard
    // technique to use when you want a function to return an array, i.e.
    // return a pointer to an array on the freestore.
    int* arr2 = make_int_arr(6, 0);
    print(arr2, 6);

    // Always remember to de-allocate memory!
    delete[] arr1;
    delete[] arr2;
}

struct Point {
    double x, y;
};

void test7() {
    // p points to a newly created Point object on the freestore.
    Point* p = new Point{3.1, -4.2};

    // p points to the Point, and so *p is the Point itself. You can thus
    // access individual elements using the regular struct "."-notation
    cout << "x = " << (*p).x << "\n";
    cout << "y = " << (*p).y << "\n";

    // Pointers to structs (i.e. objects) are so common in C++ that
    // expressions like (*p).x are quite common, and so C++ provides a special
    // notation, i.e. the -> operator. The expression p->x is the same as
    // (*p).x.
    cout << "\n";
    cout << "x = " << p->x << "\n";
    cout << "y = " << p->y << "\n";

    // Always remember to de-allocate memory!
    delete p;
}

int main() {
//     test1();
////     test2();
//     test3();
//     test4();
//     test5();
     test6();
     test7();
}