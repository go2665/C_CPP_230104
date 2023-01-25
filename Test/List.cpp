#include "List.h"

List::List()
{
}

List::~List()
{
	Clear();
}

void List::Insert(int data, int index)
{
	ListNode* pNode = new ListNode();	// �� ��� �����
	pNode->data = data;					// ������ ����
	pNode->pNext = nullptr;				// �������̴ϱ� pNext�� null

	if (index < 0)
	{
		// index�� ������ ������ �� �տ� �ִ´�.
		if (pHead != nullptr)
		{
			// ��忡 ���𰡰� ����ִ�. => �ٸ� ��尡 �̹� �� �ִ�.
			pNode->pNext = pHead;		// 1. �� ����� next�� ���� ��带 ����Ų��.
			pHead = pNode;				// 2. �� ��带 ���ο� ���� �����.
		}
		else
		{
			// ��尡 ����ִ�. => ����Ʈ�� ����ִ�.
			pHead = pNode;
			pTail = pNode;
		}
	}
	else if (index <= length)
	{
		// index�� length���� ũ�ų� ������ ������ �� �ڿ� �ִ´�.			
		if (pTail != nullptr)
		{
			// ����Ʈ�� ��尡 �ִ�.
			pTail->pNext = pNode;		// 1. ���� tail�� next�� ������ �����Ѵ�.
			pTail = pNode;				// 2. �� ��带 ���ο� ���Ϸ� �����.
		}
		else
		{
			pHead = pNode;
			pTail = pNode;
		}
	}
	else
	{
		// �ε������ �ִ´�.
	}

	length++;
}

void List::Clear()
{
	// ��� ��� �����ϱ�
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
	cout << "\n����Ʈ�� ����մϴ�.\n";
	ListNode* pNode = pHead;

	// pNode�� �ص忡�� �����ؼ� pNode�� pNext�� null�� �� ������ ��� ���� ���� ����Ѵ�.

	while (pNode != nullptr)
	{
		cout << pNode->data << " -> ";
		pNode = pNode->pNext;
	}
	cout << "null" << endl;
}
