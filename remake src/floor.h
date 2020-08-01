#pragma once

#include "constants.h"
#include "room.h"

class Floor
{
private:
	std::vector<Room> rooms;
	const short minRoomsPerFloor = 3;
	const short maxRoomsPerFloor = 3;
	
private:
	void fillFloor(char c);
	void addRoom();
	void pathRooms();
	void drawPath(char d, int x, int y);
	
public:
	short level;

	char map[MAP_HEIGHT][MAP_WIDTH];
	short numRooms;

public:
	void createFloor();
	std::vector<Room>& getRooms();
	Room& getRoom(int id);

public:
	Floor();
};