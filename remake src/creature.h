#pragma once

#include "entity.h"

class Creature : public Entity	// Every living thing, player, enemies, NPCs are creatures
{
protected:
	std::vector<Item> equipment;
	short health{ 1 };
	short maxHealth{ 1 };
	short attack{ 1 };
	short defense{ 1 };
	short gold{ 0 };

	short level{ 0 };
	short experience{ 0 };
	short maxExp{ 3 };
	bool attackedByPlayer{ false };

	short sight{ 1 };
	short direction{ 0 };
	//Maybe speed, magic, and some other cool stats

	short creatureVectorElement;

protected:
	void gainExperience(const Creature* o, std::vector<Event*>& ev);
	void levelUp(std::vector<Event*>& ev);
	//void die(std::vector<Entity*>& e, std::vector<Creature*>& c, std::vector<Event*>& ev);
	void die(std::vector<Entity*>& e, std::vector<Creature*>& c, std::vector<Event*>& ev, int mobNum);
	void deleteFromVectors(std::vector<Entity*>& e, std::vector<Creature*>& c);
	void updateDirection();
	void fight(Creature* c, std::vector<Event*>& ev);
	void move(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const Room& r, std::vector<Event*>& ev);
	bool checkForTileCollision(const char m[MAP_HEIGHT][MAP_WIDTH], const Room& r);
	int checkForCreatureCollision(const std::vector<Creature*>& c);

public:
	void virtual tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r, std::vector<Event*>& ev);

	short getSight() const;
	short getHealth() const;
	short getMaxHealth() const;
	short getAttack() const;;
	short getDefense() const;
	short getDirection() const;
	short getLevel() const;
	short getExperience() const;
	short getMaxExp() const;

public:
	Creature();
};
