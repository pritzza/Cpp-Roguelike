#pragma once
#include <string>

class Item
{
private:
	std::string name;
	short slot;		// -1 for null, 0 for consume, 1 for weap, 2 for helm, 3 for chest, 4 for leggings, 5 for boots...
public:
	Item();
};