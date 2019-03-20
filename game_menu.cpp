#include "game_menu.h"
#include "driver.h"

using namespace std; 

menu::menu() : size(10)
{
	options = NULL;
}

menu::~menu() 
{
	 delete [] options;
}

menu::menu(const menu & old) : size(10)
{
	menu oject = old;
}

string * menu::gameConfig()
{
	string * options = new string[size];
	gameConfig(options);

	for(int i = 0; i < size; i++)
	{
		cout << "options: " << options[i] << endl;
		string delimiter = "=>";
		try{
			options[i] = options[i].substr(options[i].find("=>") + 2);	

		}
		catch(std::out_of_range& e){
			cout << "No data entered for config option." << endl;
		}

	}

	return options;
}

void menu::gameConfig(string * options)
{
	int count = 0;	
	ifstream infile("config.txt");
	if( infile.is_open())
	{
		cout << "\nconfig opened" << endl;		
		string line;	
		
		while( getline (infile, line))
		{
			if(line[0] != '#' && line.size() != 0)
			{
				options[count] = line;
				count++;
			}
			if(count == size)
			{
				infile.close();
				cout << "\nThe config.txt file has too many options loaded." << endl;
			}
		}
		cout << "\n";
		infile.close();
	}	
	else cout << "Cannot open file" << endl;
}
