#include "Day13.h"

void TestDay13()
{
	cout << "Day13 ½ÃÀÛ" << endl;

	List* pList = new List;
	pList->Print();
	pList->Insert(10, -1);
	pList->Print();
	pList->Insert(20, -1);
	pList->Print();
	pList->Insert(30, -1);
	pList->Print();
	pList->Insert(40, -1);
	pList->Print();
	pList->Insert(50, -1);
	pList->Print();

	delete pList;
}
