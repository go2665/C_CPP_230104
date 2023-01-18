#include "Human.h"

Human::Human(const char* name)
{
	strcpy(this->name, name);
}

Human::Human(const char* name, int level)
{
	strcpy(this->name, name);
	this->level = level;
}

void Human::Attack(Human* pEnemy)
{
	pEnemy->Defence(strength);
}

void Human::Defence(int damage)
{
	hp -= damage;
	if (hp < 0)
	{
		Die();
	}
}

void Human::Die()
{
	// this : Ŭ���� �ڱ� �ڽ��� ����Ű�� �ּ�
	cout << this->name << "�� �׾����ϴ�.\n";
}

void Human::PrintStatus()
{
	cout << " ��������������������������������������������������������������������������������������������������������\n";
	printf(" �� �̸� : %-20s (%d, %.1f%%)                 ��\n",
		name, level, (float)exp / (float)expMax * 100.0f);
	printf(" �� HP   : ( %3d / %3d )     Mana : ( %3d / %3d )    ��\n",
		hp, hpMax, mana, manaMax);
	printf(" �� ��   : %5d  ��", strength);
	printf("�� ���� : %5d  ��", intelligence);
	printf("�� ��ø : %5d   ��\n", dexterity);
	cout << " ��������������������������������������������������������������������������������������������������������\n";

	// %d : int���
	// %f : float ���
	// %s : ���ڿ� ���
	// %% : %���
	// %5d : int�� 5�ڸ� ���缭 ���(������ ����)
	// %-5d : int�� 5�ڸ� ���缭 ���(���� ����)
	// %5.2f : float ���. �Ҽ��� ���� 5�ڸ� Ȯ��. �Ҽ��� �Ʒ��� 2�ڸ� ���.
}

void Human::SetRandomStatus()
{
	// ��, ��ø, ������ 10~100 ����
	// hpMax�� ��*10
	// manaMax�� ����*10
	// hp�� hpMax�� ����. mana�� manaMax�� ����.
	// exp�� �׻� 0. 
}