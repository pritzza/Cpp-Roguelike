#pragma once

#include "entity.h"

class Creature : public Entity	// Every living thing, player, enemies, NPCs are creatures
{
protected:
	short xVel;
	short yVel;

	std::vector<Item> equipment;
	std::string name;
	short health;
	short maxHealth;
	short attack;
	short defense;
	short gold;

	short sight = 1;
	short direction = 0;
	//Maybe speed, magic, and some other cool stats

protected:
	void updateDirection();
	void move(Floor f, std::vector<Entity*> e);
	bool checkForTileCollision(Floor& f);
	bool checkForCreatureCollision(std::vector<Entity*>& e);

public:
	short getSight() const;

public:
	Creature();
};
