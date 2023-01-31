#include "Day17.h"

void TestDay17()
{
	TestDay17_CQ();
}

void TestDay17_CQ()
{
	CircularQueue* pQueue = new CircularQueue();

	pQueue->Enqueue(10);
	pQueue->Enqueue(20);
	pQueue->Enqueue(30);
	pQueue->Enqueue(40);
	pQueue->Enqueue(50);
	pQueue->Enqueue(60);
	pQueue->Enqueue(70);
	pQueue->Dequeue();
	pQueue->Dequeue();
	pQueue->Dequeue();
	pQueue->Dequeue();
	pQueue->Dequeue();
	pQueue->Dequeue();

	delete pQueue;
	pQueue = nullptr;
}
