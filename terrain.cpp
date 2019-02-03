#include "terrain.h"


//
// TerrainTile implementation
//

TerrainTile::TerrainTile() {
    key_texture = get_tile_texture();
}

const char TerrainTile::get_tile_texture() {
    fstream file;
    file.open("terrain.textures");

    file.close();

    return 'a';
}

//
// PassableTile implementation
//

const bool PassableTile::is_passable() {
    return true;
}

//
// UnpassableTile implementation
//

const int UnpassableTile::get_move_energy() {
    return -1;
}

const bool UnpassableTile::is_passable() {
    return false;
}

//
// Water implementation
//

//
// Plains implementation
//

const int Plains::get_move_energy() {
    return 1;
}
