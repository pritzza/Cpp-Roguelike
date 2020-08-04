#include "entity.h"
#include <iostream>

Entity::Entity() {}

Entity::Entity(std::vector<Entity*>& e, short xp, short yp, bool it, short i, short v)
{
	x = xp;
	y = yp;
	xVel = 0;
	yVel = 0;
	isItem = it;
	entityType = i;
	idValue = v;
}

Entity::~Entity()
{
	//delete this;
}

std::string Entity::getName() const
{
	return name;
}