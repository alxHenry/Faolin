//Header for the armor class

#ifndef ARMOR_H_INCLUDED
#define ARMOR_H_INCLUDED

#include <string>
using namespace std;

class Armor
{
public:
	Armor(string name_in, int d_reduc_in);
	~Armor();

	int get_reduc() const;
	string get_name() const;

private:
	//One integer representing the damage reduction
	int d_reduc;
	string name;
};

#endif