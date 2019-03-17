#include "board.h"

//
// Board Implementation
//
Board::Board(){}

Board::Board(const int matrix_height) : matrix_height(matrix_height){
	matrix_width = ((matrix_height * 9) / 4);
	tile_count = matrix_width * matrix_height;

	game_board = new Tile*[tile_count];

	for (int i = 0; i < matrix_width; ++i)
		game_board[i] = new Tile[matrix_height];

	set_board();
}

Board::~Board(){

}

void Board::set_board(){
	for (int x = 0; x < matrix_width; ++x){
		for (int y = 0; y < matrix_height; ++y){
			game_board[x][y].terrain = fill_spaces(random_output(99));
			game_board[x][y].visited = (bool)(random_output(1));
		}
	}
}

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

void Board::show_all(){
	for(int y = 0; y < matrix_height; y++){
		for(int x = 0; x < matrix_width; x++)
			cout << game_board[x][y].terrain->texture();
		cout << endl;
	}
}

void Board::show_visited(){
	for(int y = 0; y < matrix_height; y++){
		for(int x = 0; x < matrix_width; x++){
			if(game_board[x][y].visited)
				cout << game_board[x][y].terrain->texture();
		}
		cout << endl;
	}
}

void Board::show_mask(){
	for(int y = 0; y < matrix_height; y++){
		for(int x = 0; x < matrix_width; x++){
			cout << game_board[x][y].visited;
		}
		cout << endl;
	}
}

const bool Board::is_passable(const Position& position){
	return (game_board[position.x][position.y].terrain->is_passable());
}

//
// Tile implementation
//
Board::Tile::Tile() : terrain(new Plains()), visited(false) {}

Board::Tile::~Tile(){
	if(terrain)
		delete terrain;
}
