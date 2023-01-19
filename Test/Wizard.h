#pragma once
#include "Human.h"
class Wizard : public Human
{
public:
	Wizard(const char* name) : Human(name)
	{
	}

	void Fireball();
};

