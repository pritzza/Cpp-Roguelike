#ifndef COMBAT_H
#define COMBAT_H

extern int level;		// floor level

class Creature {
    public:
	Creature();
	int x, y;
	char symbol;
	int HP, ATK;
	int LVL, EXP, MEXP;		// creature level/exp/maxexp

	void attack(Creature* attacked);
	void die(Creature* dying);
};

class Player : public Creature {
public:
	Player(char c = '&', int h = 0, int a = 0);		// all stats are 0 because they are set upon start()
};

class Enemy : public Creature {
public:
	Enemy(char p = '.', int v = 6, char c = 'M', int h = 3 + level/2, int a = 1 + level/3);
	char prevInput;
	int vision;
};

#endif
