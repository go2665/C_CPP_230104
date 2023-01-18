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
	// this : 클래스 자기 자신을 가리키는 주소
	cout << this->name << "는 죽었습니다.\n";
}

void Human::PrintStatus()
{
	cout << " ┌──────────────────────────────────────────────────┐\n";
	printf(" │ 이름 : %-20s (%d, %.1f%%)                 │\n",
		name, level, (float)exp / (float)expMax * 100.0f);
	printf(" │ HP   : ( %3d / %3d )     Mana : ( %3d / %3d )    │\n",
		hp, hpMax, mana, manaMax);
	printf(" │ 힘   : %5d  │", strength);
	printf("│ 지능 : %5d  │", intelligence);
	printf("│ 민첩 : %5d   │\n", dexterity);
	cout << " └──────────────────────────────────────────────────┘\n";

	// %d : int출력
	// %f : float 출력
	// %s : 문자열 출력
	// %% : %출력
	// %5d : int를 5자리 맞춰서 출력(오른쪽 정렬)
	// %-5d : int를 5자리 맞춰서 출력(왼쪽 정렬)
	// %5.2f : float 출력. 소수점 위는 5자리 확보. 소수점 아래는 2자리 출력.
}

void Human::SetRandomStatus()
{
	// 힘, 민첩, 지능은 10~100 사이
	// hpMax는 힘*10
	// manaMax는 지능*10
	// hp는 hpMax와 같다. mana는 manaMax와 같다.
	// exp는 항상 0. 
}