#include "World.h"
#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;

//Density are integers between 0 and 100
World::World(int enemy_density_in, int gift_density_in, Player* user_in, Player* player_in, SaveFile* save_in)
{
	enemy_density = enemy_density_in;
	gift_density = gift_density_in;
	user = user_in;
	player = player_in;
	save = save_in;

	//Initialize the different types of monsters in the world
	monster_vect.push_back(new Player("Direwolf", 4, 1, 3, 3, 3));
	monster_vect.push_back(new Player("Swamp Cat", 6, 2, 7, 5, 5));
	monster_vect.push_back(new Player("Nettle Toad", 2, 1, 1, 1, 1));
	monster_vect.push_back(new Player("Dragon", 8, 5, 10, 8, 8));
}

World::~World()
{}

void World::give_gift(Player* user_in)
{
	//Random int between 0 and 999
	int prob = rand() % 1000;

	//Vector of gifts. First is exp, then gold, then hp. Use 
	vector<int> gifts;
	gifts.push_back(rand() % 100);
	gifts.push_back(rand() % 100);
	gifts.push_back(rand() %10);

	if (prob <= gift_density)
	{
		cout << "You look on the ground and see a half buried package. You peel back the wrapping and find ";

		int loc = rand() % 3;

		//item string
		string object;
		if (loc == 0)
		{
			object = " of experience.";
		}
		else if (loc == 1)
		{
			object = " of gold.";
		}
		else
		{
			object = " of hp.";
		}

		cout << gifts[loc] << object << endl;
	}
}

void World::battle(Player* oppo)
{
	bool user_dead = false;
	bool oppo_dead = false;
	bool ran = false;
	cout << "You've been attacked by a level " << oppo->get_level() << " " << oppo->get_name() << "! (Imagine Pokemon battle music)" << endl;

	do
	{
	cout << endl << "What would you like to do?" << endl;

	//Define the user's weapon
	string w_name = (user->get_inventory()->get_weapon()->get_name());
	int w_dam = (user->get_inventory()->get_weapon()->get_dam());

	cout << "   1 - Attack with your " << w_name << "!" << endl;
	cout << "   2 - Screw. That. I'm getting out of here." << endl;
	
	int choice;
	cin >> choice;
	cin.ignore(200, '\n');

	if (choice == 1)
	{
		cout << endl << "You attack the " << oppo->get_name() << " with your " << w_name << ". The " << oppo->get_name() << " takes "
			<< w_dam << " damage!" << endl;

		oppo->set_hp(oppo->get_hp() - w_dam);

		//Opposition attack, if it has health
		string oppo_w_name = (oppo->get_inventory()->get_weapon()->get_name());
		int oppo_w_dam = (oppo->get_inventory()->get_weapon()->get_dam());

		if (oppo->get_hp() > 0)
		{
			cout << "The " << oppo->get_name() << " strikes back at you! You take " << oppo_w_dam << " damage! ";

			//Calculate remaining player hp
			user->set_hp((user->get_hp()) - oppo_w_dam);

			if (user->get_hp() <= 0)
			{
				cout << "You dead! Try harder next time.";
				user_dead = true;
			}

			else
			{
				cout << "You have " << user->get_hp() << " HP remaining. Don't lose it all in one place!" << endl;
			}
		}
		else
		{
			oppo_dead = true;
		}
	}

	else if (choice == 2)
	{
		cout << "You turn and sprint, disgracing your family name. At least you survive for now." << endl << endl;
		ran = true;
	}
	}
	while (oppo_dead == false && user_dead == false && ran == false);

	//Check who won and divy up the spoils
	if (user_dead)
	{
		cout << "You have been revived. As you prop yourself up from the pool of your own blood you realize that you're coinpurse now lays besides you, empty. "
			<< "You have a feeling that you've lost all progress towards a previous goal. The good news is that someone doesn't want you dead...yet." << endl;
		user->set_exp(0);
		user->set_gold(0);
		//user->set_hp((10 + 3 * (user->get_level() - 1)));
		user->set_hp(user->get_max_hp());
	}
	else if (oppo_dead)
	{
		cout << "You have defeated the " << oppo->get_name() << "! You loot the body to find " << oppo->get_gold() << " gold, it'll be more use to you anyway."
			<< "You feel in your dark bruises and in your gushing blisters that you're improving, an intangible skill grows piece by piece." << endl;
		user->set_exp(user->get_exp() + oppo->get_exp());
		user->level_up();
		user->set_gold(user->get_gold() + oppo->get_gold());
	}
}

bool World::update()
{
	//Bool to tell game to quit
	bool quit = false;

	//Each turn starts by prompting the user what to do
	char choice = user->action();

	//Now decide what methods to call
	//Travel
	if (choice == 't')
	{
		user->take_step();

		//Now determine if events occur
		//Check for battle
		if (rand() % 100 < enemy_density)
		{
			//Initialize opponent. Select randomly from monster_vect.
			Player* monster_ptr = monster_vect[rand() % monster_vect.size()];

			//battle
			battle(monster_ptr);

			//Cleanup
			delete monster_ptr;
		}
	}

	//View Inventory
	else if (choice == 'i')
	{
		user->view_inventory();
	}

	//View attributes
	else if (choice == 'a')
	{
		user->view_attributes();
	}

	//View Map
	else if (choice  == 'm')
	{
		user->view_map();
	}

	//Save
	else if (choice == 's')
	{
		save->write_save(player);
		cout << "You have successfully saved your game!" << endl;
	}
	//Quit
	else if (choice == 'q')
	{
		//Have this fucntion return bool saying to stop.
		quit = true;
	}

	return quit;
}