#pragma once
#include "Human.h"
class Wizard : public Human
{
public:
	Wizard(const char* name) : Human(name)
	{
	}

	virtual void Attack(Human* pEnemy);
	virtual void Defence(int damage);
	virtual void Skill1(Human* pTarget);

	void Fireball(Human* pEnemy);
};

