#include "creature.h"

creature::creature()
{
    x = 1;
    y = 1;

    /*
    position = new pos;
    position->x = x;
    position->y = y;
    */

    name = NULL;
    gold = 0;
    energy = 0;
}

creature::creature(int start_x, int start_y, char * start_name, int start_gold, int start_energy)
{
    x = start_x;
    y = start_y;
    /*
    if(position)
      delete position;
    position = new pos;
    position->x = start_x;
    position->y = start_y;

    // REFACTOR: use string library
    if(name)
      delete [] name;
    name = new char[strlen(start_name) + 1];
    strcpy(name, start_name);
    */

    // temp
    name = NULL;

    gold = start_gold;
    energy = start_energy;
}

creature::~creature()
{
    if(position)
        delete position;

    if(name)
        delete [] name;
}

void creature::display()
{
    cout << endl << "Name: " << name << endl;
    cout << "Location: (" << x << ", " << y << ")" << endl;
    cout << "Gold: " << gold << endl;
    cout << "Current energy: " << energy << endl << endl;
}

pos * creature::getpos()
{

}

int creature::check_bounds()
{
    return 0;
}

int creature::move(/* string */)
{
    return 0;
}

void display_map()
{
    cout << "Displaying map..." << endl;
}









