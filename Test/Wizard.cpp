#include "Wizard.h"

void Wizard::Attack(Human* pEnemy)
{
	cout << "Wizard::Attack" << endl;
	cout << this->name << "��(��) " << pEnemy->name << "��(��) �����մϴ�.\n";
	pEnemy->Defence(intelligence);
}

void Wizard::Defence(int damage)
{
	float per = (float)rand() / (float)RAND_MAX;
	if (per < 0.5f)
	{
		cout << name << "��(��) ȸ���߽��ϴ�.\n";
	}
	else
	{
		cout << this->name << "��(��) " << damage << "�� ���ظ� �Ծ����ϴ�.\n";
		hp -= damage;
		if (hp < 0)
		{
			Die();
		}
	}
}

void Wizard::Skill1(Human* pTarget)
{
	Human::Skill1(pTarget);	// �θ��� Human�� Skill1 �Լ� ����ϱ�
	Fireball(pTarget);
}

void Wizard::Fireball(Human* pEnemy)
{
	int fireBallCost = 15;
	if (mana > fireBallCost)
	{
		cout << "���̾� ��~" << endl; 
		pEnemy->Defence(intelligence * 0.5f + rand() % (intelligence * 3));	// (����*0.5f ~ ����*3) ����
		mana -= fireBallCost;
	}
	else
	{
		cout << "������ �����մϴ�.\n";
	}
}
