//
// Created by fred on 22/03/19.
//

#include <iostream>
#include "cmpt_error.h"
#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

// An enum class creates a new data type with a finite set of values. The ":
// char" means that wall, dirt, and water are implemented as characters, which
// is convenient here since we are displaying the maze in pure text.
enum class Tile : char {
    wall='m', dirt=' ', water='.'
};

// returns a random number r such that 0.0 <= r < 1.0
double rand01() {
    return rand() / (RAND_MAX + 1.0);
}


class Maze {
    // a maze is a 2-dimensional vector of Tiles
    vector<vector<Tile>> maze;

    // this struct is needed by the iterative flood method below
    struct Location {
        int row;
        int col;
    };

public:
    Maze(int w, int h) // constructor
            : maze(h)
    {
        assert(w > 1 && h > 1);

        // initialize all tiles to dirt
        for(int i = 0; i < maze.size(); ++i) {
            maze[i] = vector<Tile>(w, Tile::dirt);
        }

        // add a ring of walls around the entire maze
        for(int i = 0; i < w; ++i) maze[0][i] = Tile::wall;   // top row
        for(int i = 0; i < w; ++i) maze[h-1][i] = Tile::wall; // bottom row
        for(int i = 0; i < h; ++i) maze[i][0] = Tile::wall;   // left column
        for(int i = 0; i < h; ++i) maze[i][w-1] = Tile::wall; // right column

        // randomly set some more wall locations
        const double prob_of_wall = 0.33;
        for(int i = 1; i < h - 1; ++i) {
            for(int j = 1; j < w - 1; ++j) {
                if (rand01() < prob_of_wall) {
                    maze[i][j] = Tile::wall;
                }
            }
        }
    } // Maze(int w, int h)

    // get the width and height of the maze
    int width() const { return maze[0].size(); }
    int height() const { return maze.size(); }

    // tests if maze[row][col] is a valid location
    bool in_maze(int row, int col) const {
        return (0 <= row && row < height())
               && (0 <= col && col < width());
    }

    // set the location at row r, column c to be tile t
    void set(int r, int c, const Tile& t) {
        assert(in_maze(r, c));
        maze[r][c] = t;
    }

    // return the value at row r, column c
    Tile get(int r, int c) const {
        assert(in_maze(r, c));
        return maze[r][c];
    }

    // print the maze to the screen
    void print() const {
        for(int i = 0; i < height(); ++i) {
            for(int j = 0; j < width(); ++j) {
                cout << char(maze[i][j]) << " ";  // char(maze[i][j]) converts
            }                                     // maze[i][j] (which is of type Tile)
            cout << "\n";                         // to its underlying char
        }
    }

    void println() const {
        print();
        cout << "\n";
    }

    // Sets all locations reachable from maze[start_row][start_col] to water.
    // A location is reachable if you can get to it without hitting a wall,
    // and going one step at a time in either the north, south, east, or west
    // direction (diagonal steps are not allowed).
    //
    // Uses a vector of Locations to keep track of which locations have not
    // yet been visited. This is a purely iterative function, i.e. it only
    // uses loops. It does not recursion anywhere.
    void flood(int start_row, int start_col) {
        vector<Location> choices = { Location{start_row, start_col} };

        while (!choices.empty()) {
            // remove a Location from choices
            Location loc = choices.back();
            choices.pop_back();
            int r = loc.row;
            int c = loc.col;

            // check if maze[r][c] exists and is dirt
            if (in_maze(r, c) && maze[r][c] == Tile::dirt) {
                maze[r][c] = Tile::water;
                // add 4 neighbors
                choices.push_back(Location{r-1, c});
                choices.push_back(Location{r+1, c});
                choices.push_back(Location{r, c-1});
                choices.push_back(Location{r, c+1});
            }
        }
    }

    // Sets all locations reachable from maze[r][c] to water. Uses recursion
    // instead of an explicit loop. Notice that the Location class is not
    // needed because the row and column values are stored in the calls to
    // flood_recursive.
    void flood_recursive(int r, int c) {
        if (in_maze(r, c) && maze[r][c] == Tile::dirt) {
            maze[r][c] = Tile::water;
            flood_recursive(r-1, c);
            flood_recursive(r+1, c);
            flood_recursive(r, c-1);
            flood_recursive(r, c+1);
        }
    }
}; // class Maze


void test_flood() {
    Maze maze(30, 18);
    maze.set(1, 1, Tile::dirt); // ensure starting point is dirt
    maze.flood(1, 1);
    maze.println();
}

void test_flood_recursive() {
    Maze maze(30, 18);
    maze.set(1, 1, Tile::dirt); // ensure starting point is dirt
    maze.flood_recursive(1, 1);
    maze.println();
}

int main() {
    srand(time(NULL));
    // test_flood();
    test_flood_recursive();
}