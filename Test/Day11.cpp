#include "Day11.h"

void TestDay11()
{
	Warrior* pWarrior = new Warrior("����");
	Wizard* pWizard = new Wizard("����");

	delete pWarrior;
	pWarrior = nullptr;
	delete pWizard;
	pWizard = nullptr;
}
