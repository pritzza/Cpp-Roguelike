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

void Screen::printStats(const Player& p)
{
	char d;
	// Change direction to compas direction (N/S/E/W)
	switch (p.getDirection()) { case (0): d = 'N'; break;  case (1): d = 'S'; break; case (2): d = 'E'; break;  case (3): d = 'W'; break; }

	std::cout << p.getName() << " [ HP (" << p.getHealth() << '/' << p.getMaxHealth() << ") ATK (" << p.getAttack() << ") DEF (" << p.getDefense() << ") " << d << " ]";
}

void Screen::update(const Player& p, const Floor& f, const std::vector<Entity*>& e)
{
	char screen[MAP_HEIGHT][MAP_WIDTH];

	for (int y = 0; y < MAP_HEIGHT; y++)	// Copy all elements from the floor's map to the screen
		for (int x = 0; x < MAP_WIDTH; x++)
			if (p.getSight() != -1)
			{
				screen[y][x] = p.vision[y][x];
			}
			else
				screen[y][x] = f.map[y][x];

	for (auto& i : e)		// Draw all entities into the screen if within vision
	{
		std::cout << "\n\nX: " << i->x << "\nY: " << i->y << "\nS: " << i->sprite;

		if (p.vision[i->y][i->x] != ' ' || p.getSight() == -1)
			screen[i->y][i->x] = i->sprite;
	}

	draw(screen);		// After rasterizing game's elements, draw()'s it to print it
	printStats(p);
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