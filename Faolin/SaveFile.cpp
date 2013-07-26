#include "SaveFile.h"
#include "Nonmember.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

SaveFile::SaveFile()
{
	//Need to read this info into a vector of players from save file
	//If there is no information then no player is loaded and the user must start a new game.
	path = "Saved.txt";

	fstream in;
	string save;
	in.open(path);

	while (getline(in, save))
	{
		vector<string> data;
		data = split_string(save, '@');

		//Must convert all data from string to the appropriate type

		//Name
		name = data[0];

		//Exp
		istringstream strm_exp;
		strm_exp.str(data[1]);
		strm_exp >> exp;

		//Level
		istringstream strm_level;
		strm_level.str(data[2]);
		strm_level >> level;

		//Gold
		istringstream strm_gold;
		strm_gold.str(data[3]);
		strm_gold >> gold;

		//Hp
		istringstream strm_hp;
		strm_hp.str(data[4]);
		strm_hp >> hp;

		//Max_HP
		istringstream strm_maxhp;
		strm_maxhp.str(data[5]);
		strm_maxhp >> max_hp;

		//Loc_X
		istringstream strm_locx;
		strm_locx.str(data[6]);
		strm_locx >> loc_x;

		//Loc_Y
		istringstream strm_locy;
		strm_locy.str(data[7]);
		strm_locy >> loc_y;

		//Now create a player with these attributes and add him to the player_vect after modifying his
		//location.
		player_vect.push_back(new Player(name, exp, level, gold, hp, max_hp, loc_x, loc_y));
	}
}

//Write the player info to the path file. Seperate each field with an @ symbol to represent the field
//!!!Currently does not store inventory!!!
void SaveFile::write_save(Player* player) const
{
	ofstream out;
	out.open(path);

	out << player->get_name() << '@' << player->get_exp() << '@' << player->get_level() << '@' << player->get_gold() << '@' << player->get_hp() << '@' << player->get_max_hp() << '@'
		<< player->get_loc()[0] << '@' << player->get_loc()[1];

	out.close();
}

//Have the player choose the save he wants to load. Returns true if player is successfully loaded and 
//stores the loaded player into the SaveFile object.
bool SaveFile::load_save()
{
	if (display_saves())
	{
		int choice = -1;
		cout << "Please choose the save you wish to load: ";
		cin.ignore(200, '\n');
		cin >> choice;
		
		//Test if the option is valid
		if (choice >= 1 && choice <= player_vect.size()) 
		{
			choice = choice - 1; //Because we must convert back to terms of the location in the player_vect
			loaded_player = player_vect[choice];
			return true;
		}
		return false;
	}
	return false;
}

//Simple method that takes in a player_vect and displays the information of the saves in a numbered list. Return false if there are
//no save files. Call this from main menu if the player chooses the load game option.
bool SaveFile::display_saves() const
{
	cout << endl << "*************************************************************" << endl;
	cout <<         "**************************** SAVES **************************" << endl;

	//If no save files
	if (player_vect.size() == 0)
	{
		cout << "** Sorry, you do not have any save files. You will have to start a new game from the main menu!" << endl;
		return false;
	}

	//Save files exist, loop through and display.
	for (int i = 0; i < player_vect.size(); i++)
	{
		cout << "** " << i + 1 << ". " << player_vect[i]->get_name() << "   Level " << player_vect[i]->get_level() << " Adventurer   "
			<< player_vect[i]->get_hp() << "/" << player_vect[i]->get_max_hp() << "   Exp: " << player_vect[i]->get_exp() << endl;
	}

	//All saves have been printed. Print the closing block.
	cout << endl << "*************************************************************" << endl;
	return true;
}

//Return the loaded player
Player* SaveFile::get_player() const
{
	return loaded_player;
}