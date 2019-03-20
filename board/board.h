#ifndef FRUPAL_BOARD_H
#define FRUPAL_BOARD_H

#include <iostream>
#include <time.h>
#include <random>
#include <ncurses.h>
#include "../terrain/terrain.h"
#include "../utilities/utilities.h"

using namespace std;
using namespace frupal_utils;

struct Tile{
	TerrainTile* terrain;
	bool visited;

	Tile();
	Tile(const Tile&);
	Tile(TerrainTile*);
	~Tile();

	friend std::ostream& operator << (ostream&, const Tile&);
};

class Board{
	private:
		Tile*** game_board;
		int matrix_width;
		int matrix_height;
		int gem_count;

		const int random_output(const int); // generates a random number
		TerrainTile* fill_spaces(const int rndInput); // fills the matrix with terrain

	public:
		Board();
		Board(const int, const int, const int);
		~Board();

		void show_all();
		void show_all(ostream&);
		void show_visited();
		void show_mask();

		void update_visited(const int, const Position&);
		void place_gem();
		void remove_gem(const Position&);

		const bool is_passable(const Position&);
		const bool is_gem(const Position&);
		const Position find_open_tile(const Position&, const Position&);
		const int get_move_energy(const Position&);
};

#endif
