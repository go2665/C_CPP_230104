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

	// 실습 : 이 코드에서 발생하는 매우매우매우 심각한 문제를 찾고 해결하기
	// Insert하면서 new했던 노드를 delete하지 않아 메모리 릭이 발생한다.

	//pList->Clear();	// Clear함수를 통해서 만든 노드를 모두 삭제하기. -> 소멸자로 호출하는 것으로 변경

	delete pList;
}
