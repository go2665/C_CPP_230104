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
		if (pPrev == nullptr)
		{
			// pTarget이 head이자 tail이다 라는 것과 같은 의미
			// pTarget이 head니까 pTarget의 앞은 존재할 수 없다.
			pHead = nullptr;	// 리스트는 이제 비었으니까 머리와 꼬리를 전부 null로
			pTail = nullptr;
		}
		else
		{
			// 리스트에 노드가 2개 이상 있는 상태에서 마지막 노드를 제거하는 상황
			pPrev->pNext = nullptr;
			pTail = pPrev;
		}
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

		// 노드 링크 제거하기
		pPrev->pNext = pTarget->pNext;	// 이전 노드의 next를 지울 위치에 있는 노드의 next로 설정하기
		if (pPrev->pNext == nullptr)	// pNext가 없다는 것은 pPrev가 새로운 pTail이 되어야한다는 이야기
		{
			pTail = pPrev;	// 뒤가 없으면 새로운 꼬리로 설정
		}
	}

	delete pTarget;		// 실제로 노드 메모리 해제
	pTarget = nullptr;
	length--;			// 길이 줄이기
}

bool List::RemoveTargetData(int data)
{
	bool result = false;
	int index = FindPosition(data);	// data의 위치 찾기
	if (index != NOT_FOUND)			// 있는지 없는지 확인
	{
		// data가 있다.
		RemoveTargetIndex(index);
		result = true;
	}
	//else		// 이미 시작할 때 result를 false로 했기 때문에 사용할 필요가 없다.
	//{
	//	// data가 없다.
	//}

	return result;
}

int List::FindPosition(int data)
{
	// 실습 : 함수 완성하기
	// 시간 : 6시 5분까지
	
	// head부터 하나씩 data와 비교
	int result = NOT_FOUND;			// 초기값으로 NOT_FOUND
	ListNode* pNode = pHead;
	/*while (pNode != pTail)
	{
		pNode = pNode->pNext;
	}*/
	for (int i = 0; i < length; i++)
	{
		if (pNode->data == data)	// pNode에 들어있는 데이터가 찾는 데이터와 같으면
		{
			result = i;				// 찾는 것을 중지하고 있는 위치를 result에 저장
			break;
		}
		pNode = pNode->pNext;		// 아니면 다음 노드로 진행
	}

	return result;					// result 리턴
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
