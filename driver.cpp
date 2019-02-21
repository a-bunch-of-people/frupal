#include "driver.h"

/*
  file: where main will live for now
  program: Ctrl + F5 or Debug > Start Without Debugging menu
  program: F5 or Debug > Start Debugging menu
*/

void drawBorder();

void drawBorder() {
    clear();
    box(stdscr, '*', '*');
}

const int size(const char* s1, const char* s2) {
  return (strlen(s1) + strlen(s2));
}

int main(const int argc, const char* argv[]) {
  // Game Init stuff
  bool  running = true;

  TextureMap CHARACTER_TEXTURES;
  TextureMap TERRAIN_TEXTURES;

  load_textures(CHARACTER_TEXTURES, "textures/character.texture");
  load_textures(TERRAIN_TEXTURES, "textures/terrain.texture");

  cout << "Loading texture files in order:" << endl;
  CHARACTER_TEXTURES.display();
  TERRAIN_TEXTURES.display();
  Board board(30);
  Character player(1, 1, "Bob Kerman", 69, 100);
  // Water t1(TERRAIN_TEXTURES);
  // Plains t2(TERRAIN_TEXTURES);

  // Screen init stuff
  cout << "Initializing screen..." << endl;
  initscr();
  cbreak();
  noecho();
  curs_set(FALSE);
  nodelay(stdscr,TRUE);
  keypad(stdscr,TRUE);

  char* msg = new char[MAX_STREAM_SIZE];
  cout << "Enter something: ";
  cin >> msg;

  const int msg_len = strlen(msg);
  int width = 0;
  int height = 0;
  int x = 10;
  int x_dir = 1;
  int y = 10;
  int y_dir = 1;

  cout << "Entering main loop!" << endl;
  while(running) {
    getmaxyx(stdscr, height, width);
    if(x >= (width - msg_len) || x < 0)
      x_dir *= -1;
    if(y >= height || y < 0)
      y_dir *= -1;

    x += x_dir;
    y += y_dir;

    clear();
    mvprintw(y, x, msg);
    // drawBorder();
    // board.showBoard();
    refresh();
    sleep(THREAD_HALT_TIME);
  }

  endwin();

  return 0;
}
