#include "Day17.h"

void TestDay17()
{
	//TestDay17_CQ();
	//TestDay17_Print();
	//TestDay17_QueueDelete();
	TestDay17_Stack();
}

void TestDay17_Stack()
{
	Stack* pStack = new Stack(5);

	pStack->Push(10);
	pStack->Print();
	pStack->Push(20);
	pStack->Print();
	pStack->Push(30);
	pStack->Print();
	pStack->Push(40);
	pStack->Print();
	pStack->Push(50);
	pStack->Print();
	pStack->Push(60);
	pStack->Print();
	pStack->Push(70);
	pStack->Print();

	delete pStack;
	pStack = nullptr;
}

void TestDay17_Print()
{
	CircularQueue* pQueue = new CircularQueue();

	pQueue->Enqueue(10);
	pQueue->Print();
	pQueue->Enqueue(20);
	pQueue->Print();
	pQueue->Enqueue(30);
	pQueue->Print();
	pQueue->Dequeue(); 
	pQueue->Print();
	pQueue->Dequeue(); 
	pQueue->Print();
	pQueue->Dequeue(); 
	pQueue->Print();
	pQueue->Enqueue(40); 
	pQueue->Print();
	pQueue->Enqueue(50); 
	pQueue->Print();
	pQueue->Enqueue(60); 
	pQueue->Print();
	pQueue->Dequeue(); 
	pQueue->Print();
	pQueue->Dequeue(); 
	pQueue->Print();
	pQueue->Enqueue(70);
	pQueue->Print();
	pQueue->Enqueue(80);
	pQueue->Print();
	pQueue->Clear();
	pQueue->Print();

	delete pQueue;
	pQueue = nullptr;
}

void TestDay17_QueueDelete()
{
	Queue* pQueue = new Queue();
	pQueue->Enqueue(10);
	pQueue->Enqueue(20);
	pQueue->Enqueue(30);
	delete pQueue;
	pQueue = nullptr;
	

}

void TestDay17_CQ()
{
	CircularQueue* pQueue = new CircularQueue();

	pQueue->Enqueue(10);
	pQueue->Print();
	pQueue->Enqueue(20);
	pQueue->Print();
	pQueue->Enqueue(30);
	pQueue->Print();
	pQueue->Enqueue(40);
	pQueue->Print();
	pQueue->Enqueue(50);
	pQueue->Print();
	pQueue->Enqueue(60);
	pQueue->Print();
	pQueue->Enqueue(70);
	pQueue->Print();
	pQueue->Dequeue();
	pQueue->Print();
	pQueue->Dequeue();
	pQueue->Print();
	pQueue->Dequeue();
	pQueue->Print();
	pQueue->Dequeue();
	pQueue->Print();
	pQueue->Dequeue();
	pQueue->Print();
	pQueue->Dequeue();

	delete pQueue;
	pQueue = nullptr;
}
