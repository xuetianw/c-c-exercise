//
// Created by fred on 05/04/19.
//

#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <zconf.h>

using namespace std;
// foreground colors
const string red         = "\033[0;31m";
const string green       = "\033[1;32m";
const string yellow      = "\033[1;33m";
const string cyan        = "\033[0;36m";
const string magenta     = "\033[0;35m";
const string reset_color = "\033[0m";
const string White       = "\033[0;37m";
const string Black       = "\033[0;30m";
bool playing;

void test() {
    cout << "This is "
         << red            // set text color to red
         << "red"
         << reset_color    // reset text color
         << ", and this is "
         << yellow         // set text color to yellow
         << "yellow"
         << reset_color    // reset text color
         << ".\n";
}

class Board {
private:
    int length = 8;
    int width = 8;

    void setupBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j ++) {
                gameBoard[i][j] = ' ';
            }
        }


        gameBoard [3][3] = 'W';
        gameBoard [3][4] = 'B';
        gameBoard [4][3] = 'B';
        gameBoard [4][4] = 'W';
    }

public:
    char gameBoard[8][8]{};

    Board()
    {
        setupBoard();
    }

    void display() {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                char ch = gameBoard[i][j];
                if( ch == 'W') {
                    cout << White << "@";
                } else if (ch  == 'B'){
                    cout << Black << "@";
                } else {
                    cout << yellow << "&";
                }
            }
            cout << endl;
        }
        cout << "-------------------------------------\n" << endl;
    }
    void resetGameBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j ++) {
                gameBoard[i][j] = ' ';
            }
        }

        gameBoard [3][3] = 'W';
        gameBoard [3][4] = 'B';
        gameBoard [4][3] = 'B';
        gameBoard [4][4] = 'W';
    }

};


class Player {
private:
    int score = 0;
public:
    void process() {

    }
};

class Human_player: public Player {
private:
    int score = 0;
public:
    void setScore(int score) {
        Human_player::score = score;
    }

public:
    int getScore() const {
        return score;
    }

public:
    bool play(int r, int c , Board &board) {
        char ch = board.gameBoard[r] [c];
        if (ch == 'W' || ch == 'B') {
            cout << "this spot has been played" << endl;
            return false;
        } else {
             if (!add_points(r, c, board)) {
                 cout << "please choose another location to play" <<endl;
                 return false;
             } else{
                 cout << "succeed" <<endl;
                 return true;
             }
        }
    }
    bool add_points(int r, int c, Board& board) {
        auto &gBoard =  board.gameBoard;
        bool result = false;
        if (r == 0 && c == 0) {
            if (gBoard[0][1] == 'W') {
                gBoard[0][1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[1][0] == 'W') {
                gBoard[1][0] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[1][1] == 'W') {
                gBoard[1][1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
            return result;
        } else if(r == 0 && c == 7){
            if( gBoard[0][6] == 'W') {
                gBoard[0][6] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[1][6] == 'W') {
                gBoard[1][6] = 'B';
                score ++;
                result = true;
            } else if (gBoard[1][7] == 'W') {
                score++;
                gBoard[1][7] = 'B';
                result = true;
                gBoard[r][c] = 'B';
            }
        } else if (r == 7 && c == 0) {
            if (gBoard[7][1] == 'W') {
                gBoard[7][1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[6][0] == 'W') {
                gBoard[6][0] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[6][1] == 'W') {
                gBoard[6][1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
        } else if(r == 7 && c == 7){
            if( gBoard[7][6] == 'W') {
                gBoard[7][6] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[6][7] == 'W') {
                gBoard[6][7] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[6][6] == 'W') {
                score++;
                gBoard[6][6] = 'B';
                result = true;
                gBoard[r][c] = 'B';
            }
            return result;
        } else if(r == 0){
            if( gBoard[1][c-1] == 'W'){
                gBoard[1][c-1] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[1][c] == 'W') {
                gBoard[1][c] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[1][c+1] == 'W') {
                gBoard[1][c+1] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            }
            return result;
        } else if(r == 7){
            if( gBoard[6][c-1] == 'W'){
                gBoard[6][c-1] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[6][c] == 'W') {
                gBoard[6][c] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[6][c+1] == 'W') {
                gBoard[6][c+1] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            }
            return result;
        } else if (c == 0) {
            if (gBoard[r][1] == 'W') {
                gBoard[r][1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[r-1][1] == 'W') {
                gBoard[r-1][1] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[r+1][1] == 'W') {
                gBoard[r+1][1] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            }
            return result;
        } else if (c == 7) {
            if (gBoard[r][6] == 'W') {
                gBoard[r][6] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[r-1][6] == 'W') {
                gBoard[r-1][6] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            } else if (gBoard[r+1][1] == 'W') {
                gBoard[r+1][6] = 'B';
                score++;
                result = true;
                gBoard[r][c] = 'B';
            }
            return result;
        } else {
            if (gBoard[r-1][c-1] == 'W') {
                gBoard[r-1][c-1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
            if (gBoard[r+1][c+1] == 'W') {
                gBoard[r+1][c+1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
            if (gBoard[r-1][c+1] == 'W') {
                gBoard[r-1][c+1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
            if (gBoard[r+1][c-1] == 'W') {
                gBoard[r+1][c-1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
            if (gBoard[r-1][c] == 'W') {
                gBoard[r-1][c] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
            if (gBoard[r+1][c] == 'W') {
                gBoard[r+1][c] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
            if (gBoard[r][c-1] == 'W') {
                gBoard[r][c-1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
            if (gBoard[r][c+1] == 'W') {
                gBoard[r][c+1] = 'B';
                score ++;
                result = true;
                gBoard[r][c] = 'B';
            }
            return result;
        }
        return result;
    }
};

class Computer_player: public Player {
private:
    int score = 0;
public:
    int getScore() const {
        return score;
    }

    void setScore(int score) {
        Computer_player::score = score;
    }

public:
    void play(Board &board) {
        int c;
        int r;

        c = rand() % 8;
        r = rand() % 8;
        char ch = board.gameBoard[r] [c];
        while ((ch == 'W' || ch == 'B')) {
            srand (time(NULL));
            c = rand() % 8;
            r = rand() % 8;
            ch = board.gameBoard[r] [c];
        }

        add_points(r, c , board);
    }

    bool add_points(int r, int c, Board& board) {
        auto &gBoard =  board.gameBoard;
        bool result = false;
        gBoard[r][c] = 'W';
        if (r == 0 && c == 0) {
            if (gBoard[0][1] == 'B') {
                gBoard[0][1] = 'W';
                score ++;
                result = true;
            } else if (gBoard[1][0] == 'B') {
                gBoard[1][0] = 'W';
                score ++;
                result = true;
            } else if (gBoard[1][1] == 'B') {
                gBoard[1][1] = 'W';
                score ++;
                result = true;
            }
            return result;
        } else if(r == 0 && c == 7){
            if( gBoard[0][6] == 'B') {
                gBoard[0][6] = 'W';
                score++;
                result = true;
            } else if (gBoard[1][6] == 'B') {
                gBoard[1][6] = 'W';
                score ++;
                result = true;
            } else if (gBoard[1][7] == 'W') {
                score++;
                gBoard[1][7] = 'B';
                result = true;
            }
        }  else if (r == 7 && c == 0) {
            if (gBoard[7][1] == 'B') {
                gBoard[7][1] = 'W';
                score ++;
                result = true;
            } else if (gBoard[6][0] == 'B') {
                gBoard[6][0] = 'W';
                score ++;
                result = true;
            } else if (gBoard[6][1] == 'B') {
                gBoard[6][1] = 'W';
                score ++;
                result = true;
            }
        } else if(r == 7 && c == 7){
            if( gBoard[7][6] == 'B') {
                gBoard[7][6] = 'W';
                score++;
                result = true;
            } else if (gBoard[6][7] == 'B') {
                gBoard[6][7] = 'W';
                score ++;
                result = true;
            } else if (gBoard[6][6] == 'B') {
                score++;
                gBoard[6][6] = 'W';
                result = true;
            }
            return result;
        } else if(r == 0){
            if( gBoard[1][c-1] == 'B'){
                gBoard[1][c-1] = 'W';
                score++;
                result = true;
            } else if (gBoard[1][c] == 'B') {
                gBoard[1][c] = 'W';
                score++;
                result = true;
            } else if (gBoard[1][c+1] == 'B') {
                gBoard[1][c+1] = 'W';
                score++;
                result = true;
            }
            return result;
        } else if(r == 7){
            if( gBoard[6][c-1] == 'B'){
                gBoard[6][c-1] = 'W';
                score++;
                result = true;
            } else if (gBoard[6][c] == 'B') {
                gBoard[6][c] = 'W';
                score++;
                result = true;
            } else if (gBoard[6][c+1] == 'B') {
                gBoard[6][c+1] = 'W';
                score++;
                result = true;
            }
            return result;
        } else if (c == 0) {
            if (gBoard[r][1] == 'B') {
                gBoard[r][1] = 'W';
                score ++;
                result = true;
            } else if (gBoard[r-1][1] == 'B') {
                gBoard[r-1][1] = 'W';
                score++;
                result = true;
            } else if (gBoard[r+1][1] == 'B') {
                gBoard[r+1][1] = 'W';
                score++;
                result = true;
            }
            return result;
        } else if (c == 7) {
            if (gBoard[r][6] == 'B') {
                gBoard[r][6] = 'W';
                score ++;
                result = true;
            } else if (gBoard[r-1][6] == 'B') {
                gBoard[r-1][6] = 'W';
                score++;
                result = true;
            } else if (gBoard[r+1][1] == 'B') {
                gBoard[r+1][6] = 'W';
                score++;
                result = true;
            }
            return result;
        } else {
            if (gBoard[r-1][c-1] == 'B') {
                gBoard[r-1][c-1] = 'W';
                score ++;
                result = true;
            }
            if (gBoard[r+1][c+1] == 'B') {
                gBoard[r+1][c+1] = 'W';
                score ++;
                result = true;
            }
            if (gBoard[r-1][c+1] == 'B') {
                gBoard[r-1][c+1] = 'W';
                score ++;
                result = true;
            }
            if (gBoard[r+1][c-1] == 'B') {
                gBoard[r+1][c-1] = 'W';
                score ++;
                result = true;
            }
            if (gBoard[r-1][c] == 'B') {
                gBoard[r-1][c] = 'W';
                score ++;
                result = true;
            }
            if (gBoard[r+1][c] == 'B') {
                gBoard[r+1][c] = 'W';
                score ++;
                result = true;
            }
            if (gBoard[r][c-1] == 'B') {
                gBoard[r][c-1] = 'W';
                score ++;
                result = true;
            }
            if (gBoard[r][c+1] == 'B') {
                gBoard[r][c+1] = 'W';
                score ++;
                result = true;
            }
            return result;
        }
        return result;
    }

};

bool check_space(Board board);

int main() {
//    test();

    cout << "Welcome to the Reversi game:\n";
    cout << "We assuem that player plays color black:\n";



    Board board;
    board.display();



    string inputString;
    playing = true;

    Human_player human_player;
    Computer_player computer_player;

    while (playing) {
        cout << "Please enter the location that you want to play:\n";
        cin >> inputString;

        if (inputString.length() < 2) {
            cout << "please enter both row and colum" << endl;
            continue;
        }

        int row;
        try {
            row  = std::stoi(inputString.substr(0, 1));
        } catch (exception &e) {
            cout << "please enter a number\n" << endl;
            continue;
        }
        if (row < 0 || row > 7) {
            cout << "your row number is out of range\n" << endl;
            continue;
        }
        char column_char = inputString.at(1);
        if (column_char < 'a' || column_char > 'h') {
            cout << "colum is out of range, please enter a to h\n";
            continue;
        }
        int colum;
        switch(column_char) {
            case 'a':  colum = 0; break;
            case 'b':  colum = 1; break;
            case 'c':  colum = 2;  break;
            case 'd':  colum = 3; break;
            case 'e':  colum = 4; break;
            case 'f':  colum = 5; break;
            case 'g':  colum = 6; break;
            case 'h':  colum = 7; break;
            default:break;
        }
        cout<< "your input is: \nrow :" << to_string(row)
        << "\ncolum :" << colum <<endl;


        while (!human_player.play(row, colum, board)) {
            cin >> inputString;

            if (inputString.length() < 2) {
                cout << "please enter both row and colum" << endl;
                continue;
            }
            try {
                row  = std::stoi(inputString.substr(0, 1));
            } catch (exception &e) {
                cout << "please enter a number\n" << endl;
                continue;
            }
            if (row < 0 || row > 7) {
                cout << "your row number is out of range\n" << endl;
                continue;
            }
            char column_char = inputString.at(1);
            if (column_char < 'a' || column_char > 'h') {
                cout << "colum is out of range, please enter a to h\n";
                continue;
            }

            switch(column_char) {
                case 'a':  colum = 0; break;
                case 'b':  colum = 1; break;
                case 'c':  colum = 2;  break;
                case 'd':  colum = 3; break;
                case 'e':  colum = 4; break;
                case 'f':  colum = 5; break;
                case 'g':  colum = 6; break;
                case 'h':  colum = 7; break;
                default:break;
            }
        }




        cout << "after human played: \n " << endl;
        board.display();


        if (!check_space (board)) {
            cout << "game is finished \n" << endl;
            if (computer_player.getScore() > human_player.getScore()) {
                cout << "computer_player win with score" << computer_player.getScore()
                     << "you lost with the score" << human_player.getScore();
            } else {
                cout << "you  win with score" << human_player.getScore()
                     << "computer_player lost with the score" << computer_player.getScore();
            }

            cout << "would you like to play again? y/n";
            cin >> inputString;
            if (inputString.at(0) == 'y') {
                human_player.setScore(0);
                computer_player.setScore(0);
                board.resetGameBoard();
                continue;
            } else{
                playing = false;
                break;
            }
        }


        cout << "after computer played: \n " << endl;
        computer_player.play(board);
        sleep(1);
        board.display();
        cout << "human score :" << human_player.getScore() << " computer score :" << computer_player.getScore();


        if (!check_space (board)) {
            cout << "game is finished \n" << endl;
            if (computer_player.getScore() > human_player.getScore()) {
                cout << "computer_player win with score" << computer_player.getScore()
                     << "you lost with the score" << human_player.getScore();
            } else {
                cout << "you  win with score" << human_player.getScore()
                     << "computer_player lost with the score" << computer_player.getScore();
            }

            cout << "would you like to play again? y/n";
            cin >> inputString;
            if (inputString.at(0) == 'y') {
                human_player.setScore(0);
                computer_player.setScore(0);
                board.resetGameBoard();
                continue;
            } else{
                playing = false;
                break;
            }
        }

    }


}

bool check_space(Board board) {
    auto &gBoard =  board.gameBoard;
    for (int i = 0 ; i < 8; i++) {
        for (int j = 0 ; j < 8; j++){
            if ((gBoard[i][j] == ' ')) {
                return true;
            }
        }

    }
    return false;
}
