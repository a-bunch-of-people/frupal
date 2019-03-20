#include "driver.h"

int main(const int argc, char** argv){
  using namespace frupal_utils;

  Board board(200, 20);
  // Player player(board.find_open_tile(Position(0,0), Position(10,10)), 3, 100);

  board.show_all(true);
  board.show_mask(true);

  // char input;

  //
  // Screen init stuff
  //

  // initscr();
  // cbreak();
  // noecho();
  // curs_set(FALSE);
  // nodelay(stdscr,TRUE);
  // keypad(stdscr,TRUE);
  // start_color();
  // init_color(COLOR_RED, 2500, 0, 0);
  // init_pair(1, COLOR_BLUE, COLOR_BLACK); // Default Colors
  // init_pair(2, COLOR_WHITE, COLOR_RED); // Player Colors
  //
  // int width = 0;
  // int height = 0;
  //
  // while(true){
  //   //
  //   // Maintenece stuff
  //   //
  //   getmaxyx(stdscr, height, width);
  //
  //   //
  //   // Main draw routine
  //   //
  //   attron(COLOR_PAIR(1));
  //   board.show_visited();
  //   attron(COLOR_PAIR(2));
  //   player.show_character();
  //
  //   // Info and HUD
  //   mvprintw(height - 3, 0, to_string(width).c_str());
  //
  //   refresh();
  //
  //   //
  //   // Input controller
  //   //
  //   cin >> input;
  //   switch (input) {
  //     case 'a':
  //       if(board.is_passable(player.get_position() - Position(1,0))){
  //         player.left();
  //       }
  //       break;
  //     case 's':
  //       if(board.is_passable(player.get_position() + Position(0,1))){
  //         player.down();
  //       }
  //       break;
  //     case 'd':
  //       if(board.is_passable(player.get_position() + Position(1,0))){
  //         player.right();
  //       }
  //       break;
  //     case 'w':
  //       if(board.is_passable(player.get_position() - Position(0,1))){
  //         player.up();
  //       }
  //       break;
  //     default:
  //       break;
  //   }
  // }
  //
  // endwin();
}
