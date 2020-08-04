#pragma once
#include <conio.h>	// for _getch() input
#include <vector>
#include "constants.h"
#include "room.h"
#include "item.h"

class Entity	// The player, all enemies, and items, like equipment and warp tiles are an entity
{
public:
	short x;
	short y;
	short xVel;
	short yVel;
	char sprite;

	int entityType; //creature, tile, item
	int idValue; // enemy id value, tile value, 
	bool isItem;

	short entityVectorElement;

protected:
	std::string name;

public:
	std::string getName() const;
	Entity(std::vector<Entity*>& e, short xp, short yp, bool it, short i, short v);
	Entity();
	~Entity();
};