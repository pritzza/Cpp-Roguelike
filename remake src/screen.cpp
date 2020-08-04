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

	int formattingSpaceLength = p.getName().length() + 1;
	std::string formattingSpace = "\n";

	for (int i = 0; i < formattingSpaceLength; i++)
		formattingSpace += ' ';

	std::cout << p.getName() << " [ HP (" << p.getHealth() << '/' << p.getMaxHealth() << ") ATK (" << p.getAttack() << ") DEF (" << p.getDefense() << ") " << d << " ]"
		<< formattingSpace << "[ LVL (" << p.getLevel() << ") EXP (" << p.getExperience() << '/' << p.getMaxExp() << ") ]";

}

void Screen::printEvents(std::vector<Event*>& ev)
{
	// Clears old event messages
	for (int i = 0; i <= numPrevEvents; i++)
		std::cout << "\n                                                        ";

	gotoxy(0, MAP_HEIGHT + 1);	// Goes to where events start printing

	for (auto& eve : ev)
		eve->printEvents();	// Goes through every event and prints it

	numPrevEvents = ev.size();
}

void Screen::update(const Player& p, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Entity*>& e, std::vector<Event*>& ev)
{
	char screen[MAP_HEIGHT][MAP_WIDTH];

	for (int y = 0; y < MAP_HEIGHT; y++)	// Copy all elements from the floor's map to the screen
		for (int x = 0; x < MAP_WIDTH; x++)
			if (p.getSight() != -1)
			{
				screen[y][x] = p.vision[y][x];
			}
			else
				screen[y][x] = m[y][x];

	for (auto& i : e)		// Draw all entities into the screen if within vision
	{
		//std::cout << "\n\nX: " << i->x << "\nY: " << i->y << "\nS: " << i->entityVectorElement;	// debug on all entities x, y, and sprite

		if (p.vision[i->y][i->x] != ' ' || p.getSight() == -1)
			screen[i->y][i->x] = i->sprite;
	}

	draw(screen);		// After rasterizing game's elements, draw()'s it to print it
	printStats(p);

	//std::cout << e.size();

	printEvents(ev);

	ev.clear();

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