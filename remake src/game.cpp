	#include "game.h"   

Game::Game()
{

}

void Game::tick()
{
	input = _getch();	// get user input

	handleInput();	// process userinput, for debug commands, and also player movement, actions, and menuing

	for (int i = 1; i < entities.size() - 0; i++)
		creatures[i]->tick(entities, creatures, floor.map, floor.getRooms(), screen.events);	//Tick's every entity. Includes player's input, enemy's move gen, and everything's movement

	screen.update(player, floor.map, entities, screen.events, debugMode);	//draw the screen
}

void Game::handleInput()
{
	switch (input)
	{
		// If any of these player related inputs, call player.tick, and pass in input
	case('w'):
	case('s'):
	case('d'):
	case('a'):
		player.tick(entities, creatures, floor.map, floor.getRooms(), screen.events, input);
		break;

	case('q'):	// space to toggle debug mode
		if (debugMode)
			debugMode = false;
		else
			debugMode = true;
		break;

	case ('r'):	// r to reset floor
		floor.floorLevel--;
		progressFloor();
		break;

	case ('e'):	// r to skip floor
		progressFloor();
		break;
	}
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

	++floor.floorLevel;

	// Construct floor with rooms, and fill it with items and enemies
	floor.createFloor(entities, creatures);

	// Reference for a room to spawn the player in for readability
	const Room& const r = floor.getRoom(0);

	player.x = r.x + r.width / 2;
	player.y = r.y + r.height / 2;

	player.resetVision(floor.getRooms(), floor.map);	// clears players memory of previous floor to not overlap with future floros
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
	floor.floorLevel = 0;
	player.resetPlayer();
	//reset player stats
	//clear entities vector
	//reset gamestate
	progressFloor();
}
