#ifndef FRUPAL_TERRAIN_H
#define FRUPAL_TERRAIN_H

#include <iostream>
#include <string.h>
#include "../utilities/utilities.h"

using namespace std;
using namespace frupal_utils;

struct NULL_TEXTURE {
  char* obj_type;

  NULL_TEXTURE(const char*);
  ~NULL_TEXTURE();
  void what();
};

class TerrainTile {
  protected:
      // Stuff to define later
      char key_texture;
      bool texture_found;

  public:
    // Constructors/Destructors
      TerrainTile();
      virtual ~TerrainTile() = 0;

      // Stuff to define later
      virtual const bool is_passable() = 0;
      virtual const int get_move_energy() = 0;

      // General function stuff
      char texture();
};

class PassableTile: public TerrainTile {
  public:
      // Constructors/Destructors
      PassableTile();
      virtual ~PassableTile() = 0;

      // General function stuff
      const bool is_passable();
};

class UnpassableTile: public TerrainTile {
  public:
      // Constructors/Destructors
      UnpassableTile();
      virtual ~UnpassableTile() = 0;

      // General function stuff
      const bool is_passable();
};

class Water: public UnpassableTile {
  public:
    // Constructors/Destructors
    Water(const TextureMap&);
    ~Water();

    // General function stuff
    const int get_move_energy();
};

class Plains: public PassableTile {
  public:
    // Constructors/Destructors
    Plains(const TextureMap&);
    ~Plains();

    // General function stuff
    const int get_move_energy();
};

#endif
