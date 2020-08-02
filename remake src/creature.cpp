
#include "creature.h"

Creature::Creature()
{
	name = "Mambo";
}

void Creature::tick(Floor& f, std::vector<Entity*>& e, std::vector<Creature*>& c)
{

}

short Creature::getHealth() const
{
	return health;
}
short Creature::getMaxHealth() const
{
	return maxHealth;
}
short Creature::getAttack() const
{
	return attack;
}
short Creature::getDefense() const
{
	return defense;
}
short Creature::getDirection() const
{
	return direction;
}
short Creature::getSight() const
{
	return sight;
}

void Creature::move(Floor& f, std::vector<Entity*>& e, std::vector<Creature*>& c)
{
	updateDirection();

	int mobNum = checkForCreatureCollision(c);

	// include item collusion and special tile collsiion of sorts here
	if (mobNum != -1)
	{
		fight(c[mobNum]);
	}
	else if (checkForTileCollision(f) == false)
	{
		x += xVel;
		y += yVel;
	}
	xVel = 0;
	yVel = 0;
}

void Creature::fight(Creature* c)
{
	int damage = c->defense - attack;

	if (damage <= 0)
	{
		std::cout << std::endl << c->getName() << " attacked and missed " << getName() << '!';	//miss
	}
	else
	{
		c->health -= damage;
		std::cout << std::endl << c->getName() << " attacked " << getName() << " for " << damage << " damage!";	//attack
	}
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

int Creature::checkForCreatureCollision(std::vector<Creature*>& c)
{
	//iterate through entities to see if anthing collides
	//	if they do, attack/interact depending on hostility
	for (int i = 0; i < c.size(); i++)
	{
		if ((c[i]->x + c[i]->xVel == this->x + this->xVel && c[i]->y + c[i]->yVel == this->y + this->yVel) && this != c[i])
			return i;	// returns element number of enemy attacking
	}

	return -1;	// returns -1 if no element is attacking
}
