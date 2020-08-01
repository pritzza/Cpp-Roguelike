#include "game.h"   

Game::Game()
{

}

void Game::tick()
{

	int input = player.tick(floor, entities);
	switch (input)
	{
	case (1):
		progressFloor();
		break;
	}

	for(int i = 1; i < entities.size() - 1; i++)
		entities[i]->tick();	//Tick's every entity. Includes player's input, enemy's move gen, and everything's movement

	std::cout << entities.size();

	screen.update(player, floor, entities);	//draw the screen
}

void Game::progressFloor()
{
	for (int i = 1; i < entities.size(); i++)
		delete entities[i];

	entities.erase(entities.begin() + 1, entities.begin() + entities.size());


	++floor.level;

	floor.createFloor();

	const Room& r = floor.getRoom(0);

	player.x = r.x + r.width / 2;
	player.y = r.y + r.height / 2;

	player.clearVision();

	int xp = rand() % (r.width - 2) + r.x + 1;
	int yp = rand() % (r.height - 2) + r.y + 1;

	Enemy* e = new Enemy(entities, xp, yp);

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
