#pragma once
#include "QueueNode.h"

class Queue
{
public:		// ��� �͵��� ��� ����
	
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
};

