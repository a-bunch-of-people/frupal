#ifndef FRUPAL_TERRAIN_H
#define FRUPAL_TERRAIN_H

#include <iostream>
#include <fstream>

using namespace std;

class TerrainTile {
    protected:
        char key_texture;

        // Define the display key to use at the individual tile level
        const char get_tile_texture();

    public:
        // Constructors/Destructors
        TerrainTile();
        virtual ~TerrainTile();

        virtual const bool is_passable();
        virtual const int get_move_energy();
};

class PassableTile: public TerrainTile {
    public:
        // Constructors/Destructors
        PassableTile();
        virtual ~PassableTile();

        // General functions
        const bool is_passable();
};

class UnpassableTile: public TerrainTile {
    public:
        // Constructors/Destructors
        UnpassableTile();
        virtual ~UnpassableTIle();

        // General functions
        const bool is_passable();
        const int get_move_energy();
};

class Water: public UnpassableTile {
    public:
        // Constructors/Destructors
        Water();
};

class Plains: public PassableTile {
    public:
        // Constructors/Destructors
        Plains();

        // General function stuff
        const int get_move_energy();
};

#endif
