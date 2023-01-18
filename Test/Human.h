#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

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
	void Initialize();

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

