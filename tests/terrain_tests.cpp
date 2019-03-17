#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../terrain/terrain.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Check water is not passable"){
  Water* tile = new Water();
  CHECK(tile->is_passable() == false);
}

TEST_CASE("Check plains is passable"){
  Plains* tile = new Plains();
  CHECK(tile->is_passable() == true);
}

TEST_CASE("Check Water takes 1 energy to not move across"){
  Water* tile = new Water();
  CHECK(tile->get_move_energy() == 1);
}

TEST_CASE("Check Rocks takes 4 energy to not move across"){
  Rocks* tile = new Rocks();
  CHECK(tile->get_move_energy() == 4);
}

TEST_CASE("Check Tree takes 4 energy to not move across"){
  Tree* tile = new Tree();
  CHECK(tile->get_move_energy() == 4);
}

TEST_CASE("Check Plains takes 2 energy to move across"){
  Plains* tile = new Plains();
  CHECK(tile->get_move_energy() == 2);
}
