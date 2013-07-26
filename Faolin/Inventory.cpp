#include "Inventory.h"
#include <iostream>
#include <iomanip>
using namespace std;

Inventory::Inventory()
{
	//Will always be initialized at the very beginning of the game by the Player class
	weapon = new Weapon("Bare Hands", 1);
	armor = NULL;
	access = NULL;
}

Inventory::~Inventory()
{
	delete weapon;
}

//All stream output to show the items in inv. Takes in an integer representing the amount
//of gold the player has.
void Inventory::view_inv(int gold) const
{
	cout << endl;
	cout << "******************************* Inventory *******************************" << endl;
	cout << "--- " << gold << " gold in your coinpurse ---" << endl << endl;
	cout << "--- " << "Equipment" << " ---" << endl;
	cout << setw(12) << "Weapon: " << setw(20) << get_weapon()->get_name() << "     " << get_weapon()->get_dam() << " damage" << endl << endl;
	
	//Check if player has armor or accessor to display
	if (get_armor() != NULL)
	{
		cout << setw(12) << "Armor: " << setw(20) << get_armor()->get_name() << "     " << get_armor()->get_reduc() << " damage reduction" << endl << endl;
	}
	if (get_access() != NULL)
	{
		cout << setw(12) << "Accessory: " << setw(20) << get_access()->get_name() << endl << endl;
	}

	//Now display misc items
	cout << "--- " << setw(9) << "Items" << " ---" << endl;

	//Loop over vector print their info
	for (int i = 0; i < other_items.size(); i++)
	{
		cout << i + 1 << ". " << setw(20) << other_items[i].get_name() << "     " << other_items[i].get_descr() << endl;
	}
	cout << endl;
}

Weapon* Inventory::get_weapon() const
{
	return weapon;
}

Armor* Inventory::get_armor() const
{
	return armor;
}

Access* Inventory::get_access() const
{
	return access;
}

void Inventory::set_weapon(Weapon* weapon_in)
{
	weapon = weapon_in;
}

void Inventory::set_armor(Armor* armor_in)
{
	armor = armor_in;
}

void Inventory::set_access(Access* access_in)
{
	access = access_in;
}

void Inventory::add_item(Item new_item)
{
	other_items.push_back(new_item);
}