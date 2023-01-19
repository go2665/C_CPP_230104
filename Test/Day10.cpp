#include "Day10.h"

void TestDay10()
{
	Human* pHuman = new Human("적당히");
	pHuman->PrintStatus();
	pHuman->SetRandomStatus();
	pHuman->PrintStatus();	

	Warrior* pWarrior = new Warrior("적당전사");
	pWarrior->PrintStatus();
	pWarrior->Charge();

	Wizard* pWizard = new Wizard("근접법사");
	pWizard->PrintStatus();
	pWizard->Fireball();

	pHuman->Attack(pWarrior);

	Human* pTest = pWarrior;	
	// pWarrior는 Warrior* 타입이지만 Warrior가 Human을 상속 받았기 때문에 Human*에 저장할 수 있다.
	pTest->Attack(pWizard);
	//pTest->Charge();	// 저장은 할 수 있지만 Human이 사용가능한 맴버만 사용 가능하다.
	((Warrior*)pTest)->Charge();	// 캐스팅을 해서 사용하는 것은 가능하다.
	Warrior* pTestWarrior = (Warrior*)pTest;
	pTestWarrior->Charge();

	//pTestWarrior->proTest = 10;

	Human* players[3];
	players[0] = pHuman;
	players[1] = pWarrior;
	players[2] = pWizard;


	delete pHuman;
	pHuman = nullptr;

	delete pWarrior;
	pWarrior = nullptr;

	delete pWizard;
	pWizard = nullptr;
}
