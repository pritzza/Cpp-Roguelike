#pragma once

#include "creature.h"

class Enemy : public Creature
{
private:
	bool isHostile;

private:
	int calculateNextMove(Floor& f, std::vector<Entity*>& e);

public:
	void tick(Floor& f, std::vector<Entity*>& e);
	Enemy(std::vector<Entity*>& e, int xp, int yp);
};