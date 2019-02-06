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
    int x;
    int y;
};

// Base class for ANY creature in the game
// Initialized by user input for each stat
class creature
{
    public:
        creature();       // default constructor
        creature(int start_x, int start_y, char * start_name,
                 int start_gold, int start_energy);
        ~creature();
        void display();
        pos * getpos();
        int check_bounds();
        int move(/* string lib */);  // Up/Down, Left/Right
        void display_map();

    protected:

    private:
                           // lower left = (1,1)
        int x;             // x-coordinate in 2D map
        int y;             // y-coordinate in 2D map
        pos * position;    // struct with int x, y
                           // returned by getpos()
        char * name;       // creature's name
        int gold;          // creature's $$
        int energy;        // energy is used for moves
};

class merchant: public creature
{
    public:

    protected:

    private:
};

class sailor: public creature
{
    public:

    protected:

    private:
};







