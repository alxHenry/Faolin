//Implementation of the weapon class

#include "Weapon.h"
using namespace std;

Weapon::Weapon(string name_in, int dam_in)
{
	name = name_in;
	dam = dam_in;
}

Weapon::~Weapon()
{}

void Weapon::set_name(string name_in)
{
	name = name_in;
}

void Weapon::set_dam(int dam_in)
{
	dam = dam_in;
}

string Weapon::get_name() const
{
	return name;
}

int Weapon::get_dam() const
{
	return dam;
}