
#include "creature.h"

Creature::Creature()
{
}

void Creature::tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r, std::vector<Event*>& ev)
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
short Creature::getLevel() const
{
	return level;
}
short Creature::getExperience() const
{
	return experience;
}
short Creature::getMaxExp() const
{
	return maxExp;
}

void Creature::move(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const Room& r, std::vector<Event*>& ev)
{
	updateDirection();

	// mobNum is the foe creature being collided with
	int mobNum = checkForCreatureCollision(c); // return -1 if no enemies collide

	// include item collusion and special tile collsiion of sorts here
	if (mobNum != -1)
	{
		fight(c[mobNum], ev);
	}
	else if (checkForTileCollision(m, r) == false)
	{
		x += xVel;
		y += yVel;
	}

	xVel = 0;
	yVel = 0;

	if (health <= 0)
		die(e, c, ev, mobNum);
}

void Creature::fight(Creature* opponent, std::vector<Event*>& ev)
{
	short damage = this->attack - opponent->defense;

	if (this->creatureVectorElement == 0)	// If you're the player, and you attempt to attack an enemy
		opponent->attackedByPlayer = true;

	if (damage <= 0)
	{
		Event* miss = new Event{ ev, 1, 0, opponent->getName(), this->getName() };	// miss
	}
	else
	{
		opponent->health -= damage;
		Event* miss = new Event{ ev, 2, damage, opponent->getName(), this->getName() };	// successful attack
	}
}

void Creature::levelUp(std::vector<Event*>& ev) 
{
	experience %= maxExp;
	maxExp *= 1.5;

	health++;
	maxHealth++;
	attack++;
	defense++;

	level++;

	Event* levelUp = new Event{ ev, 4, level, "", this->getName() };
}

void Creature::gainExperience(Creature* o, std::vector<Event*>& ev)
{
	short expGained = ((o->maxHealth + o->attack + o->defense) * level / 10) + 1;

	experience += expGained;

	Event* gainExp = new Event{ ev, 3, expGained, "", this->getName() };

	if (experience >= maxExp)
		levelUp(ev);
}

// Dies to player
void Creature::die(std::vector<Entity*>& e, std::vector<Creature*>& c, std::vector<Event*>& ev, int mobNum)
{
	Event* die = new Event{ ev, 0, 0, this->getName(), "" };

	if (attackedByPlayer)	// If this creature was attacked by the player, give the player exp
	{
		c[0]->gainExperience(this, ev);
	}

	if (entityVectorElement != 0 || creatureVectorElement != 0)	// dont delete the player from the vectorsw
	{
		Entity* goldDrop = new Entity{ e, x, y, true, 3, this->gold };

		deleteFromVectors(e, c);
	}
}

void Creature::deleteFromVectors(std::vector<Entity*>& e, std::vector<Creature*>& c)
{
	e.erase(e.begin() + entityVectorElement);
	c.erase(c.begin() + creatureVectorElement);

	for (int i = entityVectorElement; i < e.size(); i++)
		e[i]->entityVectorElement--;

	for (int i = creatureVectorElement; i < c.size(); i++)
		c[i]->creatureVectorElement--;

	delete this;

	e.shrink_to_fit();
	c.shrink_to_fit();
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

bool Creature::checkForTileCollision(const char m[MAP_HEIGHT][MAP_WIDTH], const Room& r)
{
	// checks the tile you're going to move to
	char next = m[y + yVel][x + xVel];

	if (next == r.wallTile || next == ' ')
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
