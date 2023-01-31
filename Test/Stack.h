#pragma once
#include <iostream>
using namespace std;

class Stack
{
public:
	Stack(int stackSize)
	{
		size = stackSize;
		top = 0;
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
	int top = 0;
	const unsigned int EMPTY = UINT32_MAX;
};

