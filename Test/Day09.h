#pragma once

#include <iostream>

using namespace std;

void Day09();

// 재귀함수
// 함수 내부에서 자기 자신을 다시 호출하는 함수

// 팩토리얼 
// 3! = 3*2*1

int MyFactorial(int num);
int MyFactorial_Recursive(int num);

// 클래스 = 구조체 + 함수들
// C++에서 사용.
// 객체 : 다른 것과 구분이 되는 고유 특성이 있는 것
// 클래스를 사용하여 객체를 표현한다.

class Human
{
public:
	// 데이터
	char name[32] = "이름";
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

	// 생성자(이름만 받는 생성자)
	Human(const char* name);
	// 생성자(이름과 레벨을 받는 생성자)
	Human(const char* name, int level);

	// 행동
	void Attack(Human* pEnemy);
	void Defence(int damage);
	void Die();

	/// <summary>
	/// Human이 가진 데이터를 모두 출력해서 보여주는 함수
	/// </summary>
	void PrintStatus();

	/// <summary>
	/// 랜덤으로 스테이터스 설정하는 함수
	/// </summary>
	void SetRandomStatus();
};