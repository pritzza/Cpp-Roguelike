#pragma once

#include "constants.h"
#include "enemy.h"

class Floor
{
private:
	std::vector<Room> rooms;
	const short minRoomsPerFloor = 3;
	const short maxRoomsPerFloor = 3;
	
private:
	void fillFloor(const char c);
	void addRoom();
	void pathRooms();
	void drawPath(const char d, const int x, const int y);
	void spawnRoomContents(std::vector<Entity*>& e, std::vector<Creature*>& c);
	
public:
	short floorLevel;

	char map[MAP_HEIGHT][MAP_WIDTH];

	short numRooms;

public:
	void createFloor(std::vector<Entity*>& e, std::vector<Creature*>& c);
	std::vector<Room>& getRooms();
	Room& getRoom(const int id);

public:
	Floor();
};