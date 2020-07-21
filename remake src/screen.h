#pragma once

#include <string>
#include "constants.h"
#include "entity.h"
#include "floor.h"

class Screen
{
private:

public:
	void update(const Player& p, const Floor& f, const std::vector<Entity>& e);
	void draw(const char s[MAP_HEIGHT][MAP_WIDTH]);

	Screen();
};