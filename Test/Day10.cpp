#include "Day10.h"

void TestDay10()
{
	Human* pHuman = new Human("������");
	pHuman->PrintStatus();
	pHuman->SetRandomStatus();
	pHuman->PrintStatus();	

	Warrior* pWarrior = new Warrior("��������");
	pWarrior->PrintStatus();
	pWarrior->Charge();

	Wizard* pWizard = new Wizard("��������");
	pWizard->PrintStatus();
	pWizard->Fireball();

	pHuman->Attack(pWarrior);

	Human* pTest = pWarrior;	
	// pWarrior�� Warrior* Ÿ�������� Warrior�� Human�� ��� �޾ұ� ������ Human*�� ������ �� �ִ�.
	pTest->Attack(pWizard);
	//pTest->Charge();	// ������ �� �� ������ Human�� ��밡���� �ɹ��� ��� �����ϴ�.
	((Warrior*)pTest)->Charge();	// ĳ������ �ؼ� ����ϴ� ���� �����ϴ�.
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
