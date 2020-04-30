#include "enemy.h"

void enemyTick(char map[][consoleWidth], std::vector<Enemy>* enemies, Player* p)
{
	for (int i = 0; i < (*enemies).size(); i++)
	{
		if ((*enemies)[i].symbol != '*')
		enemyInput(map, &(*enemies)[i], p, enemies);
	}
}

void walkToPlayer(char map[][consoleWidth], Enemy* enemy, Player* p, std::vector<Enemy>* enemies)
{
	int h = p->x - enemy->x;
	int v = p->y - enemy->y;

	if (h < 0 && v < 0)
	{
		if (h < v)
			(*enemy).prevInput = enemyMove(map, enemy, p, -1, 0, enemies);
		if (v < h)
			(*enemy).prevInput = enemyMove(map, enemy, p, 0, -1, enemies);
	}
	else if (0 < h && 0 < v)
	{
		if (v < h)
			(*enemy).prevInput = enemyMove(map, enemy, p, 1, 0, enemies);
		if (h < v)
			(*enemy).prevInput = enemyMove(map, enemy, p, 0, 1, enemies);
	}
	else if (h < 0 && 0 < v)
	{
		if (v < -h)
			(*enemy).prevInput = enemyMove(map, enemy, p, -1, 0, enemies);
		if (-h < v)
			(*enemy).prevInput = enemyMove(map, enemy, p, 0, 1, enemies);
	}
	else if (0 < h && v < 0)
	{
		if (-v < h)
			(*enemy).prevInput = enemyMove(map, enemy, p, 1, 0, enemies);
		if (h < -v)
			(*enemy).prevInput = enemyMove(map, enemy, p, 0, -1, enemies);
	}
	else if (0 == h && v < 0)
	{
		(*enemy).prevInput = enemyMove(map, enemy, p, 0, -1, enemies);
	}
	else if (0 == h && v > 0)
	{
		(*enemy).prevInput = enemyMove(map, enemy, p, 0, 1, enemies);
	}
	else if (0 == v && h < 0)
	{
		(*enemy).prevInput = enemyMove(map, enemy, p, -1, 0, enemies);
	}
	else if (0 == v && h > 0)
	{
		(*enemy).prevInput = enemyMove(map, enemy, p, 1, 0, enemies);
	}
}

void enemyInput(char map[][consoleWidth], Enemy* enemy, Player* p, std::vector<Enemy>* enemies)
{
	if (p->x - enemy->x < enemy->vision && p->x - enemy->x > -enemy->vision && p->y - enemy->y < enemy->vision && p->y - enemy->y > -enemy->vision)
	{
			walkToPlayer(map, enemy, p, enemies);
	}
	else
	{
		int direction = rand() % 4;

		if (direction == 0)
			(*enemy).prevInput = enemyMove(map, enemy, p, 0, -1, enemies);
		else if (direction == 1)
			(*enemy).prevInput = enemyMove(map, enemy, p, -1, 0, enemies);
		else if (direction == 2)
			(*enemy).prevInput = enemyMove(map, enemy, p, 0, 1, enemies);
		else if (direction == 3)
			(*enemy).prevInput = enemyMove(map, enemy, p, 1, 0, enemies);
		else
			(*enemy).prevInput = (*enemy).prevInput;
	}
}

//bool collide(char map[][consoleWidth], Enemy* e, int x, int y)
//{
//	if (map[e->y + y][e->x + x] == '#' || map[e->y + y][e->x + x] == ' ' || map[e->y + y][e->x + x] == 'M' || map[e->y + y][e->x + x] == '&')
//		return true;
//	return false;
//}

char enemyMove(char map[][consoleWidth], Enemy* e, Player* p, int x, int y, std::vector<Enemy>* enemies)
{
	if (map[e->y + y][e->x + x] != '#' && map[e->y + y][e->x + x] != ' ') 
	{
		for (int i = 0; i < (*enemies).size(); i++)
			if (e->x + x == (*enemies)[i].x && e->y + y == (*enemies)[i].y)		// Enemy cant overlap enemy
				return e->prevInput;

		if (e->x + x == p->x && e->y + y == p->y)		// Enemy cant overlap player
		{
			e->attack(p);
			return e->prevInput;
		}

		e->x = e->x + x;
		e->y = e->y + y;
		map[e->y - y][e->x - x] = e->prevInput;

		return map[e->y][e->x];
	}
	else
		return e->prevInput;
}


//&& map[e->y + y][e->x + x] != '&')