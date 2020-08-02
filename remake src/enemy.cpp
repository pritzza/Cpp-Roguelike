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

void Enemy::calculateNextMove(Floor& f, std::vector<Entity*>& e)
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

void Enemy::tick(Floor& f, std::vector<Entity*>& e, std::vector<Creature*>& c)
{
	calculateNextMove(f, e);
	move(f, e, c);
}