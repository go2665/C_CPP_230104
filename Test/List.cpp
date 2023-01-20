#include "List.h"

void List::Insert(int data, int index)
{
	ListNode* pNode = new ListNode();	// �� ��� �����
	pNode->data = data;					// ������ ����
	pNode->pNext = nullptr;				// �������̴ϱ� pNext�� null


	// �켱 ������ ���� �������� �߰��ϱ�
	if (pTail != nullptr)
	{
		// ����Ʈ�� ��尡 �ִ�.
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
