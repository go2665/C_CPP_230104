#include "Day14.h"

void TestDay14()
{
	cout << "Day14 시작" << endl;

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
	pList->Insert(17, 2);
	pList->Print();	// 25 20 17 15 10 5

	cout << "20은 " << pList->FindPosition(20) << "번째 위치에 있습니다." << endl;
	cout << "17은 " << pList->FindPosition(17) << "번째 위치에 있습니다." << endl;
	cout << "5은 " << pList->FindPosition(5) << "번째 위치에 있습니다." << endl;
	cout << "25은 " << pList->FindPosition(25) << "번째 위치에 있습니다." << endl;
	cout << "50은 " << pList->FindPosition(50) << "번째 위치에 있습니다." << endl;

	//pList->RemoveTargetIndex(2);
	//pList->Print();	// 25 20 15 10 5
	//pList->RemoveTargetIndex(2);
	//pList->Print();	// 25 20 10 5
	//pList->RemoveTargetIndex(1);
	//pList->Print();	// 25 10 5
	//pList->RemoveTargetIndex(0);
	//pList->Print();	// 10 5
	//pList->RemoveTargetIndex(1);
	//pList->Print();	// 10
	//pList->RemoveTargetIndex(5);
	//pList->Print(); // null

	delete pList;
}
