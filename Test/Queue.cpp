#include "Queue.h"

void Queue::Enqueue(int data)
{
	QueueNode* pNode = new QueueNode();	// �� ��� �����
	pNode->data = data;					// ������ ����
	pNode->pNext = nullptr;				// �������̴ϱ� pNext�� null

	pRear->pNext = pNode;
	pRear = pNode;
}
