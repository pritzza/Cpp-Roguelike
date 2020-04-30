#include "rooms.h"
#include "renderer.h"
#include "title.h"
//#include "main.h" already included in rooms.h

Player player;
Player* player_pointer = &player;

int turn{};
int level{};

char map[consoleHeight][consoleWidth];			   // Creates a 120x38 2D array (the size of the console by default) - 2
char visibleMap[consoleHeight][consoleWidth];

std::vector<Room> rooms;
std::vector<Enemy> enemies;
//std::vector<Enemy>* enemy_pointer = nullptr;


void printStats(int turn, Player* p)
{
	std::cout << "Player x: " << p->x << " y: " << p->y << " Turn: " << turn << " Level: " << p->LVL << " EXP: " << p->EXP << '/' << p->MEXP  
		<< " HP: " << p->HP << " ATK: " << p->ATK << " Floor: " << level << '\n';
}

void newLevel()
{
	rooms.clear();
	enemies.clear();
	//for (auto &e: enemy_pointer)
	//	delete e;
	//enemy_pointer = nullptr;
	clearCanvas(map);
	clearCanvas(visibleMap);
	rooms = generateFloor(map, player_pointer);
	enemies = spawnEnemies(rooms);
	level++;
	player_pointer->HP += 4 + level;
	//enemy_pointer = &enemies;
}

void start()
{
	level = 0;
	turn = 0;
	player_pointer->EXP = 0;
	player_pointer->MEXP = 10;
	player_pointer->LVL = 1;
	player_pointer->HP = 15;		// 18 cause it will gain 5 after a new level is made
	player_pointer->ATK = 2;
	player_pointer->symbol = '&';
	newLevel();
	inGame = true;
	alive = true;
}

void tick()
{
	if (inGame && alive && GAMESTATE == 1)
	{
		printStats(turn, player_pointer);

		drawRoom(map, player_pointer, rooms, enemies);

		takePlayerInput(map, player_pointer, &enemies);

		enemyTick(map, &enemies, player_pointer);

		std::system("CLS");

		turn++;
	}
	else if (GAMESTATE == 1)
	{
		start();
	}
}

void gameLoop()
{
	while (1)
	{
		if (GAMESTATE == 0)
			startMenu();
		else if (GAMESTATE == 1)
			tick();
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	gameLoop();

	enemies.clear();
	rooms.clear();

	return 0;
}