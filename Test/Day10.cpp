#include "Day10.h"

void TestDay10()
{
	Human* pHuman = new Human("Àû´çÈ÷");
	pHuman->PrintStatus();
	pHuman->SetRandomStatus();
	pHuman->PrintStatus();
	delete pHuman;
	pHuman = nullptr;

}
