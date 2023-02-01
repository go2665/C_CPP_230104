#include "Day18.h"

void TestDay18()
{
	//TestDay18_Stack_Push();
	//TestDay18_Stack_Pop();
	TestDay18_Stack_Clear();
}

void TestDay18_Stack_Pop()
{
	Stack* pStack = new Stack(5);

	pStack->Push(10);
	pStack->Push(20);
	pStack->Push(30);
	pStack->Push(40);
	pStack->Push(50);
	pStack->Print();

	pStack->Pop();
	pStack->Print();
	pStack->Pop();
	pStack->Print();
	pStack->Pop();
	pStack->Print();
	pStack->Pop();
	pStack->Print();
	pStack->Pop();	
	pStack->Print();
	pStack->Pop();
	pStack->Print();

	delete pStack;
	pStack = nullptr;
}

void TestDay18_Stack_Clear()
{
	Stack* pStack = new Stack(5);

	pStack->Push(10);
	pStack->Push(20);
	pStack->Push(30);
	pStack->Push(40);
	pStack->Push(50);
	pStack->Print();
	pStack->Clear();
	pStack->Print();
	pStack->Push(60);
	pStack->Print();

	delete pStack;
	pStack = nullptr;
}

void TestDay18_Stack_Push()
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

