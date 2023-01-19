#include "Day11.h"

void TestDay11()
{
	Warrior* pWarrior = new Warrior("����");
	Wizard* pWizard = new Wizard("����");

	pWarrior->PrintStatus();
	pWizard->PrintStatus();

	cout << "���� ����\n";

	Human* players[2];
	if (pWarrior->dexterity >= pWizard->dexterity)	// ��ø���� ���� ����� 0��
	{
		players[0] = pWarrior;
		players[1] = pWizard;
	}
	else
	{
		players[1] = pWarrior;
		players[0] = pWizard;
	}

	Human* pWinner = nullptr;	// �¸��ڰ� �� ��
	int attacker = 0;			// ������ �ε���
	int defencer = 1;			// ������ �ε���
	while (true)
	{
		bool isOdd = (rand() % 2 == 1);		// Ȧ¦�� �������� ���ϱ�
		if (isOdd)
		{
			players[attacker]->Attack(players[defencer]);		// Ȧ���� ������ ����
		}
		else
		{
			players[attacker]->Skill1(players[defencer]);		// ¦���� ���濡�� ��ų ���
		}
		if (players[defencer]->IsDie())		// ���� ����� �׾�����
		{
			pWinner = players[attacker];	// �¸��ڴ� ��
			break;
		}

		players[attacker]->PrintStatus();	// �߰� ���� ����ϱ�
		players[defencer]->PrintStatus();

		int temp = attacker;				// �����ڿ� ����ڸ� �����ϱ�
		attacker = defencer;
		defencer = temp;
	}

	cout << pWinner->name << "��(��) �¸��߽��ϴ�!" << endl;
	
	

	delete pWarrior;
	pWarrior = nullptr;
	delete pWizard;
	pWizard = nullptr;
}
