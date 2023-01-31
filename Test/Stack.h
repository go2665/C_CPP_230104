#pragma once
#include <iostream>
using namespace std;

class Stack
{
public:
	Stack(int stackSize)
	{
		size = stackSize;
		top = STACK_IS_EMPTY;
		stack = new unsigned int[size];
		memset(stack, UINT32_MAX, sizeof(unsigned int) * size);
	}
	~Stack()
	{
		delete stack;
		stack = nullptr;
	}

	void Push(int data);
	int Pop();

	void Clear();
	void Print();

private:
	int size = 0;				// 스택의 크기
	unsigned int* stack;		// 스택의 데이터를 담는 배열
	int top = STACK_IS_EMPTY;	// 제일 위에 있는 데이터의 위치

	const unsigned int EMPTY = UINT32_MAX;
	const int STACK_IS_EMPTY = -1;
};

