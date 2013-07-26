//Implementation of the armor class

#include "Armor.h"
using namespace std;

Armor::Armor(string name_in, int d_reduc_in)
{
	name = name_in;
	d_reduc = d_reduc_in;
}

Armor::~Armor()
{}

int Armor::get_reduc() const
{
	return d_reduc;
}

string Armor::get_name() const
{
	return name;
}