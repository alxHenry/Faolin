//Alex Henry
//3/30/13 - initial start
//Text based RPG 'Faolin'

#include <iostream>
#include <string>
#include <ctime>
#include "Nonmember.h"
#include "Player.h"
#include "World.h"
#include "SaveFile.h"
using namespace std;


//Driver program for game, returns 0 if runs correctly
int main()
 {
	//Seed random number generator
	srand(time(NULL));

	//Create new SaveFile object to check for existing saves and to be used to save
	SaveFile* save = new SaveFile();

	//Display mainmenu and allow for load or new game. Player returned by the function is the user's player
	Player* user_ptr = mainmenu(save);

	//Initialize the world
	World my_world(30, 10, user_ptr, user_ptr, save);
	
	//Call World::update(), the function that plays the game
	while(!my_world.update())
	{}

	cin.ignore(200, '\n');
	cin.ignore(200, '\n');
	return 0;
}