#include "Human.h"

Human::Human(const char* name)
{
	strcpy(this->name, name);
	Initialize();

	priTest = 30;
}

Human::Human(const char* name, int level)
{
	strcpy(this->name, name);
	this->level = level;
	Initialize();
}

void Human::Initialize()
{	
	SetRandomStatus();

	exp = 0;
}

void Human::Attack(Human* pEnemy)
{
	cout << "Human::Attack" << endl;
	cout << this->name << "��(��) " << pEnemy->name << "��(��) �����մϴ�.\n";
	pEnemy->Defence(strength);
}

void Human::Defence(int damage)
{
	cout << this->name << "��(��) " << damage << "�� ���ظ� �Ծ����ϴ�.\n";
	hp -= damage;
	if (hp < 0)
	{
		Die();
	}
}

void Human::Skill1(Human* pTarget)
{
	cout << "ù��° ��ų �ߵ�" << endl;
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
	cout << "������ �����ϴ�.\n";

	int min;
	int max;
	float ratio = (float)rand() / (float)RAND_MAX;	// ratio�� 0.0f ~ 1.0f ������ ���� ������.
	/*int testResult[3] = { 0,0,0 };
	for (int i = 0; i < 1000000; i++)
	{
		ratio = (float)rand() / (float)RAND_MAX;
		if (ratio < 0.7f)
		{
			testResult[0]++;
		}
		else if (ratio < 0.9f)
		{
			testResult[1]++;
		}
		else
		{
			testResult[2]++;
		}
	}

	cout << "Test 70% ���� : " << testResult[0] << endl;
	cout << "Test 20% ���� : " << testResult[1] << endl;
	cout << "Test 10% ���� : " << testResult[2] << endl;*/

	if (ratio < 0.7f)
	{
		// ����� ���� Ȯ����? 70%, 70% Ȯ���� 10~30
		min = 10;
		max = 30;
		cout << "����մϴ�.\n";
	}
	else if (ratio < 0.9f)
	{
		// ����� ���� Ȯ����? 20%, 20% Ȯ���� 30~50
		min = 30;
		max = 50;
		cout << "�پ�ϴ�.\n";
	}
	else
	{
		// ����� ���� Ȯ����? 10%, 10% Ȯ���� 50~100
		min = 50;
		max = 100;
		cout << "õ���Դϴ�.\n";
	}
	strength = min + rand() % (max - min);
	intelligence = min + rand() % (max - min);
	dexterity = min + rand() % (max - min);

	// hpMax�� ��*10
	// manaMax�� ����*10
	// hp�� hpMax�� ����. mana�� manaMax�� ����.
	hpMax = strength * 10;
	hp = hpMax;
	manaMax = intelligence * 10;
	mana = manaMax;
}

int Human::GetPriTest()
{
	return priTest;
}
