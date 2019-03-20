#ifndef FRUPAL_CHARACTER_H
#define FRUPAL_CHARACTER_H

#include <iostream>
#include <cstring>
#include <ncurses.h>
#include "../utilities/utilities.h"

using namespace std;
using namespace frupal_utils;

const char* concatenate(const char**);

// Base class for ANY Character in the game
// Initialized by user input for each stat
class Character{
  protected:
    static TextureMap texture_dictionary;
    Position position;
    int gold;
    int energy;

    char key_texture;

  public:
    Character();
    Character(const Position&, const int, const int);
    ~Character();

    void show_character();
    void hide_character();
    Position& get_position();
    void move(const Position, const Position, const Position);  // Up+Down, Left+Right
    friend std::ostream& operator << (std::ostream &, const Character &);
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
