#pragma once

#include <cstdlib> 
#include <ctime> 
#include "screen.h"

class Game
{
private:
    bool running;
    Screen screen;
    Floor floor;
    Player player;

    std::vector<Entity> entities;

private:
    void tick();

public:
    void start();

public:
    Game();
    
};