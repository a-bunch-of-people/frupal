#include "player.h"

//
// Player Implementation
//

Player::Player(const Position& position, const int gold, const int energy) : Character(position, gold, energy), texture_found(0){
  for(int i = 0; i < texture_dictionary.size; i++){
    if(strcmp(texture_dictionary.texture_name[i], "PlayerLeft") == 0){
      texture_left = texture_dictionary.texture_list[i];
      texture_found++;
    }
    else if(strcmp(texture_dictionary.texture_name[i], "PlayerDown") == 0){
      texture_down = texture_dictionary.texture_list[i];
      texture_found++;
    }
    else if(strcmp(texture_dictionary.texture_name[i], "PlayerRight") == 0){
      texture_right = texture_dictionary.texture_list[i];
      texture_found++;
    }
    else if(strcmp(texture_dictionary.texture_name[i], "PlayerUp") == 0){
      texture_up = texture_dictionary.texture_list[i];
      texture_found++;
    }
  }

  if(texture_found < 4)
    throw NULL_TEXTURE("Player");

  key_texture = texture_right;
}

Player::~Player(){}

const bool Player::left(){
  key_texture = texture_left;
  move(position - Position(1,0), Position(0,0), Position(100,100));
}

const bool Player::down(){
  key_texture = texture_down;
  move(position + Position(0,1), Position(0,0), Position(100,100));
}

const bool Player::right(){
  key_texture = texture_right;
  move(position + Position(1,0), Position(0,0), Position(100,100));
}

const bool Player::up(){
  key_texture = texture_up;
  move(position - Position(0,1), Position(0,0), Position(100,100));
}
