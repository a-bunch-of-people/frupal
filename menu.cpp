#include "menu.h"

/*
    menu.cpp
    User Interface for Frupal project
    Russ Pedersen CS300
    contains user interface
 */

void Menu::welcome()
{
	cout << "\nWelcome to Frupal\n";
	cout << "\nAn adventure game set on the island of Frupal\n";
	cout << "\nAdam Davis, Bradley Thompson, David Djaernes, Dmitri McGuckin, Ryan Jones, Yiwei Deng, and Russ Pedersen\n";
}

void Menu::setup()
{
	cout << "\nSetup the game:\n";
	int m_width = get_width();
	int m_height = get_height();
	int energy = get_energy();
	int money = get_money();
	cout << "\nWhich tools do you want to start with?\n";
	cin >> input_tools;
	cin.ignore(100,'\n');
	cout << "\nWhich obstacles do you want to start with?\n";
	cin >> input_obstacles;
	cin.ignore(100,'\n');
	// game my_game = new game(m_width, m_height, energy, money, input_tools, input_obstacles);
}	

/*
A function to set the width of the map
no parameters
returns width of the map
*/
int Menu::get_width()
{
	cout << "\nHow wide do you want the map?\n";
	int map_width = 0;
	do
	{
		cin >> map_width;
		cin.ignore(100,'\n');
	if(map_width < 10 || map_width > 80)
	{
		cout << "Please enter a valid width (10-80)\n";
		map_width = 0;
	}while (map_width == 0);
	
	return map_width;
}

/*
A function to set the height of the map
no parameters
returns height of the map
*/
int Menu::get_height()
{
	cout << "\nHow deep do you want the map?\n";\
	int map_height = 0;
	do
	{
		cin >> map_height;
		cin.ignore(100,'\n');
	if(map_height < 10 || map_height > 40)
	{
		cout << "Please enter a valid height (10-40)\n";
		map_height = 0;
	}while (map_height == 0);
	
	return map_height;
}

/*
A function to set the player's starting energy level
no parameters
returns player's starting energy
*/
int Menu::get_energy()
{
	cout << "\nHow much energy do you want to have at the start?\n";\
	int player_energy = 0;
	do
	{
		cin >> player_energy;
		cin.ignore(100,'\n');
	if(player_energy < 1 || player_energy > 100)
	{
		cout << "Please enter a valid amount (1-100)\n";
		player_energy = 0;
	}while (player_energy == 0);
	
	return player_energy;
}

/*
A function to set the player's starting money level
no parameters
returns player's starting money
*/
int Menu::get_money()
{
	cout << "\nHow much money do you want to have at the start?\n";\
	int player_money = 0;
	do
	{
		cin >> player_money;
		cin.ignore(100,'\n');
	if(player_money < 1 || player_money > 500)
	{
		cout << "Please enter a valid amount (1-500)\n";
		player_money = 0;
	}while (player_money == 0);
	
	return player_money;
}
