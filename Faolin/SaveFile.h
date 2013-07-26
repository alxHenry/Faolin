#ifndef SAVEFILE_H_INCLUDED
#define SAVEFILE_H_INCLUDED

#include "Player.h"
#include <string>
using namespace std;

//Stores player data in a text file that can be loaded next time the game
//starts.
class SaveFile
{
public:
	SaveFile();
	~SaveFile();

	void write_save(Player* player) const;
	bool load_save();
	bool display_saves() const;
	Player* get_player() const;

private:
	string path;
	vector<Player*> player_vect;
	string name;
	int exp;
	int level;
	int gold;
	int hp;
	int max_hp;
	int loc_x;
	int loc_y;
	string inventory;		//Hard part
	Player* loaded_player;  //The player corresponding to the save the user selects
};

#endif