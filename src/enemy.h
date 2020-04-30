#ifndef ENEMY_H
#define ENEMY_H

#include <stdlib.h>     // srand & rand 
#include <vector>
#include "main.h"
#include "combat.h"

void enemyInput(char map[][consoleWidth], Enemy* enemy, Player* p, std::vector<Enemy>* enemies);
void enemyTick(char map[][consoleWidth], std::vector<Enemy>* enemies, Player* p);
char enemyMove(char map[][consoleWidth], Enemy* e, Player* p, int x, int y, std::vector<Enemy>* enemies);
void walkToPlayer(char map[][consoleWidth], Enemy* enemy, Player* p, std::vector<Enemy>* enemies);

#endif