#include "List.h"

void List::Insert(int data, int index)
{
	ListNode* pNode = new ListNode();	// 새 노드 만들고
	pNode->data = data;					// 데이터 복사
	pNode->pNext = nullptr;				// 마지막이니까 pNext는 null


	// 우선 무조건 제일 마지막에 추가하기
	if (pTail != nullptr)
	{
		// 리스트에 노드가 있다.
		pTail->pNext = pNode;
		pTail = pNode;
	}
	else
	{
		pHead = pNode;
		pTail = pNode;
	}
}

void List::Print()
{
	cout << "\n리스트를 출력합니다.\n";
	ListNode* pNode = pHead;

	// pNode가 해드에서 시작해서 pNode의 pNext가 null이 될 때까지 계속 다음 것을 출력한다.

	while (pNode != nullptr)
	{
		cout << pNode->data << " -> ";
		pNode = pNode->pNext;
	}
	cout << "null" << endl;
}
