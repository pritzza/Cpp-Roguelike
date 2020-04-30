#ifndef RENDERER_H
#define RENDERER_H
#include "rooms.h"

extern char visibleMap[consoleHeight][consoleWidth];

bool inside(Room room, Player p);
void getPlayerVision(char masterMap[][consoleWidth], Player* p, std::vector<Room> r_list);
void drawRoom(char masterMap[][consoleWidth], Player* p, std::vector<Room> r_list, std::vector<Enemy> e_list);

#endif
