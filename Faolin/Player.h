//Header file for a player object

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Character.h"
#include "Inventory.h"
#include "Map.h"
using namespace std;

class Player : public Character
{
public:
	Player(string name_in, int exp_in, int level_in, int gold_in, int hp_in, int max_hp);
	Player(string name_in, int exp_in, int level_in, int gold_in, int hp_in, int max_hp, int loc_x_in, int loc_y_in);
	~Player();
	
	//Display
	void view_inventory() const;
	void view_attributes() const;
	void view_map() const;

	//Player development
	void level_up();

	//World interaction
	char action();
	void take_step();

	//Accessors
	Inventory* get_inventory() const;
	vector<int> get_loc() const;

	//Mutators
	void set_loc(int x_in, int y_in);

private:
	//Equipment goes in inventory (except for the map)
	Inventory* inv;
	Map* map;
	int steps_taken;
	int loc_x;
	int loc_y;

	//Constant base value used to determine the amount of exp to level up, default is 20.
	int level_exp_base;
};

#endif