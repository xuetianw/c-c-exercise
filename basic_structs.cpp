//
// Created by fred on 24/01/19.
//

// basic_structs.cpp

//
// This demonstrates some basic structs, and how they can be used for
// modeling real-world objects.
//


#include <iostream>
#include "cmpt_error.h"

using namespace std;

struct Date {
    int day;   // 0 to 31
    int month; // 0 to 11
    int year;  // e.g. 2017
};

void print(const Date& d) {
    cout << "(" << d.day
         << ", " << d.month
         << ", " << d.year
         << ")";
}

void println(const Date& d) {
    print(d);
    cout << "\n";
}

//
// An alternative to writing a print and println function is to use the
// operator<<.
//
ostream& operator<<(ostream& out, const Date& d) {
    out << "("  << d.day       // note use of out, not cout!
        << ", " << d.month
        << ", " << d.year
        << ")";
    return out;
}

void test_date() {
    Date d{1, 11, 2000}; // November 1, 2000
    cout << "d = " << d << "\n";
    d.day = 14;
    cout << "d = " << d << "\n";
    d.year = -343; // nothing to stop nonsensical data!
    cout << "d = " << d << "\n";
}

// Same as test_date(), but using dynamic memory instead.
void test_date_ptr() {
    Date* d = new Date{1, 11, 2000}; // November 1, 2000
    cout << "*d = " << *d << "\n";
    d->day = 14;
    cout << "*d = " << *d << "\n";
    d->year = -343; // nothing to stop nonsensical data!
    cout << "*d = " << *d << "\n";

    delete d;  // always remember to de-allocate dynamic memory
}

//////////////////////////////////////////////////////////////////////////////////////

// A struct representing a web page. Note that it contains some Date values.
struct Webpage {
    string title;
    string url;
    string author;
    Date created;
    Date last_modified;
}; // struct Webpage


void print(const Webpage& p) {
    cout << "        Title: " << p.title << "\n"
         << "          URL: " << p.url << "\n"
         << "       Author: " << p.author << "\n"
         << "      Created: ";
    println(p.created);       // note unusual indentation of this statement
    cout << "Last modified: ";
    println(p.last_modified);
}

void println(const Webpage& p) {
    print(p);
    cout << "\n";
}

//
// Again, a nicer alternative to print and println is to use operator<<.
//
ostream& operator<<(ostream& out, const Webpage& p) {
    out << "        Title: " << p.title << "\n"
        << "          URL: " << p.url << "\n"
        << "       Author: " << p.author << "\n"
        << "      Created: " << p.created << "\n"
        << "Last modified: " << p.last_modified << "\n";
    return out;
}

// If you want a function to modify a struct that you've passed to it, you
// must pass it by reference, i.e. use a & as below.
void set_title(Webpage& p, const string& new_title) {
    p.title = new_title;
}

void test_webpage() {
    Webpage page{"My Awesome Home Page",
                 "http://www.example.com",
                 "I. Newton",
                 Date{1, 11, 2000},
                 Date{29, 12, 2016}
    };
    cout << "\n\n" << page << "\n";
    set_title(page, "My Great Home Page");
    cout << page << "\n";
}

// Same as test_webpage(), but using dynamic memory instead.
void test_webpage_ptr() {
    Webpage* page = new Webpage{"My Awesome Home Page",
                                "http://www.example.com",
                                "I. Newton",
                                Date{1, 11, 2000},
                                Date{29, 12, 2016}
    };
    cout << "\n\n" << *page << "\n";
    set_title(*page, "My Great Home Page");
    cout << *page << "\n";

    delete page;  // always remember to de-allocate dynamic memory
}

int main() {
//    test_date();
//    test_date_ptr();
//    test_webpage();
    test_webpage_ptr();
}