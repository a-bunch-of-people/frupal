#include "npc.h"

npc::npc(): creature(0, 0, NULL, 0) { }

npc::npc(int start_x, int start_y, char * start_name, int start_gold): creature(start_x, start_y, start_name, start_gold) { }

npc::~npc()
{

}

//
//
// class sailor implementation
//
//
sailor::sailor(): npc(0, 0, NULL, 0) { }

sailor::sailor(int start_x, int start_y, char * start_name, int start_gold): npc(start_x, start_y, start_name, start_gold) { }


sailor::~sailor()
{

}

void sailor::interact()
{
    int input = 0;

    cout << "\n\nArr laddy! What brings ye to these parts?" << endl;
    cout << "1. I would like to trade!" << endl;
    cout << "2. Do you have any quests for me?" << endl;
    cout << "3. Actually, I have to go." << endl << endl;
    cout << "GAME: Enter your option of choice (1, 2, or 3)" << endl;
    cin >> input;
    cout << endl;

    if(input == 1)
    {
        trade();
    } else if(input == 2)
    {
        // get_quest()
        cout << "QUEST: Could ye get me some rum? Thar'd be treasure an' adventure in it for ya..." << endl;
    } else if(input == 3)
    {
        // end interaction
        input = -1;
        cout << "Goodbye." << endl;
    } else
    {
        cout << "Do ya have sand in your ears, laddy? (GAME: Enter 1, 2, or 3)" << endl;
    }
}

void sailor::trade()
{
    cout << "Ho ho! Check out me wares, laddy!" << endl;
    //cout << "(!) DISPLAY SAILOR'S ITEMS & CORRESPONDING PRICES (should be an attribute of item)" << endl;
}

//
//
// class wizard implementation
//
//

wizard::wizard(): npc(0, 0, NULL, 0) { }

wizard::wizard(int start_x, int start_y, char * start_name, int start_gold): npc(start_x, start_y, start_name, start_gold) { }


wizard::~wizard()
{

}

void wizard::interact()
{
    int input = 0;

    cout << "\n\n*muttering* ... one emerald, three frupe branches, distilled extract of ... " << endl;
    cout << "1. I would like to trade!" << endl;
    cout << "2. Do you have any quests for me?" << endl;
    cout << "3. Actually, I have to go." << endl << endl;
    cout << "GAME: Enter your option of choice (1, 2, or 3)" << endl;
    cin >> input;
    cout << endl;

    if(input == 1)
    {
        trade();
    } else if(input == 2)
    {
        // get_quest()
        cout << "Why yes, actually. Please bring me an emerald from the Caves of Splendor! I'll make it worth your while." << endl;
    } else if(input == 3)
    {
        // end interaction
        input = -1;
        cout << "Goodbye." << endl;
    } else
    {
        cout << "I don't think that's what you meant. (GAME: Enter 1, 2, or 3)" << endl;
    }
}

void wizard::trade()
{
    cout << "I have nothing to trade; save your gold for the journey ahead -- you may need it!" << endl;
    //cout << "(!) DISPLAY wizard'S ITEMS & CORRESPONDING PRICES (should be an attribute of item)" << endl;
}

//
//
// class miner implementation
//
//
miner::miner(): npc(0, 0, NULL, 0) { }

miner::miner(int start_x, int start_y, char * start_name, int start_gold): npc(start_x, start_y, start_name, start_gold) { }


miner::~miner()
{

}

void miner::interact()
{
    int input = 0;

    cout << "\n\n*singing* It ain't no trick to get rich quick if you dig dig dig with a shovel or a pick!" << endl;
    cout << "1. I would like to trade!" << endl;
    cout << "2. Do you have any quests for me?" << endl;
    cout << "3. Actually, I have to go." << endl << endl;
    cout << "GAME: Enter your option of choice (1, 2, or 3)" << endl;
    cin >> input;
    cout << endl;

    if(input == 1)
    {
        trade();
    } else if(input == 2)
    {
        // get_quest()
        cout << "None of my tools can break open this here boulder o' gems! At least, I think there's gems. Find me somethin' for the job and I'll split the lot with ye!" << endl;
    } else if(input == 3)
    {
        // end interaction
        input = -1;
        cout << "Goodbye." << endl;
    } else
    {
        cout << "My ears are ringin'... what'd ye say? (GAME: Enter 1, 2, or 3)" << endl;
    }
}

void miner::trade()
{
    cout << "Heigh-ho, heigh-ho -- plenty o' goods gotta go!" << endl;
    //cout << "(!) DISPLAY miner'S ITEMS & CORRESPONDING PRICES (should be an attribute of item)" << endl;
}


