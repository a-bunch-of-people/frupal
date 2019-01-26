// frupal2.cpp : This file contains the 'main' function. 
// this main file illustrates how the Board class works. 

#include "pch.h"


#include <iostream>
using namespace std;


int main()
{
	int input = 0;
	std::cout << "GameSpace\n\n\n";

	std::cout << "Enter the size of the board you would like.";
		std::cout <<"\nFor example, enter 20, if you want a 20x20 square, or 30 for a 30x30 square\n";
		std::cin >> input;

	Board board(input);

	board.showBoard();
	board.showTerrain();
	board.showALL();
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

