#include "floor.h"

Floor::Floor()
{
	fillFloor(' ');
	createFloor();
}

void Floor::fillFloor(char c)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
		for (int x = 0; x < MAP_WIDTH; x++)
			map[y][x] = c;
}

void Floor::createFloor()
{
	numRooms = 0;
	short roomsInFloor = rand() % (minRoomsPerFloor) + maxRoomsPerFloor - minRoomsPerFloor;
	for (int i = 0; i < roomsInFloor; i++)
		addRoom();

	for (int i = 0; i < MAP_HEIGHT + 1; i++)
		std::cout << std::endl;
	std::cout << numRooms << roomsInFloor;

	pathRooms();
}

void Floor::pathRooms()
{
	short cxs, cxe, cys, cye;	// center x/y of starting and ending rooms
	std::vector<Room>& r = rooms;

	for (int i = 0; i < rooms.size() - 1; i++)
	{


	}
}

void Floor::drawPath( )
{

}

void Floor::addRoom()
{
	Room room(rooms, numRooms);		// Creates a room object which takes in the vector for the other rooms of the floor

	bool isNotValid = room.isRoomOverlapping(rooms);
	
	if (isNotValid == false)
	{
		rooms.push_back(room);	// Adds this room to the vector of rooms

		int roomStartX = rooms[numRooms].x;
		int roomEndX = roomStartX + rooms[numRooms].width;

		int roomStartY = rooms[numRooms].y;
		int roomEndY = roomStartY + rooms[numRooms].height;

		numRooms++;

		// Creatues box around room
		for (int x = roomStartX; x < roomEndX; x++)
			for (int y = roomStartY; y < roomEndY; y++)
				map[y][x] = room.wallTile;

		// Fills box with floor tiles
		for (int x = roomStartX + 1; x < roomEndX - 1; x++)
			for (int y = roomStartY + 1; y < roomEndY - 1; y++)
				map[y][x] = room.floorTile;

		map[roomStartY][roomStartX] = static_cast<char>(room.id + 65);
	}
}