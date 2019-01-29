#include "driver.h"

/*
    Driver file: where main will live for now
    Run program: Ctrl + F5 or Debug > Start Without Debugging menu
    Debug program: F5 or Debug > Start Debugging menu
*/

int main(const int argc, const char* argc[])
{
	int input = 0;
	cout << "GameSpace\n\n\n";

	cout << "Enter the size of the board you would like.";
		cout <<"\nFor example, enter 20, if you want a 20x20 square, or 30 for a 30x30 square\n";
		cin >> input;

	Board board(input);

	board.showBoard();
	board.showTerrain();
	board.showALL();
	
	return 0;
}
