#pragma once

#include "constants.h"
#include "room.h"

class Floor
{
private:
	std::vector<Room> rooms;
	const short minRoomsPerFloor = 6;
	const short maxRoomsPerFloor = 9;
	
private:
	void fillFloor(char c);
	void createFloor();
	
public:
	char map[MAP_HEIGHT][MAP_WIDTH];
	short numRooms;

public:
	void addRoom();
	void pathRooms();
	void drawPath(char d, int x, int y);

public:
	Floor();
};