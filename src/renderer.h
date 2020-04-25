#ifndef RENDERER_H
#define RENDERER_H
#include <iostream>
#include "rooms.h"

bool inside(Room room, Player p);
void getPlayerVision(char masterMap[][consoleWidth], Player* p, Room* r_list);
void drawRoom(char masterMap[][consoleWidth], Player* p, Room* r_list, int toggle);

#endif
