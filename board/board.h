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
			Tile(const Tile&);
			Tile(TerrainTile*);
			~Tile();
		};

		Tile** game_board;
		int matrix_width;
		int matrix_height;

		const int random_output(const int); // generates a random number
		TerrainTile* fill_spaces(const int rndInput); // fills the matrix with terrain

	public:
		Board();
		Board(const int, const int);
		~Board();

		void show_all();
		void show_all(const bool);
		void show_visited();
		void show_visited(const bool);
		void show_mask();
		void show_mask(const bool);

		const bool is_passable(const Position&);
		const Position& find_open_tile(const Position&, const Position&);
};

#endif
