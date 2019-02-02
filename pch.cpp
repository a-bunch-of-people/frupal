// pch.cpp: source file corresponding pch.h
// library definitions for Board class. 

#include "pch.h"


// constructor with parameter
Board::Board(int matrixSize) : userInput(matrixSize) {
	//Allocated pointer memory
	gameSpace = new boardSpace*[matrixSize]; //rows
	for (int i = 0; i < matrixSize; ++i)
		gameSpace[i] = new boardSpace[matrixSize]; // columns

	setBoard();
}


//Destructor
Board::~Board() {
	if (gameSpace)
		delete[] gameSpace;
}

//filled board gets set with random inputs
//called within constructor
void Board::setBoard()
{
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
int Board::randomOutput()
{
	typedef std::mt19937 myRNG;  // the Mersenne Twister with a popular choice of parameters
	myRNG rng;                   
	rng.seed(time(NULL));
	std::uniform_int_distribution<int> dist(1, 19); // range [1,19]
	std::random_device rand;
	return dist(rand);
}

// function to fill board spaces with a terrain quality
char Board::fillSpaces(int rndInput) {
	char val = 'm'; //initial value. 

	switch (rndInput)
	{
	case 1: 
	case 2:
	case 3: 
	case 4:
	case 5:
		if (rndInput >= 1 || rndInput <= 5) val = 'm';   // m for meadow
		return val;							// repeated this value to weight output to be more mmeadow than the rest
	case 6: if (rndInput = 6) val = '^';	// ^ for rocks
		return val;
	case 7: if (rndInput = 7) val = 'w';	// w for water
		return val;
	case 8: if (rndInput = 8) val = '~';	// ~ for bog
		return val;
	case 9: if (rndInput = 9) val = '!';	// ! for tree
		return val;
	case 10: if (rndInput = 10) val = 'w';	// w for water
		return val;
	case 11: if (rndInput = 11) val = '^';	// ^ for rock
		return val;
	case 12:
	case 13: 
	case 14: 
	case 15:
	case 16:
	case 17: 
	case 18: 
	case 19:	
		if (rndInput >= 12 || rndInput <= 19) val = 'm';	// ^ rocks
		return val;

	default:
		return val;
	}
}
	
// function to fill spaces with extra things like jewels, clues, expressed as a char
char Board::fillExternals(int rndInput) {
	char val = 'Q';	// initial default value	

	switch (rndInput)
	{
	case 1: if (rndInput == 1) val = 'J';	// J for jewels
		return val;
	case 2: if (rndInput == 2) val = '$';	// $ money
		return val;
	case 3: if (rndInput = 3) val = 'C';	// C for clues
		return val;
	case 4: if (rndInput = 4) val = '_';	// _ for empty space
		return val;
	case 5: if (rndInput = 5) val = '_';	// _ for empty space
		return val;
	case 6: if (rndInput = 6) val = '_';	// _ same
		return val;
	case 7: if (rndInput = 7) val = 'L';	// L for something. 
		return val;
	case 8: if (rndInput = 8) val = '_';	// _ empty
		return val;
	case 9: if (rndInput = 9) val = '_';	// _ same
		return val;
	case 10: if (rndInput == 1) val = 'J';	// J for jewels
		return val;
	case 11: if (rndInput == 2) val = '$';	// $ money
		return val;
	case 12: if (rndInput = 3) val = 'C';	// C for clues
		return val;
	case 13: if (rndInput = 4) val = '_';	// _ for empty space
		return val;
	case 14: if (rndInput = 5) val = '_';	// _ for empty space
		return val;
	case 15: if (rndInput = 6) val = '_';	// _ same
		return val;
	case 16: if (rndInput = 7) val = 'L';	// L for something. 
		return val;
	case 17: if (rndInput = 8) val = '_';	// _ empty
		return val;
	case 18: if (rndInput = 9) val = '_';	// _ same
		return val;
	case 19: if (rndInput = 9) val = '_';	// _ same
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
	std::cout << "\n\nfyi, showTerrain() function \n\n";
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
			//gameSpace[i][j].terrain = fillSpaces(randomOutput());
			//gameSpace[i][j].extThings = fillExternals(randomOutput());
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
