#include "driver.h"
#include "game_menu.h"
#include <sstream>

int main(const int argc, char** argv){
  using namespace frupal_utils;
  using namespace std;

  //Game config parameters
  menu object;
  int board_size = 0;
  string * result = object.gameConfig();
  stringstream value(result[0]);
  Player player(Position(10,10), 3, 100);
  value >> board_size;
  Board board(board_size);
  char input;
  delete [] result;

  // Screen init stuff
  initscr();
  cbreak();
  noecho();
  curs_set(FALSE);
  nodelay(stdscr,TRUE);
  keypad(stdscr,TRUE);

  int width = 0;
  int height = 0;

  while(true){
    //
    // Input controller
    //
    cin >> input;
    switch (input) {
      case 'a':
        if(board.is_passable(player.get_position() - Position(1,0)))
          player.hide_character();
          player.left();
        break;
      case 's':
        if(board.is_passable(player.get_position() + Position(0,1)))
          player.hide_character();
          player.down();
        break;
      case 'd':
        if(board.is_passable(player.get_position() + Position(1,0)))
          player.hide_character();
          player.right();
        break;
      case 'w':
        if(board.is_passable(player.get_position() - Position(0,1)))
          player.hide_character();
          player.up();
        break;
      default:
        break;
    }

    player.show_character();
    refresh();
    sleep(1);
  }

  endwin();
}
