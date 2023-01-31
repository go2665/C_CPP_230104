#pragma once
#include <iostream>
#include "QueueNode.h"

using namespace std;

class Queue
{
public:		// ��� �͵��� ��� ����
	~Queue()
	{
		Clear();	// ��尡 �����ִ� ���¿��� �������� ���� ���
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
	QueueNode* pFront = nullptr;	// Front�� �ּ�
	QueueNode* pRear = nullptr;		// Rear�� �ּ�

	const int QUEUE_EMPTY = INT32_MIN;	// ť�� ����� �� Dequeue�ϸ� ������ �Ǵ� ��
};

