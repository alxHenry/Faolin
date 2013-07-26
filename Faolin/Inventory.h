#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include "Weapon.h"
#include "Armor.h"
#include "Access.h"
#include "Item.h"
#include <vector>

class Inventory
{
public:
	//Constructor and destructors
	Inventory();
	~Inventory();

	//Actions
	void view_inv(int gold) const;

	//Accessors
	Weapon* get_weapon() const;
	Armor* get_armor() const;
	Access* get_access() const;

	//Mutators
	void set_weapon(Weapon* weapon_in);
	void set_armor(Armor* armor_in);
	void set_access(Access* access_in);
	void add_item(Item new_item);

private:
	Weapon* weapon;
	Armor* armor;
	Access* access;
	vector<Item> other_items;
};

#endif