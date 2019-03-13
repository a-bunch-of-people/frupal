#include "character.h"

//
//
//

//
// Position implementation
//

Position::Position(const int x, const int y): x(x), y(y) {}

//
// Character Implementation
//

Character::Character(): position(1,1), name(NULL), gold(0), energy(0), key_texture('X') {}

Character::Character(const int x, const int y, const char * start_name, const int gold, const int energy): position(x,y), gold(gold), energy(energy), key_texture('X') {
  // if(name)
  //   delete [] name;
  //
  // name = new char[strlen(start_name) + 1];
  // strcpy(name, start_name);
  // strcat(name, "\0");
}

Character::~Character() {
    if(name)
        delete [] name;
}

void Character::display() {
    mvprintw(position.y, position.x, "X");
    // mvprintw(51,1, concatenate({"Name: ", name}));
    // mvprintw(51,2, concatenate({"Location: (", position.x, ", ", position.y, ")"}));
    // mvprintw(51,3, concatenate({"Gold: ", gold}));
    // mvprintw(51,4, concatenate({"Current energy: ", energy}));

    // delete [] var;
}

const Position * Character::get_position() {
  return &position;
}

const bool Character::check_bounds()
{
    return false;
}

void Character::move(const int x, const int y) {
  position.x = x;
  position.y = y;
}
