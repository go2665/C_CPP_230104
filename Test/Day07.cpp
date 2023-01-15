#include "Day07.h"

void Print_GuGuDan(int dan)
{
	cout << dan << "단을 출력합니다.\n";

	for (int i = 1; i < 10; i++)
	{
		cout << dan << " * " << i << " = " << dan * i << endl;			 
	}
}

void Print_Star(int floorCount)
{
	// floorCount만큼 여러줄을 찍기
	for (int i = 0; i < floorCount; i++)
	{
		// 1~floorCount만큼의 길이가 되는 *로 이루어진 줄 찍기
		int starCount = i + 1;
		for (int j = 0; j < starCount; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void Print_Pyramid(int floorCount)
{
	// floorCount만큼 여러줄을 찍기
	for (int i = 0; i < floorCount; i++)
	{
		// *표 앞에 " "을 몇개 찍을 것인지 결정하고 찍기
		// *표를 몇개 찍을지 결정하고 찍기
		// 줄바꾸기
	}
}