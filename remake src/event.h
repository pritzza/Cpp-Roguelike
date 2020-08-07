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
	Event(std::vector<Event*>& ev, const short at, const short av, const std::string s, const std::string a);
	~Event();
};
