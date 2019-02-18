#include "driver.h"

/*
  file: where main will live for now
  program: Ctrl + F5 or Debug > Start Without Debugging menu
  program: F5 or Debug > Start Debugging menu
*/

int main(const int argc, const char* argv[]) {
  const int NUM = 1200;
  const int LENGTH = sqrt(NUM) * (10 / 4);

  TextureMap TEXTURES;
  TerrainTile * tiles[NUM];
  load_textures(TEXTURES);


  return 0;
}
