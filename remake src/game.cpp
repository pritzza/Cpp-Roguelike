#include "game.h"   

Game::Game()
{
	screen.update(player, floor, entities);
}

void Game::tick()
{
	//for(int i = 0; i < entities.size(); i++)
		//entities[i].tick();	//Tick's every entity. Includes player's input, enemy's move gen, and everything's movement
	player.tick();

	screen.update(player, floor, entities);	//draw the screen
}

void Game::start()
{
	running = true;

	while (running)
	{
		tick();
	}
}
