#include "terrain.h"

//
// TerrainTile implementation
//

TerrainTile::TerrainTile() : texture_found(false) {}
TerrainTile::~TerrainTile() {}

const char TerrainTile::texture() {
  if(texture_found)
    return key_texture;
  else
      throw NULL_TEXTURE("generic terrain tile");
}

//
// PassableTile implementation
//

PassableTile::PassableTile() {}
PassableTile::~PassableTile() {}

const bool PassableTile::is_passable() {
  return true;
}

//
// UnpassableTile implementation
//

UnpassableTile::UnpassableTile() {}
UnpassableTile::~UnpassableTile() {}

const bool UnpassableTile::is_passable() {
  return false;
}

//
// Water implementation
//

Water::Water(const TextureMap &textures) {
  for(int i = 0; i < textures.size; ++i) {
    if(strcmp(textures.tile_types[i], "Water") == 0) {
      key_texture = textures.textures[i];
      texture_found = true;
    }
  }

  if(!texture_found)
    throw NULL_TEXTURE("water");
}

const int Water::get_move_energy() {
  return 1;
}

Water::~Water() {}

//
// Rocks implementation
//

Rocks::Rocks(const TextureMap &textures) {
  for(int i = 0; i < textures.size; ++i) {
    if(strcmp(textures.tile_types[i], "Rock") == 0) {
      key_texture = textures.textures[i];
      texture_found = true;
    }
  }

  if(!texture_found)
    throw NULL_TEXTURE("Rock");
}

const int Rocks::get_move_energy() {
  return 4;
}

Rocks::~Rocks() {}

//
// Tree implementation
//

Tree::Tree(const TextureMap &textures) {
  for(int i = 0; i < textures.size; ++i) {
    if(strcmp(textures.tile_types[i], "Tree") == 0) {
      key_texture = textures.textures[i];
      texture_found = true;
    }
  }

  if(!texture_found)
    throw NULL_TEXTURE("Tree");
}

const int Tree::get_move_energy() {
  return 4;
}

Tree::~Tree() {}

//
// Plains implementation
//

Plains::Plains(const TextureMap &textures) {
  for(int i = 0; i < textures.size; ++i) {
    if(strcmp(textures.tile_types[i], "Plains") == 0) {
      key_texture = textures.textures[i];
      texture_found = true;
    }
  }

  if(!texture_found)
    throw NULL_TEXTURE("plains");
}

const int Plains::get_move_energy() {
  return 2;
}

Plains::~Plains() {}
