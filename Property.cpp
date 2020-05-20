//
// Created by fred on 22/03/19.
//

#include <string>
#include <iostream>

const std::string possible_chars = "abcdefghijklmnopqrstuvwxyz0123456789~!@#$%^*()_+";

char rand_char() {
    int r = rand() % possible_chars.size();
    return possible_chars[r];
}

// returns random string of characters; 50% chance a character is a space
// (since spaces are important when testing trim)
std::string rand_string(int max_len = 10) {
    int size = rand() % (max_len + 1);
    std::string result(size, ' ');
    for(int i = 0; i < size; i++) {
        if (rand() % 2 == 0) {
            result[i] = rand_char();
        }
    }
    return result;
}

// returns a new string that is the character-by-character reverse of s
std::string reverse(std::string s) {
    reverse(begin(s), end(s));
    return s;
}

void trim_property_test() {
    srand (time(NULL));
    const int num_tests = 100;
    for(int i = 0; i < num_tests; i++) {
        std::string s = rand_string();
        std::cout << "s = \"" << s << "\"\n";
        assert(trim_bug1(trim_bug1(s)) == trim_bug1(s));
        assert(trim_bug1(reverse(s)) == reverse(trim_bug1(s)));
    }
    std::cout << num_tests << " random tests passed\n";
}