#pragma once

#include <cstdlib> 
#include <ctime> 
#include "screen.h"

class Game
{
private:
	bool running;
	Screen screen;
	Floor floor;

	std::vector<Entity*> entities;
	std::vector<Creature*> creatures;

	Player player { entities, creatures };

private:
	void tick();
	void progressFloor();
	void reset();

public:
	void start();

public:
	Game();

};