#include "board.h"

//
// Board Implementation
//
Board::Board() : matrix_width(0), matrix_height(0), game_board(NULL){}

Board::Board(const int matrix_width, const int matrix_height) : matrix_width(matrix_width), matrix_height(matrix_height){
	game_board = new Tile*[matrix_width];

	for(int x = 0; x < matrix_width; ++x)
		for(int y = 0; y < matrix_height; ++y)
			game_board[x][y] = fill_spaces(random_output(99));
}

Board::~Board(){}

const int Board::random_output(const int range){
	typedef std::mt19937 myRNG;  // the Mersenne Twister with a popular choice of parameters
	myRNG rng;
	rng.seed(time(NULL));
	std::uniform_int_distribution<int> dist(0, range); // range [1,19]
	std::random_device rand;
	return dist(rand);
}

TerrainTile*  Board::fill_spaces(const int num){
	TerrainTile* val = new Plains();
	if(num >= 0 && num < 80){					val = new Plains(); }
	else if(num >= 80 && num < 90){		val = new Water(); }
	else if(num >= 90 && num < 95){		val = new Tree(); }
	else if(num >= 95 && num < 100){	val = new Rocks(); }
	return val;
}

void Board::show_all(){ show_all(false); }

void Board::show_all(const bool std_buffer){
	for(int y = 0; y < matrix_height; ++y){
		for(int x = 0; x < matrix_width; ++x)
			if(std_buffer){ cout << game_board[x][y].terrain->texture(); }
			else{ mvaddch(y, x, game_board[x][y].terrain->texture()); }
		if(std_buffer){ cout << endl; }
	}
}

void Board::show_visited(const bool std_buffer){
	for(int y = 0; y < matrix_height; ++y){
		for(int x = 0; x < matrix_width; ++x){
			if(game_board[x][y].visited){
				if(std_buffer){ cout << game_board[x][y].terrain->texture(); }
				else { mvaddch(y, x, game_board[x][y].terrain->texture()); }
			}
			else{
				if(std_buffer){ cout << " "; }
				else { mvaddch(y, x, ' '); }
			}
		}
		if(std_buffer){ cout << endl; }
	}
}

void Board::show_mask(const bool std_buffer){
	for(int y = 0; y < matrix_height; ++y){
		for(int x = 0; x < matrix_width; ++x){
			if(std_buffer){ cout << game_board[x][y].visited; }
			else { mvaddch(y, x, game_board[x][y].visited); }
		}
		if(std_buffer){ cout << endl; }
	}
}

const bool Board::is_passable(const Position& position){
	if(position.x < 0 || position.x == matrix_width || position.y < 0 || position.y == matrix_height) { return false; }
	return (game_board[position.x][position.y].terrain->is_passable());
}

const Position& find_open_tile(const Position& p1, const Position& p2){
	if(p2.x > p1.x || p2.y > p1.y) {
		// throw POSITION_OUT_OF_BOUNDS((p2 - p1));
	}

	// for(int y = p1.y,)
}

//
// Tile implementation
//
Board::Tile::Tile() : terrain(NULL), visited(false){}

Board::Tile::Tile(TerrainTile* terrain) : terrain(terrain), visited(false) {}

Board::Tile::~Tile(){	if(terrain){ delete terrain; };
}
