#include "Day10.h"

void TestDay10()
{
	Human* pHuman = new Human("적당히");
	pHuman->PrintStatus();
	pHuman->SetRandomStatus();
	pHuman->PrintStatus();
	delete pHuman;
	pHuman = nullptr;

	Warrior* pWarrior = new Warrior("적당전사");
	pWarrior->PrintStatus();
}
