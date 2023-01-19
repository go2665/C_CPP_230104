#include "Day11.h"

void TestDay11()
{
	Warrior* pWarrior = new Warrior("전사");
	Wizard* pWizard = new Wizard("법사");

	pWarrior->PrintStatus();
	pWizard->PrintStatus();

	cout << "전투 시작\n";

	Human* players[2];
	if (pWarrior->dexterity >= pWizard->dexterity)	// 민첩성이 높은 사람이 0번
	{
		players[0] = pWarrior;
		players[1] = pWizard;
	}
	else
	{
		players[1] = pWarrior;
		players[0] = pWizard;
	}

	Human* pWinner = nullptr;	// 승리자가 들어갈 곳
	int attacker = 0;			// 공격자 인덱스
	int defencer = 1;			// 수비자 인덱스
	while (true)
	{
		bool isOdd = (rand() % 2 == 1);		// 홀짝을 랜덤으로 정하기
		if (isOdd)
		{
			players[attacker]->Attack(players[defencer]);		// 홀수면 상대방을 공격
		}
		else
		{
			players[attacker]->Skill1(players[defencer]);		// 짝수면 상대방에게 스킬 사용
		}
		if (players[defencer]->IsDie())		// 공격 대상이 죽었으면
		{
			pWinner = players[attacker];	// 승리자는 나
			break;
		}

		players[attacker]->PrintStatus();	// 중간 과정 출력하기
		players[defencer]->PrintStatus();

		int temp = attacker;				// 공격자와 방어자를 교대하기
		attacker = defencer;
		defencer = temp;
	}

	cout << pWinner->name << "이(가) 승리했습니다!" << endl;
	
	

	delete pWarrior;
	pWarrior = nullptr;
	delete pWizard;
	pWizard = nullptr;
}
