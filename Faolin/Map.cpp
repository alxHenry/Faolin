#include "Map.h"
#include <ctime>
#include <iostream>
using namespace std;

Map::Map(int x_in, int y_in)
{
	//Sets the map size
	MAP_SIZE_X = 40;
	MAP_SIZE_Y = 40;

	//Set the player's current position
	current_pos[0] = x_in;
	current_pos[1] = y_in;

	//Composition of various terrain phenomena
	static const double WATER_P = .15;			
	static const double MTN_P = .05;
	static const double RIVER_P = .70;			//Percentage of water in a river formation
	static const double LAKE_P = .30;			//Percentage of water in a lake formation
	static const double MTN_RANGE_P = .50;

	//First initialize the array, filling all coordinates with '.'
	map_array = new char* [MAP_SIZE_Y];

	for (int row = 0; row < MAP_SIZE_Y; row++)
	{
		map_array[row] = new char[MAP_SIZE_X];
		for (int col = 0; col < MAP_SIZE_X; col++)
		{
			//Fill the array
			map_array[row][col] = '.';
		}
	}

	//Set player location
	map_array[current_pos[1]][current_pos[0]] = 'X';

	/* 
	Fill the 2d array with chars to represent the randomly-generated terrain:
		'.' represents flatland
		'^' represents mountains (cannot be traversed)
		'~' represents water (cannot be traversed)

		Initial array is already filled with '.' so we must use an algortihm to salt in water and mountains.
	*/
	int water_quantity = (MAP_SIZE_X * MAP_SIZE_Y) * WATER_P;

	/*
				***Water Algorithm***

		Water needs to be grouped to be realistic. Lakes are squares. We will roll to determined if a placed
		lake has a river flowing into it. Rivers will be simple 2 wide water channel for simplicity at the
		moment. We first decide if 
	*/

	int water_placed = 0;
	while (water_quantity > water_placed)
	{
		int x = rand() % MAP_SIZE_X;
		int y = rand() % MAP_SIZE_Y;

		//Roll to see if a lake is placed
		if (rand() % 100 < (100 * LAKE_P))
		{
			for (int j = y; j < y + LAKE_SIDE; j++)
			{
				for (int i = x; i < x + 4; i++) 
				{
					if (pos_available(i, j)) 
					{
						map_array[j][i] = '~';
						water_placed++;
					}
				}
			}
		}

		//Roll to see if a river is placed
		if (rand() % 100 < (100 * RIVER_P))
		{
			/*
				orient == true  : Vertical flow
				orient == false : Horizontal Flow
			*/
			bool orient = false;

			//Decide orientation of river
			if (rand() % 100 < 50) {orient = true;}

			//Now do placement
			//!!!NEED TO MAKE SO IT USES RIVER_WIDTH TO PLACE VARIABLY!!!
			if (orient == true)
			{
				for (int j = 0; j < MAP_SIZE_Y; j++)
				{
					if (pos_available(x, j))
					{
						map_array[j][x] = '~';
						water_placed++;
					}
					if (pos_available(x + 1, j))
					{
						map_array[j][x + 1] = '~';
						water_placed++;
					}
				}
			}
			//orient == false : Horizontal
			else
			{
				for (int i = 0; i < MAP_SIZE_X; i++)
				{
					if (pos_available(i, y))
					{
						map_array[y][i] = '~';
						water_placed++;
					}
					if (pos_available(i, y + 1))
					{
						map_array[y + 1][i] = '~';
						water_placed++;
					}
				}
			}
		}
	}

	/*
				***Mountains Algorithm***
		Just place these randomly throughout the landscape. Then roll for chance of mountain range.
		Ranges will be 4 long for now.
	*/
	int mtns_quantity = (MAP_SIZE_X * MAP_SIZE_Y) * MTN_P;
	int mtns_placed = 0;
	while (mtns_placed < mtns_quantity)
	{
		int x = rand() % MAP_SIZE_X;
		int y = rand() % MAP_SIZE_Y;

		if (pos_available(x, y))
		{
			map_array[y][x] = '^';
			mtns_placed++;

			//If spot is available roll for mtn range
			if (rand() % 100 < (MTN_RANGE_P * 100))
			{
				//orient true is vertical
				bool orient = true;
				if (rand() % 100 < 50) {orient = false;}

				if (orient == true)
				{
					for (int j = y + 1; j < y + 4; j++)
					{
						if (pos_available(x, j))
						{
							map_array[j][x] = '^';
							mtns_placed++;
						}
					}
				}
				//horizontal
				else
				{
					for (int i = x + 1; i < x + 4; i++)
					{
						if (pos_available(i, y))
						{
							map_array[i][y] = '^';
							mtns_placed++;
						}
					}
				}
			}
		}
	}
}

void Map::view_map(int x, int y) const
{
	cout << endl;
	cout << "*********************************************** MAP ************************************************" << endl;
	cout << "****************************************************************************************************" << endl;
	for (int j = 0; j < MAP_SIZE_Y; j++)
	{
		for (int i = 0; i < MAP_SIZE_X; i++)
		{
			cout << map_array[j][i];
		}
		cout << endl;
	}
	cout << "****************************************************************************************************" << endl << endl;
}

bool Map::pos_available(int x, int y) const
{
	if (in_bounds(x, y) && is_water(x, y) == false && is_mtn(x, y) == false && is_player(x, y) == false) {return true;}
	return false;
}

void Map::update_pos(int x, int y) 
{
	//Set old pos back to '.' before moving player on map
	map_array[current_pos[1]][current_pos[0]] = '.';
	current_pos[0] = x;
	current_pos[1] = y;
	map_array[current_pos[1]][current_pos[0]] = 'X';
}

char Map::at_pos(int x, int y) const
{
	return map_array[y][x];
}

bool Map::in_bounds(int x, int y) const
{
	if (y < 0 || y > MAP_SIZE_Y - 1) {return false;}
	if (x < 0 || x > MAP_SIZE_X - 1) {return false;}
	return true;
}

bool Map::is_water(int x, int y) const
{
	if (at_pos(x, y) == '~') {return true;}
	return false;
}

bool Map::is_mtn(int x, int y) const
{
	if (at_pos(x, y) == '^') {return true;}
	return false;
}

bool Map::is_player(int x, int y) const
{
	if (at_pos(x, y) == 'X') {return true;}
	return false;
}