#ifndef FRUPAL_CHARACTER_H
#define FRUPAL_CHARACTER_H

#include <iostream>
#include <cstring>
#include "../utilities/utilities.h"

using namespace std;
using namespace frupal_utils;

struct Event {
  const int type;
};

struct Position {
    int x;
    int y;

    Position(const int, const int);
};

// Base class for ANY Character in the game
// Initialized by user input for each stat
class Character {
  protected:             // lower left = (1,1)Character
      Position position;    // struct with int x, y
                            // returned by getpos()
      char * name;          // Character's name
      int gold;             // Character's $$
      int energy;           // Character's energy for moving

    public:
        Character();       // default constructor
        Character(const int start_x, const int start_y, const char * start_name, const int start_gold, const int start_energy);
        ~Character();

        void display();

        const Position * get_position();
        const bool check_bounds();
        const int move(Event);  // Up/Down, Left/Right
};

class merchant: public Character
{
    public:

    protected:

    private:
};

class sailor: public Character
{
    public:

    protected:

    private:
};

#endif