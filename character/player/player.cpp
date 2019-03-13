#include "player.h"

//
// Player Implementation
//

Player::Player(const TextureMap& textures, const int x, const int y, const char* name, const int gold, const int energy) : Character(x, y, name, gold, energy), texture_found(0){
  for(int i = 0; i < textures.size; ++i) {
    if(strcmp(textures.tile_types[i], "PlayerLeft") == 0) {
      texture_left = textures.textures[i];
      texture_found++;
    }
    else if(strcmp(textures.tile_types[i], "PlayerDown") == 0){
      texture_down = textures.textures[i];
      texture_found++;
    }
    else if(strcmp(textures.tile_types[i], "PlayerRight") == 0){
      texture_right = textures.textures[i];
      texture_found++;
    }
    else if(strcmp(textures.tile_types[i], "PlayerUp") == 0){
      texture_up = textures.textures[i];
      texture_found++;
    }
  }

  if(texture_found < 4)
    throw NULL_TEXTURE("Player");

  key_texture = texture_up;
}

Player::~Player() {}

void Player::left() { key_texture = texture_left; move(position.x - 1, position.y); }
void Player::down() { key_texture = texture_down; move(position.x, position.y + 1); }
void Player::right() { key_texture = texture_right; move(position.x + 1, position.y); }
void Player::up() { key_texture = texture_up; move(position.x, position.y - 1); }
