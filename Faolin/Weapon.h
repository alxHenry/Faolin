//Header file for generic weapon class

#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <string>
#include <vector>
using namespace std;

class Weapon
{
public:
	Weapon(string name_in, int dam_in);
	~Weapon();

	//Mutators
	void set_name(string name_in);
	void set_dam(int dam_in);

	//Accessors
	string get_name() const;
	int get_dam() const;

private:
	string name;
	int dam;
};

#endif