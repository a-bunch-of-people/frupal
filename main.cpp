#include "creature.h"

int main()
{
    int x = 10;
    int y = 10;
    char * name = new char[strlen("Speenies") + 1];
    strcpy(name, "Speenies");
    int gold = 1000;

    // x, y, name, money, energy
    creature Speenies(x, y, name, gold);
    Speenies.display();

    pos test_pos(7, 7);
    Speenies.print_pos();
    Speenies.set_pos(test_pos);
    Speenies.print_pos();

    delete [] name;

    return 0;
}
