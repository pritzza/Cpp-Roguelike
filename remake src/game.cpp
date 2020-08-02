#include "game.h"   

Game::Game()
{

}

void Game::tick()
{
	// Player has is own tick call so that certain inputs can trigger debug functions
	int input = player.tick(entities, creatures, floor.map, floor.getRooms(), true);	// delete bool part of tick parameter for release
	switch (input)
	{
	case (1):
		progressFloor();
		break;
	}

	for(int i = 1; i < entities.size() - 0; i++)
		creatures[i]->tick(entities, creatures, floor.map, floor.getRooms());	//Tick's every entity. Includes player's input, enemy's move gen, and everything's movement

	std::cout << std::endl << entities.size();
	std::cout << std::endl << creatures.size();

	screen.update(player, floor, entities);	//draw the screen
}

void Game::clearEntities(bool savePlayer)
{
	for (int i = savePlayer; i < creatures.size(); i++)
		delete creatures[i];

	entities.erase(entities.begin() + savePlayer, entities.begin() + entities.size());
	creatures.erase(creatures.begin() + savePlayer, creatures.begin() + creatures.size());

	entities.shrink_to_fit();
	creatures.shrink_to_fit();
}

void Game::progressFloor()
{
	clearEntities(true);

	++floor.level;

	floor.createFloor(entities, creatures);

	const Room& r = floor.getRoom(0);

	player.x = r.x + r.width / 2;
	player.y = r.y + r.height / 2;

	player.clearVision();
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
