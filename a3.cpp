//
// Created by fred on 08/03/19.
//


#include "cmpt_error.h"    // These are the only permitted includes!
#include "Chatbot.h"       //
#include <iostream>        // Don't include anything else.
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <cassert>



using namespace std;

//
// ... write your code here here ...
//



void converse(Chatbot* a, Chatbot* b, int max_turns = 50) {
    for(int turn = 1; turn <= max_turns; turn++) {
        string a_msg = a->get_reply();
        cout << "(" << turn << ") " << a->name() << ": " << a_msg << "\n";

        turn++;
        if (turn > max_turns) return;

        b->tell(a_msg);
        string b_msg = b->get_reply();

        cout << "(" << turn << ") " << b->name() << ": " << b_msg << "\n";
        a->tell(b_msg);
    } // for
}


class Mirror_bot: public ::Chatbot {
private:
    string botName;
//    vector<string> stringWithNoPreviousReply;
    string receiveMessage;
    string stringWithNoPreviousReply;
public:
    Mirror_bot(string name, string str2) {
        this->botName = name;
        this->stringWithNoPreviousReply = str2;
    }

    string name() const override {
        return this->botName;
    }

    void tell(const string &s) override {
        receiveMessage = s;
    }

    string get_reply() override {
        if(receiveMessage.empty()) {
            return stringWithNoPreviousReply;
        } else {
            return receiveMessage;
        }
    }

    virtual ~Mirror_bot() override {

    }
};

class Random_bot : public :: Chatbot {
private:
    string botName;
    vector<string> inputString;
public:
    Random_bot(string name, vector<string> inputString) {
        if (inputString.size() == 0) {
            cmpt::error("wrong size");
        }
        this->botName = name;
        this->inputString = inputString;
    }

    string name() const override {
        return this->botName;
    }

    void tell(const string &s) override {
        cout << s <<endl;
    }

    string get_reply() override {
        int index = rand() % inputString.size();
        return inputString[index];
    }

    virtual ~Random_bot() override {

    }
};

class User_bot : public :: Chatbot {
private:
    string inputString;
    string str2;
public:
    User_bot(string str2) {
        this->str2 = str2;
    }

    string name() const override {
//        return this->botName;
        return "";
    }

    void tell(const string &s) override {
        cout<<s<<endl;
    }

    string get_reply() override {
       string inputString;

        cout << "Please enter your name: ";
        cin >> inputString;
        cout<<inputString;
        return inputString;
    }

    virtual ~User_bot() override {

    }
};


class Datetime_bot : public :: Chatbot {
private:
    string str1;
    vector<string> inputString;
public:
    Datetime_bot(string str1, vector<string> inputString) {
        this->str1 = str1;
        this->inputString = inputString;
    }
    string name() const override {
        return std::__cxx11::string();
    }

    void tell(const string &s) override {
        cout << s <<endl;
    }

    string get_reply() override {
        string lasStr = inputString[inputString.size()-1];
        transform(lasStr.begin(), lasStr.end(), lasStr.begin(), ::tolower);
        if (lasStr.find("date") != std::string::npos || (lasStr.find("time") != std::string::npos) ||
        (lasStr.find("Time") != std::string::npos)  || (lasStr.find("date") != std::string::npos )) {
            time_t now = time(0);

            // convert now to string form
            char* dt = ctime(&now);
            return string(dt);
        } else {
            int index = rand() % inputString.size();
            return inputString[index];
        }
    }

    ~Datetime_bot() override {

    }
};

class Smart_bot : public :: Chatbot {

    //game bot
private:
    string str1;
    int score = 0;
    vector <string> questions=
            {
                    {"what is 100 + 222"},
                    {"how many legs do you have?"},
                    {"what course are you taking CMPT___?"}
            };
    vector <string> answers = {"322","2", "135"};

public:
    Smart_bot(string str1) {
        this->str1 = str1;
    }

    string name() const override {
//        return this->botName;
        return "";
    }

    void tell(const string &s) override {
        std::cout << s <<endl;
    }

    string get_reply() override {
        int a = static_cast<int>(rand() % questions.size());
        cout << questions[a] << endl;
        string inputString;

        cout << "Please enter your answer: ";
        cin >> inputString;
        cout<<inputString <<endl;
        if(inputString == answers[a]) {
            score++;
        }
        return ("you have " + to_string(score) + "scores \n");
    }

    virtual ~Smart_bot() override {

    }
};

int main() {
//    Mirror_bot *a = new Mirror_bot ("person1", "message1");
//    Mirror_bot *b = new Mirror_bot ("person2", "message2");
//    converse(a, b, 10);
//    Random_bot *cat = new Random_bot{"Mittens", {"meow", "prr", "meeeeow"}};
//    Random_bot *dog = new Random_bot{"Fido", {"woof", "ruff", "bow wow"}};
//    srand(time(NULL));
//    converse(cat, dog, 20);
//    User_bot *a = new User_bot{"person1"};
//    User_bot *b = new User_bot{"person2"};
//    converse(a, b, 10);

//    Datetime_bot * a = new Datetime_bot{"deetee", {"Ask me about the or!",
//                                                   "I know the DATE and!"}};
//    Datetime_bot * b = new Datetime_bot{"321", {"Ask me about the date or!",
//                                                        "I know the and!"}};

//    converse(a, b, 10);
    string lasStr = "time2";

    Smart_bot * a = new Smart_bot("Fred");
    Smart_bot * b = new Smart_bot("Fred");
    converse(a, b, 10);


    //
    // ... put code for testing your functions here ...
    //

}