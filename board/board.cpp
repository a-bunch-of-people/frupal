#include "board.h"

//
// Board Implementation
//
Board::Board() :  game_board(NULL), matrix_width(0), matrix_height(0){}

Board::Board(const int matrix_width, const int matrix_height, const int gem_count) : matrix_width(matrix_width), matrix_height(matrix_height), gem_count(gem_count){
	game_board = new Tile**[matrix_width];

	for(int i = 0; i < matrix_width; ++i)
		game_board[i] = new Tile*[matrix_height];

	for(int x = 0; x < matrix_width; ++x){
		for(int y = 0; y < matrix_height; ++y){
			game_board[x][y] = new Tile(fill_spaces(random_output(99)));
		}
	}

	// for(int i = 0; i < gem_count; ++i)
	place_gem();
}

Board::~Board(){
	for(int x = 0; x < matrix_width; ++x){
		for(int y = 0; y < matrix_height; ++y){
			delete game_board[x][y];
		}
		delete game_board[x];
	}

	delete [] game_board;
}

const int Board::random_output(const int range){
	typedef std::mt19937 myRNG;  // the Mersenne Twister with a popular choice of parameters
	myRNG rng;
	rng.seed(time(NULL));
	std::uniform_int_distribution<int> dist(0, range); // range [1, range]
	std::random_device rand;
	return dist(rand);
}

TerrainTile* Board::fill_spaces(const int num){
	if(num >= 0 && num < 80)				{ return new Plains(); }
	else if(num >= 80 && num < 90)	{ return new Water(); }
	else if(num >= 90 && num < 95)	{ return new Tree(); }
	else if(num >= 95 && num < 100)	{ return new Rocks(); }
	else 														{ return new Plains(); }
}

void Board::show_all(){
	for(int x = 0; x < matrix_width; ++x){
		for(int y = 0; y < matrix_height; ++y){
			if(is_gem(Position(x,y))){ attron(COLOR_PAIR(2)); }
			else{ attron(COLOR_PAIR(1)); }
			mvaddch(y, x, game_board[x][y]->terrain->texture());
		}
	}
}

void Board::show_all(ostream& buffer){
	for(int x = 0; x < matrix_width; ++x){
		for(int y = 0; y < matrix_height; ++y)
				buffer << game_board[x][y]->terrain->texture();
		cout << endl;
	}

}

void Board::show_visited(){
	for(int y = 0; y < matrix_height; ++y)
		for(int x = 0; x < matrix_width; ++x)
			if(game_board[x][y]->visited)
				mvaddch(y, x, game_board[x][y]->terrain->texture());
}

void Board::show_mask(){
	for(int y = 0; y < matrix_height; ++y)
		for(int x = 0; x < matrix_width; ++x)
			mvaddch(y, x, game_board[x][y]->visited);
}

const bool Board::is_passable(const Position& position){
	if(position.x < 0 || position.x == matrix_width || position.y < 0 || position.y == matrix_height) { return false; }
	return (game_board[position.x][position.y]->terrain->is_passable());
}

const bool Board::is_gem(const Position& position){
	return(game_board[position.x][position.y]->terrain->texture() == '?');
}

void Board::place_gem(){
	game_board[8][8] = new Tile(new Gem());
	// game_board[random_output(matrix_width)][random_output(matrix_height)] = new Tile(new Gem());
}

void Board::remove_gem(const Position& position){
	if(is_gem(position)){
		game_board[position.x][position.y] = new Tile(new Plains());
	}
}

const Position Board::find_open_tile(const Position& p1, const Position& p2){
	// if(p2.x > p1.x || p2.y > p1.y) { throw POSITION_OUT_OF_BOUNDS(p2 - p1); }

	for(int y = p1.y; y < p2.y; ++y){
		for(int x = p1.x; x < p2.x; ++x){
			Position temp(x,y);
			if(is_passable(temp))
				return temp;
		}
	}

	return Position(0,0);
}

//
// Tile implementation
//
Tile::Tile() : terrain(NULL), visited(false){}

Tile::Tile(const Tile& source) : terrain(NULL), visited(source.visited) {
	terrain = source.terrain;
}

Tile::Tile(TerrainTile* terrain) : visited(false){
	this->terrain = NULL;
	this->terrain = terrain;
}

Tile::~Tile(){
	if(terrain)
		delete terrain;
}

  std::ostream& operator<< (std::ostream & buffer, const Tile& source){
	buffer << "{ tile: " << *source.terrain << ", visited: " << source.visited << " }";
	return buffer;
}
