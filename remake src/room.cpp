#include "room.h"

Room::Room(std::vector<Room> rooms, int num)
{
	const unsigned short maxNumAttemptsAtRoom = 20;
	short attemptsToMakeRoom = 0;

	do {
		generateRoomShape();
		attemptsToMakeRoom++;
	}
	while (isRoomOverlapping(rooms) && attemptsToMakeRoom < maxNumAttemptsAtRoom);

	id = num;

	//generateRoomContents();
}

void Room::generateRoomShape()
{
	int minW { 3 + MAP_WIDTH / 12 };
	int minH { 3 + MAP_HEIGHT / 12 };
	int wRange { minW };
	int hRange { minH };

	width = rand() % wRange + minW;		// generates a random number for width/height
	height = rand() % hRange + minH;
	
	x = rand() % (MAP_WIDTH - width);	// places room anywhere between the width/height of the screen, minus the rooms width/height
	y = rand() % (MAP_HEIGHT - height);
}

bool Room::isRoomOverlapping(const std::vector<Room> r)
{
	for (int i = 0; i < r.size(); i++)	// goes through every existing room on the floor to check if any corners are inside
	{	
		if ((x >= r[i].x && x <= r[i].x + r[i].width) ||

			(x + width >= r[i].x && x + width <= r[i].x + r[i].width) ||

			(x <= r[i].x && x + width >= r[i].x + r[i].width) ||

			(x == r[i].x || x + width == r[i].x + r[i].width))

			if ((y >= r[i].y && y <= r[i].y + r[i].height) ||

				(y + height >= r[i].y && y + height <= r[i].y + r[i].height) ||

				(y <= r[i].y && y + height >= r[i].y + r[i].height) ||

				(y == r[i].y || y + height == r[i].y + r[i].height))

				return true;
	}
	return false;
}