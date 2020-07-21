#include <windows.h>
#include "screen.h"

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Screen::Screen()
{
}

void Screen::update(const Player& p, const Floor& f, const std::vector<Entity> &e)
{
	char screen[MAP_HEIGHT][MAP_WIDTH];

	for (int y = 0; y < MAP_HEIGHT; y++)	// Copy all elements from the floor's map to the screen
		for (int x = 0; x < MAP_WIDTH; x++)
			screen[y][x] = f.map[y][x];

	//for (int i = 0; i < e.size(); i++)		// Draw all entities into the screen
	//	screen[e[i].y][e[i].x] = e[i].sprite;

	screen[p.y][p.x] = p.sprite;			// Draw the player onto the screen

	draw(screen);		// After rasterizing game's elements, draw()'s it to print it
}

void Screen::draw(const char s[MAP_HEIGHT][MAP_WIDTH])
{
	std::string printedScreen;

	gotoxy(0, 0);	// Moves cursor to 0,0 so the new screen can be printed over it's old self

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			printedScreen += s[y][x];	// adds each char from s to printedScreen
		}
		printedScreen.push_back('\n');	// after adding a row, appends a new line to indent and format screen
	}

	std::cout << printedScreen;
}