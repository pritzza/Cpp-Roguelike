#include "player.h"
#include "rooms.h"
#include "renderer.h"
//#include "main.h" already included in rooms.h

void printStats(int turn, Player* p)
{
	std::cout << "Player x: " << p->x << " y: " << p->y << " Turn: " << turn << '\n';
}

int main()
{
	srand((unsigned int)time(NULL));

	char map[consoleHeight][consoleWidth];      // Creates a 120x439 2D array (the size of the console by default) - 2
	int toggle_vision = 0;

	clearCanvas(map);

	Player p1 = { 0,0,0,0,0 };
	Player* p1_pointer = &p1;

	Room rooms[10];								// Just a magic number for the max ammount of rooms we want to spawn on a floor

	generateFloor(map, p1_pointer, rooms);

	for (int i = 0;; i++)
	{
		map[p1.y][p1.x] = '&';                 // Player's icon  

		printStats(i, p1_pointer);

		drawRoom(map, p1_pointer, rooms, toggle_vision);

		toggle_vision = move(map, p1_pointer, toggle_vision);

		std::system("CLS");                     // Clears console
	}

	delete[] rooms;
	delete p1_pointer;
	return 0;
}
