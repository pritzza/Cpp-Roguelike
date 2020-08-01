
#include "creature.h"

Creature::Creature()
{
	name = "Mambo";
}

short Creature::getSight() const
{
	return sight;
}

void Creature::move(Floor f, std::vector<Entity*> e)
{
	updateDirection();

	if (checkForCreatureCollision(e))
		;	//attack
	else if (checkForTileCollision(f) == false)
	{
		x += xVel;
		y += yVel;
	}
	xVel = 0;
	yVel = 0;
}

void Creature::updateDirection()
{
	if (xVel || yVel)	// if your velocity isnt 0, change direction
	{
		if (yVel < 0)
			direction = 0; 	// North
		else if (yVel > 0)
			direction = 1;	 // South
		else if (xVel > 0)
			direction = 2;	 // East
		else if (xVel < 0)
			direction = 3;	 // West
	}
}

bool Creature::checkForTileCollision(Floor& f)
{
	// checks the tile you're going to move to
	char next = f.map[y + yVel][x + xVel];

	if (next == f.getRoom(0).wallTile || next == ' ')
		return true;

	return false;
}
bool Creature::checkForCreatureCollision(std::vector<Entity*>& e)
{
	//iterate through entities to see if anthing collides
	//	if they do, attack/interact depending on hostility
	return false;
}
