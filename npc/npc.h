//#ifndef CREATURE_H
//#define CREATURE_H

#include "../creature/creature.h"

#define STRMAX 30

// data from creature: int x, int y, pos position, char * name, int gold
class npc: public creature
{
    public:
        npc();
        npc(int start_x, int start_y, char * start_name, int start_gold);
        ~npc();
        virtual void interact() = 0;
        virtual void trade() = 0;     // display NPC's inventory of items, ask for input
                          // to purchase item(s)

    private:
};

class sailor: public npc
{
    public:
        sailor();
        sailor(int start_x, int start_y, char * start_name, int start_gold);
        ~sailor();
        void interact();
        void trade();

    private:
};


class wizard: public npc
{
    public:
        wizard();
        wizard(int start_x, int start_y, char * start_name, int start_gold);
        ~wizard();
        void interact();
        void trade();

    private:
};

class miner: public npc
{
    public:
        miner();
        miner(int start_x, int start_y, char * start_name, int start_gold);
        ~miner();
        void interact();
        void trade();

    private:
};

//#endif
