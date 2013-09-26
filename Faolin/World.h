#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "Character.h"
#include "SaveFile.h"

class World
{
public:
	//Having a Player* as well as the Character* is a very bad band aid for write_save currently
	//***Need to change all of world to use Player* not Character* and eventually get rid of that inheritance!***
	World(int enemy_density_in, int gift_density_in, Player* user_in, Player* player, SaveFile* save_in);
	~World();

	//Main function of the whole program
	bool update();
	
	void give_gift(Player* user_in);
	void battle(Player* oppo);

private:
	//Densities decide how likely an event is to happen on a step (number between 1-1000)
	int enemy_density;
	int gift_density;

	//Having a Player* as well a Character* is a band aid I use for write_save
	Player* player;
	Player* user;
	SaveFile* save;

	//Vector containing the different types of monsters. The types are constants that are
	//entered in at the constructor. Look there to add more monsters or edit them.
	vector<Player*> monster_vect;
};

#endif