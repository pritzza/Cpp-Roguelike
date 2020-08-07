#include "entity.h"
#include <iostream>

Entity::Entity() {}

std::string Entity::getName() const { return name; }

Entity::Entity(std::vector<Entity*>& e, const short xp, const short yp, const bool it, const short i, const short v)
{
	x = xp;
	y = yp;
	isItem = it;
	entityType = i;
	idValue = v;
}

Entity::~Entity()
{
	//delete this;
}