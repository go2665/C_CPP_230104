#pragma once

#include <iostream>

using namespace std;

void Day09();

// ����Լ�
// �Լ� ���ο��� �ڱ� �ڽ��� �ٽ� ȣ���ϴ� �Լ�

// ���丮�� 
// 3! = 3*2*1

int MyFactorial(int num);
int MyFactorial_Recursive(int num);

// Ŭ���� = ����ü + �Լ���
// C++���� ���.
// ��ü : �ٸ� �Ͱ� ������ �Ǵ� ���� Ư���� �ִ� ��
// Ŭ������ ����Ͽ� ��ü�� ǥ���Ѵ�.

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
	void Attack(Human* pEnemy);
	void Defence(int damage);
	void Die();

	/// <summary>
	/// Human�� ���� �����͸� ��� ����ؼ� �����ִ� �Լ�
	/// </summary>
	void PrintStatus();

	/// <summary>
	/// �������� �������ͽ� �����ϴ� �Լ�
	/// </summary>
	void SetRandomStatus();
};