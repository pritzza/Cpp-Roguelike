#pragma once

#include "creature.h"

class Enemy : public Creature
{
private:
	bool isHostile;
	bool willAttackSame;
	short ai;

private:
	void calculateNextMove(std::vector<Entity*>& e); // will need to take in parameters for surroundings eventually
	void setEnemy(short fl);

public:
	void tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r, std::vector<Event*>& ev);
	Enemy(std::vector<Entity*>& e, std::vector<Creature*>& c, int xp, int yp, int i, short fl);
	~Enemy();
};