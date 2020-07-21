#pragma once
#include <stdlib.h>
#include <vector>
#include "constants.h"

class Room
{
public:
	short x;
	short y;
	short width;
	short height;
	short id = 0;
	char wallTile = '#';
	//char wallTile2;
	char floorTile = '.';

public:
	void generateRoomShape();
	bool isRoomOverlapping(std::vector<Room> r);

public:
	Room(std::vector<Room> rooms, int n);
};