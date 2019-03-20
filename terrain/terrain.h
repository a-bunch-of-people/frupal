#ifndef FRUPAL_TERRAIN_H
#define FRUPAL_TERRAIN_H

#include <iostream>
#include "../utilities/utilities.h"

using namespace std;
using namespace frupal_utils;

class TerrainTile{
  protected:
      // Stuff to define later
      static TextureMap texture_dictionary;
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
      const char texture();
      friend std::ostream& operator << (std::ostream &, const TerrainTile &);
};

class PassableTile: public TerrainTile{
  public:
      // Constructors/Destructors
      PassableTile();
      virtual ~PassableTile() = 0;

      // General function stuff
      const bool is_passable();
};

class UnpassableTile: public TerrainTile{
  public:
      // Constructors/Destructors
      UnpassableTile();
      virtual ~UnpassableTile() = 0;

      // General function stuff
      const bool is_passable();
};

class Water: public UnpassableTile{
  public:
    // Constructors/Destructors
    Water();
    ~Water();

    // General function stuff
    const int get_move_energy();
};

class Rocks: public UnpassableTile{
  public:
    // Constructors/Destructors
    Rocks();
    ~Rocks();

    // General function stuff
    const int get_move_energy();
};

class Tree: public UnpassableTile{
  public:
    // Constructors/Destructors
    Tree();
    ~Tree();

    // General function stuff
    const int get_move_energy();
};

class Gem: public PassableTile{
  public:
    // Constructors/Destructors
    Gem();
    ~Gem();

    // General function stuff
    const int get_move_energy();
};

class Plains: public PassableTile{
  public:
    // Constructors/Destructors
    Plains();
    ~Plains();

    // General function stuff
    const int get_move_energy();
};

#endif
