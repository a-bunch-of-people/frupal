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

  try{
    for(int i = 0; i < NUM; ++i) {
      int rand_num = rand() % TEXTURES.size;

      switch (rand_num) {
        case 0:
          tiles[i] = new Water(TEXTURES);
          break;
        case 1:
          tiles[i] = new Plains(TEXTURES);
          break;
        default:
          tiles[i] = new Plains(TEXTURES);
      }
    }

    for(int i = 0; i < NUM; ++i) {
      cout << tiles[i]->texture();

      if((i % LENGTH) == 0)
        cout << endl;
    }
  }
  catch(NULL_TEXTURE e){
    e.what();
  }

  //
  // Destruction Phase
  //

  for(int i = 0; i < NUM - 1; ++i)
    if(tiles[i])
      delete tiles[i];

  return 0;
}
