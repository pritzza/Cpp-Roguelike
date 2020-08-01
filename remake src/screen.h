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

public:
	void update(const Player& p, const Floor& f, const std::vector<Entity*>& e);
	void draw(const char s[MAP_HEIGHT][MAP_WIDTH]);

	Screen();
};