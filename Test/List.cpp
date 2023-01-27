#include "List.h"

List::List()
{
}

List::~List()
{
	Clear();
}

// Ŭ������ ����ü�� �ɹ��� ������ �ϱ� ���� ������.
// .  : Ŭ������ ����ü ��ü�� ��
// -> : Ŭ������ ����ü�� �ּ��� ��

void List::Insert(int data, int index)
{
	ListNode* pNode = new ListNode();	// �� ��� �����
	pNode->data = data;					// ������ ����
	pNode->pNext = nullptr;				// �������̴ϱ� pNext�� null

	if (index <= 0)
	{
		// index�� 0���� �۰ų� ������ ������ �� �տ� �ִ´�.
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
	else if (index >= length)
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
		// �ε����� ���� ��ġ�� �ִ´�.

		// pTarget�� pPrev ã��
		ListNode* pTarget = pHead;		// ���� ���� ��ġ�� �ִ� ���
		ListNode* pPrev = nullptr;		// ���� ���� ��ġ ��ĭ �տ� �ִ� ���
		for (int i = 0; i < index ; i++)
		{
			pPrev = pTarget;
			pTarget = pTarget->pNext;
		}

		// pPrev�� pTarget ���̿� ���� �ֱ�
		pPrev->pNext = pNode;	// prev����� next�� �� ���� �����Ѵ�.
		pNode->pNext = pTarget;	// �� ����� next�� target���� �����Ѵ�.
	}

	length++;
}

void List::RemoveTargetIndex(int index)
{
	// Ư�� ��ġ�� �ִ� ��带 �����
	ListNode* pTarget = pHead;
	if (index <= 0)
	{
		// ������ �� �տ� �ִ� ��� �����
		pHead = pHead->pNext;		
	}
	else if (index >= length)
	{
		// ������ �� �ڿ� �ִ� ��� �����
		ListNode* pPrev = nullptr;
		while (pTarget != pTail)
		{
			pPrev = pTarget;
			pTarget = pTarget->pNext;
		}
		if (pPrev == nullptr)
		{
			// pTarget�� head���� tail�̴� ��� �Ͱ� ���� �ǹ�
			// pTarget�� head�ϱ� pTarget�� ���� ������ �� ����.
			pHead = nullptr;	// ����Ʈ�� ���� ������ϱ� �Ӹ��� ������ ���� null��
			pTail = nullptr;
		}
		else
		{
			// ����Ʈ�� ��尡 2�� �̻� �ִ� ���¿��� ������ ��带 �����ϴ� ��Ȳ
			pPrev->pNext = nullptr;
			pTail = pPrev;
		}
	}
	else
	{
		// �ʿ��� ��� ã��
		ListNode* pPrev = nullptr;		// ���� ��ġ ��ĭ �տ� �ִ� ���
		for (int i = 0; i < index; i++)
		{
			pPrev = pTarget;
			pTarget = pTarget->pNext;	// ���� ��ġ�� �ִ� ���� ã�ư���
		}

		// ��� ��ũ �����ϱ�
		pPrev->pNext = pTarget->pNext;	// ���� ����� next�� ���� ��ġ�� �ִ� ����� next�� �����ϱ�
		if (pPrev->pNext == nullptr)	// pNext�� ���ٴ� ���� pPrev�� ���ο� pTail�� �Ǿ���Ѵٴ� �̾߱�
		{
			pTail = pPrev;	// �ڰ� ������ ���ο� ������ ����
		}
	}

	delete pTarget;		// ������ ��� �޸� ����
	pTarget = nullptr;
	length--;			// ���� ���̱�
}

bool List::RemoveTargetData(int data)
{
	bool result = false;
	int index = FindPosition(data);	// data�� ��ġ ã��
	if (index != NOT_FOUND)			// �ִ��� ������ Ȯ��
	{
		// data�� �ִ�.
		RemoveTargetIndex(index);
		result = true;
	}
	//else		// �̹� ������ �� result�� false�� �߱� ������ ����� �ʿ䰡 ����.
	//{
	//	// data�� ����.
	//}

	return result;
}

int List::FindPosition(int data)
{
	// �ǽ� : �Լ� �ϼ��ϱ�
	// �ð� : 6�� 5�б���
	
	// head���� �ϳ��� data�� ��
	int result = NOT_FOUND;			// �ʱⰪ���� NOT_FOUND
	ListNode* pNode = pHead;
	/*while (pNode != pTail)
	{
		pNode = pNode->pNext;
	}*/
	for (int i = 0; i < length; i++)
	{
		if (pNode->data == data)	// pNode�� ����ִ� �����Ͱ� ã�� �����Ϳ� ������
		{
			result = i;				// ã�� ���� �����ϰ� �ִ� ��ġ�� result�� ����
			break;
		}
		pNode = pNode->pNext;		// �ƴϸ� ���� ���� ����
	}

	return result;					// result ����
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
