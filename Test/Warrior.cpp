#include "Warrior.h"

void Warrior::Attack(Human* pEnemy)
{
	cout << "Warrior::Attack" << endl;
	cout << this->name << "이(가) " << pEnemy->name << "을(를) 공격합니다.\n";
	pEnemy->Defence(strength);
}

void Warrior::Defence(int damage)
{
	int finalDamage = damage * 0.5f;
	cout << name << "은(는) 데미지를 절반만 받습니다.\n";
	cout << this->name << "이(가) " << finalDamage << "의 피해를 입었습니다.\n";
	hp -= finalDamage;
	if (hp < 0)
	{
		Die();
	}
}

void Warrior::Skill1(Human* pTarget)
{
	Charge(pTarget);
}

void Warrior::Charge(Human* pEnemy)
{
	int chargeCost = 30;
	if (mana > chargeCost)
	{
		cout << "돌격!!" << endl;
		pEnemy->Defence(strength + rand() % (strength * 2));	// (힘 ~ 힘*3) 범위
		mana -= chargeCost;
	}
	else
	{
		cout << "마나가 부족합니다.\n";
	}
}