#include "Day11.h"

void TestDay11()
{
	Warrior* pWarrior = new Warrior("전사");
	Wizard* pWizard = new Wizard("법사");

	delete pWarrior;
	pWarrior = nullptr;
	delete pWizard;
	pWizard = nullptr;
}
