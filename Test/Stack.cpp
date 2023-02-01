#include "Stack.h"

void Stack::Push(int data)
{	
	// Top ������ ���� �� ������ �ְ�
	// ���� á���� "������ ���� ���ֽ��ϴ�."��� ����ϱ�

	if (top < size - 1 )	// ������ ���� ���ִ��� Ȯ��
	{
		// ���ÿ� ���ڸ��� �ִ�.
		top++;
		stack[top] = data;
	}
	else
	{
		// ������ ���� �� �ִ�.
		cout << "������ ���� ���ֽ��ϴ�." << endl;
	}

}

int Stack::Pop()
{
	int data = EMPTY;				// �⺻ ������ EMPTY ����
	if (top > -1 && top < size)		// top�� ������ �������� Ȯ��
	{
		data = stack[top];			// �������� �����̸� data�� Top�� �ִ� ������ ����
		top--;						// Top ����
	}

	if (data == EMPTY)
	{
		cout << "������ ������ϴ�." << endl;		// ��������� ����ִٰ� ���
	}

	return data;					// ��� ����
}

void Stack::Clear()
{
	top = STACK_IS_EMPTY;
	memset(stack, UINT32_MAX, sizeof(unsigned int) * size);
}

void Stack::Print()
{
	// [  ]
	// [  ]
	// [30] <- Top
	// [20]
	// [10]

	cout << "���� ���" << endl;

	// ��ĭ ����ϱ�
	int emptySize = size - top - 1;
	for (int i = 0; i < emptySize; i++)
	{
		cout << " [    ] " << endl;
	}

	if (top != STACK_IS_EMPTY)	// ������ ������� ������ ���� ���� ���
	{
		// top�κ� ����ϱ�
		cout << " [ " << stack[top] << " ] <- Top" << endl;

		// top �Ʒ��� ����ϱ�
		for (int i = top - 1; i > -1; i--)
		{
			cout << " [ " << stack[i] << " ] " << endl;
		}
		cout << endl;
	}
}
