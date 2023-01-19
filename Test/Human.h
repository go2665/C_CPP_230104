#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Human
{
public:
	// ������
	char name[32] = "�̸�";
	int level = 1;
	int hp = 100;
	int hpMax = 100;
	int mana = 30;
	int manaMax = 50;
	int exp = 501;
	const int expMax = 1000;

	int strength = 10;
	int intelligence = 10;
	int dexterity = 10;

	// ������(�̸��� �޴� ������)
	Human(const char* name);
	// ������(�̸��� ������ �޴� ������)
	Human(const char* name, int level);

	// �ൿ
	void Initialize();

	virtual void Attack(Human* pEnemy);
	virtual void Defence(int damage);
	virtual void Skill1(Human* pTarget);

	void Die();

	/// <summary>
	/// Human�� ���� �����͸� ��� ����ؼ� �����ִ� �Լ�
	/// </summary>
	void PrintStatus();

	/// <summary>
	/// �������� �������ͽ� �����ϴ� �Լ�
	/// </summary>
	void SetRandomStatus();

	/// <summary>
	/// �� ĳ���Ͱ� �׾����� Ȯ���ϴ� �Լ�
	/// </summary>
	/// <returns>true�� �׾���. false�� ��Ҵ�.</returns>
	inline bool IsDie() { return hp <= 0; };

protected:
	int proTest;

private :
	int priTest;

public:
	int GetPriTest();
};

