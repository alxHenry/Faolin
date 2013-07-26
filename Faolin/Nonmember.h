//Nomember functions

#ifndef NONMEMBER_H_INCLUDED
#define NONMEMBER_H_INCLUDED

#include <string>
#include "Character.h"
#include "Player.h"
#include "SaveFile.h"
using namespace std;

//Format the inventory into a string to use for saving
string format_inv(Inventory inv_in);

vector<string> split_string(string to_split, char delim);

//Displays main menu and offers a new game or load option. Returns the player to be used with the game
Player* mainmenu(SaveFile* save_in);

//Inititalizes a new game and displays the story opening. Returns the new player
Player* newgame();

#endif