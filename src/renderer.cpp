#include "renderer.h"
#include <stdio.h>

char visibleMap[consoleHeight][consoleWidth];

bool inside(Room room, Player p)
{
	if (room.x < p.x && p.x < room.x + room.width && room.y < p.y && p.y < room.y + room.height)
		return true;
	return false;
}

void getPlayerVision(char masterMap[][consoleWidth], Player* p, Room* r_list)
{
	for (int i = 0; i < consoleHeight; i++)
		for (int j = 0; j < consoleWidth; j++)
			if (visibleMap[i][j] != '#' && visibleMap[i][j] != '>')				// Sets everything that isnt a door or wall to a blank space in players map
				visibleMap[i][j] = ' ';

	for (int i = p->y - 1; i < p->y + 2; i++)
		for (int j = p->x - 1; j < p->x + 2; j++)
			visibleMap[i][j] = masterMap[i][j];

	for (int i = 0; i < 10; i++)												// Goes through floor's room list to see if player x,y are inside any room,
		if (inside(r_list[i], *p))												// if player is inside, reveal and draw entire room.
			for (int x = r_list[i].x; x < r_list[i].x + r_list[i].width; x++)
				for (int y = r_list[i].y; y < r_list[i].y + r_list[i].height; y++)
					visibleMap[y][x] = masterMap[y][x];
}

void drawRoom(char masterMap[][consoleWidth], Player* p, Room* r_list, int toggle)     // Can be [][x] or [y][x], not [][] or [y][]
{
	getPlayerVision(masterMap, p, r_list);

	std::string mapString;

	for (int i = 0; i < consoleHeight; i++)
		for (int j = 0; j < consoleWidth; j++)
			if (toggle)
				mapString += visibleMap[i][j];		// player vison
			else
				mapString += masterMap[i][j];			// god vision

	std::cout << mapString << std::endl;
}