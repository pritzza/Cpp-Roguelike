#pragma once

#include "creature.h"

class Enemy : public Creature
{
private:
	bool isHostile;
	short ai;

private:
	void calculateNextMove(Floor& f, std::vector<Entity*>& e);
	void setEnemy();

public:
	void tick(Floor& f, std::vector<Entity*>& e, std::vector<Creature*>& c);
	Enemy(std::vector<Entity*>& e, std::vector<Creature*>& c, int xp, int yp, int i);
	~Enemy();
};