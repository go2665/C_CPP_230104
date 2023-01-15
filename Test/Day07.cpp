#include "Day07.h"

void Print_GuGuDan(int dan)
{
	cout << dan << "단을 출력합니다.\n";

	for (int i = 1; i < 10; i++)
	{
		cout << dan << " * " << i << " = " << dan * i << endl;			 
	}
}