#include "game_menu.h"

using namespace std;

int main() {

	bool finish = false;
	char choice;

	menu object;
	object.gameConfig();

	do{
		cout << "\nWhat would you like to do? m = move, b = buy, t = select tool"
			", q = quit" << endl;
		cin >> choice;
		choice = toupper(choice);
		cout << "This was your choice: " << choice << endl;
	}
	while(toupper(choice) != 'Q' && finish == false);

	return 0;
}
