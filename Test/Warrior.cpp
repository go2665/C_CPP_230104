#include "Warrior.h"

void Warrior::Attack(Human* pEnemy)
{
	cout << "Warrior::Attack" << endl;
	cout << this->name << "��(��) " << pEnemy->name << "��(��) �����մϴ�.\n";
	pEnemy->Defence(strength);
}

void Warrior::Defence(int damage)
{
	int finalDamage = damage * 0.5f;
	cout << name << "��(��) �������� ���ݸ� �޽��ϴ�.\n";
	cout << this->name << "��(��) " << finalDamage << "�� ���ظ� �Ծ����ϴ�.\n";
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
		cout << "����!!" << endl;
		pEnemy->Defence(strength + rand() % (strength * 2));	// (�� ~ ��*3) ����
		mana -= chargeCost;
	}
	else
	{
		cout << "������ �����մϴ�.\n";
	}
}