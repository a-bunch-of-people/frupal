#ifndef FRUPAL_PLAYER_H// Ryan M Jones
// CS300 with Jane Massey
// Date: 1/23/2019
// This file contains the base class for all Characters within
// the game (player, enemy, npc -- for now)
#define FRUPAL_PLAYER_H

#include "../character.h"
#include "../../utilities/utilities.h"

class Player: public Character {
  public:
    Player(const TextureMap&, const int, const int, const char*, const int, const int);
    ~Player();
    void left(Board &);
    void down(Board &);
    void right(Board &);
    void up(Board &);

  protected:
    int texture_found;
    char texture_left;
    char texture_down;
    char texture_right;
    char texture_up;
};

#endif
