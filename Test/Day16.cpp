#include "Day16.h"

void TestDay16()
{
	//TestDay16_Queue();
	TestDay16_CQ();
}

void TestDay16_Queue()
{
	cout << "Day16 시작 : 큐 테스트" << endl;

	Queue* pQueue = new Queue();
	pQueue->Print();	// null
	pQueue->Enqueue(10);
	pQueue->Print();	// 10 | null
	pQueue->Enqueue(20);
	pQueue->Print();	// 10 | 20 | null
	pQueue->Enqueue(30);
	pQueue->Print();	// 10 | 20 | 30 | null

	pQueue->Dequeue();
	pQueue->Print();	// 20 | 30 | null
	pQueue->Dequeue();
	pQueue->Print();	// 30 | null
	pQueue->Dequeue();
	pQueue->Print();	// null
	pQueue->Dequeue();
	pQueue->Print();	// null

	pQueue->Enqueue(40);
	pQueue->Print();	// 40 | null
	pQueue->Enqueue(50);
	pQueue->Print();	// 40 | 50 | null
	pQueue->Enqueue(60);
	pQueue->Print();	// 40 | 50 | 60 | null
	
	pQueue->Clear();
	pQueue->Print();	// null

	delete pQueue;
	pQueue = nullptr;

}

void TestDay16_CQ()
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
