#ifndef FRUPAL_PLAYER_H
#define FRUPAL_PLAYER_H

#include "../character/character.h"
#include "../utilities/utilities.h"

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
