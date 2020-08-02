#include "floor.h"

Floor::Floor()
{
}

std::vector<Room>& Floor::getRooms()
{
	return rooms;
}

Room& Floor::getRoom(int id)
{
	return rooms[id];
}

void Floor::fillFloor(char c)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
		for (int x = 0; x < MAP_WIDTH; x++)
			map[y][x] = c;
}

void Floor::createFloor(std::vector<Entity*>& e, std::vector<Creature*>& c)
{
	fillFloor(' ');
	rooms.clear();
	numRooms = 0;

	short roomsInFloor = rand() % (maxRoomsPerFloor - minRoomsPerFloor + 1) + minRoomsPerFloor;
	for (int i = 0; i < roomsInFloor; i++)
		addRoom();

	// garbage debug for how many rooms tried and actual room count
	//for (int i = 0; i < MAP_HEIGHT + 1; i++)
	//	std::cout << std::endl;
	//std::cout << numRooms << roomsInFloor;

	pathRooms();

	spawnRoomContents(e, c);
}

void Floor::spawnRoomContents(std::vector<Entity*>& e, std::vector<Creature*>& c)
{
	// goes through each room to see enemy composition of each one
	for (auto& r : rooms)
	{
		short minEnemies = 0;
		short maxEnemies = 2;
		short enemiesInRoom = rand() % (maxEnemies - minEnemies) + minEnemies;

		// Turn into function
		short chanceOfSwarm = 5;
		short isSwarm = rand() % chanceOfSwarm + 1;
		short swarmFactor = 3;

		if (isSwarm == chanceOfSwarm)
			enemiesInRoom *= swarmFactor;
		//

		// Spawns enemies
		for (int i = 0; i < enemiesInRoom; i++)
		{

			int xp = rand() % (r.width - 2) + r.x + 1;
			int yp = rand() % (r.height - 2) + r.y + 1;

			Enemy* enemy = new Enemy(e, c, xp, yp, 0);
		}
	}
}

void Floor::pathRooms()
{
	short cxr1, cxr2, cyr1, cyr2;	// (center x of r1) center x/y of starting and ending rooms, r1 and r2

	for (int i = 0; i < rooms.size() - 1; i++)
	{
		Room& r1 = rooms[i];		// the room we're starting the path
		Room& r2 = rooms[i + 1];	// the destination room of the path

		cxr1 = r1.x + r1.width / 2;
		cyr1 = r1.y + r1.height / 2;

		cxr2 = r2.x + r2.width / 2;
		cyr2 = r2.y + r2.height / 2;

		int path = cxr1;	// sets the path to the x center of r1

		// Go through and draw the horizontal part of the path first
		if (cxr1 <= cxr2)
			for (; path < cxr2; path++)
				drawPath('r', path, cyr1);
		else if (cxr1 > cxr2)
			for (path; path > cxr2; path--)
				drawPath('l', path, cyr1);

		path = cyr1;	// switch the path to the y center of r2

		// So that next the horizontal part of the path can be built
		if (cyr1 <= cyr2)
			for (; path < cyr2; path++)
				drawPath('d', cxr2, path);
		else if (cyr1 > cyr2)
			for (path; path > cyr2; path--)
				drawPath('u', cxr2, path);
	}
}

void Floor::drawPath(char d, int x, int y)
{
	// Actually draws the tiles to the map depending on the x/y of the path

	if (map[y][x] == rooms[0].wallTile)
		map[y][x] = rooms[0].doorTile;
	else if (map[y][x] == ' ')
		map[y][x] = rooms[0].pathTile;
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