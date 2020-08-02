#pragma once

#include "entity.h"

class Creature : public Entity	// Every living thing, player, enemies, NPCs are creatures
{
protected:
	std::vector<Item> equipment;
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
	void fight(Creature* c);
	void move(Floor& f, std::vector<Entity*>& e, std::vector<Creature*>& c);
	bool checkForTileCollision(Floor& f);
	int checkForCreatureCollision(std::vector<Creature*>& c);

public:
	void virtual tick(Floor& f, std::vector<Entity*>& e, std::vector<Creature*>& c);

	short getSight() const;
	short getHealth() const;
	short getMaxHealth() const;
	short getAttack() const;;
	short getDefense() const;
	short getDirection() const;

public:
	Creature();
};
