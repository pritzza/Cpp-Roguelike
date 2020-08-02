#include "enemy.h"

Enemy::Enemy(std::vector<Entity*>& e, std::vector<Creature*>& c, int xp, int yp, int i)
{
	sprite = 'e';
	x = xp;
	y = yp;
	id = i;

	setEnemy();

	e.push_back(this);
	c.push_back(this);
}

Enemy::~Enemy()
{
	delete this;
}

void Enemy::setEnemy()
{
	switch (id)
	{
	case (0):
		name = "Rat";

		break;
	}
}

void Enemy::calculateNextMove(std::vector<Entity*>& e) // will need to take in parameters for surroundings eventually
{
	short move;

	switch (ai)
	{
	case(0):
		// pick move in random direction or stand still (1/5 all)
		move = rand() % 5;

		if (move == 0)		 { yVel = -1; }
		else if (move == 1)	 { yVel = 1; }
		else if (move == 2)	 { xVel = 1; }
		else if (move == 3)  { xVel = -1; }

		break;

	default:
		break;
	}
}

void Enemy::tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r)
{
	calculateNextMove(e);
	move(e, c, m, r[0]);
}