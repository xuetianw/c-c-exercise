//
// Created by fred on 08/03/19.
//


#include <stdexcept>
using namespace std;

#include <iostream>
#include <vector>
#include "cmpt_error.h"

void error(const string& message)
{
    throw std::runtime_error(message);
    cout << "This line is never executed!\n";
}
void error_test1() {
    cout << "About to call error ...\n";
    error("testing 1, 2 ,3");
    cout << "... error called!\n";
}


void error_test2() {
    int* arr = new int[10];

    error("testing 1, 2 ,3");

    delete[] arr;  // oops: memory leak!
}

void error_test3() {
    int* arr = new int[10];

    try {
        error("testing 1, 2 ,3");
        delete[] arr;  // not called if there is an exception thrown above
    } catch (std::runtime_error e) {
        cout << "Caught a runtime exception thrown by error: "
             << e.what() << "\n";
        delete[] arr;  // clean up memory
    }
    cout << "error_test3 finished\n";
}

void error_test4() {
    int* arr = new int[10];

    try {
        error("testing 1, 2 ,3");
    } catch (std::runtime_error e) {
        cout << "Caught a runtime exception thrown by error: "
             << e.what() << "\n";
    }

    delete[] arr;  // clean up memory
}



void error_test5() {
    int* arr = new int[10];

    try {
        error("testing 1, 2 ,3");
    } catch (...) {  // ... catches all exceptions
        cout << "Caught some exception thrown by error\n";
    }

    delete[] arr;  // clean up memory
}


void error_test6() {
    int* arr = new int[10];

    try {
        error("testing 1, 2 ,3");
    } catch (std::runtime_error e) {
        cout << "Caught a runtime exception thrown by error: "
             << e.what() << "\n";
    } catch (...) {
        cout << "Caught some exception thrown by error\n";
    }

    delete[] arr;  // clean up memory
}


void error_test7() {
    int* arr = nullptr;

    try {
        arr = new int[10];
        error("testing 1, 2 ,3");
    } catch (std::runtime_error e) {
        cout << "Caught a runtime exception thrown by error: "
             << e.what() << "\n";
    } catch (std::bad_alloc e) {
        cout << "bad allocation: " << e.what() << "\n";
    } catch (...) {
        cout << "Caught some other exception\n";
    }

    delete[] arr;  // clean up memory
}

void error_test8() {
    // v has a private pointer to an underlying array on the free store
    std::vector<int> v = {1, 2, 3, 4, 5};

    try {
        error("testing 1, 2 ,3");
    } catch (...) {
        cout << "Caught some exception\n";
    }
    // uh oh: what about the underlying array belonging to v?
}

void error_test9() {
    try {
        vector<int> v = {1, 2, 3, 4, 5};
        error("testing 1, 2 ,3");
    } catch (...) {
        cout << "Caught some exception\n";
    }
    // v's destructor is guaranteed to be called
}

// Takes a string of the form "a + b", where a and b are ints, and returns
// their sum.
int eval(const string& s) {
    // find the position of the '+'
    int plus_loc = s.find('+');
    if (plus_loc == string::npos) cmpt::error("eval: + not found");

    // get a and b as their own strings
    string a = s.substr(0, plus_loc);
    string b = s.substr(plus_loc + 1, s.size() - plus_loc);

    // convert a and b to ints using the standard function stoi (string to
    // int)
    int result = stoi(a) + stoi(b);

    return result;
}

//void print_safe(const string& s) {
//    try {
//        int result = add(s);
//        cout << "result = " << result << "\n\n";
//    } catch (std::invalid_argument e) {
//        cout << "error: one, or both, of the operands of \"" << s << "\"\n"
//             << "       is not a valid int\n\n";
//    } catch (std::out_of_range e) {
//        cout << "error: one, or both, of the operands of \"" << s << "\"\n"
//             << "       are outside the range of an int\n\n";
//    } catch (...) {
//        cout << "error: an unknown error has occurred\n\n";
//    }
//}
//
//void test_safe() {
//    print_safe(" 11  +33");
//    print_safe(" two + 3");
//    print_safe(" 2 + 39043090300473");
//}


class Test {
    string name;
public:
    Test(const string& s)
            : name(s)
    {
        cout << "Test(): " << name << " constructed ...\n";
    }

    ~Test() {
        cout << "... ~Test(): destructor for " << name << " called\n";
    }
};

void c() {
    cout << "c() called ...\n";
    Test c1{"c1"};
    cmpt::error("aaahhhhhh!!!");
    Test c2{"c2"};
    cout << "... c() ended normally\n";
}

void b() {
    cout << "b() called ...\n";
    Test b1{"b1"};
    c();
    Test b2{"b2"};
    cout << "... b() ended normally\n";
}

void a() {
    cout << "a() called ...\n";
    Test a1{"a1"};
    b();
    Test a2{"a2"};
    cout << "... a() ended normally\n";
}

int main() {
    try {
        a();
    } catch (...) {
        cout << "caught an exception!\n";
    }
}



//
//int main() {
////    error_test1();
////    error_test2();
////    error_test3();
////    error_test4();
////    error_test5();
////    error_test6();
////    error_test7();
////    error_test8();
////    error_test9();
////    cout << eval("2 + 3");          // 5
////    cout << eval("25+-3");          // 22
////    cout << eval(" 8   +  10   ");  // 18
//}