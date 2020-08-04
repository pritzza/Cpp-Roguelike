#pragma once

#include <string>
#include "constants.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "floor.h"

void gotoxy(int x, int y);

class Screen
{
private:
	short numPrevEvents;

public:
	std::vector<Event*> events;

public:
	void printEvents(std::vector<Event*>& ev);
	void printStats(const Player& p);
	void update(const Player& p, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Entity*>& e, std::vector<Event*>& ev);
	void draw(const char s[MAP_HEIGHT][MAP_WIDTH]);

	Screen();
};