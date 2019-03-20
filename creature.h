// Ryan M Jones
// CS300 with Jane Massey
// Date: 1/23/2019
// This file contains the base class for all creatures within
// the game (player, enemy, npc -- for now)

#include <iostream>
#include <cstring>

using namespace std;

struct pos
{
    pos(int the_x, int the_y);
    int x;
    int y;
};

// forward declare struct item
#define INVENMAX 10
struct item { };

// Base class for ANY creature in the game
// Initialized by user input for each stat
class creature
{
    public:
        creature();         // default constructor
        creature(int start_x, int start_y, char * start_name, int start_gold);  // param constructor
        creature(const creature & obj); // copy constructor
        ~creature();        // destructor
        pos get_pos();      // returns "struct pos"
        void set_pos(const pos &to_set); // set pos to given pos
        void print_pos();   // display pos: (x, y)

        // char get_texture(): change what it returns based on last move
        // pos update_pos() tell the map

        int check_bounds(); // just check immediate tile, not FOV
        void display();            // for debugging

    protected:
        // REFACTOR: just position, not position plus x, y
        int x;              // x-coordinate in 2D map
        int y;              // y-coordinate in 2D map
        pos position;       // struct with int x, y. Returned by getpos();
        char * name;        // creature's name
        int gold;           // creature's $$
        // bool in_bounds;
        item inven[INVENMAX];

    private:
};
