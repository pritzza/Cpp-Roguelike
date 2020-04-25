#ifndef ROOMS_H
#define ROOMS_H

#include <stdlib.h>     // srand & rand 
#include <time.h>       // time 
#include "player.h"
#include "main.h"

// Will contain all map information

struct Room {
	int width, height, x, y, id;
	bool gavePath;
};

void pathDown(char map[][consoleWidth], Room* r_list, int r1, int r2, char symbol, int centerX1, int centerY1, int centerX2, int centerY2);
void pathUp(char map[][consoleWidth], Room* r_list, int r1, int r2, char symbol, int centerX1, int centerY1, int centerX2, int centerY2);
void pathLeft(char map[][consoleWidth], Room* r_list, int r1, int r2, char symbol, int centerX1, int centerY1, int centerX2, int centerY2);
void pathRight(char map[][consoleWidth], Room* r_list, int r1, int r2, char symbol, int centerX1, int centerY1, int centerX2, int centerY2);
void drawPath(char map[][consoleWidth], char symbol, int x, int y);
void findPaths(char map[][consoleWidth], Room* r_list, int numRooms);
void setPath(char map[][consoleWidth], Room* r_list, int r1, int r2);
int distanceSquared(int p1_x, int p1_y, int p2_x, int p2_y);
void clearCanvas(char map[consoleHeight][consoleWidth]);
bool checkRoom(char map[][consoleWidth], Room r, Room* r_list);
int makeRoomWidth();
int makeRoomHeight();
int makeRoomOffsetX(int width);
int makeRoomOffsetY(int height);
void generateRoom(char map[][consoleWidth], Room r);
int move(char map[][consoleWidth], Player* p, int toggle);
void generateFloor(char map[][consoleWidth], Player* p, Room* r_list);
void fillRoom(char map[][consoleWidth], Room r);

#endif