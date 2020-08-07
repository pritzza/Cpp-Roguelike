#pragma once

#include <cstdlib> 
#include <ctime> 
#include "screen.h"

class Game
{
private:
	short gameState{ 0 };
	bool running;
	char input;
	bool debugMode{ true };

	Screen screen;
	Floor floor;

	std::vector<Entity*> entities;
	std::vector<Creature*> creatures;

	Player player { entities, creatures };

private:
	void tick();
	void progressFloor();
	void handleInput();
	void clearEntities(bool savePlayer);
	void reset();

public:
	void start();

public:
	Game();

};