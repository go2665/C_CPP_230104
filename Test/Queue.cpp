#include "Queue.h"

void Queue::Enqueue(int data)
{
	QueueNode* pNode = new QueueNode();	// 새 노드 만들고
	pNode->data = data;					// 데이터 복사
	pNode->pNext = nullptr;				// 마지막이니까 pNext는 null

	if (pRear != nullptr)
	{
		// 큐에 데이터가 있는 상황
		pRear->pNext = pNode;
		pRear = pNode;
	}
	else
	{
		// 큐에 데이터가 없는 상황
		pRear = pNode;
		pFront = pNode;
	}
}

int Queue::Dequeue()
{
	int data = QUEUE_EMPTY;
	if (pFront != nullptr)
	{
		QueueNode* pNode = pFront;	// 원래 front 기록해 놓기
		pFront = pFront->pNext;		// 원래 front의 다음 노드를 새 front로 설정

		data = pNode->data;			// 원래 front의 데이터 복사
		delete pNode;				// 원래 front 제거
		pNode = nullptr;
	}

	if (pFront == nullptr)			// 큐에서 데이터가 전부 빠졌을 때의 문제 처리
		pRear = nullptr;

	return data;
}

void Queue::Clear()
{
}

void Queue::Print()
{
	// 큐에 10과 20이 순서대로 enqueue됬으면 아래와 같이 출력하기
	// 10 | 20 | null

	cout << "\n큐의 내용을 출력합니다.\n";

	// 순회를 위한 변수
	QueueNode* pNode = pFront;
	while (pNode != nullptr)
	{
		cout << pNode->data << " | ";
		pNode = pNode->pNext;
	}
	cout << "null" << endl;

}
