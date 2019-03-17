#ifndef FRUPAL_PLAYER_H
#define FRUPAL_PLAYER_H

#include "../character/character.h"
#include "../board/board.h"
#include "../utilities/utilities.h"

class Player: public Character{
  public:
    Player(const Position&, const int, const int);
    ~Player();

    const bool left();
    const bool down();
    const bool right();
    const bool up();

  protected:
    int texture_found;
    char texture_left;
    char texture_down;
    char texture_right;
    char texture_up;
};

#endif
