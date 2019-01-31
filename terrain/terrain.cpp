#include "terrain.h"

//
// Error Typdefs
//

NULL_TEXTURE::NULL_TEXTURE(const char* obj_type) {
  this->obj_type = new char[strlen(obj_type) + 1];
  strcpy(this->obj_type, obj_type);
}

NULL_TEXTURE::~NULL_TEXTURE() {
  delete [] obj_type;
}

void NULL_TEXTURE::what() {
  cerr << "[ERROR]: No textures were found for the " << obj_type << " object!" << endl;
}

//
// TerrainTile implementation
//

TerrainTile::TerrainTile() : texture_found(false) {}
TerrainTile::~TerrainTile() {}

char TerrainTile::texture() {
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
  return 2;
}

Water::~Water() {}

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
  return 1;
}

Plains::~Plains() {}
