#include "game.h"   

Game::Game()
{

}

void Game::tick()
{
	// Player has is own tick call so that certain inputs can trigger debug functions
	int input = player.tick(floor, entities, creatures, true);	// delete bool part of tick parameter for release
	switch (input)
	{
	case (1):
		progressFloor();
		break;
	}

	for(int i = 1; i < entities.size() - 0; i++)
		creatures[i]->tick(floor, entities, creatures);	//Tick's every entity. Includes player's input, enemy's move gen, and everything's movement

	std::cout << std::endl << entities.size();
	std::cout << std::endl << creatures.size();

	screen.update(player, floor, entities);	//draw the screen
}

void Game::progressFloor()
{

	for (int i = 1; i < creatures.size(); i++)
	  	delete creatures[i];

	entities.erase(entities.begin() + 1, entities.begin() + entities.size());
	creatures.erase(creatures.begin() + 1, creatures.begin() + creatures.size());


	++floor.level;

	floor.createFloor();

	const Room& r = floor.getRoom(0);

	player.x = r.x + r.width / 2;
	player.y = r.y + r.height / 2;

	player.clearVision();

	int xp = rand() % (r.width - 2) + r.x + 1;
	int yp = rand() % (r.height - 2) + r.y + 1;

	Enemy* e1 = new Enemy(entities, creatures, xp, yp, 0);
	Enemy* e2 = new Enemy(entities, creatures, xp, yp, 0);
	Enemy* e3 = new Enemy(entities, creatures, xp, yp, 0);

}

void Game::start()
{
	running = true;

	reset();

	while (running)
	{
		tick();
	}
}

void Game::reset()
{
	floor.level = 0;
	player.resetPlayer();
	//reset player stats
	//clear entities vector
	//reset gamestate
	progressFloor();
}
