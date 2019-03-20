#ifndef FRUPAL_PLAYER_H
#define FRUPAL_PLAYER_H

#include "../character/character.h"
#include "../board/board.h"
#include "../utilities/utilities.h"

class Player: public Character{
  public:
    Player(const Position&, const int, const int);
    ~Player();


    const int get_view_radius();
    const int get_energy();
    const int add_gem();
    const bool carrying_max_gems();
    const bool left(const int);
    const bool down(const int);
    const bool right(const int);
    const bool up(const int);

  protected:
    int texture_found;
    int gems_found;
    int view_radius;
    char texture_left;
    char texture_down;
    char texture_right;
    char texture_up;
};

#endif
