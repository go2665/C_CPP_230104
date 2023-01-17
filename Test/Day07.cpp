#include "Day07.h"

void Print_GuGuDan(int dan)
{
	cout << dan << "���� ����մϴ�.\n";

	for (int i = 1; i < 10; i++)
	{
		cout << dan << " * " << i << " = " << dan * i << endl;			 
	}
}

void Print_Star(int floorCount)
{
	// floorCount��ŭ �������� ���
	for (int i = 0; i < floorCount; i++)
	{
		// 1~floorCount��ŭ�� ���̰� �Ǵ� *�� �̷���� �� ���
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

	// floorCount��ŭ �������� ���
	for (int i = 0; i < floorCount; i++)
	{
		// *ǥ �տ� " "�� � ���� ������ �����ϰ� ���
		//		������ - 1���� 0����		
		//for (int j = floorCount - 1; j > i; j--)		// ���⿡�� �ٸ����� ���� ����
		//for (int j = 0; j < floorCount - 1 - i; j++)
		int starCount = i * 2 + 1;
		int spaceCount = (maxCount - starCount) / 2;
		for(int j = 0; j < spaceCount; j++)
		{
			cout << " ";
		}

		// *ǥ�� � ������ �����ϰ� ���(1,3,5,7,9... �̷��� �����ؾ� �Ѵ�.)
		for (int j = 0; j < starCount; j++)
		{
			cout << "*";
		}	

		// �ٹٲٱ�
		cout << endl;		
	}	
}

// scope(������) : Ư���� ������ �Լ��� Ŭ�������� �����ϴ� ����