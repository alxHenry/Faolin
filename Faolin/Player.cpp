//Implementation for the player class

#include <string>
#include <iostream>
#include <iomanip>
#include "Player.h"

Player::Player(string name_in, int exp_in, int level_in, int gold_in, int hp_in, int max_hp_in)
{
	set_name(name_in);
	set_exp(exp_in);
	set_level(level_in);
	set_gold(gold_in);
	set_hp(hp_in);
	set_max_hp(max_hp_in);
	steps_taken = 0;
	level_exp_base = 3;
	loc_x = 0;
	loc_y = 0;
	inv = new Inventory;
	map = new Map(loc_x, loc_y);
}

Player::Player(string name_in, int exp_in, int level_in, int gold_in, int hp_in, int max_hp_in, int loc_x_in, int loc_y_in)
{
	set_name(name_in);
	set_exp(exp_in);
	set_level(level_in);
	set_gold(gold_in);
	set_hp(hp_in);
	set_max_hp(max_hp_in);
	steps_taken = 0;
	loc_x = loc_x_in;
	loc_y = loc_y_in;
	level_exp_base = 3;

	inv = new Inventory;
	map = new Map(loc_x, loc_y);
}

Player::~Player()
{
	delete inv;
}

//Call this after a player gains experience. First checks if the player should level up, if so it levels
//him up. If not, it does nothing.
void Player::level_up()
{
	//First check. Each level you gain it takes 30% more experience to level up the next time
	if (get_exp() >= (1 + ((get_level() - 1) * .3)) * level_exp_base)
	{
		//Level up
		set_level(get_level() + 1);
		set_exp(0);

		//Increase max hp
		set_max_hp((10 + 3 * (get_level() - 1)));

		//Restore player hp
		set_hp(get_max_hp());

		//Notify user
		cout << endl << "*** You are becoming more resilient and are acclimating to the unforgiving land."
			<< " Your vitality increases and your will strengthens, you are now level " << get_level() << " ***" <<endl << endl;
	}
}

//Function that takes in the Players choice of action. Returns the choice of the Player
char Player::action()
{
	bool loop = false;
	do
	{
	char choice;
	cout << endl;
	cout << "Select an action:" << endl;
	cout << "[t]ravel, view [i]nventory, view [a]ttributes, view [m]ap, [s]ave, or [q]uit?: ";
	cin >> choice;

	if (cin.fail())
	{
		cout << "Enter a single character of your choice." << endl;
		cin.clear();
		cin.ignore(200, '\n');
		loop = true;
	}
	//If it is a valid option return it, otherwise loop again.
	else
	{
		if (choice == 't' || choice == 'i' || choice == 'a' || choice == 'm' || choice == 's' || choice == 'q')
		{
			return choice;
		}
		else
		{
			cout << "That is not a valid choice, try again." << endl;
			loop = true;
		}
	}
	}
	while(loop);
}

void Player::view_inventory() const
{
	inv->view_inv(get_gold());
}

Inventory* Player::get_inventory() const
{
	return inv;
}

vector<int> Player::get_loc() const
{
	vector<int> data;
	data.push_back(loc_x);
	data.push_back(loc_y);
	return data;
}

void Player::set_loc(int x_in, int y_in)
{
	loc_x = x_in;
	loc_y = y_in;
}

void Player::view_attributes() const
{
	cout << endl;
	cout << "****************************** Attributes ******************************" << endl << endl;
	cout << "--- Level " << get_level() << " Adventurer " << get_name() << " ---" << endl;
	cout << setw(10) << "Health: " << get_hp() << "/" << get_max_hp() << endl;
	cout << setw(10) << "Exp: " << get_exp() << "/" << int((1 + ((get_level() - 1) * .3)) * level_exp_base) << endl << endl;	//Need to place exp to level up here

}

void Player::take_step()
{
	cout << "Which direction would you like to travel in?" << endl;
	cout << "1 - North" << endl;
	cout << "2 - East" << endl;
	cout << "3 - South" << endl;
	cout << "4 - West" << endl;

	int choice;
	cin >> choice;
	cout << endl;
	bool valid = true;

	//Save a variable for the desired x and y the player is trying to travel to
	int pos_x = loc_x;
	int pos_y = loc_y;

	if (choice == 1)
	{
		pos_y--;
		if (map->pos_available(pos_x, pos_y))
		{
			loc_y--;
			map->update_pos(loc_x, loc_y);
			steps_taken++;
			cout << "You travel towards the North." << endl << endl;
		}
		else {valid = false;}
	}
	if (choice == 2)
	{
		pos_x++;
		if (map->pos_available(pos_x, pos_y))
		{
			loc_x++;
			map->update_pos(loc_x, loc_y);
			steps_taken++;
			cout << "You travel towards the East." << endl << endl;
		}
		else {valid = false;}
	}
	if (choice == 3)
	{
		pos_y++;
		if (map->pos_available(pos_x, pos_y))
		{
			loc_y++;
			map->update_pos(loc_x, loc_y);
			steps_taken++;
			cout << "You travel towards the South." << endl << endl;
		}
		else {valid = false;}
	}
	if (choice == 4)
	{
		pos_x--;
		if (map->pos_available(pos_x, pos_y))
		{
			loc_x--;
			map->update_pos(loc_x, loc_y);
			steps_taken++;
			cout << "You travel towards the West." << endl << endl;
		}
		else {valid = false;}
	}
	if (valid == false)
	{
		cout << "Your travel is blocked by ";
		if (map->in_bounds(pos_x, pos_y))
		{
			if (map->at_pos(pos_x, pos_y) == '~')
			{
				cout << "a raging river!" << endl << endl;
			}
			else if (map->at_pos(pos_x, pos_y) == '^')
			{
				cout << "a mountainous crag of rock, reaching into the clouds!" << endl << endl;
			}
		}
		else
		{
			cout << "a steep ledge that plunges into the depths of a seemingly endless sea." << endl << endl;
		}
	}
}

void Player::view_map() const
{
	map->view_map(loc_x, loc_y);
}