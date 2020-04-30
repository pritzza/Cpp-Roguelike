#include "renderer.h"

bool inside(Room room, Player p)
{
	if (room.x < p.x && p.x < room.x + room.width && room.y < p.y && p.y < room.y + room.height)
		return true;
	return false;
}

void getPlayerVision(char masterMap[][consoleWidth], Player* p, std::vector<Room> r_list)
{
	for (int i = 0; i < consoleHeight; i++)
		for (int j = 0; j < consoleWidth; j++)
			if (visibleMap[i][j] != '#' && visibleMap[i][j] != '>')				// Sets everything that isnt a door or wall to a blank space in players map
				visibleMap[i][j] = ' ';

	for (int i = p->y - 1; i < p->y + 2; i++)
		for (int j = p->x - 1; j < p->x + 2; j++)
			visibleMap[i][j] = masterMap[i][j];

	for (auto &r: r_list)												// Goes through floor's room list to see if player x,y are inside any room,
		if (inside(r, *p))												// if player is inside, reveal and draw entire room.
			for (int x = r.x; x < r.x + r.width; x++)
				for (int y = r.y; y < r.y + r.height; y++)
					visibleMap[y][x] = masterMap[y][x];
}

void drawRoom(char masterMap[][consoleWidth], Player* p, std::vector<Room> r_list, std::vector<Enemy> e_list)     // Can be [][x] or [y][x], not [][] or [y][]
{
	masterMap[p->y][p->x] = p->symbol;

	for (auto &e : e_list)
	{
		masterMap[e.y][e.x] = e.symbol;
	}

	getPlayerVision(masterMap, p, r_list);

	std::string mapString;

	for (int i = 0; i < consoleHeight; i++)
		for (int j = 0; j < consoleWidth; j++)
			mapString += visibleMap[i][j];// put masterMap or visibleMap		// player vison

	std::cout << mapString << std::endl;
}