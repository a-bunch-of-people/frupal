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

void Player::left(Board & board) {
  Position new_pos(position.x - 1, position.y);
  key_texture = texture_left;

  if(board.isPassable(new_pos.x, new_pos.y))
    move(new_pos, Position(1, 1), Position(50, 50));
}

void Player::down(Board & board) {
  Position new_pos(position.x, position.y + 1);
  key_texture = texture_down;

  if(board.isPassable(new_pos.x, new_pos.y))
    move(new_pos, Position(1, 1), Position(50, 50));
}

void Player::right(Board & board) {
  Position new_pos(position.x + 1, position.y);
  key_texture = texture_right;

  if(board.isPassable(new_pos.x, new_pos.y))
    move(new_pos, Position(1, 1), Position(50, 50));
}

void Player::up(Board & board) {
  Position new_pos(position.x, position.y - 1);
  key_texture = texture_up;

  if(board.isPassable(new_pos.x, new_pos.y))
    move(new_pos, Position(1, 1), Position(50, 50));
}
