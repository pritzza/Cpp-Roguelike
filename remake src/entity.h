#pragma once
#include <conio.h>	// for _getch() input
#include <vector>
#include "constants.h"
#include "room.h"
#include "item.h"

class Entity	// The player, all enemies, and items, like equipment and warp tiles are an entity
{
public:
	short x{ 0 };
	short y{ 0 };
	short xVel{ 0 };
	short yVel{ 0 };
	char sprite;

	int entityType; //creature, tile, item
	int idValue; // enemy id value, tile value, 
	bool isItem;

	short entityVectorElement;

protected:
	std::string name;

public:
	std::string getName() const;
	Entity(std::vector<Entity*>& e, const short xp, const short yp, const bool it, const short i, const short v);
	Entity();
	~Entity();
};