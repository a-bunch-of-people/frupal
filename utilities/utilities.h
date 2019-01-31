#ifndef FRUPAL_UTILS
#define FRUPAL_UTILS

#include <iostream>
#include <string.h>
#include <istream>
#include <fstream>

namespace frupal_utils {
  //
  // Utility stuff
  //

  struct TextureMap{
    char** tile_types;
    char* textures;
    int size;

    TextureMap();
    ~TextureMap();
    void display();
  };

  void load_textures(TextureMap&);
  const int MAX_STREAM_SIZE = 64;
  const bool DEBUG = false;
}

#endif
