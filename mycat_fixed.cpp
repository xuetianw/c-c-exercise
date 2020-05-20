//
// Created by fred on 16/01/19.
//

// mycat_fixed.cpp

//////////////////////////////////////////////////////////////////////////////////////////
//
// This is a simple version of the standard Linux command "cat", that is used
// for displaying the contents of files at the command-line.
//
// You can use cat like this:
//
//    $ cat makefile
//   CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g
//
// cat has a few options, such as:
//
// - -E puts a $ character at the end of each line
//
// - -n numbers the lines
//
// - -T shows tab characters as ^I
//
// The version of cat we create here won't any flags as iput, but will have
// all of these options turned on by default.
//
// Note that for printing line numbers the C function printf is used. This is
// for simplicity, since it is easier to create a right-justified number using
// printf than using cout. You can certainly do it with cout, but it is more
// complicated and requires more code.
//
// printf requires C-style strings as input, and so when want to use C++-style
// strings (i.e. from #include stirng>) we call the s.c_str().
//
//////////////////////////////////////////////////////////////////////////////////////////

#include "cmpt_error.h"
#include <iostream>     // cout
#include <fstream>      // ifstream
#include <cstdio>       // printf
#include <string>
#include <stdlib.h>


using namespace std;

//
// useful constants
//
const bool DEBUG_ON = false;

const string TAB_PRINT = "^I";
const string NEWLINE_PRINT = "$";
const string NUM_FORMAT = "%6d\t"; // right-justified in a 6 char wide field
// ending with a tab character (\t)

//
// We're reading arguments from the command-line, and so we use this
// old-fashioned C-style way of dealing with strings and arrays.
//
//   argc: the argument count
//
//   argv: an array of C-style strings contain all the arguments;
//         the first argument is the program name
int main(int argc, char *argv[]) {
    if (DEBUG_ON) {
        // print all arguments
        cout << argc << " arguments:\n";
        for(int i = 0; i < argc; i++) {
            cout << "   arg[" << i << "] = \"" << argv[i] << "\"\n";
        }
    }

    //
    // make sure a file argument has been provided
    //
    // first argument to mycat will be the file we want to display
//    if (argc < 2) {
//        cout << "Error: not enough arguments\n";
//        exit(-1);  // -1 could be used by programs that call this program as an
//    }              // error code

    //
    // try opening the file
    //
    ifstream infile(argv[1]);  // not argv[0] (which is the name of the program)
    if (infile.fail()) {
        cout << "Error: unable to open file " << argv[1] << "\n";
        exit(-1);
    }

    //
    // read the input file one character at a time
    //
    int line_num = 0;
    char c;
    infile.get(c);

    // if the file is empty then we're done`
    if (infile.eof()) return 0;

    // first line of the file is handled as a special case
    line_num++;
    printf(NUM_FORMAT.c_str(), line_num);
    cout << c;
    infile.get(c);

    while (!infile.eof()) {
        switch (c) {
            case '\n': // newline character
                cout << NEWLINE_PRINT << "\n";
                if (infile.peek() != EOF) { // peek returns next character without consuming it
                    line_num++;
                    printf(NUM_FORMAT.c_str(), line_num);
                }
                break;
            case '\t': // tab character
                cout << TAB_PRINT;
                break;
            default:
                cout << c;
        } // switch
        infile.get(c);
    } // while

} // main