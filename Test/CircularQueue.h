#pragma once
#include <memory.h>
#include <iostream>

using namespace std;


class CircularQueue
{
public:		// ��� �͵��� ��� ����
	CircularQueue()
	{
		front = 0;
		rear = 0;
		memset(queue, EMPTY, sizeof(int) * Queue_Size);
	}

	/// <summary>
	/// ������ �ϳ��� ť�� �߰��ϴ� �Լ�
	/// </summary>
	/// <param name="data">�߰��� ������</param>
	void Enqueue(int data);

	/// <summary>
	/// ť���� �����͸� �ϳ� �����ϴ� �Լ�
	/// </summary>
	/// <returns>ť���� ������ ������</returns>
	int Dequeue();

	/// <summary>
	/// ť���� �����͸� ��� �����ϴ� �Լ�
	/// </summary>
	void Clear();

	/// <summary>
	/// ť�� ����ִ� ��� �����͸� ����ϴ� �Լ�
	/// </summary>
	void Print();

protected:	// ���� ���� ��� ���� �͵鸸 ��� ����
private:	// ���� ��� ����
	static const int Queue_Size = 6;	// ���� ���. ��� CircularQueue�� ���� ���� ������.
	int queue[Queue_Size];				// ���� ����� �̿��� �迭 ��� ����.

	const int EMPTY = INT32_MIN;

	int front = 0;
	int rear = 0;

	/// <summary>
	/// ť�� ������� Ȯ�����ִ� �Լ�
	/// </summary>
	/// <returns>ť�� ������� true. �ƴϸ� false</returns>
	inline bool IsEmpty() { return front == rear; }	// �ζ��� �Լ��� �Լ��� ȣ��Ǵ� ���� �ƴ϶� �����Ϸ��� ���ؼ� �ڵ尡 ��ü�ȴ�.

	/// <summary>
	/// ť�� ���� á���� Ȯ�����ִ� �Լ�
	/// </summary>
	/// <returns>ť�� ����á���� true, �ƴϸ� false</returns>
	inline bool IsFull() { return front == (rear + 1) % Queue_Size; }
};

