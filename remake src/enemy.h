#pragma once

#include "creature.h"

class Enemy : public Creature
{
private:
	bool isHostile;
	short ai;

private:
	void calculateNextMove(std::vector<Entity*>& e); // will need to take in parameters for surroundings eventually
	void setEnemy();

public:
	void tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r);
	Enemy(std::vector<Entity*>& e, std::vector<Creature*>& c, int xp, int yp, int i);
	~Enemy();
};