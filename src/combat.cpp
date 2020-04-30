#include "combat.h"

Creature::Creature() 
{
    int  x = 0, y = 0;	
    int LVL = 1, EXP = 0, MEXP = 25;
}

Player::Player(char c, int h, int a)
{	
    symbol = c;
    HP = h;
    ATK = a;
}

Enemy::Enemy(char p, int v, char c, int h, int a) : prevInput(), vision()
{	
    symbol = c;
    HP = h;
    ATK = a;
    prevInput = p;
    vision = v;
}

void Creature::attack(Creature* attacked)
{  
    //"this" refers to the creature that is calling the function, the attacker
    attacked->HP -= this->ATK;

    if (attacked->HP <= 0)
    {
        this->EXP += attacked->ATK;
        die(attacked);

        if (this->EXP >= this->MEXP)     // Level up
        {
            this->ATK++;
            this->HP += this->LVL + this->EXP/5;
            this->EXP -= this->MEXP;
            this->MEXP += 10;
            this->LVL++;
        }
    }
}

void Creature::die(Creature* dying)
{
    dying->symbol = '*';
}