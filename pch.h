// obects for gamespace area

#ifndef FRUPAL_PCH_H
#define FRUPAL_PCH_H

#include <iostream>
#include <time.h>
#include <random>

using namespace std;

struct boardSpace {
	TerrainTile terrain;
	char extThings;
	char unknownBlank;
	int mask;
};


class Board {
public:
	Board(int userInput);	//constructor
	void showBoard();		// user can display board from main
	void showTerrain();		// user can display all the board
	void showALL();			// can give up and see everything
	~Board();

private:
	void setBoard();					// randomly sets up board.
	int randomOutput();					// generates a random number
	char fillSpaces(int rndInput);		// fills the matrix with terrain
	char fillExternals(int rndInput);	// fills the matrix with extras
	void visited(int x, int y);			// updates tile from unseen 0 to seen 1


	boardSpace** gameSpace;  // struct that has 4 qualities.
							 // blank space for user to uncover
							 // space with terrain
							 // space with the extra thing like food, jewels, etc
							 // and a tracker to keep track of which tile has been seen
	int userInput;			 // variable for user input on matrix size

};

#endif //PCH_H
