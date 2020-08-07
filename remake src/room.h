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
	static const char wallTile = '#';
	//static const char wallTile2;	// Multiple tiles for looks
	static const char floorTile = '.';
	static const char doorTile = '>';
	static const char pathTile = ':';

public:
	void generateRoomShape();
	bool isRoomOverlapping(const std::vector<Room> r);

public:
	Room(std::vector<Room> rooms, int n);
};