#ifndef FRUPAL_MENU_H
#define FRUPAL_MENU_H

#include <cctype> 
#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <string> 

using namespace std;

class menu
{
	public:
		menu();
		~menu();
		menu(const menu & old);		
		const int size;
		string * gameConfig();

	private:
		void gameConfig(string * options);
		string * options;
};
#endif
