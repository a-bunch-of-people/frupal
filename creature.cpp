#include "creature.h"

// param constructor for struct pos
pos::pos(int the_x, int the_y): x(the_x), y(the_y) { }

// default constructor for creature
creature::creature(): x(0), y(0), position(0, 0), name(NULL), gold(0) { }

// param constructor for creature
creature::creature(int start_x, int start_y, char * start_name, int start_gold): x(start_x), y(start_y), position(start_x, start_y), gold(start_gold)
{
    name = new char[strlen(start_name) + 1];
    strcpy(name, start_name);
}

// copy constructor
creature::creature(const creature & obj): x(obj.x), y(obj.y), position(obj.x, obj.y), gold(obj.gold)
{
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);
}

creature::~creature()
{
    if(name) {
        delete [] name;
    }
}

pos creature::get_pos()
{
  return position;
}

void creature::set_pos(const pos &to_set)
{
    x = to_set.x;
    y = to_set.y;
}

void creature::print_pos()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

void creature::display()
{
    cout << endl << "Name: " << name << endl;
    cout << "Location: (" << x << ", " << y << ")" << endl;
    cout << "Gold: " << gold << endl;
}











