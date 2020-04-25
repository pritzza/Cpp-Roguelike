#include "player.h"

char prevInput = '.';

char playerMove(char map[][consoleWidth], Player* p, int x, int y)
{
	if (map[p->y + y][p->x + x] != '#' && map[p->y + y][p->x + x] != ' ')
	{
		p->x = p->x + x;
		p->y = p->y + y;
		map[p->y - y][p->x - x] = prevInput;
		return map[p->y][p->x];
	}
	else
		return prevInput;
}

int move(char map[][consoleWidth], Player* p, int toggle)
{
	char input;
	input = _getch();

	// Movement and collision: checks if # is blocking the direction of where you want to go
	if (input == 'w')
	{
		prevInput = playerMove(map, p, 0, -1); // prevInput global char
	}
	if (input == 'a')
	{
		prevInput = playerMove(map, p, -1, 0);
	}
	if (input == 's')
	{
		prevInput = playerMove(map, p, 0, 1);
	}
	if (input == 'd')
	{
		prevInput = playerMove(map, p, 1, 0);
	}
	if (input == ' ')
	{
		// clearCanvas()
		//	generateFloor();
	}
	if (input == 'q')
	{
		return (toggle + 1) % 2;
	}
	return toggle;
}