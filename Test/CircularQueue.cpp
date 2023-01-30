#include "CircularQueue.h"

void CircularQueue::Enqueue(int data)
{
	if (IsFull())
	{
		cout << "ť�� ����á���ϴ�." << endl;
		return;
	}

	queue[rear] = data;
	rear = (rear + 1) % Queue_Size;
}

int CircularQueue::Dequeue()
{
	int result = EMPTY;
	if (!IsEmpty())
	{
		result = queue[front];
		queue[front] = EMPTY;
		front = (front + 1) % Queue_Size;
	}
	return result;
}

void CircularQueue::Clear()
{
}

void CircularQueue::Print()
{
}
