#ifndef FRUPAL_EQUIPTMENT_H
#define FRUPAL_EQUIPTMENT_H

#include <iostream>
#include <cstring>

//This is the home for the equipment hierarchy.
//I'll have operators, copy constructors, blah blah,
//so that hopefully the equipment classes are really
//easy to use.

#define MAX_STRSIZE 50
#define MAX_DURBL 100

using namespace std;

/* Equipment class -- Base class */
class equipment
{
  public:
    equipment(); ~equipment();
    equipment(const equipment& copy);

    int fill_equipment(void);         //User input to fill an empty object.
    void get_name(char* new_name);  //arg data filling functions
    void get_durbl(int new_durbl);    //These will overwrite existing data.
    void get_dmg(int new_dmg);
    void report(void);                //Prints equip info to standard out

    //Operators
    equipment& operator=(const equipment& copy);

  private:
    char* name;
    int durability;
    int damage;
};

#endif
