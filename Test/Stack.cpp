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
	// �����Ͱ� ������ 1�� ������ ����
	// ��������� EMPTY ����
	return 0;
}

void Stack::Clear()
{
}

void Stack::Print()
{
	// [  ]
	// [  ]
	// [30] <- Top
	// [20]
	// [10]

	// ��ĭ ����ϱ�
	int emptySize = size - top - 1;
	for (int i = 0; i < emptySize; i++)
	{
		cout << " [    ] " << endl;
	}

	// top�κ� ����ϱ�
	cout << " [ " << stack[top] << " ] <- Top" << endl;
	
	// top �Ʒ��� ����ϱ�
	for (int i = top-1; i > -1; i--)
	{
		cout << " [ " << stack[i] << " ] " << endl;
	}
	cout << endl;
}
