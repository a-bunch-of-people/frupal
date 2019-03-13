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
  Board board(50);

  TextureMap CHARACTER_TEXTURES;
  TextureMap TERRAIN_TEXTURES;

  load_textures(CHARACTER_TEXTURES, "textures/character.texture");

  cout << "Loading texture files in order:" << endl;
  CHARACTER_TEXTURES.display();
  Player player(CHARACTER_TEXTURES, 5, 5, "Bob Kerman", 69, 100);

  // Screen init stuff
  cout << "Initializing screen..." << endl;
  initscr();
  cbreak();
  noecho();
  curs_set(FALSE);
  nodelay(stdscr,TRUE);
  keypad(stdscr,TRUE);

  int width = 0;
  int height = 0;

  cout << "Entering main loop!" << endl;
  while(running) {
    getmaxyx(stdscr, height, width);
    clear();

    drawBorder();
    // board.showTerrain();
    player.display();

    refresh();


    // Really ghetto movement

    char key;
    cin >> key;
    switch(key){
      case 'a': player.left(); break;
      case 's': player.down(); break;
      case 'd': player.right(); break;
      case 'w': player.up(); break;
    }

    sleep(THREAD_HALT_TIME);
  }

  endwin();

  return 0;
}
