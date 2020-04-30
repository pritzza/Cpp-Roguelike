#include "rooms.h"

void pathDown(char map[][consoleWidth], std::vector<Room> r_list, int r1, int r2, char symbol, int centerX1, int centerY1, int centerX2, int centerY2)
{
	//symbol = 'D';
	if (centerX1 > r_list[r2].x && centerX1 < r_list[r2].x + r_list[r2].width)			// checks if parallel to room 2
		for (int pathStart = r_list[r1].y + r_list[r1].height - 1; pathStart - 2 <= r_list[r2].y; pathStart++)
			drawPath(map, symbol, pathStart, centerX1);
	else																				// Draws a vertical line from top to bottom
		for (int pathStart = r_list[r1].y + r_list[r1].height - 1; pathStart <= centerY2; pathStart++)
			drawPath(map, symbol, pathStart, centerX1);
	if (centerX1 > centerX2)
		for (int h = centerX1; h + 2 > r_list[r2].x + r_list[r2].width; h--)			   // Draws horizontal line right to left
			drawPath(map, symbol, centerY2, h);
	else
		for (int h = centerX1; h - 1 < r_list[r2].x; h++)								   // Draws horizontal line left to right
			drawPath(map, symbol, centerY2, h);
}

void pathUp(char map[][consoleWidth], std::vector<Room> r_list, int r1, int r2, char symbol, int centerX1, int centerY1, int centerX2, int centerY2)
{
	//symbol = 'U';
	if (centerX1 > r_list[r2].x && centerX1 < r_list[r2].x + r_list[r2].width)				// checks if parallel to room 2
		for (int pathStart = r_list[r1].y; pathStart + 2 >= r_list[r2].y + r_list[r2].height; pathStart--)
			drawPath(map, symbol, pathStart, centerX1);
	else																				
		for (int pathStart = r_list[r1].y; pathStart >= centerY2; pathStart--)			// Draws a vertical line from bottom to top
			drawPath(map, symbol, pathStart, centerX1);

	if (centerX1 > centerX2)
		for (int h = centerX1; h + 2 > r_list[r2].x + r_list[r2].width; h--)				// Draws horizontal line right to left
			drawPath(map, symbol, centerY2, h);
	else
		for (int h = centerX1; h - 1 < r_list[r2].x; h++)									// Draws horizontal line left to right
			drawPath(map, symbol, centerY2, h);
}

void pathLeft(char map[][consoleWidth], std::vector<Room> r_list, int r1, int r2, char symbol, int centerX1, int centerY1, int centerX2, int centerY2)
{
	//symbol = 'L';
	if (centerY1 > r_list[r2].y && centerY1 < r_list[r2].y + r_list[r2].height)			// checks if parallel to room 2
		for (int pathStart = r_list[r1].x; pathStart + 2 >= r_list[r2].x + r_list[r2].width; pathStart--)
			drawPath(map, symbol, centerY1, pathStart);
	else
		for (int pathStart = r_list[r1].x; pathStart > centerX2; pathStart--)			// Draws a horizontal line from right to left
			drawPath(map, symbol, centerY1, pathStart);
	if (centerY1 > centerY2)
		for (int v = centerY1; v + 1 >= r_list[r2].y + r_list[r2].height; v--)			   // Draws vertical line from bottom to top
			drawPath(map, symbol, v, centerX2);
	else
		for (int v = centerY1; v - 1 < r_list[r2].y; v++)								   // Draws vertical line from top to bottom
			drawPath(map, symbol, v, centerX2);
}

void pathRight(char map[][consoleWidth], std::vector<Room> r_list, int r1, int r2, char symbol, int centerX1, int centerY1, int centerX2, int centerY2)
{
	//symbol = 'R';
	if (centerY1 > r_list[r2].y && centerY1 < r_list[r2].y + r_list[r2].height)			// checks if parallel to room 2
		for (int pathStart = r_list[r1].x + r_list[r1].width - 1; pathStart - 3 <= r_list[r2].x; pathStart++)
			drawPath(map, symbol, centerY1, pathStart);
	else
		for (int pathStart = r_list[r1].x + r_list[r1].width - 1; pathStart < centerX2; pathStart++)	// Draws a horizontal line from right to left
			drawPath(map, symbol, centerY1, pathStart);
	if (centerY1 > centerY2)
		for (int v = centerY1; v + 1 >= r_list[r2].y + r_list[r2].height; v--)			   // Draws a vertical line from bottom to top
			drawPath(map, symbol, v, centerX2);
	else
		for (int v = centerY1; v - 1 < r_list[r2].y; v++)								   // Draws a vertical line from top to bottom
			drawPath(map, symbol, v, centerX2);
}

void drawPath(char map[][consoleWidth], char symbol, int y, int x)
{
	if (map[y][x] == '#')			// If wall, make door, else if space, make path, if not wall or space, do nothing
		map[y][x] = '>';
	else if (map[y][x] == ' ')
		map[y][x] = symbol;
	else
		map[y][x] = map[y][x];
}

void setPath(char map[][consoleWidth], std::vector<Room> r_list, int r1, int r2) // r1 is starting room, the one giving the path
{
	int centerX1 = r_list[r1].x + (r_list[r1].width / 2);
	int centerY1 = r_list[r1].y + (r_list[r1].height / 2);
	int centerX2 = r_list[r2].x + (r_list[r2].width / 2);
	int centerY2 = r_list[r2].y + (r_list[r2].height / 2);

	char direction = ':';

	//std::cerr << "Room: " << r_list[r1].id << " and " << r_list[r2].id << " match. \n";

	if (centerY1 < centerY2 && centerY2 - centerY1 > r_list[r1].width / 2)										// Path down (North to South)
	{
		pathDown(map, r_list, r1, r2, direction, centerX1, centerY1, centerX2, centerY2);
	}
	else if (centerY1 > centerY2 && centerY1 - centerY2 > r_list[r1].width / 2)									// Path up (South to North)
	{
		pathUp(map, r_list, r1, r2, direction, centerX1, centerY1, centerX2, centerY2);
	}
	else if (centerX1 > centerX2 && (centerX1 != r_list[r2].y || centerX1 != r_list[r2].y + r_list[r2].height))	// Path left (East to West)
	{
		pathLeft(map, r_list, r1, r2, direction, centerX1, centerY1, centerX2, centerY2);
	}
	else if (centerX1 < centerX2 && (centerX1 != r_list[r2].y || centerX1 != r_list[r2].y + r_list[r2].height))	// Path right (West to East)
	{
		pathRight(map, r_list, r1, r2, direction, centerX1, centerY1, centerX2, centerY2);
	}	
	else        // all the previous conditionals should be met, however if they aren't met, there is this backup
	{
		pathDown(map, r_list, r1, r2, direction, centerX1, centerY1, centerX2, centerY2);
	}
	//std::cerr << "pathfinding error\n";
	//map[r_list[r1].y][r_list[r1].x + r_list[r1].width - 1] = r2 + '0';		// Debug info to show what rooms pair
	//map[r_list[r2].y][r_list[r2].x + r_list[r2].width - 1] = r1 + '0';
}

void findPaths(char map[][consoleWidth], std::vector<Room> r_list, int numRooms)
{
	int distance{};
	int r1;
	int r2;

	for (int i = 0; i < numRooms -1; i++)
	{
		int minDistance{ 10000 };
		for (int j = 0; j < numRooms; j++)
			if (i != j)
			{
				distance = distanceSquared(r_list[i].x, r_list[i].y, r_list[j].x, r_list[j].y);

				if (distance < minDistance && r_list[j].gavePath == false)
				{
					minDistance = distance;
					r1 = i;
					r2 = j;
				}
				//std::cerr << "The distance from room " << i << " and room " << j << " is " << distance;
				//std::cerr << " The minimum distance found is between rooms " << r1 << " and " << r2 << " which is: " << minDistance << std::endl;
			}
		r_list[r1].gavePath = true;
		setPath(map, r_list, r1, r2);
	}
}

int distanceSquared(int p1_x, int p1_y, int p2_x, int p2_y)
{
	return ((p1_x - p2_x) * (p1_x - p2_x)) + ((p1_y - p2_y) * (p1_y - p2_y));
}

void fillRoom(char map[][consoleWidth], Room r, std::vector<Room> r_list)
{
	if (r.id == 1)
		map[rand() % (r.height - 2) + (r.y + 1)][rand() % (r.width - 2) + (r.x + 1)] = 'A';
	if (r.id == 2)
		map[rand() % (r.height - 2) + (r.y + 1)][rand() % (r.width - 2) + (r.x + 1)] = '^';

}

// Prevents room overlap/clipping on generation
bool checkRoom(char map[][consoleWidth], int roomsMade, Room r, std::vector<Room> r_list)
 {
	for (int i = 0; i < roomsMade; i++)
	{
		if ((r.x > r_list[i].x && r.x < r_list[i].x + r_list[i].width) ||
			(r.x + r.width > r_list[i].x && r.x + r.width < r_list[i].x + r_list[i].width) ||
			(r.x < r_list[i].x && r.x + r.width > r_list[i].x + r_list[i].width) ||
			(r.x == r_list[i].x || r.x + r.width == r_list[i].x + r_list[i].width))
		if ((r.y > r_list[i].y && r.y < r_list[i].y + r_list[i].height) ||
			(r.y + r.height > r_list[i].y && r.y + r.height < r_list[i].y + r_list[i].height) ||
			(r.y < r_list[i].y && r.y + r.height > r_list[i].y + r_list[i].height) ||
			(r.y == r_list[i].y || r.y + r.height == r_list[i].y + r_list[i].height))
			return false;
	}
	return true;
}

int makeRoomWidth()
{
	int w{ rand() % 20 + 7 };
	return w;
}

int makeRoomHeight()
{
	int h{ rand() % 6 + 5 };
	return h;
}

int makeRoomOffsetX(int width)
{
	int x{ rand() % (consoleWidth - (width + 2)) + 1 };
	return x;
}

int makeRoomOffsetY(int height)
{
	int y{ rand() % (consoleHeight - (height + 2)) + 1 };
	return y;
}

void clearCanvas(char map[consoleHeight][consoleWidth])
{
	for (int y = 0; y < consoleHeight; y++)               // Goes through map[][] and draws mapHeight * mapWidth of ' ' (empty space char)
		for (int x = 0; x < consoleWidth; x++)
			map[y][x] = ' ';
}

void generateRoom(char map[][consoleWidth], Room r, std::vector<Room> r_list)
{
	for (int y = r.y; y < r.height + r.y; y++)            // Goes through map[][] and draws a box of # at r.y r.x for r.height x r.width
		for (int x = r.x; x < r.width + r.x; x++)
			map[y][x] = '#';

	for (int y = 2 + r.y; y < r.height + r.y; y++)        // Goes through map[][] and fills the box of # with '.'
		for (int x = 2 + r.x; x < r.width + r.x; x++)
			map[y - 1][x - 1] = '.';

	//map[r.y][r.x] = r.id + '0';						  // + 48 because the value of 48 in the decimal to ASCII chart is 0 so 49 is 1 and so on
	fillRoom(map, r, r_list);
}

std::vector<Room> generateFloor(char map[][consoleWidth], Player* p)
{
	int numRooms{ rand() % 5 + 5 };
	std::vector<Room> r_list;

	for (int i = 0; i < numRooms; i++)
	{
		Room r = { 0,0,0,0,0, false };
		do
		{
			r.id = i;
			r.width = makeRoomWidth();
			r.height = makeRoomHeight();
			r.x = makeRoomOffsetX(r.width);
			r.y = makeRoomOffsetY(r.height);
		} while (!checkRoom(map, i, r, r_list));
		generateRoom(map, r, r_list);
		r_list.push_back(r);
	}
	findPaths(map, r_list, numRooms);

	p->x = r_list[0].x + r_list[0].width / 2;          // spawn in middle of room in [0]
	p->y = r_list[0].y + r_list[0].height / 2;

	return r_list;
}

std::vector<Enemy> spawnEnemies(std::vector<Room> r_list)
{
	int numEnemies;
	std::vector<Enemy> e_list;
	Enemy e;
	for (auto &r : r_list)
	{
		numEnemies = rand() % 3;
		for (int i = 0; i < numEnemies; i++)
		{
			e.x = rand() % (r.width - 2) + (r.x + 1);
			e.y = rand() % (r.height - 2) + (r.y + 1);
			e_list.push_back(e);
		}
	}
	return e_list;
}
