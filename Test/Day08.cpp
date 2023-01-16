#include "Day08.h"

int Min1(int datas[], int count)
{
	// 가장 작은 값이란? => datas 중에서 숫자가 가장 작은 것
	// 가장 작은 값을 구하는 조건은?

	//int min = INT32_MAX;
	int min = datas[0];
	for (int i = 1; i < count; i++)
	{
		if (min > datas[i])	// datas[i]번째까 min보다 작으면 아래 코드를 수행해라.
		{
			min = datas[i];
		}
	}

	return min;	// datas에서 가장 작은 값이 리턴 되어야 한다.
}

int Min2(int* pData, int count)
{
	int min = pData[0];
	for (int i = 1; i < count; i++)
	{
		if (min > pData[i])	// datas[i]번째까 min보다 작으면 아래 코드를 수행해라.
		{
			min = pData[i];
		}
	}

	return min;
}

int Max(int* pData, int count)
{
	int max = pData[0];
	for (int i = 1; i < count; i++)
	{
		if (max < pData[i])	// datas[i]번째까 min보다 작으면 아래 코드를 수행해라.
		{
			max = pData[i];
		}
	}

	return max;
}

int Clamp(int value, int min, int max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}

	return value;
}

float Clamp(float value, float min, float max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}

	return value;
}

void Print_PlayerInfo_Deep(PlayerInfo info)
{
	info.level++;
	cout << endl << "Print_PlayerInfo(Deep) --------------------------" << endl;
	cout << "This player's name is " << info.name << endl;
	cout << info.name << " level is " << info.level << endl;
	cout << info.name << " exp is " << info.exp << endl;
}

void Print_PlayerInfo(PlayerInfo* pInfo)
{
	pInfo->level++;
	cout << endl << "Print_PlayerInfo --------------------------" << endl;
	cout << "This player's name is " << pInfo->name << endl;
	cout << pInfo->name << " level is " << pInfo->level << endl;
	cout << pInfo->name << " exp is " << pInfo->exp << endl;
}

//template <typename T>
//T ClampTemplate(T value, T min, T max)
//{
//	if (value < min)
//	{
//		value = min;
//	}
//	else if (value > max)
//	{
//		value = max;
//	}
//
//	return value;
//}