#include "Item.h"
using namespace std;

Item::Item(string name_in, string type_in, int mag_in, string descr_in)
{
	name = name_in;
	type = type_in;
	mag = mag_in;
	descr = descr_in;
}

Item::~Item()
{}

string Item::get_name() const
{
	return name;
}

string Item::get_type() const
{
	return type;
}

int Item::get_mag() const
{
	return mag;
}

string Item::get_descr() const
{
	return descr;
}