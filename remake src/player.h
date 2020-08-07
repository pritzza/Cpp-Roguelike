#pragma once
#include "creature.h"

class Player : public Creature
{
private:
	std::vector<Item> inventory;

private:
	void processInput(const char i);
	void updateVision(const std::vector<Room>& f, const char m[MAP_HEIGHT][MAP_WIDTH]);

public:
	char vision[MAP_HEIGHT][MAP_WIDTH];

public:
	void tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r, std::vector<Event*>& ev, const char input);
	void resetVision(const std::vector<Room>& f, const char m[MAP_HEIGHT][MAP_WIDTH]); // Fills player's vision[][] with ' ' and writes current vision
	void clearVision();	// Fills player's vision[][] with ' '
	void resetPlayer();

	Player(std::vector<Entity*>& e, std::vector<Creature*>& c);
};