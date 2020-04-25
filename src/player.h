#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include "main.h"

// we'll have hp and atk and other combat stuff here
// Maybe should make these classes instead of structs
struct Player {
	int  x, y;
	int HP, ATK, DEF;
};

struct Enemy {
	int  x, y;
	int HP, ATK, DEF;
};

char playerMove(char map[][consoleWidth], Player* p, int x, int y);
int move(char map[][consoleWidth], Player* p, int toggle);

#endif