#include "terrain.h"

//
// TerrainTile implementation
//

TextureMap TerrainTile::texture_dictionary("textures/terrain.texture");

TerrainTile::TerrainTile() : texture_found(false){}
TerrainTile::~TerrainTile(){}

const char TerrainTile::texture(){
  if(texture_found)
    return key_texture;
  else
      throw NULL_TEXTURE("generic terrain tile");
}

ostream& operator<< (ostream& buffer, const TerrainTile& source){
  buffer << "{ texture: " << source.key_texture << ", texture found: " << source.texture_found << ", textures: " << source.texture_dictionary << " }";
  return buffer;
}

//
// PassableTile implementation
//

PassableTile::PassableTile(){}
PassableTile::~PassableTile(){}

const bool PassableTile::is_passable(){
  return true;
}

//
// UnpassableTile implementation
//

UnpassableTile::UnpassableTile(){}
UnpassableTile::~UnpassableTile(){}

const bool UnpassableTile::is_passable(){
  return false;
}

//
// Water implementation
//

Water::Water(){
  for(int i = 0; i < texture_dictionary.size; ++i){
    if(strcmp(texture_dictionary.texture_name[i], "Water") == 0){
      key_texture = texture_dictionary.texture_list[i];
      texture_found = true;
    }
  }

  if(!texture_found)
    throw NULL_TEXTURE("water");
}

const int Water::get_move_energy(){
  return 1;
}

Water::~Water(){}

//
// Rocks implementation
//

Rocks::Rocks(){
  for(int i = 0; i < texture_dictionary.size; ++i){
    if(strcmp(texture_dictionary.texture_name[i], "Rock") == 0){
      key_texture = texture_dictionary.texture_list[i];
      texture_found = true;
    }
  }

  if(!texture_found)
    throw NULL_TEXTURE("Rock");
}

const int Rocks::get_move_energy(){
  return 4;
}

Rocks::~Rocks(){}

//
// Tree implementation
//

Tree::Tree(){
  for(int i = 0; i < texture_dictionary.size; ++i){
    if(strcmp(texture_dictionary.texture_name[i], "Tree") == 0){
      key_texture = texture_dictionary.texture_list[i];
      texture_found = true;
    }
  }

  if(!texture_found)
    throw NULL_TEXTURE("Tree");
}

const int Tree::get_move_energy(){
  return 4;
}

Tree::~Tree(){}

//
// Gem implementation
//

Gem::Gem(){
  for(int i = 0; i < texture_dictionary.size; ++i){
    if(strcmp(texture_dictionary.texture_name[i], "Gem") == 0){
      key_texture = texture_dictionary.texture_list[i];
      texture_found = true;
    }
  }

  if(!texture_found)
    throw NULL_TEXTURE("Gem");
}

const int Gem::get_move_energy(){
  return 0;
}

Gem::~Gem(){}

//
// Plains implementation
//

Plains::Plains(){
  for(int i = 0; i < texture_dictionary.size; ++i){
    if(strcmp(texture_dictionary.texture_name[i], "Plains") == 0){
      key_texture = texture_dictionary.texture_list[i];
      texture_found = true;
    }
  }

  if(!texture_found)
    throw NULL_TEXTURE("Plains");
}

const int Plains::get_move_energy(){
  return 2;
}

Plains::~Plains(){}
