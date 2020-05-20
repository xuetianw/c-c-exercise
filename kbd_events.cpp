//
// Created by fred on 11/02/19.
//

#include <string>

namespace event {
    // kbd_events.cpp

    // Returns true iff s is a whitespace character, or a two-char code
    // for a whitespace character.
    bool is_whitespace(const std::string& s) {
        return c == " " || c == "\n" || c == "\t" || c == "\r"
               || c == "\\n" || c == "\\t" || c == "\\r";
    }
} // namespace event
