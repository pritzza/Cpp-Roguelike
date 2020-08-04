#include "enemy.h"

Enemy::Enemy(std::vector<Entity*>& e, std::vector<Creature*>& c, int xp, int yp, int i, short fl)
{
	sprite = 'e';
	x = xp;
	y = yp;
	idValue = i;
	entityType = 0;

	setEnemy(fl);

	e.push_back(this);
	entityVectorElement = e.size() - 1;

	c.push_back(this);
	creatureVectorElement = c.size() - 1;
}

Enemy::~Enemy()
{
	delete this;
}

void Enemy::setEnemy(short fl)
{
	switch (idValue)
	{
	case (1):	// idValue 0 is the player
		name = "Rat";
		ai = 0;
		isHostile = true;
		willAttackSame = false;

		health = 2;
		maxHealth = health;
		attack = 1;
		defense = 0;

		sprite = 'r';

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

		if (move == 0) { yVel = -1; }
		else if (move == 1) { yVel = 1; }
		else if (move == 2) { xVel = 1; }
		else if (move == 3) { xVel = -1; }

		break;

	default:
		break;
	}
}

void Enemy::tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r, std::vector<Event*>& ev)
{
	calculateNextMove(e);
	move(e, c, m, r[0], ev);
}