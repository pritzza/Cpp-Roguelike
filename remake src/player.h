#pragma once
#include "creature.h"

class Player : public Creature
{
private:
	std::vector<Item> inventory;

private:
	int getInput();
	void updateVision(const std::vector<Room>& f, const char m[MAP_HEIGHT][MAP_WIDTH]);

public:
	char vision[MAP_HEIGHT][MAP_WIDTH];

public:
	int tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r, bool debug);	// debugging
	void tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r);	// release
	void clearVision();
	void resetPlayer();

	Player(std::vector<Entity*>& e, std::vector<Creature*>& c);
};