#include "entity.h"
#include <iostream>

void Entity::tick()
{

}

Creature::Creature()
{
	name = "Mambo";
}

void Creature::move()
{
	if (checkForCreatureCollision())
		;	//attack
	else if (checkForTileCollision() == false)
	{
		x += xVel;
		y += yVel;
		xVel = 0;
		yVel = 0;
	}
}

bool Creature::checkForTileCollision()
{
	return false;
}
bool Creature::checkForCreatureCollision()
{
	//iterate through entities to see if anthing collides
	//	if they do, attack/interact depending on hostility
	return false;
}

Player::Player()
{
	name = "You";
	sprite = '&';
}

void Player::getInput()
{
	char input;
	input = _getch();

	if (input == 'w')
		yVel = -1;
	else if (input == 's')
		yVel = 1;
	else if (input == 'a')
		xVel = -1;
	else if (input == 'd')
		xVel = 1;
}

void Player::tick()
{
	getInput();
	move();
}

Enemy::Enemy()
{

}

int Enemy::calculateNextMove()
{
	return 0;
}

void Enemy::tick()
{

}