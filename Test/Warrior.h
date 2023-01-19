#pragma once
#include "Human.h"

class Warrior : public Human
{
public:
	Warrior(const char* name) : Human(name)
	{
		this->proTest = 10;
		//this->priTest = 20;
	}
	void Charge();
};

