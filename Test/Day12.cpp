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

	// �ǽ� : �� �ڵ忡�� �߻��ϴ� �ſ�ſ�ſ� �ɰ��� ������ ã�� �ذ��ϱ�
	// Insert�ϸ鼭 new�ߴ� ��带 delete���� �ʾ� �޸� ���� �߻��Ѵ�.

	//pList->Clear();	// Clear�Լ��� ���ؼ� ���� ��带 ��� �����ϱ�. -> �Ҹ��ڷ� ȣ���ϴ� ������ ����

	delete pList;
}
