#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "main.h"
#include "title.h"
#include "combat.h"

// we'll have hp and atk and other combat stuff here
// Maybe should make these classes instead of structs

char playerMove(char map[][consoleWidth], Player* p, int x, int y, std::vector<Enemy>* enemies);
void takePlayerInput(char map[][consoleWidth], Player* p, std::vector<Enemy>* enemies);

#endif