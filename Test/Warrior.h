#pragma once
#include "Human.h"

class Warrior : public Human
{
public:
	Warrior(const char* name) : Human(name)
	{
		strcpy(this->name, name);
	}
	void Charge();
};

