// pch.cpp: source file corresponding pch.h and terrain.h
// library definitions for Board class and BoardUpdate.

#include "board.h"

Board::Board() {}

// constructor with parameter
Board::Board(const int matrixSize) : gridSize(matrixSize){
	gameSpace = new boardSpace*[matrixSize]; //rows

	for (int i = 0; i < matrixSize; ++i)
		gameSpace[i] = new boardSpace[matrixSize]; // columns

	setBoard();
}

Board::~Board() {
	if (gameSpace)
		delete[] gameSpace;
}

Board::boardSpace::boardSpace() : terrain(NULL), unknownBlank('_'), visited(0){}

Board::boardSpace::~boardSpace(){}

//filled board gets set with random inputs
//called within constructor
void Board::setBoard(){
	for (int i = 0; i < gridSize; ++i) {
		for (int j = 0; j < gridSize; ++j) {
			gameSpace[i][j].unknownBlank = '_';
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
	std::uniform_int_distribution<int> dist(0, 99); // range [1,19]
	std::random_device rand;
	return dist(rand);
}

// function to fill board spaces with a terrain quality
TerrainTile*  Board::fillSpaces(int rndInput) {
	TextureMap TERRAIN_TEXTURES;
	load_textures(TERRAIN_TEXTURES, "textures/terrain.texture");

	TerrainTile* val = new Plains(TERRAIN_TEXTURES); //default value plains/meadow.

	if(rndInput >= 0 && rndInput < 50){
		val = new Plains(TERRAIN_TEXTURES);
	}
	else if(rndInput >= 50 && rndInput < 80){
		val = new Tree(TERRAIN_TEXTURES);
	}
	else if(rndInput >= 80 && rndInput < 95){
		val = new Water(TERRAIN_TEXTURES);
	}
	else if(rndInput >= 95 && rndInput < 100){
		val = new Rocks(TERRAIN_TEXTURES);
	}

	return val;
}

//shows player where he has been
//initially shows all _ as they haven't been anywhere yet
void Board::showBoard() { showBoard(0, 0); }
void Board::showBoard(const int x, const int y)
{
	for (int i = x; i < gridSize; ++i)
		for (int j = y; j < gridSize; ++j)
			mvprintw(j, i, "" + gameSpace[i][j].unknownBlank);
}

void Board::showTerrain() { showTerrain(0, 0); }
void Board::showTerrain(const int x, const int y) {
	for (int i = x; i < gridSize; ++i)
		for (int j = y; j < gridSize; ++j)
			if(gameSpace[i][j].visited == 1)
				mvprintw(j, i, "" + gameSpace[i][j].terrain->texture());
			else
				mvprintw(j, i, "_");// + gameSpace[i][j].unknownBlank);
}

void Board::showALL() { showALL(0, 0); }
void Board::showALL(const int x, const int y)
{
	for (int i = x; i < gridSize; ++i)
		for (int j = y; j < gridSize; ++j)
			mvprintw(j, i, "" + gameSpace[i][j].terrain->texture());
}

void Board::showVisited() { showVisited(0, 0); }
void Board::showVisited(const int x, const int y)
{
	for (int i = x; i < gridSize; ++i)
		for (int j = y; j < gridSize; ++j)
			mvprintw(j, i, "" + gameSpace[i][j].visited);
}

const bool Board::isPassable(const int x, const int y) { return gameSpace[x][y].terrain->is_passable(); }

// wrapper function to pass gridSize to derived class
int Board::userValue() {
	return gridSize - 1;
}

BoardUpdate::BoardUpdate(posXY& position, int matrixSize) {}

BoardUpdate::BoardUpdate(posXY& position, const Board& board)
	: Board(board), pos(position) {}

// movment functions
Board::posXY& BoardUpdate::left(posXY& position) {
	//takes xy coordinate and updates location in the up direction
	if (pos.y > 0)  pos.y--; //top of grid. no op.
	location();
	return pos;
}

Board::posXY &BoardUpdate::right(posXY &position) {
	//takes xy coordinate and updates location in the down direction
	int max = userValue();
	if (pos.y != max) pos.y++; // bottom of grid. no op.
	location();
	return pos;
}

Board::posXY &BoardUpdate::up(posXY& position) {
	//takes xy coordinate and updates location in the left direction
	if (pos.x != 0) pos.x--; // left side of grid, no op
	location();
	return pos;
}

Board::posXY &BoardUpdate::down(posXY& position) {
	//takes xy coordinate and updates location in the right direction
	int max = userValue();
	if (pos.x != max) pos.x++; // right side of grid. no op.
	location();
	return pos;
}

void BoardUpdate::location() {
	std::cout << "location pos.x : " << pos.x
		<< "  location pos.y : " << pos.y << std::endl;
}

void BoardUpdate::updateLocation() {
	visited();
	showVisited();

}

// this function updates mask variable from 0 to 1 when player visits a specific tile
void BoardUpdate::visited() {
	std::cout << "location pos.x : " << pos.x
		<< "  location pos.y : " << pos.y << std::endl;

	gameSpace[pos.x][pos.y].visited = 1;
	gameSpace[pos.x][pos.y].unknownBlank = gameSpace[pos.x][pos.y].terrain->texture();
}
