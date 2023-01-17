#include "Day09.h"

void Day09()
{
	//Human a;
	//strcpy(a.name, "餌塋");
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
	Human* pHuman = new Human("偃掘葬");
	pHuman->PrintStatus();
	delete pHuman;
	pHuman = nullptr;	// NULL

	pHuman = new Human("餌塋",10);
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
/// 營敝л熱煎 虜菟橫霞 ね饜葬橡 掘ж朝 л熱
/// </summary>
/// <param name="num"></param>
/// <returns></returns>
int MyFactorial_Recursive(int num)
{
	if (num == 1)
		return 1;
	return num * MyFactorial_Recursive(num-1);
}

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
	// this : 贗楚蝶 濠晦 濠褐擊 陛葬酈朝 輿模
	cout << this->name << "朝 避歷蝗棲棻.\n";
}

void Human::PrintStatus()
{	
	cout << " 忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	printf(" 弛 檜葷 : %-20s (%d, %.1f%%)                 弛\n", 
		name, level, (float)exp/ (float)expMax * 100.0f);	// %s : 僥濠翮 轎溘
	printf(" 弛 HP   : ( %3d / %3d )     Mana : ( %3d / %3d )    弛\n", 
		hp, hpMax, mana, manaMax);
	printf(" 弛 ��   : %5d  弛", strength);			// %5d : 5蘊縑 璋濠 鎰晦(螃艇薹 薑溺)
	printf("弛 雖棟 : %5d  弛", intelligence);	// %-5d : 5蘊縑 璋濠 鎰晦(豭薹 薑溺)
	printf("弛 團繪 : %5d   弛\n", dexterity);			// %d : int 鎰晦
	cout << " 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
}

void Human::SetRandomStatus()
{
	// ��, 團繪, 雖棟擎 10~100 餌檜
	// hpMax朝 ��*10
	// manaMax朝 雖棟*10
	// hp朝 hpMax諦 偽棻. mana朝 manaMax諦 偽棻.
	// exp朝 о鼻 0. 
}
