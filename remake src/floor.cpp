#include "floor.h"

Floor::Floor()
{
}

std::vector<Room>& Floor::getRooms() { return rooms; }

Room& Floor::getRoom(const int id) { return rooms[id]; }

// Fills the map[][] of the floor with a char to overwrite/erase the information on the previous floor
void Floor::fillFloor(const char c)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
		for (int x = 0; x < MAP_WIDTH; x++)
			map[y][x] = c;
}

void Floor::createFloor(std::vector<Entity*>& e, std::vector<Creature*>& c)
{
	fillFloor(' ');	// resets map[][]
	rooms.clear();	// removes all rooms from vector
	numRooms = 0;

	short roomsInFloor = rand() % (maxRoomsPerFloor - minRoomsPerFloor + 1) + minRoomsPerFloor;

	for (int i = 0; i < roomsInFloor; i++)
		addRoom();

	pathRooms();
	spawnRoomContents(e, c);

	// garbage debug for how many rooms tried and actual room count
	//for (int i = 0; i < MAP_HEIGHT + 1; i++)
	//	std::cout << std::endl;
	//std::cout << numRooms << roomsInFloor;
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

		// Spawns enemies
		for (int i = 0; i < enemiesInRoom; i++)
		{
			int xp = rand() % (r.width - 2) + r.x + 1;
			int yp = rand() % (r.height - 2) + r.y + 1;

			// Generate x and y coords for new entities so that they dont overlap with existing ones

			int creatureId = 1; // 0 is player, 1 is rat

			Enemy* enemy = new Enemy(e, c, xp, yp, 1, floorLevel);

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

		// Get the center tile of both rooms
		cxr1 = r1.x + r1.width / 2;
		cyr1 = r1.y + r1.height / 2;

		cxr2 = r2.x + r2.width / 2;
		cyr2 = r2.y + r2.height / 2;

		int path = cxr1;	// sets the path to the x center of r1, where we start

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

// Actually writes the chars to the map[][] depending on the x/y of the path
void Floor::drawPath(const char d, const int x, const int y)
{
	const Room& const r = rooms[0];

	// somehow make to switch statement
	if (map[y][x] == r.wallTile)
		map[y][x] = r.doorTile;
	else if (map[y][x] == ' ')
		map[y][x] = r.pathTile;
}

void Floor::addRoom()
{
	Room room(rooms, numRooms);		// Creates a room object which takes in the vector for the other rooms of the floor

	bool isNotValid = room.isRoomOverlapping(rooms);

	if (isNotValid == false)
	{
		rooms.push_back(room);	// Adds this room to the vector of rooms

		// The leftmost face of the room, starting at its x
		int leftFace = rooms[numRooms].x;
		int rightFace = leftFace + rooms[numRooms].width;

		// The leftmost face of the room, starting at its y
		int topFace = rooms[numRooms].y;
		int bottomFace = topFace + rooms[numRooms].height;

		numRooms++;

		// Creatures rectangle of wall tiles around room
		for (int x = leftFace; x < rightFace; x++)
			for (int y = topFace; y < bottomFace; y++)
				map[y][x] = room.wallTile;

		// Fills box with floor tiles
		for (int x = leftFace + 1; x < rightFace - 1; x++)
			for (int y = topFace + 1; y < bottomFace - 1; y++)
				map[y][x] = room.floorTile;

		// Debug to be able to identify rooms visually by id
		//map[topFace][leftFace] = static_cast<char>(room.id + 'A');
	}
}