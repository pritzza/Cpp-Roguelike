#include "player.h"

Player::Player(std::vector<Entity*>& e, std::vector<Creature*>& c)
{
	name = "You";
	sprite = '&';
	entityType = 0;
	idValue = 0;

	e.push_back(this);
	entityVectorElement = e.size() - 1;
	
	c.push_back(this);
	creatureVectorElement = c.size() - 1;
}

void Player::resetPlayer()
{
	clearVision();
	health = 10;
	maxHealth = health;
	attack = 2;
	defense = 0;
	//etc
}

void Player::clearVision()
{
	for (int i = 0; i < MAP_WIDTH; i++)
		for (int j = 0; j < MAP_HEIGHT; j++)
			vision[j][i] = ' ';
}

void Player::resetVision(const std::vector<Room>& f, const char m[MAP_HEIGHT][MAP_WIDTH])
{
	for (int i = 0; i < MAP_WIDTH; i++)
		for (int j = 0; j < MAP_HEIGHT; j++)
			vision[j][i] = ' ';

	updateVision(f, m);
}

void Player::processInput(const char i)
{
	switch (i)
	{
	case('w'): yVel = -1; break;
	case('s'): yVel = 1; break;
	case('a'): xVel = -1; break;
	case('d'): xVel = 1; break;
	}
}

void Player::updateVision(const std::vector<Room>& f, const char m[MAP_HEIGHT][MAP_WIDTH])
{
	// Used to tell direction in terms of x and y
	//short xd = 0;
	//short yd = 0;
	//
	//switch (direction)
	//{
	//case(0):	// North
	//	yd = -1;
	//	break;
	//case(1):	// South
	//	yd = 1;
	//	break;
	//case(2):	// East
	//	xd = -1;
	//	break;
	//case(3):	// West
	//	xd = 1;
	//	break;
	//}

	// reveals rooms when entering
	for (auto& r : f)	// Goes through each room
		if ((x > r.x && x < r.x + r.width) && (y > r.y && y < r.y + r.height))	// checks if player is inside r
			for (int i = r.x; i < r.x + r.width; i++)
				for (int j = r.y; j < r.y + r.height; j++)
				{
					vision[j][i] = m[j][i];	// adds r to vision map
				}
		else
			for (int i = r.x + 1; i < r.x + r.width - 1; i++)
				for (int j = r.y + 1; j < r.y + r.height - 1; j++)
				{
					vision[j][i] = ' '; // if you leave room, empty room
				}

	for (int i = x - sight - 1; i <= x + sight + 1; i++)
		for (int j = y - sight - 1; j <= y + sight + 1; j++)
		{
			// Erases/forgets tiles out of vision
			if (m[j][i] == ':')
				vision[j][i] = ' ';

			// Draws what you can see
			if (i >= x - sight && i <= x + sight)
				if (j >= y - sight && j <= y + sight)
					vision[j][i] = m[j][i];
		}
}

void Player::tick(std::vector<Entity*>& e, std::vector<Creature*>& c, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Room>& r, std::vector<Event*>& ev, const char input)
{
	// returns input inorder to change gamestates in game obj
	processInput(input);
	move(e, c, m, r[0], ev);
	updateVision(r, m);
}
