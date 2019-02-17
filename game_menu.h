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
		void gameConfig();	

	private:
		void gameConfig(string * options);
		string * options;
		const int size;

};
