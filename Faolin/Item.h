#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <string>
using namespace std;

//An item has four fields, name, type(what it effects), magnitude, and description
class Item
{
public:
	//Constructor/Destructor
	Item(string name_in, string type_in, int mag_in, string descr_in);
	~Item();

	//Mutators
	//None, an item will not change after it has been created

	//Accessors
	string get_name() const;
	string get_type() const;
	int get_mag() const;
	string get_descr() const;

private:
	string name;
	string type;
	int mag;
	string descr;
};

#endif