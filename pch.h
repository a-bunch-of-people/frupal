// obects for gamespace area

#ifndef FRUPAL_PCH_H
#define FRUPAL_PCH_H

#include <iostream>
#include <time.h>
#include <random>
#include <ncurses.h>
#include <unistd.h>
#include "terrain/terrain.h"
#include "utilities/utilities.h"

using namespace std;


class Board {
	public:
		Board();
		Board(const int);	//constructor
		void showBoard();	// user can display board from main
		void showTerrain();	// user can display all the board
		void showALL();		// can give up and see everything
		void showVisited();
		int userValue();
		~Board();

	private:
		void setBoard();		// randomly sets up board.
		int randomOutput();		// generates a random number
		TerrainTile* fillSpaces(int rndInput);	// fills the matrix with terrain


	protected:
		struct boardSpace {
			boardSpace();
			~boardSpace();
			TerrainTile* terrain;
			char unknownBlank;
			int visited;
		};

		struct posXY { //position
			int x;
			int y;
		};

		boardSpace ** gameSpace;  // struct that has 3 qualities.
		// blank tile for user to uncover
		// tile with terrain
		// and a tracker to keep track of which tile has been seen
		int gridSize;		 // variable for user input on matrix size
};

// Hey, Dmitri, all the void functions below will be updated as posXY functions
// to pass the updated locations to the player entity when called.
// I'll do that by Friday. (possibly Thursday night).
class BoardUpdate : public Board {
public:
	BoardUpdate(posXY &position, int matrixSize);
	BoardUpdate(posXY &position, const Board & board);
	posXY &up(posXY &position);		// this will take and pass a struct w/ xy coords
	posXY &down(posXY &position);		// same
	posXY &left(posXY &position);		// same
	posXY &right(posXY &position);		// same
	void location();
	void updateLocation();
	void visited();		// updates tile from unseen 0 to seen 1



private:
	posXY pos;


};



#endif //PCH_H
