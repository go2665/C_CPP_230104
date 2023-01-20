#include "Day12.h"

void TestDay12()
{
	List* pList = new List;
	pList->Print();
	pList->Insert(10, 0);
	pList->Print();
	pList->Insert(20, 0);
	pList->Print();
	pList->Insert(30, 0);
	pList->Print();
	pList->Insert(40, 0);
	pList->Print();
	pList->Insert(50, 0);
	pList->Print();


	delete pList;
}
