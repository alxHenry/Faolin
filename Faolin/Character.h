//Header file for the character class. Will be the base class for player, monster, etc...

#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>
#include "Weapon.h"
#include "Armor.h"
#include "Access.h"
#include "Inventory.h"
using namespace std;

class Character
{
public:
	Character(string name_in, int exp_in, int level_in, int gold_in, int hp_in);
	Character();
	virtual ~Character();

	//Mutators
	void set_exp(int exp_in);
	void set_level(int level_in);
	void set_gold(int gold_in);
	void set_hp(int hp_in);
	void set_max_hp(int hp_in);
	void set_status(string status_in);
	void set_name(string name_in);

	//Accessors
	int get_exp() const;
	int get_level() const;
	int get_gold() const;
	int get_hp() const;
	int get_max_hp() const;
	string get_status() const;
	string get_name() const;

private:
	int exp;
	int level;
	int gold;
	int hp;
	int hp_max;
	string status;
	string name;
};

#endif