#ifndef FRUPAL_UTILS_H
#define FRUPAL_UTILS_H

#include <iostream>
#include <string.h>
#include <istream>
#include <fstream>
#include <thread>
#include <math.h>

namespace frupal_utils{
  //
  // Utility stuff
  //

  struct Position{
    int x;
    int y;

    Position();
    Position(const Position&);
    Position(const int, const int);
    Position operator + (const Position &);
    Position operator - (const Position &);
    friend const double operator % (const Position&, const Position&);
    friend std::ostream& operator << (std::ostream &, const Position &);
  };

  struct NULL_TEXTURE{
    char* obj_type;

    NULL_TEXTURE(const char*);
    ~NULL_TEXTURE();
    void what();
  };

  struct POSITION_OUT_OF_BOUNDS{
    Position bad_position;

    POSITION_OUT_OF_BOUNDS(const Position&);
    ~POSITION_OUT_OF_BOUNDS();
    void what();
  };

  struct TextureMap{
    char** texture_name;
    char* texture_list;
    int size;

    TextureMap(const char*);
    ~TextureMap();
    friend std::ostream& operator << (std::ostream &, const TextureMap &);
  };

  void sleep(const int);

  const int MAX_STREAM_SIZE = 64;
  const int THREAD_HALT_TIME = 15; // Time in miliseconds
  const int MAX_GEMS = 3;
};

#endif
