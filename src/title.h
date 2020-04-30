#ifndef TITLE_H
#define TITLE_H

#include <cstdlib> 
#include <conio.h>
#include <iostream>

extern bool inGame;
extern bool alive;
extern int GAMESTATE;

void quit();
void startMenu();
void options();
void credits();
void printTitle();

#endif