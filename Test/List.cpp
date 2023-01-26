#include "List.h"

List::List()
{
}

List::~List()
{
	Clear();
}

// 클래스나 구조체의 맴버에 접근을 하기 위한 연산자.
// .  : 클래스나 구조체 본체일 때
// -> : 클래스나 구조체의 주소일 때

void List::Insert(int data, int index)
{
	ListNode* pNode = new ListNode();	// 새 노드 만들고
	pNode->data = data;					// 데이터 복사
	pNode->pNext = nullptr;				// 마지막이니까 pNext는 null

	if (index <= 0)
	{
		// index가 0보다 작거나 같으면 무조건 맨 앞에 넣는다.
		if (pHead != nullptr)
		{
			// 헤드에 무언가가 들어있다. => 다른 노드가 이미 들어가 있다.
			pNode->pNext = pHead;		// 1. 새 노드의 next가 원래 헤드를 가리킨다.
			pHead = pNode;				// 2. 새 노드를 새로운 헤드로 만든다.
		}
		else
		{
			// 헤드가 비어있다. => 리스트가 비어있다.
			pHead = pNode;
			pTail = pNode;
		}
	}
	else if (index >= length)
	{
		// index가 length보다 크거나 같으면 무조건 맨 뒤에 넣는다.			
		if (pTail != nullptr)
		{
			// 리스트에 노드가 있다.
			pTail->pNext = pNode;		// 1. 이전 tail의 next는 새노드로 설정한다.
			pTail = pNode;				// 2. 새 노드를 새로운 테일로 만든다.
		}
		else
		{
			pHead = pNode;
			pTail = pNode;
		}
	}
	else
	{
		// 인덱스로 받은 위치에 넣는다.

		// pTarget과 pPrev 찾기
		ListNode* pTarget = pHead;		// 끼워 넣을 위치에 있는 노드
		ListNode* pPrev = nullptr;		// 끼워 넣을 위치 한칸 앞에 있는 노드
		for (int i = 0; i < index ; i++)
		{
			pPrev = pTarget;
			pTarget = pTarget->pNext;
		}

		// pPrev와 pTarget 사이에 끼워 넣기
		pPrev->pNext = pNode;	// prev노드의 next를 새 노드로 설정한다.
		pNode->pNext = pTarget;	// 새 노드의 next를 target노드로 설정한다.
	}

	length++;
}

void List::RemoveTargetIndex(int index)
{
	// 특정 위치에 있는 노드를 지우기
	ListNode* pTarget = pHead;
	if (index <= 0)
	{
		// 무조건 맨 앞에 있는 노드 지우기
		pHead = pHead->pNext;		
	}
	else if (index >= length)
	{
		// 무조건 맨 뒤에 있는 노드 지우기
		ListNode* pPrev = nullptr;
		while (pTarget != pTail)
		{
			pPrev = pTarget;
			pTarget = pTarget->pNext;
		}
		pPrev->pNext = nullptr;
		pTail = pPrev;
	}
	else
	{
		// 필요한 노드 찾기
		ListNode* pPrev = nullptr;		// 지울 위치 한칸 앞에 있는 노드
		for (int i = 0; i < index; i++)
		{
			pPrev = pTarget;
			pTarget = pTarget->pNext;	// 지울 위치에 있는 노드로 찾아가기
		}

		// 노드 제거하기
		pPrev->pNext = pTarget->pNext;	//이전 노드의 next를 지울 위치에 있는 노드의 next로 설정하기
	}

	delete pTarget;		// 실제로 노드 메모리 해제
	pTarget = nullptr;
	length--;			// 길이 줄이기
}

void List::Clear()
{
	// 모든 노드 삭제하기
	while (pHead != nullptr)
	{
		ListNode* pDelete = pHead;
		pHead = pHead->pNext;
		delete pDelete;
	}
	pTail = nullptr;
	length = 0;
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
