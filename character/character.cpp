#include "character.h"

//
// Position implementation
//

Position::Position(const int x, const int y): x(x), y(y) {}

//
// Character Implementation
//

Character::Character(): position(1,1), name(NULL), gold(0), energy(0) {}

Character::Character(const int x, const int y, const char * start_name, const int gold, const int energy): position(x,y), gold(gold), energy(energy) {
  if(name)
    delete [] name;

  name = new char[strlen(start_name) + 1];
  strcpy(name, start_name);
  strcat(name, "\0");
}

Character::~Character() {
    if(name)
        delete [] name;
}

void Character::display() {
    cout << endl << "Name: " << name << endl;
    cout << "Location: (" << position.x << ", " << position.y << ")" << endl;
    cout << "Gold: " << gold << endl;
    cout << "Current energy: " << energy << endl << endl;
}

void display_map()
{
    cout << "Displaying map..." << endl;
}

const Position * Character::getpos() {
  return &position;
}

const bool Character::check_bounds()
{
    return false;
}

const int Character::move(/* string */)
{
    return 0;
}
