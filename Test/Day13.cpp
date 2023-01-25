#include "Day13.h"

void TestDay13()
{
	cout << "Day13 ½ÃÀÛ" << endl;

	List* pList = new List;
	pList->Print();
	pList->Insert(10, -1);
	pList->Print();	// 10
	pList->Insert(20, -1);
	pList->Print();	// 20 10
	pList->Insert(15, 1);
	pList->Print();	// 20 15 10
	pList->Insert(5, 10);
	pList->Print();	// 20 15 10 5
	pList->Insert(25, 0);
	pList->Print();	// 25 20 15 10 5

	delete pList;
}
