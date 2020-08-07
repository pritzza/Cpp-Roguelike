#pragma once

#include <string>
#include <sstream>
#include "constants.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "floor.h"

void gotoxy(const int x, const int y);

class Screen
{
private:
	short numPrevEvents{ 0 };

public:
	std::vector<Event*> events;

public:
	void printEvents(std::vector<Event*>& ev);
	void printStats(const Player& p);
	std::string renderExpBar(const Player& p);
	std::string getSecondLineSpace(const Player& p);
	void update(const Player& p, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Entity*>& e, std::vector<Event*>& ev, bool debug);
	void draw(const char s[MAP_HEIGHT][MAP_WIDTH]);

	Screen();
};