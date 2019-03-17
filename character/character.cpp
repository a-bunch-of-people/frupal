#include "character.h"

//
// Character Implementation
//

Character::Character(): position(Position()), gold(0), energy(0), key_texture(texture_dictionary.texture_list[texture_dictionary.size - 1]){}

Character::Character(const Position& position, const int gold, const int energy): position(position), gold(gold), energy(energy), key_texture(texture_dictionary.texture_list[texture_dictionary.size - 1]){}

TextureMap Character::texture_dictionary("textures/characters.texture");

Character::~Character(){}

void Character::show_character(){
  mvaddch(position.y, position.x, key_texture);
}

void Character::hide_character(){
  mvdelch(position.y, position.x);
}

Position& Character::get_position(){ return position; }

void Character::move(const Position new_pos, const Position top_left, const Position lower_right){
  if(new_pos.x >= top_left.x && new_pos.x < lower_right.x){ position.x = new_pos.x; }
  if(new_pos.y >= top_left.y && new_pos.y < lower_right.y){ position.y = new_pos.y; }
}

std::ostream& operator<< (ostream& buffer, const Character& source){
  buffer << "{ position: " << source.position << ", gold: " << source.gold << ", engergy: " << source.energy << ", active texture: " << source.key_texture << ", textures: " << Character::texture_dictionary << " }";
  return buffer;
}
