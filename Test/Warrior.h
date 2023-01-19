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
	virtual void Attack(Human* pEnemy);
	virtual void Defence(int damage);
	virtual void Skill1(Human* pTarget);

	void Charge(Human* pEnemy);
};

