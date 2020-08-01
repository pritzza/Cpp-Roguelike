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
	const char wallTile = '#';
	//const char wallTile2;
	const char floorTile = '.';
	const char doorTile = '>';
	const char pathTile = ':';

public:
	void generateRoomShape();
	bool isRoomOverlapping(const std::vector<Room> r);

public:
	Room(std::vector<Room> rooms, int n);
};