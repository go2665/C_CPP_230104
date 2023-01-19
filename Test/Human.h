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

	virtual void Attack(Human* pEnemy);
	virtual void Defence(int damage);
	virtual void Skill1(Human* pTarget);

	void Die();

	/// <summary>
	/// Human이 가진 데이터를 모두 출력해서 보여주는 함수
	/// </summary>
	void PrintStatus();

	/// <summary>
	/// 랜덤으로 스테이터스 설정하는 함수
	/// </summary>
	void SetRandomStatus();

	/// <summary>
	/// 이 캐릭터가 죽었는지 확인하는 함수
	/// </summary>
	/// <returns>true면 죽었다. false면 살았다.</returns>
	inline bool IsDie() { return hp <= 0; };

protected:
	int proTest;

private :
	int priTest;

public:
	int GetPriTest();
};

