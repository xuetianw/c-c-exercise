//
// Created by fred on 22/03/19.
//



#include <vector>
#include <assert.h>
#include <iostream>

// Pre-condition:
//    none
// Post-condition:
//    Returns the smallest i >= 0 such that v[i] == x; or, if
//    x is not anywhere in v, then -1 is returned
int linear_search1(const std::vector<int>& v, int x) {
    for(int i = 0; i < v.size(); ++i) {
        if (x == v[i]) return i;
    }
    return -1;
}


// Pre-condition:
//    x is in v (i.e. there exists some i such that v[i] == x)
// Post-condition:
//    returns the smallest i >= 0 such that v[i] == x
int location_of(const std::vector<int>& v, int x) {
    int i = 0;
    while (v[i] != x) ++i;
    return i;
}


// Notice that v is *not* const so that the end value can be temporarily
// modified by the algorithm.
int linear_search2(std::vector<int>& v, int x) {
    const int n = v.size();
    if (n == 0) return -1;
    if (n == 1) {
        if (v[0] == x) return 0;
        else return -1;
    }

    // n >= 2 at this point

    // first check if x is the last element
    if (v[n-1] == x) return n - 1;

    // at this point we know v[n-1] != x
    int last = v[n-1];          // save the last element
    v[n-1] = x;                 // make the last element equal to x
    int i = location_of(v, x);  // search for x
    v[n-1] = last;              // now put the true last element back
    if (i == n - 1) return -1;  // if the first x was the one at the end, x is not in v
    else return i;
}


// linear search on the range [begin, end)
int linear_search3(const std::vector<int>& v, int x, int begin, int end) {
    for(int i = begin; i < end; ++i) {
        if (x == v[i]) return i;
    }
    return -1;
}


// recursive linear search on a range
int linear_search4(const std::vector<int>& v, int x, int begin, int end) {
    if (begin >= end) {          // base case: empty range
        return -1;
    } else if (v[begin] == x) {  // base case: x is at range's beginning
        return begin;
    } else {                     // recursive case
        return linear_search4(v, x, begin + 1, end);  // note the + 1
    }
}

void insertion_sort(std::vector<int>& v) {
    for(int i = 1; i < v.size(); ++i) {

        int key = v[i];             // key is the value we are going to insert
        // into the sorted part of v

        int j = i - 1;              // j points to one position before the
        // (possible) insertion point of the key;
        // thus, key will eventually be inserted at
        // v[j + 1]

        //
        // This loop determines where to insert the key into the sorted part
        // of v. It does this by searching backwards through the sorted part
        // for the first value that is less than, or equal to, key.
        //
        // This loop combines searching with element moving. Every time an element
        // bigger than the key is found, it is moved up one position.
        //
        // It's possible that there is no value in the sorted part that is
        // smaller than key, in which case key gets inserted at the very
        // start of v. This is a special case that is handled by j >= 0
        // in the loop condition.
        //
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            --j;
        }
        // After loop ends this is true: (j < 0 || v[j] <= key)

        v[j + 1] = key;             // j points to the location *before*
        // the one where key will be inserted
    }
}

// returns true if v is in ascending sorted order, and false otherwise
bool is_sorted(const std::vector<int>& v) {
    for(int i = 1; i < v.size(); i++) {  // note i starts at 1
        if (!(v[i-1] <= v[i])) {
            return false;
        }
    }
    return true;
}


bool sort_ok(std::vector<int> v) {
    insertion_sort(v);
    return is_sorted(v);
}

void insertion_sort_test() {
    std::vector<int> empty;
    std::vector<int> one = {5};
    std::vector<int> two_a = {2, 7};
    std::vector<int> two_b = {4, 1};
    std::vector<int> two_c = {3, 3};
    std::vector<int> same = {4,4,4,4,4,4};
    std::vector<int> ordered = {-1, 0, 5, 9, 10};
    std::vector<int> rev = {8, 7, 3, 1, 0, -5};

    assert(sort_ok(empty));
    assert(sort_ok(one));
    assert(sort_ok(two_a));
    assert(sort_ok(two_b));
    assert(sort_ok(two_c));
    assert(sort_ok(same));
    assert(sort_ok(ordered));
    assert(sort_ok(rev));
    std::cout << "all insertion_sort tests passed\n";
}