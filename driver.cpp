#include "driver.h"

void screen_log(const char* string, const int value, const Position& position){
  char* destination = new char[99];
  strcpy(destination, string);
  strcat(destination, to_string(value).c_str());
  mvprintw(position.x, position.y, destination);
  delete [] destination;
}

void screen_log(const char* string, const Position& value, const Position& position){
  char* destination = new char[99];
  strcpy(destination, string);
  strcat(destination, "(");
  strcat(destination, to_string(value.x).c_str());
  strcat(destination, ", ");
  strcat(destination, to_string(value.y).c_str());
  strcat(destination, ")");
  mvprintw(position.x, position.y, destination);
  delete [] destination;
}

int main(const int argc, char** argv){
  using namespace frupal_utils;

  Board board(50, 25, 3);
  Player player(board.find_open_tile(Position(10,10), Position(20,20)), 3, 100);
  char input;
  bool running = true;

  //
  // Screen init stuff
  //

  initscr();
  cbreak();
  noecho();
  curs_set(FALSE);
  nodelay(stdscr,TRUE);
  keypad(stdscr,TRUE);
  start_color();
  init_color(COLOR_RED, 2500, 0, 0);
  init_pair(1, COLOR_GREEN, COLOR_BLACK); // Default Colors
  init_pair(2, COLOR_WHITE, COLOR_RED); // Player Colors

  int width = 0;
  int height = 0;

  while(running){
    //
    // Maintenece stuff
    //
    getmaxyx(stdscr, height, width);

    //
    // Main draw routine
    //
    // attron(COLOR_PAIR(1));
    board.update_visited(player.get_view_radius(), player.get_position());
    board.show_visited();
    attron(COLOR_PAIR(2));
    player.show_character();

    // Info and HUD
    screen_log("Player Position: ", player.get_position(), Position(height - 3, width - 40));
    screen_log("Input Key: ", input, Position(height - 2, width - 40));

    //
    // Draw loaded buffer
    //
    refresh();

    //
    // Input controller
    //
    cin >> input;
    switch (input) {
      case 'a':
        if(board.is_passable(player.get_position() - Position(1,0))){
          player.left();
          board.update_visited(player.get_view_radius(), player.get_position());
        }
        break;
      case 's':
        if(board.is_passable(player.get_position() + Position(0,1))){
          player.down();
          board.update_visited(player.get_view_radius(), player.get_position());
        }
        break;
      case 'd':
        if(board.is_passable(player.get_position() + Position(1,0))){
          player.right();
          board.update_visited(player.get_view_radius(), player.get_position());
        }
        break;
      case 'w':
        if(board.is_passable(player.get_position() - Position(0,1))){
          player.up();
          board.update_visited(player.get_view_radius(), player.get_position());
        }
        break;
      case 'q':
        running = false;
        break;
      case 'g':
        screen_log("Gems Found: ", player.add_gem(), Position(height - 5, 0));
        break;
      default:
        break;
    }

    if(board.is_gem(player.get_position())){
      screen_log("Gems Found: ", player.add_gem(), Position(height - 5, 0));
      board.remove_gem(player.get_position());
    }

    if(player.carrying_max_gems())
      running = false;
  }

  endwin();
}
