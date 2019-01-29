/*
    menu.h
    User Interface for Frupal project
    Russ Pedersen CS300
    contains user interface
*/

#ifndef FRUPAL_MENU_H
#define FRUPAL_MENU_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAX = 100;

char input_tools[MAX], input_obstacles[MAX];
int m_width, m_height, energy, money;
char response;
char choice;

class menu
{
	public:
		void welcome();
		void setup();
	
	
	private:
		int get_width();
		int get_height();
		int get_energy();
		int get_money();
};
 
#endif
