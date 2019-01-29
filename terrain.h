#ifndef FRUPAL_TERRAIN_H
#define FRUPAL_TERRAIN_H

#include <iostream>

using namespace std;

class TerrainTile {
    private:
            char key_texture;

    public:
            const bool is_passable;
            virtual int getMoveTime();
};

class PassableTile < TerrainTile {

}
#endif
