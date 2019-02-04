// pch.cpp: source file corresponding pch.h
// library definitions for Board class.

#include "pch.h"


// constructor with parameter
Board::Board(int matrixSize) : userInput(matrixSize) {
	gameSpace = new boardSpace*[matrixSize]; //rows
	for (int i = 0; i < matrixSize; ++i)
		gameSpace[i] = new boardSpace[matrixSize]; // columns

	setBoard();
}

Board::~Board() {
	if (gameSpace)
		delete[] gameSpace;
}

//filled board gets set with random inputs
//called within constructor
void Board::setBoard(){
	for (int i = 0; i < userInput; ++i) {
		for (int j = 0; j < userInput; ++j) {
			gameSpace[i][j].unknownBlank = '_';
			gameSpace[i][j].terrain = fillSpaces(randomOutput());
			gameSpace[i][j].extThings = fillExternals(randomOutput());
			gameSpace[i][j].mask = 0;
		}
		std::cout << std::endl;
	}
}


// function to generate random numbers.
int Board::randomOutput(){
	typedef std::mt19937 myRNG;  // the Mersenne Twister with a popular choice of parameters
	myRNG rng;
	rng.seed(time(NULL));
	std::uniform_int_distribution<int> dist(1, 19); // range [1,19]
	std::random_device rand;
	return dist(rand);
}

// function to fill board spaces with a terrain quality
char Board::fillSpaces(int rndInput) {
	char val = '_'; //default value plains/meadow.

	switch (rndInput)
	{
	case 6: if (rndInput == 6) val = '*';	//   rocks
		return val;
	case 7: if (rndInput == 7) val = '~';	//  water
		return val;
	case 8: if (rndInput == 8) val = '~';	//  water
		return val;
	case 9: if (rndInput == 9) val = '^';	//  tree
		return val;
	case 10: if (rndInput == 10) val = '#';	// bush
		return val;
	case 11: if (rndInput == 11) val = '*';	//  rock
		return val;

	default:
		return val;
	}
}

// function to fill spaces with extra things like jewels, clues, expressed as a char
char Board::fillExternals(int rndInput) {
	char val = '_';	// initial default value

	switch (rndInput)
	{
	case 1: if (rndInput == 1) val = 'J';	// J for jewels
		return val;
	case 2: if (rndInput == 2) val = '$';	// $ money
		return val;
	case 3: if (rndInput == 3) val = 'C';	// C for clues
		return val;
	case 4: // fall_through
	case 5: // fall_through
	case 6: if (rndInput == 6) val = '_';	// nothing
		return val;
	case 7: if (rndInput == 7) val = 'L';	// L for something.
		return val;
	case 8: // fall_through
	case 9: // fall_through
	case 10: if (rndInput == 10) val = 'J';	// J for jewels
		return val;
	case 11: if (rndInput == 11) val = '$';	// $ money
		return val;
	case 12: if (rndInput == 12) val = 'C';	// C for clues
		return val;
	case 13: //fall_through
	case 14: //fall_through
	case 15: if (rndInput == 15) val = '_';	// nothing
		return val;
	case 16: if (rndInput == 16) val = 'L';	// L for something.
		return val;
	case 17: // fall_through
	case 18: // fall_through
	case 19: if (rndInput == 19) val = '_';	// _ nothing
		return val;

	default:
		return val;
	}
}



//shows player where he has been
//initially shows all _ as they haven't been anywhere yet
void Board::showBoard()
{
	std::cout << "\n\nfyi, showBoard() function\n\n";
	for (int i = 0; i < userInput; ++i) {
		for (int j = 0; j < userInput; ++j)
			std::cout <<" " << gameSpace[i][j].unknownBlank << " " ;
		std::cout << std::endl;
	}
}

void Board::showTerrain() {
	std::cout << "\n\nfyi, showTerrain() function \n\n"; // just fyi to developers. will remove when program is running
	for (int i = 0; i < userInput; ++i) {
		for (int j = 0; j < userInput; ++j) {
			std::cout << " " << gameSpace[i][j].terrain << " ";
		}
		std::cout << std::endl;
	}
}


void Board::showALL()
{
	std::cout << "\n\n fyi, showAll function() \n\n"; // just fyi to developers.
	for (int i = 0; i < userInput; ++i) {
		for (int j = 0; j < userInput; ++j) {
			std::cout << " " << gameSpace[i][j].terrain;
			std::cout << gameSpace[i][j].extThings;
		}
		std::cout << std::endl;
	}
}

// this function updates mask variable from 0 to 1 when player visits a specific tile
void Board::visited(int x, int y) {
	// purpose of this function is to track which tiles player has visited.
	// recieves input as (x, y) coordinate
	// updates mask from 0 to 1 for a visited space

}
