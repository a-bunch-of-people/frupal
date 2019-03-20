#include "player.h"

//
// Player Implementation
//

Player::Player(const Position& position, const int gold, const int energy) : Character(position, gold, energy), texture_found(0), gems_found(0){
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

const int Player::add_gem(){ return ++gems_found; }

const bool Player::carrying_max_gems() { return (gems_found == frupal_utils::MAX_GEMS); }

const bool Player::left(){
  try{
    key_texture = texture_left;
    move(position - Position(1,0), Position(0,0), Position(100,100));
    return true;
  }
  catch(...){
    return false;
  }
}

const bool Player::down(){
  try{
    key_texture = texture_down;
    move(position + Position(0,1), Position(0,0), Position(100,100));
    return true;
  }
  catch(...){
    return false;
  }
}

const bool Player::right(){
  try{
    key_texture = texture_right;
    move(position + Position(1,0), Position(0,0), Position(100,100));
    return true;
  }
  catch(...){
    return false;
  }
}

const bool Player::up(){
  try{
    key_texture = texture_up;
    move(position - Position(0,1), Position(0,0), Position(100,100));
    return true;
  }
  catch(...){
    exit(1);
    return false;
  }
}
