#include "Wizard.h"

void Wizard::Attack(Human* pEnemy)
{
	cout << "Wizard::Attack" << endl;
	cout << this->name << "이(가) " << pEnemy->name << "을(를) 공격합니다.\n";
	pEnemy->Defence(intelligence);
}

void Wizard::Defence(int damage)
{
	float per = (float)rand() / (float)RAND_MAX;
	if (per < 0.5f)
	{
		cout << name << "은(는) 회피했습니다.\n";
	}
	else
	{
		cout << this->name << "이(가) " << damage << "의 피해를 입었습니다.\n";
		hp -= damage;
		if (hp < 0)
		{
			Die();
		}
	}
}

void Wizard::Skill1(Human* pTarget)
{
	Human::Skill1(pTarget);	// 부모인 Human의 Skill1 함수 사용하기
	Fireball(pTarget);
}

void Wizard::Fireball(Human* pEnemy)
{
	int fireBallCost = 15;
	if (mana > fireBallCost)
	{
		cout << "파이어 볼~" << endl; 
		pEnemy->Defence(intelligence * 0.5f + rand() % (intelligence * 3));	// (지능*0.5f ~ 지능*3) 범위
		mana -= fireBallCost;
	}
	else
	{
		cout << "마나가 부족합니다.\n";
	}
}
