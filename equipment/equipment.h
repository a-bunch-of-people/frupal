//Dev: Bradley Thompson

#include <iostream>

//This is the home for the equipment hierarchy.
//I'll have operators, copy constructors, blah blah,
//so that hopefully the equipment classes are really 
//easy to use.



/* Equipment class -- Base class */
class equipment
{
  public:
    equipment(); ~equipment();
    equipment(const equipment& copy);

  private:
    char* name;
    int durabilty;
    int damage;
};
