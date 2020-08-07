#include <windows.h>
#include "screen.h"

void gotoxy(const int x, const int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Screen::Screen() {}

void Screen::printStats(const Player& p)
{
	char d;
	// Change direction to compas direction (N/S/E/W)
	switch (p.getDirection()) {
	case (0): d = 'N'; break;  case (1): d = 'S'; break; case (2): d = 'E'; break;  case (3): d = 'W'; break;
	}

	// Prepare the first line of the player's stats, including name, health, etc
	std::ostringstream firstLine;
	firstLine << p.getName() << " [ HP (" << p.getHealth() << '/' << p.getMaxHealth() << ") ATK (" << p.getAttack() << ") DEF (" << p.getDefense() << ") " << d << " ]                  ";

	std::string formattingSpace = getSecondLineSpace(p);	// creates indent for second line according to player.name.length()

	// Prepares the second line of the player's stats, including level, and exp bar
	std::ostringstream secondLine;
	secondLine << formattingSpace << "[ LVL (" << p.getLevel() << ") EXP (";

	std::string expBar = renderExpBar(p);

	secondLine << expBar << ") ]                  ";	// appends exp bar to the end of the second line with empty space to overwrite any possible shrinkage

	std::cout << (firstLine.str() + secondLine.str());	// Turns ostringstreams into strings, and prints em
}

// Gets the second line of the stats lined up with the whitespaces before the solid braces
std::string Screen::getSecondLineSpace(const Player& p)
{
	std::string formattingSpace = "\n";
	int formattingSpaceLength = p.getName().length() + 1;

	for (int i = 0; i < formattingSpaceLength; i++)
		formattingSpace += ' ';

	return formattingSpace;
}

// Returns the exp bar (e.g. "####::::::::")
std::string Screen::renderExpBar(const Player& p)
{
	std::string expBar;

	const int expBarLength{ 12 + p.getAttack() / 10 + p.getHealth() / 10 + p.getMaxHealth() / 10 + p.getDefense() / 10 };
	const int expBarFill = static_cast<int>((p.getExperience() * expBarLength / p.getMaxExp()));

	for (int i = 0; i < expBarLength; i++)
	{
		if (i < expBarFill)
			expBar += '#';
		else
			expBar += ':';
	}

	return expBar;
}

void Screen::printEvents(std::vector<Event*>& ev)
{
	// Clears old event messages
	for (int i = 0; i <= numPrevEvents; i++)
		std::cout << "\n                                                      ";

	gotoxy(0, MAP_HEIGHT + 2);	// Goes to where events start printing

	for (auto& eve : ev)
		eve->printEvents();	// Goes through every event and prints it

	numPrevEvents = ev.size();
}

// Prepares the map into a string according to player vision to be printed by Screen::draw(), and actually prints the players stats, and events
void Screen::update(const Player& p, const char m[MAP_HEIGHT][MAP_WIDTH], const std::vector<Entity*>& e, std::vector<Event*>& ev, bool debug)
{
	char screen[MAP_HEIGHT][MAP_WIDTH];

	for (int y = 0; y < MAP_HEIGHT; y++)	// Copy all elements from the floor's map to the screen
		for (int x = 0; x < MAP_WIDTH; x++)
			if (debug)
			{
				screen[y][x] = m[y][x];
			}
			else
				screen[y][x] = p.vision[y][x];

	for (auto& i : e)		// Draw all entities into the screen if within vision
	{
		//std::cout << "\n\nX: " << i->x << "\nY: " << i->y << "\nS: " << i->entityVectorElement;	// debug on all entities x, y, and sprite

		if (p.vision[i->y][i->x] != ' ' || p.getSight() == -1)
			screen[i->y][i->x] = i->sprite;
	}

	//std::cout << e.size();

	draw(screen);		// After rasterizing game's elements, draw()'s it to print it
	printStats(p);

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