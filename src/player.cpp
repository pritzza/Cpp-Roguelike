#include "player.h"

char prevInput = '.';

char playerMove(char map[][consoleWidth], Player* p, int x, int y, std::vector<Enemy>* enemies)
{
	if (map[p->y + y][p->x + x] != '#' && map[p->y + y][p->x + x] != ' ' && map[p->y + y][p->x + x] != 'M')
	{
		p->x = p->x + x;
		p->y = p->y + y;
		map[p->y - y][p->x - x] = prevInput;

		// make new collision function

		if (prevInput == 'A')
			newLevel();
		if (prevInput == '^')
		{
			p->HP += 5;
			prevInput = '.';
			map[p->y-y][p->x-x] = prevInput;
		}
		return map[p->y][p->x];
	}
	else
		if (map[p->y + y][p->x + x] == 'M')		// player collides with enemy
		{
			for (int i = 0; i < (*enemies).size(); i++)
			{
				if ((*enemies)[i].x == p->x + x && (*enemies)[i].y == p->y + y)
				{
					p->attack(&(*enemies)[i]);
				}
			}
		}
	return prevInput;
}

void takePlayerInput(char map[][consoleWidth], Player* p, std::vector<Enemy>* enemies)
{
	if (p->HP <= 0)
	{

		alive = false;
		prevInput = '.';
		startMenu();
	}
	else
	{
		char input;
		input = _getch();

		// Movement and collision: checks if # is blocking the direction of where you want to go
		if (input == 'w')
			prevInput = playerMove(map, p, 0, -1, enemies); // prevInput global char
		if (input == 'a')
			prevInput = playerMove(map, p, -1, 0, enemies);
		if (input == 's')
			prevInput = playerMove(map, p, 0, 1, enemies);
		if (input == 'd')
			prevInput = playerMove(map, p, 1, 0, enemies);
		if (input == ' ')
			startMenu();
	}
}