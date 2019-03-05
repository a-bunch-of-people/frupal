#ifndef FRUPAL_UTILS
#define FRUPAL_UTILS

#include <iostream>
#include <string.h>
#include <istream>
#include <fstream>
#include <chrono>
#include <thread>

namespace frupal_utils {
  //
  // Utility stuff
  //


  struct NULL_TEXTURE {
    char* obj_type;

    NULL_TEXTURE(const char*);
    ~NULL_TEXTURE();
    void what();
  };

  struct TextureMap{
    char** tile_types;
    char* textures;
    int size;

    TextureMap();
    ~TextureMap();
    void display();
  };

  void load_textures(TextureMap&, const char*);
  void sleep(const int);

  const int MAX_STREAM_SIZE = 64;
  const int THREAD_HALT_TIME = 15; // Time in miliseconds
  const bool DEBUG = false;
}

#endif
