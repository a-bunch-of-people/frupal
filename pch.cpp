// pch.cpp: source file corresponding pch.h and terrain.h
// library definitions for Board class and BoardUpdate.

#include "pch.h"
#include "terrain.h"

Board::Board() {}

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
			gameSpace[i][j].blankSpace = '_';
			gameSpace[i][j].terrain = fillSpaces(randomOutput());
			gameSpace[i][j].visited = 0;
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

//shows player where he has been
//initially shows all _ as they haven't been anywhere yet
void Board::showBoard()
{
	std::cout << "\n\nfyi, showBoard() function\n\n";
	for (int i = 0; i < userInput; ++i) {
		for (int j = 0; j < userInput; ++j)
			std::cout <<" " << gameSpace[i][j].blankSpace << " " ;
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
	//std::cout << "\n\n fyi, showAll function() \n\n"; // just fyi to developers.
	for (int i = 0; i < userInput; ++i) {
		for (int j = 0; j < userInput; ++j) {
			std::cout << " " << gameSpace[i][j].terrain;
		}
		std::cout << std::endl;
	}
}
void Board::showVisited()
{
	//std::cout << "\n\n fyi, showMask function() \n\n"; // just fyi to developers.
	for (int i = 0; i < userInput; ++i) {
		for (int j = 0; j < userInput; ++j) {
			std::cout << " " << gameSpace[i][j].visited << " ";
		}
		std::cout << std::endl;
	}
}

// wrapper function to pass userInput to derived class
int Board::userValue() {
	return userInput - 1;
}


BoardUpdate::BoardUpdate(posXY &position, int matrixSize) {}

BoardUpdate::BoardUpdate(posXY &position, const Board & board)
	: Board(board), pos(position) {}

// movment functions
void  BoardUpdate::left() {
	//takes xy coordinate and updates location in the up direction
	if (pos.y > 0)  pos.y--; //top of grid. no op.
	location();
}

void BoardUpdate::right() {
	//takes xy coordinate and updates location in the down direction
	int max = userValue();
	if (pos.y != max) pos.y++; // bottom of grid. no op.
	location();
}

void BoardUpdate::up() {
	//takes xy coordinate and updates location in the left direction
	if (pos.x != 0) pos.x--; // left side of grid, no op
	location();
}

void BoardUpdate::down() {
	//takes xy coordinate and updates location in the right direction
	int max = userValue();
	if (pos.x != max) pos.x++; // right side of grid. no op. 
	location();
}

void BoardUpdate::location() {
	std::cout << "location pos.x : " << pos.x
		<< "  location pos.y : " << pos.y << std::endl;
}

void BoardUpdate::updateLocation() {
	visited();
	showMask();

}

// this function updates mask variable from 0 to 1 when player visits a specific tile
void BoardUpdate::visited() {
	std::cout << "location pos.x : " << pos.x
		<< "  location pos.y : " << pos.y << std::endl;

	gameSpace[pos.x][pos.y].visited = 1;
	gameSpace[pos.x][pos.y].blankSpa = gameSpace[pos.x][pos.y].terrain;

