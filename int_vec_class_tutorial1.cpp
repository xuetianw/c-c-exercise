//
// Created by fred on 24/01/19.
//

// int_vec_class_tutorial1.cpp

#include <iostream>
#include "cmpt_error.h"
#include <cassert>

using namespace std;

// In these notes we are going to implement an object-oriented version of a
// dynamic array of ints that we'll call int_vec. We will start from the
// function-oriented implementation from the first assignment.
//
// Recall that the key data structure for the function-oriented version this
// struct::
//
//    struct int_vec {
//        int capacity; // length of underlying array
//        int* arr;     // pointer to the underlying array
//        int size;     // # of elements in this int_vec from user's perspective
//    };
//
// The basic idea of the object-oriented version is to put the relevant functions
// in the object itself.
//
// First, we will change struct to class::
//
//    class int_vec {
//    public:
//        int capacity; // length of underlying array
//        int* arr;     // pointer to the underlying array
//        int size;     // # of elements in this int_vec from user's perspective
//    };
//
// class is very similar to struct, but with one difference: the "public:"
// label is required. "public:" says that everything underneath it is publicly
// available, i.e. any code can read or write arr, size, or capacity. This is
// exactly how a struct works by default. However, a class is different: by
// default, everything in a class is "private:", i.e. only code in the int_vec
// can access arr, size, and capacity.
//
// In object-oriented programing it's usually a good idea to **hide** the
// variables for an object by declaring them private like this::
//
//    class int_vec {
//    private:
//        int capacity; // length of underlying array
//        int* arr;     // pointer to the underlying array
//        int size;     // # of elements in this int_vec from user's perspective
//    public:
//        // nothing here yet
//    };
//
// All three of arr, size, and capacity should be private because we don't
// want programmers messing directly with these, e.g. they could easily cause
// problems, like deleting the array, making size negative, or increasing
// capacity (without re-sizing the underlying array). We will carefully
// control access to these variables through methods
//
// Since all the variables in int_vec are private, no functions outside of
// int_vec can read or write its variables. So to allow access to these
// variables, we'll write functions inside of the int_vec class; functions
// inside of a class are called **methods**.
//
//    class int_vec {
//    private:
//        int capacity; // length of underlying array
//        int* arr;     // pointer to the underlying array
//        int size;     // # of elements in this int_vec from user's perspective
//
//    public:
//      int get_size() const {      // a method
//          return size;
//      }
//
//      int get_capacity() const {  // a method
//          return capacity;
//      }
//    };
//
// We've added two methods to int_vec: get_size and get_capacity. Let's look
// in more detail at get_size. First, notice that get_size is in the public
// part of the class, which means that code outside of the class is able to
// call it. Second, we put "const" after the header and before the first "{"
// of its body to indicate that the method does not change any values in
// int_vec: get_size() just *reads* a value  from int_vec, but doesn't modify
// that value. Third, get_size() take any input parameters because it is a
// method and so has access to all the variables in int_vec (even private
// ones) size variable in int_vec. Recall that with the function-oriented
// int_vec struct we always had to pass the struct as the first parameter.
//
// Methods that read, or *get*, the value of a variable in a class are often
// called **getters**. So, get_size() and get_capacity() are both getters.
//
// Importantly, we do not provide functions that allow the user to *set* the
// value of size or capacity, i.e. we don't provide any **setters** for size
// or capacity. This is a design decision: we could have provided setter
// methods, but that doesn't make sense for this particular class: the user
// should not be able to change the size/capacity whenever they want.
//
// This idea of making data private is called **information hiding**, i.e. we
// hide details of the implementation so that the programmer doesn't have to
// worry about them, and can't accidentally (or intentionally!) mess them up.
// Experience has shown that information hiding is one of the most useful
// techniques in building large and complex programs.
//
// There is no getter or setter for arr. Instead, we provide a getters and
// setters to access its individual elements::
//
//     int get(int i) const {
//       if (i < 0 || i > size) cmpt::error("get: index out of bounds");
//       return arr[i];
//     }
//
//     // Note that set is not a const method because it modifies the underlying
//     // array.
//     void set(int i, int x) {
//       if (i < 0 || i > size) cmpt::error("get: index out of bounds");
//       arr[i] = x;
//     }
//
//
// Constructors and Destructors
// ----------------------------
//
// For the function-oriented dynamic array, we used "make" functions to create
// new int_vecs, e.g. make_empty_vec, make_filled_vec, make_copy, .... We also
// had a function called deallocate that deleted the underlying array that the
// programmer had to remember to call to avoid memory leaks.
//
// In object-oriented programming, instead of creating new objects with make
// functions we create them using **constructors**. A constructor is
// essentially a special method that creates a new object for a class. Inside
// the constructor, all the object's variables are initialized to sensible
// values. Importantly, there's no way to create a C++ object without calling
// a constructor, and that gives programmers total control over how objects
// are initialized.
//
// Also, all C++ objects have a special method called a **destructor** that is
// automatically called when the object is deleted. The destructor is where
// dynamic memory, or any other resource used by the object, can be
// de-allocated. Since the destructor is called automatically, the programmer
// never needs to worry about calling. Indeed, you cannot explicitly call a
// destructor!
//
// Lets add a constructor to our int_vec class to create a new empt int_vec::
//
//    class int_vec {
//    private:
//       int capacity; // length of underlying array
//       int* arr;     // pointer to the underlying array
//       int size;     // # of elements in this int_vec from user's perspective
//    public:
//
//       // Default constructor (takes no parameters)
//       int_vec() {
//         capacity = 10;            // set initial values
//         arr = new int[capacity];  // of all private
//         size = 0;                 // variables
//       }
//
//       int get_size() const {
//         return size;
//       }
//
//       int get_capacity() const {
//         return capacity;
//       }
//
//       int get(int i) const {
//         if (i < 0 || i > size) cmpt::error("get: index out of bounds");
//         return arr[i];
//       }
//
//       // Note that set is not a const method because it modifies the underlying
//       // array.
//       void set(int i, int x) {
//         if (i < 0 || i > size) cmpt::error("get: index out of bounds");
//         arr[i] = x;
//        }
//    };
//
// Constructors always have the same name as the class they are in, and they
// have no return type (not even void). A constructors job is to create a new
// instance of an object, which usually means initializing all its private
// variables.
//
// While initializing variables in this way in a constructor works, there is a
// better way to initializer variables in constructors: an **initializer
// list**. An initializer list appears just before the constructor body like
// this::
//
//     int_vec()
//     : capacity(10), arr(new int[capacity]), size(0)  // initializer list
//     { }
//
// There are a couple of reasons for using initializer lists. One is that it
// guarantees that the variables always have sensible values inside the body
// of the constructor. This can help prevent errors due to uninitialized
// variables. Second, some types don't work with =, i.e. some types cannot be
// assigned. For such types, writing "a = b;" doesn't even compile. When you
// use an initializer list, you don't use the =, you instead use the
// constructor for that type.
//
// Constructors are called automatically when you define an int_vec, e.g.::
//
//    int_vec v;  // default constructor automatically called
//
// There is no way to forget to call the constructor because it is called
// automatically. This solves the problem of forgetting to properly initialize
// an int_vec when you define it!
//
// Lets add another constructor that creates a new int_vec filled with copies
// of a given int::
//
//     int_vec(int sz, int fill_value)
//     : capacity(10), size(sz)  // initializer list
//     {
//         if (size < 0) cmpt::error("can't construct int_vec of negative size");
//         if (size > 0) capacity += size;  // capacity is 10 more than size
//         arr = new int[capacity];
//         for(int i = 0; i < size; ++i) {
//             arr[i] = fill_value;
//         }
//     }
//
// Notice that we check inside the constructor body that n is 0 or greater:
// the user is not allowed to create an int_vec with a negative size. There is
// also no return statement in the constructor because once capacity, arr, and
// size are assigned then the object is constructed and there's nothing else
// to do.
//
// Next, lets add a constructor that makes  copy of another int_vec. This is
// called a **copy constructor**::
//
//     // copy constructor
//     int_vec(const int_vec& other)
//     : capacity(other.capacity), arr(new int[capacity]), size(other.size)
//     {
//         for(int i = 0; i < size; ++i) {
//             arr[i] = other.arr[i];
//         }
//     }
//
// This copy constructor makes a brand new array (in the initializer list) and
// then copies all the elements of other into it.
//
// These constructors now let us write code like this::
//
//    int_vec a;         // empty vector (size 0)
//    int_vec b(5, 0);   // size 5 vector initialized to all 0s
//    int_vec c(b);      // c is a copy of b (using a new underlying array)
//
//
// Destructors
// -----------
//
// If you compile and run this code with valgrind, then you will notice that
// there are memory leaks. That's because the constructors allocate memory
// using new, but that memory is de-allocated anywhere.
//
// C++ objects provide a neat trick that solves the de-allocation problem
// (among others) almost perfectly: **destructors**. A destructor is a special
// method that is automatically called when the object is deleted. The
// destructor is the ideal place to put the delete[] statement to de-allocate
// the memory allocated in the constructor::
//
//     ~int_vec() {  // destructor: always ~ followed by class name
//         delete[] arr;
//      }
//
// The addition of this one method gets rid of all the int_vec memory leaks!
// There is no way to *not* have the destructor called, and there is also no
// way to manually call the destructor. This guarantees that delete[] is
// called exactly once on arr when it is no longer needed.
//
// Destructors always begin with a ~ followed by the name of the class. They
// never have any parameters.
//
// You can put any code you like in a destructor, although usually it contains
// "clean up" code that de-allocates resources used by the object. For
// debugging, it can be very handy to add a print message to see when the
// destructor is called, e.g.
//
//     ~int_vec() {  // destructor
//         delete[] arr;
//         cout << "int_vec destructor called\n";
//      }
//
//
// Print and Append Methods
// ------------------------
//
// Now lets add methods to print an int_vec and to append a value onto the
// right end.
//
// Here are a print and println method. Notice that both are declared const
// because they don't modify the object:
//
//   class int_vec {
//   private:
//      // ...
//   public:
//      // ...
//
//      void print() const {
//          if (size == 0) {
//              cout << "{}";
//          } else {
//              cout << "{";
//              cout << arr[0];
//              for (int i = 1; i < size; ++i) {  // i starts at 1 (not 0)
//                  cout << ", " << arr[i];
//              }
//              cout << "}";
//          }
//      }
//
//      void println() const {
//          print();
//          cout << "\n";
//      }
//
//    };
//
// And here is the implementation of append::
//
//    class int_vec {
//    private:
//       // ...
//    public:
//       // ...
//
//     void append(int x) {
//        if (size >= capacity) {
//           capacity = 2 * capacity;          // double the capacity
//           int* new_arr = new int[capacity]; // make new underlying array
//                                             // twice size of old one
//
//           for(int i = 0; i < size; ++i) {   // copy elements of v
//              new_arr[i] = arr[i];           // into new_arr
//           }
//
//           delete[] arr;                     // delete old arr
//
//           arr = new_arr;                    // assign new_arr
//        }
//        assert(size < capacity);
//        arr[size] = x;
//        size++;
//     }
//
//   };
//


class int_vec {
private:
    int capacity; // length of underlying array
    int* arr;     // pointer to the underlying array
    int size;     // # of elements in this int_vec from user's perspective
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
        for(int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    ~int_vec() {
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
            capacity = 2 * capacity;          // double the capacity
            int* new_arr = new int[capacity]; // make new underlying array
            // twice size of old one

            for(int i = 0; i < size; ++i) {   // copy elements of v
                new_arr[i] = arr[i];           // into new_arr
            }

            delete[] arr;                     // delete old arr

            arr = new_arr;                    // assign new_arr
        }
        assert(size < capacity);
        arr[size] = x;
        size++;
    }

}; // class int_vec

int main() {
    int_vec v;
    cout << "    v.size(): " << v.get_size() << "\n";
    cout << "v.capacity(): " << v.get_capacity() << "\n";
    for(int i = 0; i < 25; ++i) {
        v.append(i);
    }
    v.println();
    string temp = "a";
    if (temp == "a") std :: cout << "equal";
}