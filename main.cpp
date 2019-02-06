#include "creature.h"

int main()
{
    int x = 10;
    int y = 10;
    char * name = new char[strlen("Speenies") + 1];
    strcpy(name, "Speenies");
    int gold = 1000;
    int energy = 50;

    // x, y, name, money, energy
    creature Speenies(x, y, name, gold, energy);
    Speenies.display();

    delete [] name;

    return 0;
}
