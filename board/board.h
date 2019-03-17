#ifndef FRUPAL_BOARD_H
#define FRUPAL_BOARD_H

#include <iostream>
#include <time.h>
#include <random>
#include <ncurses.h>
#include <unistd.h>
#include "../terrain/terrain.h"
#include "../utilities/utilities.h"

using namespace std;
using namespace frupal_utils;

class Board{
	private:
		struct Tile{
			TerrainTile* terrain;
			bool visited;

			Tile();
			~Tile();
		};

		Tile** game_board;
		int tile_count;
		int matrix_height;
		int matrix_width;

		void set_board(); // randomly sets up board.
		const int random_output(const int); // generates a random number
		TerrainTile* fill_spaces(const int rndInput); // fills the matrix with terrain

	public:
		Board();
		Board(const int);
		~Board();

		void show_all();
		void show_visited();
		void show_mask();

		const bool is_passable(const Position&);
};

#endif
