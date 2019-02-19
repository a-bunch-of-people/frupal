#include "driver.h"

/*
  file: where main will live for now
  program: Ctrl + F5 or Debug > Start Without Debugging menu
  program: F5 or Debug > Start Debugging menu
*/

int main(const int argc, const char* argv[]) {
  TextureMap CHARACTER_TEXTURES;
  TextureMap TERRAIN_TEXTURES;

  load_textures(CHARACTER_TEXTURES, "textures/character.texture");
  load_textures(TERRAIN_TEXTURES, "textures/terrain.texture");

  CHARACTER_TEXTURES.display();
  TERRAIN_TEXTURES.display();
  Character player(1, 1, "Bob Kerman", CHARACTER_TEXTURES, 99, 100);
  // Water t1(TERRAIN_TEXTURES);
  // Plains t2(TERRAIN_TEXTURES);

  player.display();
  // cout << t1.texture() << " " << t2.texture() << endl;

  return 0;
}
