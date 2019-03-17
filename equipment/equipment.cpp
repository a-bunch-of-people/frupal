#include "equipment.h"

/*Equipment -- Base class */

//Constructors & Desctructor
equipment::equipment(): name(NULL), durability(0), damage(0){}

equipment::equipment(const equipment& copy)
{
  *this = copy;
}

equipment::~equipment()
{
  if (name)
    delete [] name;
  name = NULL;
}


//public functions
int equipment::fill_equipment(void)
{
  if (name)   //Assuming this is filled if it has a name
    return 0; //Error: Can't overwrite an equip w/ user input.

  char* temp = new char[MAX_STRSIZE];

  cout << "Please enter the equipment's name: ";
  cin >> temp;
  name = new char[strlen(temp)+1];
  strcpy(name, temp);

  cout << "Please enter its durability: ";
  cin >> durability;
  if (durability < 0 || durability > MAX_DURBL)
    return 0; //Error: Bound check.

  cout << "Please enter its damage: ";
  cin >> damage; //I think I'll leave negative damage for the lols

  return 1;
}

void equipment::get_name(char* new_name)
{
  if (name)
    delete[] name; //the arg fillers can overwrite

  name = new char[strlen(new_name)+1];
  strcpy(name, new_name);
}

void equipment::get_durbl(int new_durbl)
{
  if (new_durbl >= 0 && new_durbl <= MAX_DURBL)
    durability = new_durbl;
}

void equipment::get_dmg(int new_dmg){damage = new_dmg;}

//Send object info to standard out (for testing purposes mostly)
void equipment::report(void)
{
  if (!name)
    return;

  cout << endl << name << endl << "Durability: " << durability <<
    endl << "Damage: " << damage << endl << endl;
}


//Operators for equipment class
equipment& equipment::operator=(const equipment& copy)
{
  if (this == &copy)
    return *this; //self-assignment check.

  if (name)
    delete [] name;
  name = new char[strlen(copy.name)+1];
  strcpy(name, copy.name);

  durability = copy.durability;
  damage = copy.damage;

  return *this;
}
