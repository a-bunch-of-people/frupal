// class for gamespace area

#ifndef FRUPAL_PCH_H
#define FRUPAL_PCH_H

#include <iostream>
#include <time.h>
#include <random>

using namespace std;

struct boardSpace {
	char terrain;
	char extThings;
	char unknownBlank;
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


            boardSpace** gameSpace;  // struct that has 3 qualities. 
                                     // blank space for user to uncover
                                     // space with terrain 
                                     // space with the extra thing like food, jewels, etc
            int userInput;			 // variable for user input on matrix size
};

#endif //PCH_H
