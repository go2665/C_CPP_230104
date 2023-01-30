#include "Queue.h"

void Queue::Enqueue(int data)
{
	QueueNode* pNode = new QueueNode();	// �� ��� �����
	pNode->data = data;					// ������ ����
	pNode->pNext = nullptr;				// �������̴ϱ� pNext�� null

	if (pRear != nullptr)
	{
		// ť�� �����Ͱ� �ִ� ��Ȳ
		pRear->pNext = pNode;
		pRear = pNode;
	}
	else
	{
		// ť�� �����Ͱ� ���� ��Ȳ
		pRear = pNode;
		pFront = pNode;
	}
}

int Queue::Dequeue()
{
	int data = QUEUE_EMPTY;
	if (pFront != nullptr)
	{
		QueueNode* pNode = pFront;	// ���� front ����� ����
		pFront = pFront->pNext;		// ���� front�� ���� ��带 �� front�� ����

		data = pNode->data;			// ���� front�� ������ ����
		delete pNode;				// ���� front ����
		pNode = nullptr;
	}

	if (pFront == nullptr)			// ť���� �����Ͱ� ���� ������ ���� ���� ó��
		pRear = nullptr;

	return data;
}

void Queue::Clear()
{
}

void Queue::Print()
{
	// ť�� 10�� 20�� ������� enqueue������ �Ʒ��� ���� ����ϱ�
	// 10 | 20 | null

	cout << "\nť�� ������ ����մϴ�.\n";

	// ��ȸ�� ���� ����
	QueueNode* pNode = pFront;
	while (pNode != nullptr)
	{
		cout << pNode->data << " | ";
		pNode = pNode->pNext;
	}
	cout << "null" << endl;

}
