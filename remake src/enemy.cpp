#include "enemy.h"

Enemy::Enemy(std::vector<Entity*>& e, int xp, int yp)
{
	sprite = 'e';
	x = xp;
	y = yp;

	e.push_back(this);
}

int Enemy::calculateNextMove(Floor& f, std::vector<Entity*>& e)
{
	return 0;
}

void Enemy::tick(Floor& f, std::vector<Entity*>& e)
{
}