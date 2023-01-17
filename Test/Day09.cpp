#include "Day09.h"

void Day09()
{
	//Human a;
	//strcpy(a.name, "»ç¶÷");
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
	Human* pHuman = new Human("°³±¸¸®");
	pHuman->PrintStatus();
	delete pHuman;
	pHuman = nullptr;	// NULL

	pHuman = new Human("»ç¶÷",10);
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
/// Àç±ÍÇÔ¼ö·Î ¸¸µé¾îÁø ÆÑÅä¸®¾ó ±¸ÇÏ´Â ÇÔ¼ö
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
	// this : Å¬·¡½º ÀÚ±â ÀÚ½ÅÀ» °¡¸®Å°´Â ÁÖ¼Ò
	cout << this->name << "´Â Á×¾ú½À´Ï´Ù.\n";
}

void Human::PrintStatus()
{	
	cout << " ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n";
	printf(" ¦¢ ÀÌ¸§ : %-20s (%d, %.1f%%)                 ¦¢\n", 
		name, level, (float)exp/ (float)expMax * 100.0f);	// %s : ¹®ÀÚ¿­ Ãâ·Â
	printf(" ¦¢ HP   : ( %3d / %3d )     Mana : ( %3d / %3d )    ¦¢\n", 
		hp, hpMax, mana, manaMax);
	printf(" ¦¢ Èû   : %5d  ¦¢", strength);			// %5d : 5Ä­¿¡ ¼ýÀÚ Âï±â(¿À¸¥ÂÊ Á¤·Ä)
	printf("¦¢ Áö´É : %5d  ¦¢", intelligence);	// %-5d : 5Ä­¿¡ ¼ýÀÚ Âï±â(¿ÞÂÊ Á¤·Ä)
	printf("¦¢ ¹ÎÃ¸ : %5d   ¦¢\n", dexterity);			// %d : int Âï±â
	cout << " ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n";
}

void Human::SetRandomStatus()
{
	// Èû, ¹ÎÃ¸, Áö´ÉÀº 10~100 »çÀÌ
	// hpMax´Â Èû*10
	// manaMax´Â Áö´É*10
	// hp´Â hpMax¿Í °°´Ù. mana´Â manaMax¿Í °°´Ù.
	// exp´Â Ç×»ó 0. 
}
