#pragma once
#include <conio.h>
#include <vector>
#include "item.h"

class Entity	// The player, all enemies, and items, like equipment and warp tiles are an entity
{
public:
	int x;
	int y;
	bool item;
	char sprite;

public:
	void virtual tick();
};

class Creature : public Entity	// Every living thing, player, enemies, NPCs are creatures
{
protected:
	short xVel;
	short yVel;

	std::vector<Item> equipment;
	std::string name;
	short health;
	short maxHealth;
	short attack;
	short defense;
	short gold;
	//Maybe speed, magic, and some other cool stats

protected:
	void move();
	bool checkForTileCollision();
	bool checkForCreatureCollision();
public:
	Creature();
};

class Player : public Creature
{
private:
	std::vector<Item> inventory;
private:
	void getInput();
public:
	void tick();
	Player();
};

class Enemy : public Creature
{
private:
	bool isHostile;
private:
	int calculateNextMove();
public:
	void tick();
	Enemy();
};