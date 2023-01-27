#include "Queue.h"

void Queue::Enqueue(int data)
{
	QueueNode* pNode = new QueueNode();	// 새 노드 만들고
	pNode->data = data;					// 데이터 복사
	pNode->pNext = nullptr;				// 마지막이니까 pNext는 null

	pRear->pNext = pNode;
	pRear = pNode;
}
