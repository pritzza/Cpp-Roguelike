#include "title.h"

bool inGame = false;
bool alive = false;
int GAMESTATE;

void startMenu()
{
	GAMESTATE = 0;
	char input;

	while (GAMESTATE == 0)
	{
		printTitle();

		if (!inGame)
		{
			std::cout << "Press 1 to start" << std::endl;
			std::cout << "Press 2 for how to play" << std::endl;
			std::cout << "Press 3 to see credits" << std::endl;
			std::cout << "Press 4 to quit" << std::endl;

			input = _getch();
			std::system("CLS");

			if (input == '1')
			{
				GAMESTATE = 1;
			}
			if (input == '2')
				options();
			if (input == '3')
				credits();
			if (input == '4')
				quit();
		}
		else if (inGame && !alive)
		{
			std::cout << "You died!\n" << std::endl;

			std::cout << "Press 1 to try again" << std::endl;
			std::cout << "Press 2 for how to play" << std::endl;
			std::cout << "Press 3 to see credits" << std::endl;
			std::cout << "Press 4 to quit" << std::endl;

			input = _getch();
			std::system("CLS");

			if (input == '1')
			{
				inGame = false;
				GAMESTATE = 1;
			}
			if (input == '2')
				options();
			if (input == '3')
				credits();
			if (input == '4')
				quit();
		}
		else
		{
			std::cout << "Press 1 to resume" << std::endl;
			std::cout << "Press 2 to restart" << std::endl;
			std::cout << "Press 3 for how to play" << std::endl;
			std::cout << "Press 4 to see credits" << std::endl;
			std::cout << "Press 5 to quit" << std::endl;

			input = _getch();
			std::system("CLS");

			if (input == '1')
			{
				GAMESTATE = 1;
			}
			if (input == '2')
			{
				inGame = false;
				GAMESTATE = 1;
			}
			if (input == '3')
				options();
			if (input == '4')
				credits();
			if (input == '5')
				quit();
		}
	}
}

void quit()
{
	std::cout << "bird up\n";
	exit(0);
}

void options()
{
	std::cout << std::endl << "How to play: \n\n";

	std::cout << "First, right click the top of your console, go to Defaults, and Layout." << std::endl;
	std::cout << "Then set your window size to 120x40, from there on, the controls are WASD and space to pause/reset." << std::endl;
	std::cout << "Also it's highly recommended that you don't play in fullscreen.\n" << std::endl;
	std::cout << "To interact with an object, walk over them. To interact with enemies, walk into them.\n" << std::endl;
	std::cout << "Here's a legend of everything in the game:" << std::endl;
	std::cout << "\t& = you" << std::endl;
	std::cout << "\tM = enemy" << std::endl;
	std::cout << "\t^ = food" << std::endl;
	std::cout << "\tA = next level" << std::endl;
	std::cout << "\t. = floor" << std::endl;
	std::cout << "\t# = wall" << std::endl;
	std::cout << "\t> = door" << std::endl;
	std::cout << "\t: = path" << std::endl;
	std::cout << "\t* = corpse" << std::endl;
}

void credits()
{
	std::cout << "\nCredits:\n" << std::endl;
	std::cout << "\tInspired by: Rogue\n" << std::endl;
	std::cout << "Made by:\n" << std::endl;
	std::cout << "\tJonathan Z. & David A." << std::endl;
}

void printTitle()
{
	std::cout << " _____                                        _____						"			<< std::endl;
	std::cout << "|  __ \\                                      / ____|                     "			<< std::endl;
	std::cout << "| |  | |_   _ _ __   __ _  ___  ___  _ __   | |  __  __ _ _ __ ___   ___  "			<< std::endl;
	std::cout << "| |  | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\  | | |_ |/ _` | '_ ` _ \\ / _ \\"		<< std::endl;
	std::cout << "| |__| | |_| | | | | (_| |  __/ (_) | | | | | |__| | (_| | | | | | |  __/ "			<< std::endl;
	std::cout << "|_____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  \\_____|\\__,_|_| |_| |_|\\___|"	    << std::endl;
	std::cout << "                    __/ |"                                                            << std::endl;
	std::cout << "                   |___/"																<< std::endl;
}