#include "npc.h"

int main()
{
    int x = 10;
    int y = 10;
    char * name = new char[strlen("Generic") + 1];
    strcpy(name, "Generic");
    int gold = 1000;

    // x, y, name, money, energy
    creature Generic(x, y, name, gold);
    //Generic.display();

    pos test_pos(7, 7);
    //Generic.print_pos();
    //Generic.set_pos(test_pos);
    //Generic.print_pos();

    // testing sailor (an NPC)
    char * sailor_name = new char[strlen("Salt Beard") + 1];
    strcpy(sailor_name, "Salt Beard");
    sailor SaltBeard(25, 25, sailor_name, 5000);
    SaltBeard.interact();
    cout << endl << endl;

    // testing wizard (an NPC)
    char * wizard_name = new char[strlen("Sandolf") + 1];
    strcpy(wizard_name, "Sandolf");
    wizard Sandolf(25, 25, wizard_name, 5000);
    Sandolf.interact();
    cout << endl << endl;

    // testing miner (an NPC)
    char * miner_name = new char[strlen("Shinin' Jimmy") + 1];
    strcpy(miner_name, "Shinin' Jimmy");
    miner ShiningJimmy(25, 25, miner_name, 5000);
    ShiningJimmy.interact();
    cout << endl << endl;

    SaltBeard.display();
    Sandolf.display();
    ShiningJimmy.display();

    delete [] name;
    delete [] sailor_name;
    delete [] wizard_name;
    delete [] miner_name;

    return 0;
}
