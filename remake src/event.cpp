#include "event.h"

void Event::printEvents()
{
	std::cout << std::endl;

	switch (actionType)
	{
	case (0):	// Enemy Death
		std::cout << subject << " died!";
		break;
	case (1):	// Attack Miss
		std::cout << actor << " missed " << subject << '!';
		break;
	case(2):	// Successful Attack
		std::cout << actor << " attacked " << subject << " for " << actionValue << " damage!";
		break;
	case(3):	// Experience Gain
		std::cout << actor << " gained " << actionValue << " EXP!";
		break;
	case(4):	// Level Up
		std::cout << actor << " leveled up to level " << actionValue << '!';
		break;
	default:
		std::cout << "Suicide Is Painless";
		break;
	}
}

Event::Event(std::vector<Event*>& ev, const short at, const short av, const std::string s, const std::string a)
{
	actionType = at;
	actionValue = av;
	subject = s;
	actor = a;

	ev.push_back(this);
}

Event::~Event()
{
	delete this;
}