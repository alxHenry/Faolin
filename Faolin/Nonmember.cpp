//Implementation of Nonmember functions

#include "Nonmember.h"
#include <iostream>
using namespace std;

vector<string> split_string(string to_split, char delim)
{
	vector<string> words;
	
	//Find first @, if npos is returned there is an error
	int i1 = to_split.find('@');

	if (i1 == string::npos){
		cout << "The save file is not formatted correctly!" << endl;}
	else{
		words.push_back(to_split.substr(0, i1));}

	int index = i1;

	for (int i = i1 + 1; i < to_split.length(); i++){
		if (to_split[i] == delim){
			words.push_back(to_split.substr(index + 1, i - (index + 1)));
			index = i;}}

	//Add last word to vector
	words.push_back(to_split.substr(index + 1));

	return words;
}

Player* mainmenu(SaveFile* save_in)
{
	cout << "Welcome. I hope you enjoy your stay in" << endl << endl;
	cout << "8 8888888888       .8.           ,o888888o.     8 8888          8 8888 b.             8" << endl;
	cout << "8 8888            .888.       . 8888     `88.   8 8888          8 8888 888o.          8" << endl;
	cout << "8 8888           :88888.     ,8 8888       `8b  8 8888          8 8888 Y88888o.       8" << endl;
	cout << "8 8888          . `88888.    88 8888        `8b 8 8888          8 8888 .`Y888888o.    8" << endl;
	cout << "8 888888888888 .8. `88888.   88 8888         88 8 8888          8 8888 8o. `Y888888o. 8" << endl;
	cout << "8 8888        .8`8. `88888.  88 8888         88 8 8888          8 8888 8`Y8o. `Y88888o8" << endl;
	cout << "8 8888       .8' `8. `88888. 88 8888        ,8P 8 8888          8 8888 8   `Y8o. `Y8888" << endl;
	cout << "8 8888      .8'   `8. `88888.`8 8888       ,8P  8 8888          8 8888 8      `Y8o. `Y8" << endl;
	cout << "8 8888     .888888888. `88888.` 8888     ,88'   8 8888          8 8888 8         `Y8o.`" << endl;
	cout << "8 8888    .8'       `8. `88888.  `8888888P'     8 888888888888  8 8888 8            `Yo" << endl;
	cout << "***************************************************************************************" << endl << endl;

	bool fail = true;
	do
	{
		cout << "***** How would you like to play? *****" << endl;
		cout << "** 1. New Adventure" << endl << "** 2. Load Game" << endl;

		int choice = -1;
		cin >> choice;

		if (choice == 1)
		{
			Player* user_ptr = newgame();
			return user_ptr;
		}
		else if (choice == 2)
		{
			//Check to see if saves exist and we can use its interface
			if (save_in->load_save())			//If this fails because there is no date the user is prompted to start new game
			{
				return save_in->get_player();
			}
		}
	}
	while(fail);
}

Player* newgame()
{
	cout << "You awake on a bed of grass, soaked in morning dew. Animals in a clear near you startle when you move, as if you have "
		<< "been stoic for a long time..." << endl;
	cout << endl << "What is your adventurer's name? -- ";

	string name;
	cin.ignore(200, '\n');
	getline(cin, name);

	Player* user_ptr = new Player(name, 0, 1, 0, 10, 10);

	cout << endl << "You try to shake off the fog in your head and see a crudely stitched name in your wool socks, " << name;
	cout << ". After gathering yourself you see no discernable path. You take your first step on your curious adventure..." << endl << endl;

	return user_ptr;
}



