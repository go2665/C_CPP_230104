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
	int maxCount = floorCount * 2 - 1;

	// floorCount만큼 여러줄을 찍기
	for (int i = 0; i < floorCount; i++)
	{
		// *표 앞에 " "을 몇개 찍을 것인지 결정하고 찍기
		//		층갯수 - 1에서 0까지		
		//for (int j = floorCount - 1; j > i; j--)		// 보기에는 다르지만 같은 내용
		//for (int j = 0; j < floorCount - 1 - i; j++)
		int starCount = i * 2 + 1;
		int spaceCount = (maxCount - starCount) / 2;
		for(int j = 0; j < spaceCount; j++)
		{
			cout << " ";
		}

		// *표를 몇개 찍을지 결정하고 찍기(1,3,5,7,9... 이렇게 증가해야 한다.)
		for (int j = 0; j < starCount; j++)
		{
			cout << "*";
		}	

		// 줄바꾸기
		cout << endl;		
	}	
}

// scope(스코프) : 특정한 변수나 함수나 클래스들이 존재하는 범위