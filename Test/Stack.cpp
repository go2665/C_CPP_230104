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
}
