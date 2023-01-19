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
	cout << this->name << "이(가) " << pEnemy->name << "을(를) 공격합니다.\n";
	pEnemy->Defence(strength);
}

void Human::Defence(int damage)
{
	cout << this->name << "이(가) " << damage << "의 피해를 입었습니다.\n";
	hp -= damage;
	if (hp < 0)
	{
		Die();
	}
}

void Human::Skill1(Human* pTarget)
{
	cout << "첫번째 스킬 발동" << endl;
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
	cout << "스탯을 돌립니다.\n";

	int min;
	int max;
	float ratio = (float)rand() / (float)RAND_MAX;	// ratio는 0.0f ~ 1.0f 사이의 값을 가진다.
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

	cout << "Test 70% 이하 : " << testResult[0] << endl;
	cout << "Test 20% 이하 : " << testResult[1] << endl;
	cout << "Test 10% 이하 : " << testResult[2] << endl;*/

	if (ratio < 0.7f)
	{
		// 여기로 들어올 확률은? 70%, 70% 확률로 10~30
		min = 10;
		max = 30;
		cout << "평범합니다.\n";
	}
	else if (ratio < 0.9f)
	{
		// 여기로 들어올 확률은? 20%, 20% 확률로 30~50
		min = 30;
		max = 50;
		cout << "뛰어납니다.\n";
	}
	else
	{
		// 여기로 들어올 확률은? 10%, 10% 확률로 50~100
		min = 50;
		max = 100;
		cout << "천재입니다.\n";
	}
	strength = min + rand() % (max - min);
	intelligence = min + rand() % (max - min);
	dexterity = min + rand() % (max - min);

	// hpMax는 힘*10
	// manaMax는 지능*10
	// hp는 hpMax와 같다. mana는 manaMax와 같다.
	hpMax = strength * 10;
	hp = hpMax;
	manaMax = intelligence * 10;
	mana = manaMax;
}

int Human::GetPriTest()
{
	return priTest;
}
