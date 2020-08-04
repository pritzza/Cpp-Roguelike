#pragma once

#include <iostream>
#include <string>
#include <vector>

class Event
{
public:
	short actionType;
	short actionValue;
	std::string subject;
	std::string actor;

public:
	void printEvents();
	Event(std::vector<Event*>& ev, short at, short av, std::string s, std::string a);
	~Event();
};
