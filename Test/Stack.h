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
	int size = 0;
	unsigned int* stack;
	int top = STACK_IS_EMPTY;

	const unsigned int EMPTY = UINT32_MAX;
	const int STACK_IS_EMPTY = -1;
};

