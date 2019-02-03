#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../terrain/terrain.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Check loaded water textures with good file") {
  TextureMap TEXTURES;
  load_textures(TEXTURES);
  Water* tile = new Water(TEXTURES);
  CHECK(tile->texture() == '~');
}

TEST_CASE("Check loaded plains textures with good file") {
  TextureMap TEXTURES;
  load_textures(TEXTURES);
  Plains* tile = new Plains(TEXTURES);
  CHECK(tile->texture() == '_');
}

TEST_CASE("Check non-loaded water textures with bad file") {
  TextureMap TEXTURES;
  load_textures(TEXTURES, "textures/bad_terrain.texture");
  CHECK_THROWS_AS(new Water(TEXTURES), NULL_TEXTURE);
}

TEST_CASE("Check non-loaded plains textures with bad file") {
  TextureMap TEXTURES;
  load_textures(TEXTURES, "textures/bad_terrain.texture");
  CHECK_THROWS_AS(new Plains(TEXTURES), NULL_TEXTURE);
}

TEST_CASE("Check water is not passable") {
  TextureMap TEXTURES;
  load_textures(TEXTURES);
  Water* tile = new Water(TEXTURES);
  CHECK(tile->is_passable() == false);
}

TEST_CASE("Check plains is passable") {
  TextureMap TEXTURES;
  load_textures(TEXTURES);
  Plains* tile = new Plains(TEXTURES);
  CHECK(tile->is_passable() == true);
}

TEST_CASE("Check water takes 2 energy to not move across") {
  TextureMap TEXTURES;
  load_textures(TEXTURES);
  Water* tile = new Water(TEXTURES);
  CHECK(tile->get_move_energy() == 2);
}

TEST_CASE("Check plains takes 1 energy to move across") {
  TextureMap TEXTURES;
  load_textures(TEXTURES);
  Plains* tile = new Plains(TEXTURES);
  CHECK(tile->get_move_energy() == 1);
}
