//
// Created by fred on 18/04/19.
//

// int_vec_class_tutorial2.cpp

#include "cmpt_error.h"
#include <iostream>
#include <cassert>

using namespace std;

//
// There are a few features mentioned in the textbook not used here, such as
// member initializers and constructor delegation. See p.587-8 of the textbook
// for how to use these features.
//

class int_vec {
private:
    int capacity; // length of underlying array
    int* arr;     // pointer to the underlying array
    int size;     // # of elements in this int_vec from user's perspective

    void resize(int new_cap) {
        if (new_cap < capacity) return;
        capacity = new_cap;

        int* new_arr = new int[capacity];  // create new, bigger array

        for(int i = 0; i < size; ++i) {    // copy elements of arr
            new_arr[i] = arr[i];           // into new_arr
        }

        delete[] arr;                     // delete old arr

        arr = new_arr;                    // assign new_arr
    }

public:
    // Default constructor (takes no parameters)
    int_vec()
            : capacity(10), arr(new int[capacity]), size(0)
    { }

    int_vec(int sz, int fill_value)
            : capacity(10), size(sz)
    {
        if (size < 0) cmpt::error("can't construct int_vec of negative size");
        if (size > 0) capacity += size;
        arr = new int[capacity];
        for(int i = 0; i < size; ++i) {
            arr[i] = fill_value;
        }
    }

    // Copy constructor
    int_vec(const int_vec& other)
            : capacity(other.capacity), arr(new int[capacity]), size(other.size)
    {
        cout << "int_vec copy constructor called ...\n";
        for(int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    ~int_vec() {
        cout << "... ~int_vec called\n";
        delete[] arr;
    }

    int get_size() const {
        return size;
    }

    int get_capacity() const {
        return capacity;
    }

    int get(int i) const {
        if (i < 0 || i > size) cmpt::error("get: index out of bounds");
        return arr[i];
    }

    // Note that set is not a const method because it modifies the underlying
    // array.
    void set(int i, int x) {
        if (i < 0 || i > size) cmpt::error("get: index out of bounds");
        arr[i] = x;
    }


    //
    // Modifying version of operator[], e.g for statements like:
    //
    //    v[2] = -7;
    //
    // Notice that thre return type is int&, i.e a reference to an int. This
    // is important! If it was just plain int, then a *copy* of the value at
    // location i would be returned, which would mean the array's copy would
    // not actually be modified in an assignment statement.
    //
    int& operator[](int i) {
        cout << "(modifying operator[] called)\n";
        return arr[i];
    }

    //
    // Constant version of operator[], e.g. for statements like:
    //
    //   const int_vec v(100, 24);
    //   int x = v[2];
    //
    // In this example v is const, so the compiler does not permit any methods
    // to be called that might modify v. The previous operator[] is not const,
    // so it could modify v. Thus we need a second operator[], given below, to
    // use with a const int_vec.
    //
    int operator[](int i) const {
        cout << "(const operator[] called)\n";
        return arr[i];
    }

    void print() const {
        if (size == 0) {
            cout << "{}";
        } else {
            cout << "{";
            cout << arr[0];
            for (int i = 1; i < size; ++i) {  // i starts at 1 (not 0)
                cout << ", " << arr[i];
            }
            cout << "}";
        }
    }

    void println() const {
        print();
        cout << "\n";
    }

    void append(int x) {
        if (size >= capacity) {
            resize(2 * capacity);   // double the capacity
            // capacity = 2 * capacity;          // double the capacity
            // int* new_arr = new int[capacity]; // make new underlying array
            //                                   // twice size of old one

            // for(int i = 0; i < size; ++i) {   // copy elements of v
            //    new_arr[i] = arr[i];           // into new_arr
            // }

            // delete[] arr;                     // delete old arr

            // arr = new_arr;                    // assign new_arr
        }
        assert(size < capacity);
        arr[size] = x;
        size++;
    }


    //
    // The following assignment operator lets us write code like this:
    //
    //     int_vec a;
    //     int_vec b;
    //     a.append(5);
    //     b = a;         // b's original value is over-written, now contains
    //                    // a copy of a
    //
    // Notice that the return type of operator= is int_vec&, i.e. a reference to
    // int_vec. This only matters in the case where you want to use operator= in an
    // expression, e.g. something like this:
    //
    //     cout << (v = w);  // assign w to v and also print the value of the
    //                       // expression v = w, i.e. the copy of w now in v
    //
    // If you just write code like this then the return value of operator= doesn't
    // matter, e.g.::
    //
    //     v = w;  // assign a copy of w's value to v
    //             // value returned by = is ignored
    //
    int_vec& operator=(const int_vec& other) {
        // self-assignment is a special case: don't need to do anything
        if (this == &other) {
            return *this;
        } else {
            // re-size this int_vecs underlying array if necessary
            if (capacity < other.size) {
                resize(other.size + 10);     // a little bit of extra capacity
            }                                // to speed up append

            size = other.size;

            for(int i = 0; i < size; ++i) {  // copy other's values
                arr[i] = other.arr[i];       // into this array
            }

            return *this;
        }
    }


    //
    // Declare the function shrink_to_fit to be a friend of int_vec, i.e.
    // shrink_to_fit can read or write any of the private variables of
    // int_vec.
    //
    friend void clear(int_vec& v);
}; // class int_vec


//
// Friend Functions
// ----------------
//
// Sometimes you might need to allow a function outside of a class access to
// itsprivate variables. For example, suppose you want to write this function:
//
//     void clear(int_vec& v) {
//         v.size = 0;
//     }
//
// We could easily add clear as a method within int_vec, but lets assume for
// the sake of this example that we don't want to do that, and must implement
// it as an outside function.
//
// Since clear is not inside int_vec, it is not allowed to read or write
// v.size. Thus, this code won't compile.
//
// C++ lets you get around this problem by allowing int_vec to declare that
// clear is a **friend**. Being a friend means that clear can read or write
// the private variables of v.
//
// A class declares a friend function like this::
//
//     class int_vec {
//     private:
//         // ...
//
//     public:
//         // ...
//
//         friend void clear(int_vec& v);
//
//     }; // class int_vec
//
// int_vec thus gives clear permission to read and write its private
// variables.
//
// A good rule of thumb is to *never* use friends, unless there is no other
// possible choice. If your class has a lot of friend functions, then that
// might be a sign of poor design. The problem is that they break
// encapsulation: they allow outside functions to access an objects private
// variables. If a function really needs access to an object's private
// variables, then it is probably better to declare it to be a method.
//

void clear(int_vec& v) {
    v.size = 0;
}

//
// operator==(a, b) is the name of the == operator in C++, and it's used to
// test if two values are equal. To make sense, operator==(a, b) should be an
// **equivalence relation**, i.e. obey these rules:
//
// 1. For all objects a, a == a.
//    (reflexivity)
//
// 2. For all objects a and b, if a == b then b == a.
//    (symmetry)
//
// 3. For all objects a, b, and c, if a == b and b == c, then a == c.
//    (transitivity)
//
// Note that by "all objects" we mean all objects of the variable type for the
// operator== being defined.
//
// It's entirely up to the programmer to ensure that these three rules are
// obeyed. In many cases, it is easy to see they are true, but there can be
// trickier cases where it is not so clear that the rules hold. So you need to
// be careful when creation your own operator==.
//
// Notice that the int_vec parameters are all passed by constant reference,
// e.g. const int_vec&. This is for efficiency. If we passed them just as
// int_vec, i.e. by value, then the int_vec copy constructor would be called
// for each parameter. Then, when the function ends, those copies would be
// immediately destroyed.
//
// For example, if you passed a and b by value, then evaluating a != b would
// call the int_vec copy constructor 4 times, and then the destructor 4 times.
// This would be extremely inefficient in most cases.
//
bool operator==(const int_vec& a, const int_vec& b) {
    if (a.get_size() != b.get_size()) {
        return false;
    } else {
        for(int i = 0; i < a.get_size(); ++i) {
            if (a.get(i) != b.get(i)) {
                return false;
            }
        }
        return true;
    }
}

bool operator!=(const int_vec& a, const int_vec& b) {
    return !(a == b);
}

//
// This overloads operator<< so that you can easily print an int_vec to cin,
// or any other stream, e.g.:
//
//     int_vec a;
//     for(int i = 0; i < 10; ++i) {
//         a.append(i);
//     }
//
//     cout << "a = " << a << "\n";
//
// The function header is rather complex! Note that operator<< takes two
// inputs, an ostream& (i.e. a reference to an ostream), and an int_vec. An
// ostream is the C++ type for output streams, such as cout.
//
// os, is passed by reference (i.e. as ostream& instead of ostream) because it
// is modified by having numbers from arr put onto it. The int_vec is passed
// as const int_vec&, which means that the actual int_vec is passed and the
// compiler ensures it is not modified.
//
// The return type of operator<< is ostream&, i.e. it returns a reference to
// the passed-in ostream. It can't return just an ostream (i.e. without the
// &), because then a copy would be returned --- but we don't usually want to
// copy ostreams (e.g. we don't want to make a copy of cout!).
//
ostream& operator<<(ostream& os, const int_vec& arr) {
    if (arr.get_size() == 0) {
        os << "{}";
    } else {
        os << "{";
        os << arr.get(0);
        for (int i = 1; i < arr.get_size(); ++i) {  // i starts at 1 (not 0)
            os << ", " << arr.get(i);
        }
        os << "}";
    }
    return os;
}

void test1() {
    int_vec a;
    int_vec b;
    for(int i = 0; i < 10; ++i) {
        a.append(i);
        b.append(i);
    }

    if (a != b) {
        cout << "a and b are different\n";
    } else {
        cout << "a and b are the same\n";
    }

    cout << "a = " << a << "\n"
         << "b = " << b << "\n";
}

void test2() {
    int_vec a;
    for(int i = 0; i < 10; ++i) {
        a.append(i);
    }

    int_vec b = a;  // calls operator=
    int_vec c(a);   // calls copy constructor

    c.append(14);
    c.append(-1);
    b = c;

    if (a != b) {
        cout << "a and b are different\n";
    } else {
        cout << "a and b are the same\n";
    }

    cout << "a = " << a << "\n"
         << "b = " << b << "\n"
         << "c = " << c << "\n";
}

void test3() {
    int_vec a;
    for(int i = 0; i < 10; ++i) {
        a.append(i);
    }

    cout << "a = " << a << "\n";

    for(int i = 0; i < a.get_size(); ++i) {
        a[i] = 2 * a[i];
    }

    cout << "a = " << a << "\n";

    const int_vec b(10, -1);
    for(int i = 0; i < b.get_size(); ++i) {
        cout << "b[" << i << "] = " << b[i] << "\n";
    }

}

void test4() {
    int_vec a;
    for(int i = 0; i < 10; ++i) {
        a.append(i);
    }

    cout << "a = " << a << "\n";

    clear(a);

    cout << "a = " << a << "\n";
}

class Printable {
public:
    // prints the object to cout
    virtual void print() const = 0;

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

    ~Printable() {
        cout << "Printable destructor called\n";
    }

}; // class Printable



int main() {
//     test1();
//     test2();
//     test3();
//    test4();
}