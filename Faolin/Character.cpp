//Implementation of Character class

#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(string name_in, int exp_in, int level_in, int gold_in, int hp_in)
{
	name = name_in;
	exp = exp_in;
	level = level_in;
	gold = gold_in;
	hp = hp_in;
	hp_max = hp_in;
}

//Used for inheritance
Character::Character()
{}

Character::~Character()
{}

void Character::set_exp(int exp_in)
{
	exp = exp_in;
}

void Character::set_level(int level_in)
{
	level = level_in;
}

void Character::set_gold(int gold_in)
{
	gold = gold_in;
}

void Character::set_hp(int hp_in)
{
	hp = hp_in;
}

void Character::set_max_hp(int hp_in)
{
	hp_max = hp_in;
}


void Character::set_status(string status_in)
{
	status = status_in;
}

void Character::set_name(string name_in)
{
	name = name_in;
}

int Character::get_exp() const
{
	return exp;
}

int Character::get_level() const
{
	return level;
}

int Character::get_gold() const
{
	return gold;
}

int Character::get_hp() const
{
	return hp;
}

int Character::get_max_hp() const
{
	return hp_max;
}

string Character::get_status() const
{
	return status;
}

string Character::get_name() const
{
	return name;
}