//
// Created by fred on 11/02/19.
//

#include "error.h"
#include "cmpt_error.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace cmpt;
class doublevec {
private:
    int cap;  // capacity, i.e. size of the underlying array
    int sz;   // size of the vector; sz <= cap

    double* arr; // pointer to the first element of the
    // underlying array

    // Re-sizes the array arr points to be size n.
    // If cap >= n, then nothing is done.
    void reallocate_arr(int n) {
        if (n < 0) error("reallocate_arr n < 0");

        if (cap < n) {
            // copy arr into a new array of size n
            double* temp = new double[n];
            for(int i = 0; i < cap; ++i) {
                temp[i] = arr[i];
            }

            // delete the old array
            delete[] arr;  // note the use of delete[] with square brackets
            // necessary because arr points to an array

            // make arr point to the new array
            arr = temp;

            // set the new capacity
            cap = n;
        }
    }

public:
    // default constructor
    doublevec()
            : cap(10), sz(0)  // note the initial capacity is 10
    {
        arr = new double[cap];
    }

    // The explicit keyword ensures this constructor is not silently called to
    // covnert an int to a doublevec: it can only be called explicitly by the
    // programmer (and not implicitly by the compiler).
     doublevec(int n)
            : cap(n), sz(n)
    {
        if (n < 0) error("negative size");
        arr = new double[cap];
        for(int i = 0; i < sz; ++i) {
            arr[i] = 0;
        }
    }

    // copy constructor
    doublevec(const doublevec& other)
            : cap(other.cap), sz(other.sz)
    {
        arr = new double[cap];
        for(int i = 0; i < sz; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // assignment operator
    doublevec& operator=(const doublevec& other){
        if (this != &other) {  // check for self-assignment
            arr = new double[cap];
            for(int i = 0; i < sz; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // destructor
    ~doublevec() {
        delete[] arr;
    }

    int size() const {
        return sz;
    }

    int capacity() const {
        return cap;
    }

    bool empty() const {
        return size() == 0;
    }

    void clear() {
        sz = 0;
    }

    // Both set and get check that the passed-in index variable i is
    // in range, i.e. 0 <= i < size(). If not, an error is thrown.
    double get(int i) const {
        if (i < -sz || i >= sz) error("get index out of bounds");
        if (i < 0) {
            return arr[i + sz];
        } else {
            return arr[i];
        }
    }

    void set(int i, double val) {
        if (i < -sz || i >= sz) error("get index out of bounds");
        if (i < 0) {
            arr[i + sz] = val;
        } else {
            arr[i] = val;
        }
    }

    void push_back(double val) {
        cout << "push_back(" << val << ") called ... " << endl;
        if (sz == cap) {
            reallocate_arr(2 * capacity());  // double the capacity
        }                                    // to avoid frequent
        // re-allocations
        arr[sz] = val;
        sz++;
    }

    double pop_back() {
        if (sz == 0) error("popped empty vector");
        sz--;
        return arr[sz];
    }

    void push_front(double val) {
        if (sz == cap) {
            reallocate_arr(2 * capacity());  // double the capacity
        }                                    // to avoid frequent
        // re-allocations
        // move each element up one index
        for(int i = sz; i > 0; --i) {
            arr[i] = arr[i - 1];
        }

        arr[0] = val;
    }

    double pop_front() {
        if (sz == 0) error("popped empty vector");

        // save the popped element
        double result = arr[0];

        // move each element down on index
        for(int i = 1; i < sz; ++i) {
            arr[i - 1] = arr[i];
        }

        // decrease the size
        --sz;

        return result;
    }

    // Returns a copy of the element at arr[i].
    double operator[](int i) const {
        if (i < -sz || i >= sz) error("get index out of bounds");
        if (i < 0) {
            return arr[i + sz];
        } else {
            return arr[i];
        }
    }

    // Returns a reference to the element at location arr[i], which allows the
    // actual array to be set.
    double& operator[](int i) {
        if (i < -sz || i >= sz) error("get index out of bounds");
        if (i < 0) {
            return arr[i + sz];
        } else {
            return arr[i];
        }
    }

    // Returns a pointer to the first element of the vector.
    double* begin() const { return arr; }

    // Returns a pointer to one past the last element of the vector.
    double* end() const { return arr + sz; }

    void shrink() {
        if (sz < cap) {
            // copy arr into a new array of size sz
            double* temp = new double[sz];
            for(int i = 0; i < sz; ++i) {
                temp[i] = arr[i];
            }

            // delete the old array
            delete[] arr;  // note the use of delete[] with square brackets
            // necessary because arr points to an array

            // make arr point to the new array
            arr = temp;

            // set the new capacity
            cap = sz;
        }
    }

}; // class doublevec


// Returns true iff a and have the same elements in the
// same order.
bool operator==(const doublevec& a, const doublevec& b) {
    if (a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const doublevec& a, const doublevec& b) {
    return !(a == b);
}

ostream& operator<<(ostream& out, const doublevec& v) {
    int n = v.size();
    if (n == 0) {
        out << "{}";
    } else {
        out << '{' << v[0];
        for(int i = 1; i < n; ++i) {
            out << ", " << v[i];
        }
        out << '}';
    }
    return out;
}