#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <vector>
using namespace std;

class Map
{
public:
	//Constructor takes in the current position of the player and the map size
	Map(int x_in, int y_in);
	~Map();

	//Displays the map to the user, takes in the current coordinates of the player and displays them at
	//the given position.
	void view_map(int x, int y) const;

	//Checks if a position is eligible of being traveled onto (not water, not mountain, in bounds). 
	//Returns a bool with the answer.
	bool pos_available(int x, int y) const;

	//Call this function after the player moves to update his position on the map. Moves the 'X' char to the new pos in the map_array
	//as well as resets the old one to '.' (because the player can only travel on '.' so that must be the previous contents of the square.
	void update_pos(int x, int y);

	//Return what character is at a location
	char at_pos(int x, int y) const;

	//Check if a space is out of bounds
	bool in_bounds(int x, int y) const;

private:
	//Helper functions
	//Check if a space is water
	bool is_water(int x, int y) const;

	//Check if a space is mountain
	bool is_mtn(int x, int y) const;

	//Check if player is at current spot
	bool is_player(int x, int y) const;

	char **map_array;
	int MAP_SIZE_X;
	int MAP_SIZE_Y;

	//Stores current pos of player so it can be marked
	int current_pos[2];

	//Had to move to a .cpp file because of C++ restrictions. It is in constructor now
	////Composition of various terrain phenomena
	//static const double WATER_P = .30;			
	//static const double MTN_P = .10;
	//static const double RIVER_P = .70;			//Percentage of water in a river formation
	//static const double LAKE_P = .30;			//Percentage of water in a lake formation
	//static const double MTN_RANGE_P = .50;

	//Terrain phenomena properties
	static const int LAKE_SIDE = 4;
	static const int RIVER_WIDTH = 2;
};

#endif