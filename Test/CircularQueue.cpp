#include "CircularQueue.h"

void CircularQueue::Enqueue(int data)
{
	if (IsFull())
	{
		cout << "큐가 가득찼습니다." << endl;
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
	front = 0;
	rear = 0;
	memset(queue, EMPTY, sizeof(int) * Queue_Size);
}

void CircularQueue::Print()
{
	// front에서 시작해서 rear가 될 때까지 for문 돌리기
	cout << "서큘러 큐 출력하기" << endl;

	for (int i = front; i != rear; i = (i + 1) % Queue_Size)
	{
		cout << queue[i] << " | ";
	}
	cout << "null" << endl;
}
