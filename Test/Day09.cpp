#include "Day09.h"

void Day09()
{
	//Human a;
	//strcpy(a.name, "���");
	//a.level = 3;
	//a.hp = 100;
	//a.hpMax = 100;
	//a.mana = 30;
	//a.manaMax = 50;
	//a.exp = 5025;
	//a.expMax = 10000;
	//a.strength = 10;
	//a.intelligence = 5;
	//a.dexterity = 7;
	//a.PrintStatus();

	//Human* pHuman = (Human*)malloc(sizeof(Human));
	HumanTest* pHuman = new HumanTest("������");
	pHuman->PrintStatus();
	delete pHuman;
	pHuman = nullptr;	// NULL

	pHuman = new HumanTest("���",10);
	pHuman->PrintStatus();
	delete pHuman;
	pHuman = nullptr;	// NULL

	
	int i = 0;

}

int MyFactorial(int num)
{
	int f = 1;
	for (int i = 1; i <= num; i++)
	{
		f *= i;
	}
	return f;
}

/// <summary>
/// ����Լ��� ������� ���丮�� ���ϴ� �Լ�
/// </summary>
/// <param name="num"></param>
/// <returns></returns>
int MyFactorial_Recursive(int num)
{
	if (num == 1)
		return 1;
	return num * MyFactorial_Recursive(num-1);
}

HumanTest::HumanTest(const char* name)
{
	strcpy(this->name, name);
}

HumanTest::HumanTest(const char* name, int level)
{
	strcpy(this->name, name);
	this->level = level;
}

void HumanTest::Attack(HumanTest* pEnemy)
{
	pEnemy->Defence(strength);
}

void HumanTest::Defence(int damage)
{
	hp -= damage;
	if (hp < 0)
	{
		Die();
	}
}

void HumanTest::Die()
{
	// this : Ŭ���� �ڱ� �ڽ��� ����Ű�� �ּ�
	cout << this->name << "�� �׾����ϴ�.\n";
}

void HumanTest::PrintStatus()
{	
	cout << " ��������������������������������������������������������������������������������������������������������\n";
	printf(" �� �̸� : %-20s (%d, %.1f%%)                 ��\n", 
		name, level, (float)exp/ (float)expMax * 100.0f);		
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

void HumanTest::SetRandomStatus()
{
	// ��, ��ø, ������ 10~100 ����
	// hpMax�� ��*10
	// manaMax�� ����*10
	// hp�� hpMax�� ����. mana�� manaMax�� ����.
	// exp�� �׻� 0. 
}
