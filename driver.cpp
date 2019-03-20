#include "driver.h"


const int MAP_WIDTH = 100;
const int MAP_HEIGHT = 50;
const int GEMS_COUNT = 6;

void clear_line(const Position& position){ // For the record, this is a stupid way to do this and I know this
  mvprintw(position.y, position.x, "                                  ");
}

void screen_log(const char* string, const Position& position){
  clear_line(position);
  mvprintw(position.y, position.x, string);
}

void screen_log(const char* string, const int value, const Position& position){
  char* destination = new char[99];
  strcpy(destination, string);
  strcat(destination, to_string(value).c_str());
  clear_line(position);
  mvprintw(position.y, position.x, destination);
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
  clear_line(position);
  mvprintw(position.y, position.x, destination);
  delete [] destination;
}

void centered_screen_log(const char* string){
  int x_pos = MAP_WIDTH / 2 - strlen(string) / 2;
  int y_pos = MAP_HEIGHT / 2;

  screen_log(string, Position(x_pos, y_pos));
}

int main(const int argc, char** argv){
  using namespace frupal_utils;

  Board board(MAP_WIDTH, MAP_HEIGHT, GEMS_COUNT);
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
  init_pair(3, COLOR_YELLOW, COLOR_WHITE); // Announcement Colors

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
    attron(COLOR_PAIR(1));
    board.update_visited(player.get_view_radius(), player.get_position());
    board.show_visited();
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    player.show_character();
    attroff(COLOR_PAIR(2));

    // Info and HUD
    int offset = 10;
    screen_log("Player Position: ", player.get_position(), Position(0, height - (offset--)));
    screen_log("Player Energy: ", player.get_energy(), Position(0, height - (offset--)));
    screen_log("Input Key: ", input, Position(0, height - (offset--)));

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
          player.left(board.get_move_energy(player.get_position() - Position(1,0)));
          board.update_visited(player.get_view_radius(), player.get_position());
        }
        break;
      case 's':
        if(board.is_passable(player.get_position() + Position(0,1))){
          player.down(board.get_move_energy(player.get_position() + Position(0,1)));
          board.update_visited(player.get_view_radius(), player.get_position());
        }
        break;
      case 'd':
        if(board.is_passable(player.get_position() + Position(1,0))){
          player.right(board.get_move_energy(player.get_position() + Position(1,0)));
          board.update_visited(player.get_view_radius(), player.get_position());
        }
        break;
      case 'w':
        if(board.is_passable(player.get_position() - Position(0,1))){
          player.up(board.get_move_energy(player.get_position() - Position(0,1)));
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

    if(player.get_energy() <= 0){
      running = false;
      attron(COLOR_PAIR(1));
      const char* str = "You  died of dysentery! (lack of energy)";
      screen_log(str, Position(width / 2 - strlen(str), height / 2));
      attroff(COLOR_PAIR(1));
      refresh();
      sleep(5000);
    }

    if(player.carrying_max_gems()){
      running = false;
      attron(COLOR_PAIR(1));
      const char* str = "You collected all the gems, you win!";
      screen_log(str, Position(width / 2 - strlen(str), height / 2));
      attroff(COLOR_PAIR(1));
      refresh();
      sleep(5000);
    }
  }

  endwin();
}
